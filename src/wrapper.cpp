#include "wrapper.h"


/*-----------------------------------------------------------------------------
    Miscellaneous helper functions
-----------------------------------------------------------------------------*/

int copyStrToBuf(void* dst, wxString& src) {
  if (dst) wxStrcpy ((wxChar*)dst, src.c_str());
  return src.Length();
}

/*-----------------------------------------------------------------------------
    The global idle timer
-----------------------------------------------------------------------------*/
class wxIdleTimer : public wxTimer
{
public:
  void Notify() {
    wxWakeUpIdle();   /* send idle events */
  }
};

wxIdleTimer* idleTimer = NULL;

void initIdleTimer()
{
  idleTimer = new wxIdleTimer();
}

void doneIdleTimer()
{
  if (idleTimer) {
    idleTimer->Stop();
    delete idleTimer;
    idleTimer = NULL;
  }
}



/*-----------------------------------------------------------------------------
    The main application
-----------------------------------------------------------------------------*/
wxClosure* initClosure = NULL;
int APPTerminating = 0;

IMPLEMENT_APP_NO_MAIN(ELJApp);

bool ELJApp::OnInit (void)
{
  wxInitAllImageHandlers();
  initIdleTimer();
  if (initClosure) {
    delete initClosure; /* special: init is only called once with a NULL event */
    initClosure=NULL;
  }
  return true;
}

int ELJApp::OnExit( void )
{
  doneIdleTimer();
  return wxApp::OnExit();
}

void ELJApp::InitZipFileSystem()
{
        static int InitZIPFileSystem_done = 0;

        if (!InitZIPFileSystem_done)
        {
                InitZIPFileSystem_done = 1;
                wxFileSystem::AddHandler(new wxZipFSHandler());
        }
}

void ELJApp::InitImageHandlers()
{
        static int InitImageHandlers_done = 0;

        if (!InitImageHandlers_done)
        {
                InitImageHandlers_done = 1;
                wxInitAllImageHandlers();
        }
}


/* "getCallback" is a hack to retrieve the callback object for a certain event
   see also "wxEvtHandler_FindClosure"
*/
static wxCallback** getCallback = NULL;

void ELJApp::HandleEvent(wxEvent& _evt)
{
  wxCallback* callback = (wxCallback*)(_evt.m_callbackUserData);
  if (getCallback) {
    *getCallback = callback;    /* retrieve the callback */
  }
  else if (callback) {
    callback->Invoke( &_evt );  /* normal: invoke the callback function */
  }
}

/*-----------------------------------------------------------------------------
    Closures
-----------------------------------------------------------------------------*/
wxClosure::wxClosure( ClosureFun fun, void* data )
{
  m_refcount = 0;
  m_fun  = fun;
  m_data = data;
}

wxClosure::~wxClosure()
{
  /* call for the last time with a NULL event. Give opportunity to clean up resources */
  if (m_fun) { m_fun((void*)m_fun, m_data, NULL); }
}

void wxClosure::IncRef()
{
  m_refcount++;
}

void wxClosure::DecRef()
{
  m_refcount--;
  if (m_refcount <= 0) {
    delete this;
  }
}

void wxClosure::Invoke( wxEvent* event )
{
  if (event && m_fun) { m_fun((void*)m_fun, m_data, event); }
};

void* wxClosure::GetData()
{
  return m_data;
}

/*-----------------------------------------------------------------------------
    callback: a reference counting wrapper for a closure
-----------------------------------------------------------------------------*/
wxCallback::wxCallback( wxClosure* closure )
{
  m_closure = closure;
  m_closure->IncRef();
}

wxCallback::~wxCallback()
{
  m_closure->DecRef();
}

void wxCallback::Invoke( wxEvent* event )
{
  m_closure->Invoke(event);
}

wxClosure* wxCallback::GetClosure()
{
  return m_closure;
}



/*-----------------------------------------------------------------------------
    wrapper for objectRefData
-----------------------------------------------------------------------------*/
class wxcClosureRefData : public wxObjectRefData
{
  private:
    wxClosure*  m_closure;
  public:
    wxcClosureRefData( wxClosure* closure );
    ~wxcClosureRefData();

    wxClosure* GetClosure();
};

wxcClosureRefData::wxcClosureRefData( wxClosure* closure )
{
  m_closure = closure;
}

wxcClosureRefData::~wxcClosureRefData()
{
/* printf("delete wxc-ClosureRefData\n");  */
  if (m_closure) { delete m_closure; m_closure = NULL; }
}

wxClosure* wxcClosureRefData::GetClosure()
{
  return m_closure;
}


/*-----------------------------------------------------------------------------
    C interface to event handling and closures.
-----------------------------------------------------------------------------*/
extern "C"
{
/* event handling */
EWXWEXPORT(int,wxEvtHandler_Connect)(wxEvtHandler* self,int first,int last,int type,wxClosure* closure)
{
  wxCallback* callback = new wxCallback(closure);
  self->Connect(first, last, type, (wxObjectEventFunction)&ELJApp::HandleEvent, callback);
  return 0;
}

EWXWEXPORT(wxClosure*,wxEvtHandler_GetClosure)(wxEvtHandler* evtHandler,int id,int type)
{
  wxCommandEvent  event(type,id);     //We can use any kind of event here
  wxCallback*     callback = NULL;
  bool            found    = false;

  //set the global variable 'getCallback' so HandleEvent
  //knows we just want to know the closure. Unfortunately, this
  //seems the cleanest way to retrieve the callback in wxWindows.
  getCallback = &callback;
  found = evtHandler->SearchDynamicEventTable( event );
  getCallback = NULL;

  if (found && callback)
    return callback->GetClosure();
  else
    return NULL;
}

/* closures */
EWXWEXPORT(wxClosure*,wxClosure_Create)(ClosureFun fun,wxObject* data)
{
  return new wxClosure(fun,data);
}

EWXWEXPORT(void*,wxClosure_GetData)(wxClosure* closure)
{
  return closure->GetData();
}

/* client data */
EWXWEXPORT(void*,wxEvtHandler_GetClientClosure)(wxEvtHandler* self)
{
  return (void*)self->GetClientObject();
}

EWXWEXPORT(void,wxEvtHandler_SetClientClosure)(wxEvtHandler* self,wxClosure* closure)
{
  self->SetClientObject(closure);
}

EWXWEXPORT(wxClosure*,wxObject_GetClientClosure)(wxObject* self)
{
  wxcClosureRefData* refData = (wxcClosureRefData*)self->GetRefData();
  if (refData)
    return refData->GetClosure();
  else
    return NULL;
}

EWXWEXPORT(void,wxObject_SetClientClosure)(wxObject* self,wxClosure* closure)
{
  wxcClosureRefData* refData;
  /* wxASSERT(self->GetRefData() == NULL); */
  self->UnRef();
  wxASSERT(self->GetRefData() == NULL);
  refData = new wxcClosureRefData( closure );
  self->SetRefData( refData );    //set new data -- ref count must be 1 as setRefData doesn't increase it.  
}

/*-----------------------------------------------------------------------------
    C interface to the idle timer
-----------------------------------------------------------------------------*/
EWXWEXPORT(int,ELJApp_GetIdleInterval)()
{
  if (!idleTimer) return 0;

  if (idleTimer->IsRunning())
    return idleTimer->GetInterval();
  else
    return 0;
}

EWXWEXPORT(void,ELJApp_SetIdleInterval)(int interval)
{
  if (idleTimer) {
    if (idleTimer->IsRunning()) {
      idleTimer->Stop();
    }
    if (interval >= 5) {
      idleTimer->Start( interval, false );
    }
  }
}

/*-----------------------------------------------------------------------------
    C interface to the application.
-----------------------------------------------------------------------------*/
//int OnExit();
//virtual void OnFatalException();
EWXWEXPORT(int,ELJApp_MainLoop)()
{
        return wxGetApp().MainLoop();
}

EWXWEXPORT(bool,ELJApp_Initialized)()
{
#if WXWIN_COMPATIBILITY_2_6
        return wxGetApp().Initialized();
#else
        return TRUE;
#endif
}

EWXWEXPORT(int,ELJApp_Pending)()
{
        return (int)wxGetApp().Pending();
}

EWXWEXPORT(void,ELJApp_Dispatch)()
{
        wxGetApp().Dispatch();
}

EWXWEXPORT(wxString*,ELJApp_GetAppName)()
{
  return new wxString(wxGetApp().GetAppName());
}

EWXWEXPORT(void,ELJApp_SetAppName)(wxString* name)
{
        wxGetApp().SetAppName(*name);
}

EWXWEXPORT(wxString*,ELJApp_GetClassName)()
{
  return new wxString(wxGetApp().GetClassName());
}

EWXWEXPORT(void,ELJApp_SetClassName)(wxString* name)
{
        wxGetApp().SetClassName(*name);
}

EWXWEXPORT(wxString*,ELJApp_GetVendorName)()
{
  return new wxString(wxGetApp().GetVendorName());
}

EWXWEXPORT(void,ELJApp_SetVendorName)(wxString* name)
{
        wxGetApp().SetVendorName(*name);
}

EWXWEXPORT(void*,ELJApp_GetTopWindow)()
{
        return wxGetApp().GetTopWindow();
}

EWXWEXPORT(void,ELJApp_SetExitOnFrameDelete)(bool flag)
{
        wxGetApp().SetExitOnFrameDelete(flag);
}

EWXWEXPORT(int,ELJApp_GetExitOnFrameDelete)()
{
        return (int)wxGetApp().GetExitOnFrameDelete();
}

EWXWEXPORT(void*,ELJApp_CreateLogTarget)()
{
#if wxVERSION_NUMBER <= 2600
        return wxGetApp().CreateLogTarget();
#else
        wxAppTraits* appTraits = wxGetApp().GetTraits();
        return appTraits->CreateLogTarget();
#endif
}

/*
EWXWEXPORT(int,ELJApp_GetWantDebugOutput)()
{
        return (int)wxGetApp().GetWantDebugOutput();
}
*/

EWXWEXPORT(void,ELJApp_SetUseBestVisual)(bool flag)
{
        wxGetApp().SetUseBestVisual( flag);
}

EWXWEXPORT(int,ELJApp_GetUseBestVisual)()
{
        return (int)wxGetApp().GetUseBestVisual();
}

EWXWEXPORT(void,ELJApp_SetPrintMode)(int mode)
{
        wxGetApp().SetPrintMode(mode);
}

EWXWEXPORT(void,ELJApp_ExitMainLoop)()
{
        wxGetApp ().ExitMainLoop();
}

EWXWEXPORT(void,ELJApp_SetTopWindow)(wxWindow* _wnd)
{
        wxGetApp ().SetTopWindow (_wnd);
}
/*
EWXWEXPORT(int,ELJApp_SendIdleEvents)()
{
        return (int)wxGetApp().SendIdleEvents();
}

EWXWEXPORT(int,ELJApp_SendIdleEventsToWindow)(wxWindow* win)
{
        return (int)wxGetApp().SendIdleEvents( win);
}
*/
EWXWEXPORT(void,ELJApp_EnableTooltips)(bool _enable)
{
        wxToolTip::Enable (_enable);
}

EWXWEXPORT(void,ELJApp_SetTooltipDelay)(int _ms)
{
        wxToolTip::SetDelay (_ms);
}

EWXWEXPORT(void,ELJApp_InitAllImageHandlers)()
{
        wxInitAllImageHandlers();
}

EWXWEXPORT(void,ELJApp_Bell)()
{
        wxBell();
}

EWXWEXPORT(wxSize*,ELJApp_DisplaySize)()
{
  return new wxSize(wxGetDisplaySize());
}

EWXWEXPORT(void,ELJApp_EnableTopLevelWindows)(bool _enb)
{
        wxEnableTopLevelWindows(_enb);
}

EWXWEXPORT(void,ELJApp_Exit)()
{
        wxExit();
}

EWXWEXPORT(wxPoint*,ELJApp_MousePosition)()
{
  return new wxPoint(wxGetMousePosition());
}

EWXWEXPORT(void*,ELJApp_FindWindowByLabel)(wxString* _lbl,wxWindow* _prt)
{
        return (void*)wxFindWindowByLabel(*_lbl, _prt);
}

EWXWEXPORT(void*,ELJApp_FindWindowByName)(wxString* _lbl,wxWindow* _prt)
{
        return (void*)wxFindWindowByName(*_lbl, _prt);
}

EWXWEXPORT(void*,ELJApp_FindWindowById)(int _id,wxWindow* _prt)
{
        return (void*)wxWindow::FindWindowById((long)_id, _prt);
}


EWXWEXPORT(void*,ELJApp_GetApp)()
{
        return (void*)wxTheApp;
}

EWXWEXPORT(wxString*,ELJApp_GetUserId)()
{
  return new wxString(wxGetUserId());
}

EWXWEXPORT(wxString*,ELJApp_GetUserName)()
{
  return new wxString(wxGetUserName());
}

EWXWEXPORT(wxString*,ELJApp_GetUserHome)(wxString* _usr)
{
  return new wxString(wxGetUserHome(*_usr));
}

EWXWEXPORT(int,ELJApp_ExecuteProcess)(wxString* _cmd,bool _snc,void* _prc)
{
        return (int)wxExecute(*_cmd, _snc , (wxProcess*)_prc);
}

EWXWEXPORT(int,ELJApp_Yield)()
{
        return (int)wxYield();
}

EWXWEXPORT(int,ELJApp_SafeYield)(wxWindow* _win)
{
        return (int)wxSafeYield(_win);
}

EWXWEXPORT(int,ELJApp_GetOsVersion)(int* _maj,int* _min)
{
        return wxGetOsVersion(_maj, _min);
}

EWXWEXPORT(wxString*,ELJApp_GetOsDescription)()
{
  return new wxString(wxGetOsDescription());
}

EWXWEXPORT(void,ELJApp_Sleep)(int _scs)
{
        wxSleep(_scs);
}

EWXWEXPORT(void,ELJApp_MilliSleep)(int _mscs)
{
#if (wxVERSION_NUMBER < 2600)
        wxUsleep(_mscs);
#else
        wxMilliSleep(_mscs);
#endif
}

EWXWEXPORT(bool,ELJApp_IsTerminating)()
{
        return APPTerminating;
}

EWXWEXPORT(int,QuantizePalette)(wxImage* src,wxImage* dest,void* pPalette,int desiredNoColours,void* eightBitData,int flags)
{
#if defined(__WXGTK__) && (wxVERSION_NUMBER <= 2400)
    return 0;
#else
        return (int)wxQuantize::Quantize(*src,*dest, (wxPalette**)pPalette, desiredNoColours, (unsigned char**)eightBitData, flags);
#endif
}

EWXWEXPORT(int,Quantize)(wxImage* src,wxImage* dest,int desiredNoColours,void* eightBitData,int flags)
{
#if defined(__WXGTK__) && (wxVERSION_NUMBER <= 2400)
    return 0;
#else
        return (int)wxQuantize::Quantize(*src,*dest, desiredNoColours, (unsigned char**)eightBitData, flags);
#endif
}


EWXWEXPORT(void*,wxEvtHandler_Create)()
{
        return (void*)new wxEvtHandler();
}

EWXWEXPORT(void,wxEvtHandler_Delete)(wxEvtHandler* self)
{
        delete self;
}


EWXWEXPORT(int,wxEvtHandler_Disconnect)(wxEvtHandler* self,int first,int last,int type,wxObject* data)
{
        return (int)self->Disconnect(first, last, type, (wxObjectEventFunction)&ELJApp::HandleEvent, data);
}

EWXWEXPORT(void*,wxEvtHandler_GetNextHandler)(wxEvtHandler* self)
{
        return (void*)self->GetNextHandler();
}

EWXWEXPORT(void*,wxEvtHandler_GetPreviousHandler)(wxEvtHandler* self)
{
        return (void*)self->GetPreviousHandler();
}

EWXWEXPORT(void,wxEvtHandler_SetNextHandler)(wxEvtHandler* self,void* handler)
{
        self->SetNextHandler((wxEvtHandler*)handler);
}

EWXWEXPORT(void,wxEvtHandler_SetPreviousHandler)(wxEvtHandler* self,void* handler)
{
        self->SetPreviousHandler((wxEvtHandler*)handler);
}

EWXWEXPORT(void,wxEvtHandler_SetEvtHandlerEnabled)(wxEvtHandler* self,bool enabled)
{
        self->SetEvtHandlerEnabled(enabled);
}

EWXWEXPORT(int,wxEvtHandler_GetEvtHandlerEnabled)(wxEvtHandler* self)
{
        return (int)self->GetEvtHandlerEnabled();
}

EWXWEXPORT(int,wxEvtHandler_ProcessEvent)(wxEvtHandler* self,wxEvent* event)
{
        return (int)self->ProcessEvent(*event);
}

EWXWEXPORT(void,wxEvtHandler_AddPendingEvent)(wxEvtHandler* self,wxEvent* event)
{
        self->AddPendingEvent(*event);
}

EWXWEXPORT(void,wxEvtHandler_ProcessPendingEvents)(wxEvtHandler* self)
{
        self->ProcessPendingEvents();
}

EWXWEXPORT(void*,Null_AcceleratorTable)()
{
        return (void*)&wxNullAcceleratorTable;
}

EWXWEXPORT(void*,Null_Bitmap)()
{
        return (void*)&wxNullBitmap;
}

EWXWEXPORT(void*,Null_Icon)()
{
        return (void*)&wxNullIcon;
}

EWXWEXPORT(void*,Null_Cursor)()
{
        return (void*)&wxNullCursor;
}

EWXWEXPORT(void*,Null_Pen)()
{
        return (void*)&wxNullPen;
}

EWXWEXPORT(void*,Null_Brush)()
{
        return (void*)&wxNullBrush;
}

EWXWEXPORT(void*,Null_Palette)()
{
        return (void*)&wxNullPalette;
}

EWXWEXPORT(void*,Null_Font)()
{
        return (void*)&wxNullFont;
}

EWXWEXPORT(void*,Null_Colour)()
{
        return (void*)&wxNullColour;
}
/*
EWXWEXPORT(int,wxDllLoader_LoadLibrary)(void* _name,int* _success)
{
        bool success;

        wxDllType result = wxDllLoader::LoadLibrary ((const wxChar*)_name, &success);

        if (success)
                *_success = 1;
        else
                *_success = 0;

        return (int) result;
}

EWXWEXPORT(void,wxDllLoader_UnloadLibrary)(int _handle)
{
        wxDllLoader::UnloadLibrary ((wxDllType)_handle);
}

EWXWEXPORT(void*,wxDllLoader_GetSymbol)(int _handle,void* _name)
{
        return wxDllLoader::GetSymbol ((wxDllType)_handle, (const wxChar*)_name);
}
*/
EWXWEXPORT(void,wxCFree)(void* _ptr)
{
        free (_ptr);
}

EWXWEXPORT(void*,wxClassInfo_CreateClassByName)(wxString* _inf)
{
        wxClassInfo* inf = wxClassInfo::FindClass (*_inf);
        if (inf)
                return inf->CreateObject();
        return NULL;
}

EWXWEXPORT(void*,wxClassInfo_GetClassName)(wxObject* self)
{
        wxClassInfo* inf = self->GetClassInfo();
        if (inf)
                return (void*)inf->GetClassName();
        return NULL;
}

EWXWEXPORT(bool,wxClassInfo_IsKindOf)(wxObject* self,wxString* _name)
{
        wxClassInfo* inf = wxClassInfo::FindClass (*_name);
        if (inf)
                return self->IsKindOf(inf);
        return false;
}

EWXWEXPORT(int,wxEvent_NewEventType)()
{
        return (int)wxNewEventType();
}
}
