#include "wrapper.h"


#if defined(wxUSE_TAB_DIALOG) && (wxUSE_TAB_DIALOG==0)
# undef wxUSE_TAB_DIALOG
#endif


extern "C"
{

EWXWEXPORT(wxCommandEvent*,wxCommandEvent_Create)(int _typ,int _id)
{
        return new wxCommandEvent((wxEventType)_typ, _id);
}

EWXWEXPORT(void,wxCommandEvent_Delete)(wxCommandEvent* self)
{
        delete self;
}

EWXWEXPORT(int,wxEvent_GetTimestamp)(wxEvent* self)
{
        return self->GetTimestamp();
}

EWXWEXPORT(void,wxEvent_Skip)(wxEvent* self)
{
        self->Skip();
}

EWXWEXPORT(int,wxEvent_GetEventType)(wxEvent* self)
{
        return (int)self->GetEventType();
}

EWXWEXPORT(void,wxEvent_SetEventType)(wxEvent* self,int typ)
{
        self->SetEventType((wxEventType) typ);
}

EWXWEXPORT(void*,wxEvent_GetEventObject)(wxEvent* self)
{
        return (void*)self->GetEventObject();
}

EWXWEXPORT(void,wxEvent_SetEventObject)(wxEvent* self,wxObject* obj)
{
        self->SetEventObject(obj);
}

EWXWEXPORT(void,wxEvent_SetTimestamp)(wxEvent* self,int ts)
{
        self->SetTimestamp((long)ts);
}

EWXWEXPORT(int,wxEvent_GetId)(wxEvent* self)
{
        return self->GetId();
}

EWXWEXPORT(void,wxEvent_SetId)(wxEvent* self,int Id)
{
        self->SetId(Id);
}

EWXWEXPORT(bool,wxEvent_GetSkipped)(wxEvent* self)
{
        return self->GetSkipped();
}

EWXWEXPORT(bool,wxEvent_IsCommandEvent)(wxEvent* self)
{
        return self->IsCommandEvent();
}

EWXWEXPORT(void,wxEvent_CopyObject)(wxEvent* self,wxObject* object_dest)
{
#if wxVERSION_NUMBER < 2400
        self->CopyObject(*object_dest);
#endif
}

EWXWEXPORT(void,wxEvent_SetCallbackUserData)(wxEvent* self,wxObject* obj)
{
        self->m_callbackUserData = obj;
}

EWXWEXPORT(void*,wxEvent_GetCallbackUserData)(wxEvent* self)
{
        return (void*)self->m_callbackUserData;
}

EWXWEXPORT(void,wxCommandEvent_SetClientData)(wxCommandEvent* self,void* clientData)
{
        self->SetClientData(clientData);
}

EWXWEXPORT(void*,wxCommandEvent_GetClientData)(wxCommandEvent* self)
{
        return self->GetClientData();
}

EWXWEXPORT(void,wxCommandEvent_SetClientObject)(wxCommandEvent* self,void* clientObject)
{
        self->SetClientObject((wxClientData*)clientObject);
}

EWXWEXPORT(void*,wxCommandEvent_GetClientObject)(wxCommandEvent* self)
{
        return (void*)self->GetClientObject();
}

EWXWEXPORT(int,wxCommandEvent_GetSelection)(wxCommandEvent* self)
{
        return self->GetSelection();
}

EWXWEXPORT(void,wxCommandEvent_SetString)(wxCommandEvent* self,wxString* s)
{
        self->SetString(*s);
}

EWXWEXPORT(wxString*,wxCommandEvent_GetString)(wxCommandEvent* self)
{
  return new wxString(self->GetString());
}

EWXWEXPORT(bool,wxCommandEvent_IsChecked)(wxCommandEvent* self)
{
        return self->IsChecked();
}

EWXWEXPORT(bool,wxCommandEvent_IsSelection)(wxCommandEvent* self)
{
        return self->IsSelection();
}

EWXWEXPORT(void,wxCommandEvent_SetExtraLong)(wxCommandEvent* self,long extraLong)
{
        self->SetExtraLong(extraLong);
}

EWXWEXPORT(long,wxCommandEvent_GetExtraLong)(wxCommandEvent* self)
{
        return self->GetExtraLong();
}

EWXWEXPORT(void,wxCommandEvent_SetInt)(wxCommandEvent* self,int i)
{
        self->SetInt(i);
}

EWXWEXPORT(long,wxCommandEvent_GetInt)(wxCommandEvent* self)
{
        return self->GetInt();
}

EWXWEXPORT(void,wxCommandEvent_CopyObject)(wxCommandEvent* self,wxObject* object_dest)
{
#if wxVERSION_NUMBER < 2400
        self->CopyObject(*object_dest);
#endif
}

EWXWEXPORT(void,wxNotifyEvent_Veto)(void* self)
{
        ((wxNotifyEvent*)self)->Veto();
}

EWXWEXPORT(void,wxNotifyEvent_Allow)(void* self)
{
        ((wxNotifyEvent*)self)->Allow();
}

EWXWEXPORT(bool,wxNotifyEvent_IsAllowed)(wxNotifyEvent* self)
{
        return self->IsAllowed();
}

EWXWEXPORT(void,wxNotifyEvent_CopyObject)(void* self,wxObject* object_dest)
{
#if wxVERSION_NUMBER < 2400
        ((wxNotifyEvent*)self)->CopyObject(*object_dest);
#endif
}

EWXWEXPORT(int,wxScrollWinEvent_GetOrientation)(void* self)
{
        return ((wxScrollWinEvent*)self)->GetOrientation();
}

EWXWEXPORT(int,wxScrollWinEvent_GetPosition)(void* self)
{
        return ((wxScrollWinEvent*)self)->GetPosition();
}

EWXWEXPORT(void,wxScrollWinEvent_SetOrientation)(void* self,int orient)
{
        ((wxScrollWinEvent*)self)->SetOrientation(orient);
}

EWXWEXPORT(void,wxScrollWinEvent_SetPosition)(void* self,int pos)
{
        ((wxScrollWinEvent*)self)->SetPosition(pos);
}

EWXWEXPORT(bool,wxMouseEvent_IsButton)(wxMouseEvent* self)
{
        return self->IsButton();
}

EWXWEXPORT(bool,wxMouseEvent_ButtonDown)(wxMouseEvent* self,int but)
{
        return self->ButtonDown(but);
}

EWXWEXPORT(bool,wxMouseEvent_ButtonDClick)(wxMouseEvent* self,int but)
{
        return self->ButtonDClick(but);
}

EWXWEXPORT(bool,wxMouseEvent_ButtonUp)(wxMouseEvent* self,int but)
{
        return self->ButtonUp(but);
}

EWXWEXPORT(bool,wxMouseEvent_Button)(wxMouseEvent* self,int but)
{
        return self->Button(but);
}

EWXWEXPORT(bool,wxMouseEvent_ButtonIsDown)(wxMouseEvent* self,int but)
{
        return self->ButtonIsDown(but);
}

EWXWEXPORT(bool,wxMouseEvent_ControlDown)(wxMouseEvent* self)
{
        return self->ControlDown();
}

EWXWEXPORT(bool,wxMouseEvent_MetaDown)(wxMouseEvent* self)
{
        return self->MetaDown();
}

EWXWEXPORT(bool,wxMouseEvent_AltDown)(wxMouseEvent* self)
{
        return self->AltDown();
}

EWXWEXPORT(bool,wxMouseEvent_ShiftDown)(wxMouseEvent* self)
{
        return self->ShiftDown();
}

EWXWEXPORT(bool,wxMouseEvent_LeftDown)(wxMouseEvent* self)
{
        return self->LeftDown();
}

EWXWEXPORT(bool,wxMouseEvent_MiddleDown)(wxMouseEvent* self)
{
        return self->MiddleDown();
}

EWXWEXPORT(bool,wxMouseEvent_RightDown)(wxMouseEvent* self)
{
        return self->RightDown();
}

EWXWEXPORT(bool,wxMouseEvent_LeftUp)(wxMouseEvent* self)
{
        return self->LeftUp();
}

EWXWEXPORT(bool,wxMouseEvent_MiddleUp)(wxMouseEvent* self)
{
        return self->MiddleUp();
}

EWXWEXPORT(bool,wxMouseEvent_RightUp)(wxMouseEvent* self)
{
        return self->RightUp();
}

EWXWEXPORT(bool,wxMouseEvent_LeftDClick)(wxMouseEvent* self)
{
        return self->LeftDClick();
}

EWXWEXPORT(bool,wxMouseEvent_MiddleDClick)(wxMouseEvent* self)
{
        return self->MiddleDClick();
}

EWXWEXPORT(bool,wxMouseEvent_RightDClick)(wxMouseEvent* self)
{
        return self->RightDClick();
}

EWXWEXPORT(bool,wxMouseEvent_LeftIsDown)(wxMouseEvent* self)
{
        return self->LeftIsDown();
}

EWXWEXPORT(bool,wxMouseEvent_MiddleIsDown)(wxMouseEvent* self)
{
        return self->MiddleIsDown();
}

EWXWEXPORT(bool,wxMouseEvent_RightIsDown)(wxMouseEvent* self)
{
        return self->RightIsDown();
}

EWXWEXPORT(bool,wxMouseEvent_Dragging)(wxMouseEvent* self)
{
        return self->Dragging();
}

EWXWEXPORT(bool,wxMouseEvent_Moving)(wxMouseEvent* self)
{
        return self->Moving();
}

EWXWEXPORT(bool,wxMouseEvent_Entering)(wxMouseEvent* self)
{
        return self->Entering();
}

EWXWEXPORT(bool,wxMouseEvent_Leaving)(wxMouseEvent* self)
{
        return self->Leaving();
}

EWXWEXPORT(wxPoint*,wxMouseEvent_GetPosition)(wxMouseEvent* self)
{
  return new wxPoint(self->GetPosition());
}

EWXWEXPORT(wxPoint*,wxMouseEvent_GetLogicalPosition)(wxMouseEvent* self,wxDC* dc)
{
  return new wxPoint(self->GetLogicalPosition(*dc));
}

EWXWEXPORT(int,wxMouseEvent_GetX)(wxMouseEvent* self)
{
        return self->GetX();
}

EWXWEXPORT(int,wxMouseEvent_GetY)(wxMouseEvent* self)
{
        return self->GetY();
}

EWXWEXPORT(void,wxMouseEvent_CopyObject)(wxMouseEvent* self,wxObject* object_dest)
{
#if wxVERSION_NUMBER < 2400
        self->CopyObject(*object_dest);
#endif
}

EWXWEXPORT(wxCoord,wxSetCursorEvent_GetX)(void* self)
{
        return ((wxSetCursorEvent*)self)->GetX();
}

EWXWEXPORT(wxCoord,wxSetCursorEvent_GetY)(void* self)
{
        return ((wxSetCursorEvent*)self)->GetY();
}

EWXWEXPORT(void,wxSetCursorEvent_SetCursor)(void* self,void* cursor)
{
        ((wxSetCursorEvent*)self)->SetCursor(*((wxCursor*)cursor));
}

EWXWEXPORT(void*,wxSetCursorEvent_GetCursor)(void* self)
{
        return (void*)(&((wxSetCursorEvent*)self)->GetCursor());
}

EWXWEXPORT(bool,wxSetCursorEvent_HasCursor)(wxSetCursorEvent* self)
{
        return self->HasCursor();
}

EWXWEXPORT(bool,wxKeyEvent_ControlDown)(wxKeyEvent* self)
{
        return self->ControlDown();
}

EWXWEXPORT(bool,wxKeyEvent_MetaDown)(wxKeyEvent* self)
{
        return self->MetaDown();
}

EWXWEXPORT(bool,wxKeyEvent_AltDown)(wxKeyEvent* self)
{
        return self->AltDown();
}

EWXWEXPORT(bool,wxKeyEvent_ShiftDown)(wxKeyEvent* self)
{
        return self->ShiftDown();
}

EWXWEXPORT(bool,wxKeyEvent_HasModifiers)(wxKeyEvent* self)
{
        return self->HasModifiers();
}

EWXWEXPORT(int,wxKeyEvent_GetKeyCode)(wxKeyEvent* self)
{
        return self->GetKeyCode();
}

EWXWEXPORT(int,wxKeyEvent_GetModifiers)(wxKeyEvent* self)
{
        return self->GetModifiers();
}

EWXWEXPORT(void,wxKeyEvent_SetKeyCode)(wxKeyEvent* self,int code)
{
        self->m_keyCode = code;
}

EWXWEXPORT(wxPoint*,wxKeyEvent_GetPosition)(wxKeyEvent* self)
{
  return new wxPoint(self->GetPosition());
}

EWXWEXPORT(wxUint32,wxKeyEvent_GetRawKeyCode)(wxKeyEvent* self)
{
        return self->GetRawKeyCode();
}

EWXWEXPORT(wxUint32,wxKeyEvent_GetRawKeyFlags)(wxKeyEvent* self)
{
        return self->GetRawKeyFlags();
}

EWXWEXPORT(wxCoord,wxKeyEvent_GetX)(wxKeyEvent* self)
{
        return self->GetX();
}

EWXWEXPORT(wxCoord,wxKeyEvent_GetY)(wxKeyEvent* self)
{
        return self->GetY();
}

EWXWEXPORT(void,wxKeyEvent_CopyObject)(wxKeyEvent* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        self->CopyObject(*obj);
#endif
}

EWXWEXPORT(wxSize*,wxSizeEvent_GetSize)(void* self)
{
  return new wxSize(((wxSizeEvent*)self)->GetSize());
}

EWXWEXPORT(void,wxSizeEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxSizeEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(wxPoint*,wxMoveEvent_GetPosition)(void* self)
{
  return new wxPoint (((wxMoveEvent*)self)->GetPosition());
}

EWXWEXPORT(void,wxMoveEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxMoveEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(void*,wxEraseEvent_GetDC)(void* self)
{
        return (void*)((wxEraseEvent*)self)->GetDC();
}

EWXWEXPORT(void,wxEraseEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxEraseEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(bool,wxActivateEvent_GetActive)(wxActivateEvent* self)
{
        return self->GetActive();
}

EWXWEXPORT(void,wxActivateEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxActivateEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(int,wxMenuEvent_GetMenuId)(void* self)
{
        return ((wxMenuEvent*)self)->GetMenuId();
}

EWXWEXPORT(void,wxMenuEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxMenuEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(void,wxCloseEvent_SetLoggingOff)(void* self,bool logOff)
{
        ((wxCloseEvent*)self)->SetLoggingOff(logOff);
}

EWXWEXPORT(bool,wxCloseEvent_GetLoggingOff)(wxCloseEvent* self)
{
        return self->GetLoggingOff();
}

EWXWEXPORT(void,wxCloseEvent_Veto)(void* self,bool veto)
{
        ((wxCloseEvent*)self)->Veto(veto);
}

EWXWEXPORT(void,wxCloseEvent_SetCanVeto)(void* self,bool canVeto)
{
        ((wxCloseEvent*)self)->SetCanVeto(canVeto);
}

EWXWEXPORT(bool,wxCloseEvent_CanVeto)(wxCloseEvent* self)
{
        return self->CanVeto();
}

EWXWEXPORT(bool,wxCloseEvent_GetVeto)(wxCloseEvent* self)
{
        return self->GetVeto();
}

EWXWEXPORT(void,wxCloseEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxCloseEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(void,wxShowEvent_SetShow)(void* self,bool show)
{
        ((wxShowEvent*)self)->SetShow(show);
}

EWXWEXPORT(bool,wxShowEvent_GetShow)(wxShowEvent* self)
{
        return self->GetShow();
}

EWXWEXPORT(void,wxShowEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxShowEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(wxPoint*,wxJoystickEvent_GetPosition)(wxJoystickEvent* self)
{
  return new wxPoint(self->GetPosition());
}

EWXWEXPORT(int,wxJoystickEvent_GetZPosition)(wxJoystickEvent* self)
{
        return self->GetZPosition();
}

EWXWEXPORT(int,wxJoystickEvent_GetButtonState)(wxJoystickEvent* self)
{
        return self->GetButtonState();
}

EWXWEXPORT(int,wxJoystickEvent_GetButtonChange)(wxJoystickEvent* self)
{
        return self->GetButtonChange();
}

EWXWEXPORT(int,wxJoystickEvent_GetJoystick)(wxJoystickEvent* self)
{
        return self->GetJoystick();
}

EWXWEXPORT(void,wxJoystickEvent_SetJoystick)(wxJoystickEvent* self,int stick)
{
        self->SetJoystick(stick);
}

EWXWEXPORT(void,wxJoystickEvent_SetButtonState)(wxJoystickEvent* self,int state)
{
        self->SetButtonState(state);
}

EWXWEXPORT(void,wxJoystickEvent_SetButtonChange)(wxJoystickEvent* self,int change)
{
        self->SetButtonChange(change);
}

EWXWEXPORT(void,wxJoystickEvent_SetPosition)(wxJoystickEvent* self,void* pos)
{
        self->SetPosition(*((wxPoint*)pos));
}

EWXWEXPORT(void,wxJoystickEvent_SetZPosition)(wxJoystickEvent* self,int zPos)
{
        self->SetZPosition(zPos);
}

EWXWEXPORT(bool,wxJoystickEvent_IsButton)(wxJoystickEvent* self)
{
        return self->IsButton();
}

EWXWEXPORT(bool,wxJoystickEvent_IsMove)(wxJoystickEvent* self)
{
        return self->IsMove();
}

EWXWEXPORT(bool,wxJoystickEvent_IsZMove)(wxJoystickEvent* self)
{
        return self->IsZMove();
}

EWXWEXPORT(bool,wxJoystickEvent_ButtonDown)(wxJoystickEvent* self,int but)
{
        return self->ButtonDown(but);
}

EWXWEXPORT(bool,wxJoystickEvent_ButtonUp)(wxJoystickEvent* self,int but)
{
        return self->ButtonUp(but);
}

EWXWEXPORT(bool,wxJoystickEvent_ButtonIsDown)(wxJoystickEvent* self,int but)
{
        return self->ButtonIsDown(but);
}

EWXWEXPORT(void,wxJoystickEvent_CopyObject)(wxJoystickEvent* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        self->CopyObject(*obj);
#endif
}

EWXWEXPORT(bool,wxUpdateUIEvent_GetChecked)(wxUpdateUIEvent* self)
{
        return self->GetChecked();
}

EWXWEXPORT(bool,wxUpdateUIEvent_GetEnabled)(wxUpdateUIEvent* self)
{
        return self->GetEnabled();
}

EWXWEXPORT(wxString*,wxUpdateUIEvent_GetText)(void* self)
{
  return new wxString(((wxUpdateUIEvent*)self)->GetText());
}

EWXWEXPORT(bool,wxUpdateUIEvent_GetSetText)(wxUpdateUIEvent* self)
{
        return self->GetSetText();
}

EWXWEXPORT(bool,wxUpdateUIEvent_GetSetChecked)(wxUpdateUIEvent* self)
{
        return self->GetSetChecked();
}

EWXWEXPORT(bool,wxUpdateUIEvent_GetSetEnabled)(wxUpdateUIEvent* self)
{
        return self->GetSetEnabled();
}

EWXWEXPORT(void,wxUpdateUIEvent_Check)(void* self,bool check)
{
        ((wxUpdateUIEvent*)self)->Check(check);
}

EWXWEXPORT(void,wxUpdateUIEvent_Enable)(void* self,bool enable)
{
        ((wxUpdateUIEvent*)self)->Enable(enable);
}

EWXWEXPORT(void,wxUpdateUIEvent_SetText)(void* self,wxString* text)
{
        ((wxUpdateUIEvent*)self)->SetText(*text);
}

EWXWEXPORT(void,wxUpdateUIEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxUpdateUIEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(void,wxPaletteChangedEvent_SetChangedWindow)(void* self,wxWindow* win)
{
        ((wxPaletteChangedEvent*)self)->SetChangedWindow(win);
}

EWXWEXPORT(void*,wxPaletteChangedEvent_GetChangedWindow)(void* self)
{
        return (void*)((wxPaletteChangedEvent*)self)->GetChangedWindow();
}

EWXWEXPORT(void,wxPaletteChangedEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxPaletteChangedEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(void,wxQueryNewPaletteEvent_SetPaletteRealized)(void* self,bool realized)
{
        ((wxQueryNewPaletteEvent*)self)->SetPaletteRealized(realized);
}

EWXWEXPORT(bool,wxQueryNewPaletteEvent_GetPaletteRealized)(void* self)
{
        return ((wxQueryNewPaletteEvent*)self)->GetPaletteRealized();
}

EWXWEXPORT(void,wxQueryNewPaletteEvent_CopyObject)(void* self,wxObject* obj)
{
#if wxVERSION_NUMBER < 2400
        ((wxQueryNewPaletteEvent*)self)->CopyObject(*obj);
#endif
}

EWXWEXPORT(bool,wxNavigationKeyEvent_GetDirection)(void* self)
{
        return ((wxNavigationKeyEvent*)self)->GetDirection();
}

EWXWEXPORT(void,wxNavigationKeyEvent_SetDirection)(void* self,bool bForward)
{
        ((wxNavigationKeyEvent*)self)->SetDirection(bForward);
}

EWXWEXPORT(bool,wxNavigationKeyEvent_IsWindowChange)(wxNavigationKeyEvent* self)
{
        return self->IsWindowChange();
}

EWXWEXPORT(void,wxNavigationKeyEvent_SetWindowChange)(void* self,bool bIs)
{
        ((wxNavigationKeyEvent*)self)->SetWindowChange(bIs);
}

EWXWEXPORT(bool,wxNavigationKeyEvent_ShouldPropagate)(void* self)
{
        return ((wxNavigationKeyEvent*)self)->ShouldPropagate();
}
	
EWXWEXPORT(void*,wxNavigationKeyEvent_GetCurrentFocus)(void* self)
{
        return (void*)((wxNavigationKeyEvent*)self)->GetCurrentFocus();
}

EWXWEXPORT(void,wxNavigationKeyEvent_SetCurrentFocus)(void* self,wxWindow* win)
{
        ((wxNavigationKeyEvent*)self)->SetCurrentFocus(win);
}

EWXWEXPORT(void*,wxWindowCreateEvent_GetWindow)(void* self)
{
        return (void*)((wxWindowCreateEvent*)self)->GetWindow();
}

EWXWEXPORT(void*,wxWindowDestroyEvent_GetWindow)(void* self)
{
        return (void*)((wxWindowDestroyEvent*)self)->GetWindow();
}

EWXWEXPORT(void,wxIdleEvent_RequestMore)(void* self,bool needMore)
{
        ((wxIdleEvent*)self)->RequestMore(needMore);
}

EWXWEXPORT(bool,wxIdleEvent_MoreRequested)(wxIdleEvent* self)
{
        return self->MoreRequested();
}

EWXWEXPORT(void,wxIdleEvent_CopyObject)(void* self,wxObject* object_dest)
{
#if wxVERSION_NUMBER < 2400
        ((wxIdleEvent*)self)->CopyObject(*object_dest);
#endif
}

EWXWEXPORT(int,wxListEvent_GetCode)(void* self)
{
#if wxCHECK_VERSION(2,5,0)
	return ((wxListEvent*)self)->GetKeyCode();
#else
        return ((wxListEvent*)self)->GetCode();
#endif
}

EWXWEXPORT(long,wxListEvent_GetIndex)(void* self)
{
        return ((wxListEvent*)self)->GetIndex();
}
EWXWEXPORT(int,wxListEvent_GetColumn)(void* self)
{
        return ((wxListEvent*)self)->GetColumn();
}

EWXWEXPORT(int,wxListEvent_Cancelled)(void* self)
{
#if wxVERSION_NUMBER < 2400
        return (int)((wxListEvent*)self)->Cancelled();
#else
        return 0;
#endif
}

EWXWEXPORT(wxPoint*,wxListEvent_GetPoint)(void* self)
{
  return new wxPoint(((wxListEvent*)self)->GetPoint());
}

EWXWEXPORT(wxString*,wxListEvent_GetLabel)(void* self)
{
  return new wxString(((wxListEvent*)self)->GetLabel());
}

EWXWEXPORT(wxString*,wxListEvent_GetText)(void* self)
{
  return new wxString(((wxListEvent*)self)->GetText());
}

EWXWEXPORT(int,wxListEvent_GetImage)(void* self)
{
        return ((wxListEvent*)self)->GetImage();
}

EWXWEXPORT(long,wxListEvent_GetData)(void* self)
{
        return ((wxListEvent*)self)->GetData();
}

EWXWEXPORT(long,wxListEvent_GetMask)(void* self)
{
        return ((wxListEvent*)self)->GetMask();
}

EWXWEXPORT(void,wxListEvent_GetItem)(void* self,void* _ref)
{
#if wxVERSION_NUMBER < 2400
        *((wxListItem*)_ref) = ((wxListEvent*)self)->GetItem();
#else
        wxListItem* ret = new wxListItem(((wxListEvent*)self)->GetItem());
        *((void**)_ref) = (void*)ret;
#endif
}

EWXWEXPORT(void,wxTreeEvent_GetItem)(void* self,wxTreeItemId* _ref)
{
        *_ref = ((wxTreeEvent*)self)->GetItem();
}

EWXWEXPORT(void,wxTreeEvent_GetOldItem)(void* self,wxTreeItemId* _ref)
{
        *_ref = ((wxTreeEvent*)self)->GetOldItem();
}

EWXWEXPORT(wxPoint*,wxTreeEvent_GetPoint)(void* self)
{
  return new wxPoint (((wxTreeEvent*)self)->GetPoint());
}

EWXWEXPORT(int,wxTreeEvent_GetCode)(void* self)
{
        return ((wxTreeEvent*)self)->GetKeyCode();
}

EWXWEXPORT(wxString*,wxTreeEvent_GetLabel)(void* self)
{
  return new wxString(((wxTreeEvent*)self)->GetLabel());
}

EWXWEXPORT(int,wxSpinEvent_GetPosition)(void* self)
{
        return ((wxSpinEvent*)self)->GetPosition();
}

EWXWEXPORT(void,wxSpinEvent_SetPosition)(void* self,int pos)
{
        ((wxSpinEvent*)self)->SetPosition(pos);
}

EWXWEXPORT(int,wxTimerEvent_GetInterval)(void* self)
{
        return ((wxTimerEvent*)self)->GetInterval();
}

EWXWEXPORT(int,wxCalendarEvent_GetWeekDay)(void* self)
{
        return ((wxCalendarEvent*)self)->GetWeekDay();
}

EWXWEXPORT(void,wxCalendarEvent_GetDate)(void* self,wxDateTime* _dte)
{
        *_dte = ((wxCalendarEvent*)self)->GetDate();
}


EWXWEXPORT(int,wxScrollEvent_GetOrientation)(void* self)
{
        return ((wxScrollEvent*)self)->GetOrientation();
}

EWXWEXPORT(int,wxScrollEvent_GetPosition)(void* self)
{
        return ((wxScrollEvent*)self)->GetPosition();
}

EWXWEXPORT(wxPoint*,wxHelpEvent_GetPosition)(void* self)
{
  return new wxPoint(((wxHelpEvent*)self)->GetPosition());
}

EWXWEXPORT(void,wxHelpEvent_SetPosition)(void* self,int x,int y)
{
        ((wxHelpEvent*)self)->SetPosition(wxPoint(x, y));
}

EWXWEXPORT(wxString*,wxHelpEvent_GetLink)(void* self)
{
  return new wxString(((wxHelpEvent*)self)->GetLink());
}

EWXWEXPORT(void,wxHelpEvent_SetLink)(void* self,wxString* link)
{
        ((wxHelpEvent*)self)->SetLink(*link);
}

EWXWEXPORT(wxString*,wxHelpEvent_GetTarget)(void* self)
{
  return new wxString(((wxHelpEvent*)self)->GetTarget());
}

EWXWEXPORT(void,wxHelpEvent_SetTarget)(void* self,wxString* target)
{
        ((wxHelpEvent*)self)->SetTarget(*target);
}

EWXWCONSTANTINT(EVT_COMMAND_BUTTON_CLICKED,wxEVT_COMMAND_BUTTON_CLICKED)
EWXWCONSTANTINT(EVT_COMMAND_CHECKBOX_CLICKED,wxEVT_COMMAND_CHECKBOX_CLICKED)
EWXWCONSTANTINT(EVT_COMMAND_CHOICE_SELECTED,wxEVT_COMMAND_CHOICE_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_LISTBOX_SELECTED,wxEVT_COMMAND_LISTBOX_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_LISTBOX_DOUBLECLICKED,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED)
EWXWCONSTANTINT(EVT_COMMAND_CHECKLISTBOX_TOGGLED,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED)
EWXWCONSTANTINT(EVT_COMMAND_TEXT_UPDATED,wxEVT_COMMAND_TEXT_UPDATED)
EWXWCONSTANTINT(EVT_COMMAND_TEXT_ENTER,wxEVT_COMMAND_TEXT_ENTER)
EWXWCONSTANTINT(EVT_COMMAND_MENU_SELECTED,wxEVT_COMMAND_MENU_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_TOOL_CLICKED,wxEVT_COMMAND_TOOL_CLICKED)
EWXWCONSTANTINT(EVT_COMMAND_SLIDER_UPDATED,wxEVT_COMMAND_SLIDER_UPDATED)
EWXWCONSTANTINT(EVT_COMMAND_RADIOBOX_SELECTED,wxEVT_COMMAND_RADIOBOX_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_RADIOBUTTON_SELECTED,wxEVT_COMMAND_RADIOBUTTON_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_SCROLLBAR_UPDATED,wxEVT_COMMAND_SCROLLBAR_UPDATED)
EWXWCONSTANTINT(EVT_COMMAND_VLBOX_SELECTED,wxEVT_COMMAND_VLBOX_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_COMBOBOX_SELECTED,wxEVT_COMMAND_COMBOBOX_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_TOOL_RCLICKED,wxEVT_COMMAND_TOOL_RCLICKED)
EWXWCONSTANTINT(EVT_COMMAND_TOOL_ENTER,wxEVT_COMMAND_TOOL_ENTER)
EWXWCONSTANTINT(EVT_COMMAND_SPINCTRL_UPDATED,wxEVT_COMMAND_SPINCTRL_UPDATED)
EWXWCONSTANTINT(EVT_SOCKET,wxEVT_SOCKET)
EWXWCONSTANTINT(EVT_TIMER,wxEVT_TIMER)
EWXWCONSTANTINT(EVT_LEFT_DOWN,wxEVT_LEFT_DOWN)
EWXWCONSTANTINT(EVT_LEFT_UP,wxEVT_LEFT_UP)
EWXWCONSTANTINT(EVT_MIDDLE_DOWN,wxEVT_MIDDLE_DOWN)
EWXWCONSTANTINT(EVT_MIDDLE_UP,wxEVT_MIDDLE_UP)
EWXWCONSTANTINT(EVT_RIGHT_DOWN,wxEVT_RIGHT_DOWN)
EWXWCONSTANTINT(EVT_RIGHT_UP,wxEVT_RIGHT_UP)
EWXWCONSTANTINT(EVT_MOTION,wxEVT_MOTION)
EWXWCONSTANTINT(EVT_ENTER_WINDOW,wxEVT_ENTER_WINDOW)
EWXWCONSTANTINT(EVT_LEAVE_WINDOW,wxEVT_LEAVE_WINDOW)
EWXWCONSTANTINT(EVT_LEFT_DCLICK,wxEVT_LEFT_DCLICK)
EWXWCONSTANTINT(EVT_MIDDLE_DCLICK,wxEVT_MIDDLE_DCLICK)
EWXWCONSTANTINT(EVT_RIGHT_DCLICK,wxEVT_RIGHT_DCLICK)
EWXWCONSTANTINT(EVT_SET_FOCUS,wxEVT_SET_FOCUS)
EWXWCONSTANTINT(EVT_KILL_FOCUS,wxEVT_KILL_FOCUS)
EWXWCONSTANTINT(EVT_NC_LEFT_DOWN,wxEVT_NC_LEFT_DOWN)
EWXWCONSTANTINT(EVT_NC_LEFT_UP,wxEVT_NC_LEFT_UP)
EWXWCONSTANTINT(EVT_NC_MIDDLE_DOWN,wxEVT_NC_MIDDLE_DOWN)
EWXWCONSTANTINT(EVT_NC_MIDDLE_UP,wxEVT_NC_MIDDLE_UP)
EWXWCONSTANTINT(EVT_NC_RIGHT_DOWN,wxEVT_NC_RIGHT_DOWN)
EWXWCONSTANTINT(EVT_NC_RIGHT_UP,wxEVT_NC_RIGHT_UP)
EWXWCONSTANTINT(EVT_NC_MOTION,wxEVT_NC_MOTION)
EWXWCONSTANTINT(EVT_NC_ENTER_WINDOW,wxEVT_NC_ENTER_WINDOW)
EWXWCONSTANTINT(EVT_NC_LEAVE_WINDOW,wxEVT_NC_LEAVE_WINDOW)
EWXWCONSTANTINT(EVT_NC_LEFT_DCLICK,wxEVT_NC_LEFT_DCLICK)
EWXWCONSTANTINT(EVT_NC_MIDDLE_DCLICK,wxEVT_NC_MIDDLE_DCLICK)
EWXWCONSTANTINT(EVT_NC_RIGHT_DCLICK,wxEVT_NC_RIGHT_DCLICK)
EWXWCONSTANTINT(EVT_CHAR,wxEVT_CHAR)
EWXWCONSTANTINT(EVT_CHAR_HOOK,wxEVT_CHAR_HOOK)
EWXWCONSTANTINT(EVT_NAVIGATION_KEY,wxEVT_NAVIGATION_KEY)
EWXWCONSTANTINT(EVT_KEY_DOWN,wxEVT_KEY_DOWN)
EWXWCONSTANTINT(EVT_KEY_UP,wxEVT_KEY_UP)
EWXWCONSTANTINT(EVT_SET_CURSOR,wxEVT_SET_CURSOR)
EWXWCONSTANTINT(EVT_SCROLL_TOP,wxEVT_SCROLL_TOP)
EWXWCONSTANTINT(EVT_SCROLL_BOTTOM,wxEVT_SCROLL_BOTTOM)
EWXWCONSTANTINT(EVT_SCROLL_LINEUP,wxEVT_SCROLL_LINEUP)
EWXWCONSTANTINT(EVT_SCROLL_LINEDOWN,wxEVT_SCROLL_LINEDOWN)
EWXWCONSTANTINT(EVT_SCROLL_PAGEUP,wxEVT_SCROLL_PAGEUP)
EWXWCONSTANTINT(EVT_SCROLL_PAGEDOWN,wxEVT_SCROLL_PAGEDOWN)
EWXWCONSTANTINT(EVT_SCROLL_THUMBTRACK,wxEVT_SCROLL_THUMBTRACK)
EWXWCONSTANTINT(EVT_SCROLL_THUMBRELEASE,wxEVT_SCROLL_THUMBRELEASE)
EWXWCONSTANTINT(EVT_SCROLLWIN_TOP,wxEVT_SCROLLWIN_TOP)
EWXWCONSTANTINT(EVT_SCROLLWIN_BOTTOM,wxEVT_SCROLLWIN_BOTTOM)
EWXWCONSTANTINT(EVT_SCROLLWIN_LINEUP,wxEVT_SCROLLWIN_LINEUP)
EWXWCONSTANTINT(EVT_SCROLLWIN_LINEDOWN,wxEVT_SCROLLWIN_LINEDOWN)
EWXWCONSTANTINT(EVT_SCROLLWIN_PAGEUP,wxEVT_SCROLLWIN_PAGEUP)
EWXWCONSTANTINT(EVT_SCROLLWIN_PAGEDOWN,wxEVT_SCROLLWIN_PAGEDOWN)
EWXWCONSTANTINT(EVT_SCROLLWIN_THUMBTRACK,wxEVT_SCROLLWIN_THUMBTRACK)
EWXWCONSTANTINT(EVT_SCROLLWIN_THUMBRELEASE,wxEVT_SCROLLWIN_THUMBRELEASE)
EWXWCONSTANTINT(EVT_SIZE,wxEVT_SIZE)
EWXWCONSTANTINT(EVT_MOVE,wxEVT_MOVE)
EWXWCONSTANTINT(EVT_CLOSE_WINDOW,wxEVT_CLOSE_WINDOW)
EWXWCONSTANTINT(EVT_END_SESSION,wxEVT_END_SESSION)
EWXWCONSTANTINT(EVT_QUERY_END_SESSION,wxEVT_QUERY_END_SESSION)
EWXWCONSTANTINT(EVT_ACTIVATE_APP,wxEVT_ACTIVATE_APP)


#ifdef wxHAS_POWER_EVENTS
#if (wxVERSION_NUMBER <= 2800)
EWXWCONSTANTINT(EVT_POWER,wxEVT_POWER)
#endif
EWXWCONSTANTINT(EVT_POWER_SUSPENDING,wxEVT_POWER_SUSPENDING)
EWXWCONSTANTINT(EVT_POWER_SUSPENDED,wxEVT_POWER_SUSPENDED)
EWXWCONSTANTINT(EVT_POWER_SUSPEND_CANCEL,wxEVT_POWER_SUSPEND_CANCEL)
EWXWCONSTANTINT(EVT_POWER_RESUME,wxEVT_POWER_RESUME)

#endif //wxHAS_POWER_EVENTS

EWXWCONSTANTINT(EVT_ACTIVATE,wxEVT_ACTIVATE)
EWXWCONSTANTINT(EVT_CREATE,wxEVT_CREATE)
EWXWCONSTANTINT(EVT_DESTROY,wxEVT_DESTROY)
EWXWCONSTANTINT(EVT_SHOW,wxEVT_SHOW)
EWXWCONSTANTINT(EVT_ICONIZE,wxEVT_ICONIZE)
EWXWCONSTANTINT(EVT_MAXIMIZE,wxEVT_MAXIMIZE)
EWXWCONSTANTINT(EVT_MOUSE_CAPTURE_CHANGED,wxEVT_MOUSE_CAPTURE_CHANGED)
EWXWCONSTANTINT(EVT_PAINT,wxEVT_PAINT)
EWXWCONSTANTINT(EVT_ERASE_BACKGROUND,wxEVT_ERASE_BACKGROUND)
EWXWCONSTANTINT(EVT_NC_PAINT,wxEVT_NC_PAINT)
EWXWCONSTANTINT(EVT_PAINT_ICON,wxEVT_PAINT_ICON)

//???
EWXWCONSTANTINT(EVT_MENU_CHAR,-1)
EWXWCONSTANTINT(EVT_MENU_INIT,-1)
EWXWCONSTANTINT(EVT_MENU_HIGHLIGHT,wxEVT_MENU_HIGHLIGHT)
//???
EWXWCONSTANTINT(EVT_POPUP_MENU_INIT,-1)

EWXWCONSTANTINT(EVT_CONTEXT_MENU,wxEVT_CONTEXT_MENU)
EWXWCONSTANTINT(EVT_SYS_COLOUR_CHANGED,wxEVT_SYS_COLOUR_CHANGED)
EWXWCONSTANTINT(EVT_SETTING_CHANGED,wxEVT_SETTING_CHANGED)
EWXWCONSTANTINT(EVT_QUERY_NEW_PALETTE,wxEVT_QUERY_NEW_PALETTE)
EWXWCONSTANTINT(EVT_PALETTE_CHANGED,wxEVT_PALETTE_CHANGED)
EWXWCONSTANTINT(EVT_JOY_BUTTON_DOWN,wxEVT_JOY_BUTTON_DOWN)
EWXWCONSTANTINT(EVT_JOY_BUTTON_UP,wxEVT_JOY_BUTTON_UP)
EWXWCONSTANTINT(EVT_JOY_MOVE,wxEVT_JOY_MOVE)
EWXWCONSTANTINT(EVT_JOY_ZMOVE,wxEVT_JOY_ZMOVE)
EWXWCONSTANTINT(EVT_DROP_FILES,wxEVT_DROP_FILES)
EWXWCONSTANTINT(EVT_DRAW_ITEM,wxEVT_DRAW_ITEM)
EWXWCONSTANTINT(EVT_MEASURE_ITEM,wxEVT_MEASURE_ITEM)
EWXWCONSTANTINT(EVT_COMPARE_ITEM,wxEVT_COMPARE_ITEM)
EWXWCONSTANTINT(EVT_INIT_DIALOG,wxEVT_INIT_DIALOG)
EWXWCONSTANTINT(EVT_IDLE,wxEVT_IDLE)
EWXWCONSTANTINT(EVT_UPDATE_UI,wxEVT_UPDATE_UI)
EWXWCONSTANTINT(EVT_END_PROCESS,wxEVT_END_PROCESS)

#if wxUSE_DIALUP_MANAGER
EWXWCONSTANTINT(EVT_DIALUP_CONNECTED,wxEVT_DIALUP_CONNECTED)
EWXWCONSTANTINT(EVT_DIALUP_DISCONNECTED,wxEVT_DIALUP_DISCONNECTED)
#endif //wxUSE_DIALUP_MANAGER

EWXWCONSTANTINT(EVT_COMMAND_LEFT_CLICK,wxEVT_COMMAND_LEFT_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_LEFT_DCLICK,wxEVT_COMMAND_LEFT_DCLICK)
EWXWCONSTANTINT(EVT_COMMAND_RIGHT_CLICK,wxEVT_COMMAND_RIGHT_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_RIGHT_DCLICK,wxEVT_COMMAND_RIGHT_DCLICK)
EWXWCONSTANTINT(EVT_COMMAND_SET_FOCUS,wxEVT_COMMAND_SET_FOCUS)
EWXWCONSTANTINT(EVT_COMMAND_KILL_FOCUS,wxEVT_COMMAND_KILL_FOCUS)
EWXWCONSTANTINT(EVT_COMMAND_ENTER,wxEVT_COMMAND_ENTER)
EWXWCONSTANTINT(EVT_COMMAND_TREE_BEGIN_DRAG,wxEVT_COMMAND_TREE_BEGIN_DRAG)
EWXWCONSTANTINT(EVT_COMMAND_TREE_BEGIN_RDRAG,wxEVT_COMMAND_TREE_BEGIN_RDRAG)
EWXWCONSTANTINT(EVT_COMMAND_TREE_BEGIN_LABEL_EDIT,wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT)
EWXWCONSTANTINT(EVT_COMMAND_TREE_END_LABEL_EDIT,wxEVT_COMMAND_TREE_END_LABEL_EDIT)
EWXWCONSTANTINT(EVT_COMMAND_TREE_DELETE_ITEM,wxEVT_COMMAND_TREE_DELETE_ITEM)
EWXWCONSTANTINT(EVT_COMMAND_TREE_GET_INFO,wxEVT_COMMAND_TREE_GET_INFO)
EWXWCONSTANTINT(EVT_COMMAND_TREE_SET_INFO,wxEVT_COMMAND_TREE_SET_INFO)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_EXPANDED,wxEVT_COMMAND_TREE_ITEM_EXPANDED)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_EXPANDING,wxEVT_COMMAND_TREE_ITEM_EXPANDING)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_COLLAPSED,wxEVT_COMMAND_TREE_ITEM_COLLAPSED)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_COLLAPSING,wxEVT_COMMAND_TREE_ITEM_COLLAPSING)
EWXWCONSTANTINT(EVT_COMMAND_TREE_SEL_CHANGED,wxEVT_COMMAND_TREE_SEL_CHANGED)
EWXWCONSTANTINT(EVT_COMMAND_TREE_SEL_CHANGING,wxEVT_COMMAND_TREE_SEL_CHANGING)
EWXWCONSTANTINT(EVT_COMMAND_TREE_KEY_DOWN,wxEVT_COMMAND_TREE_KEY_DOWN)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_ACTIVATED,wxEVT_COMMAND_TREE_ITEM_ACTIVATED)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_RIGHT_CLICK,wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_TREE_ITEM_MIDDLE_CLICK,wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_TREE_END_DRAG,wxEVT_COMMAND_TREE_END_DRAG)
EWXWCONSTANTINT(EVT_COMMAND_LIST_BEGIN_DRAG,wxEVT_COMMAND_LIST_BEGIN_DRAG)
EWXWCONSTANTINT(EVT_COMMAND_LIST_BEGIN_RDRAG,wxEVT_COMMAND_LIST_BEGIN_RDRAG)
EWXWCONSTANTINT(EVT_COMMAND_LIST_BEGIN_LABEL_EDIT,wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT)
EWXWCONSTANTINT(EVT_COMMAND_LIST_END_LABEL_EDIT,wxEVT_COMMAND_LIST_END_LABEL_EDIT)
EWXWCONSTANTINT(EVT_COMMAND_LIST_DELETE_ITEM,wxEVT_COMMAND_LIST_DELETE_ITEM)
EWXWCONSTANTINT(EVT_COMMAND_LIST_DELETE_ALL_ITEMS,wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS)
EWXWCONSTANTINT(EVT_COMMAND_LIST_ITEM_SELECTED,wxEVT_COMMAND_LIST_ITEM_SELECTED)
EWXWCONSTANTINT(EVT_COMMAND_LIST_ITEM_DESELECTED,wxEVT_COMMAND_LIST_ITEM_DESELECTED)
EWXWCONSTANTINT(EVT_COMMAND_LIST_KEY_DOWN,wxEVT_COMMAND_LIST_KEY_DOWN)
EWXWCONSTANTINT(EVT_COMMAND_LIST_INSERT_ITEM,wxEVT_COMMAND_LIST_INSERT_ITEM)
EWXWCONSTANTINT(EVT_COMMAND_LIST_COL_CLICK,wxEVT_COMMAND_LIST_COL_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_LIST_ITEM_RIGHT_CLICK,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_LIST_ITEM_MIDDLE_CLICK,wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK)
EWXWCONSTANTINT(EVT_COMMAND_LIST_ITEM_ACTIVATED,wxEVT_COMMAND_LIST_ITEM_ACTIVATED)
EWXWCONSTANTINT(EVT_COMMAND_LIST_ITEM_FOCUSED,wxEVT_COMMAND_LIST_ITEM_FOCUSED)

#if ((wxVERSION_NUMBER > 2800) && !defined(wxUSE_TAB_DIALOG)) || defined(__WXGTK__) || defined(__WXMAC__)
#else
EWXWCONSTANTINT(EVT_COMMAND_TAB_SEL_CHANGED,wxEVT_COMMAND_TAB_SEL_CHANGED)
EWXWCONSTANTINT(EVT_COMMAND_TAB_SEL_CHANGING,wxEVT_COMMAND_TAB_SEL_CHANGING)
#endif

EWXWCONSTANTINT(EVT_COMMAND_NOTEBOOK_PAGE_CHANGED,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED)
EWXWCONSTANTINT(EVT_COMMAND_NOTEBOOK_PAGE_CHANGING,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING)
EWXWCONSTANTINT(EVT_COMMAND_SPLITTER_SASH_POS_CHANGED,wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED)
EWXWCONSTANTINT(EVT_COMMAND_SPLITTER_SASH_POS_CHANGING,wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING)
EWXWCONSTANTINT(EVT_COMMAND_SPLITTER_DOUBLECLICKED,wxEVT_COMMAND_SPLITTER_DOUBLECLICKED)
EWXWCONSTANTINT(EVT_COMMAND_SPLITTER_UNSPLIT,wxEVT_COMMAND_SPLITTER_UNSPLIT)
EWXWCONSTANTINT(EVT_WIZARD_PAGE_CHANGED,wxEVT_WIZARD_PAGE_CHANGED)
EWXWCONSTANTINT(EVT_WIZARD_PAGE_CHANGING,wxEVT_WIZARD_PAGE_CHANGING)
EWXWCONSTANTINT(EVT_WIZARD_CANCEL,wxEVT_WIZARD_CANCEL)
EWXWCONSTANTINT(EVT_CALENDAR_SEL_CHANGED,wxEVT_CALENDAR_SEL_CHANGED)
EWXWCONSTANTINT(EVT_CALENDAR_DAY_CHANGED,wxEVT_CALENDAR_DAY_CHANGED)
EWXWCONSTANTINT(EVT_CALENDAR_MONTH_CHANGED,wxEVT_CALENDAR_MONTH_CHANGED)
EWXWCONSTANTINT(EVT_CALENDAR_YEAR_CHANGED,wxEVT_CALENDAR_YEAR_CHANGED)
EWXWCONSTANTINT(EVT_CALENDAR_DOUBLECLICKED,wxEVT_CALENDAR_DOUBLECLICKED)
EWXWCONSTANTINT(EVT_CALENDAR_WEEKDAY_CLICKED,wxEVT_CALENDAR_WEEKDAY_CLICKED)

#ifdef USE_CONTRIB

EWXWCONSTANTINT(EVT_PLOT_SEL_CHANGING,wxEVT_PLOT_SEL_CHANGING)
EWXWCONSTANTINT(EVT_PLOT_SEL_CHANGED,wxEVT_PLOT_SEL_CHANGED)
EWXWCONSTANTINT(EVT_PLOT_CLICKED,wxEVT_PLOT_CLICKED)
EWXWCONSTANTINT(EVT_PLOT_DOUBLECLICKED,wxEVT_PLOT_DOUBLECLICKED)
EWXWCONSTANTINT(EVT_PLOT_ZOOM_IN,wxEVT_PLOT_ZOOM_IN)
EWXWCONSTANTINT(EVT_PLOT_ZOOM_OUT,wxEVT_PLOT_ZOOM_OUT)
EWXWCONSTANTINT(EVT_PLOT_VALUE_SEL_CREATING,wxEVT_PLOT_VALUE_SEL_CREATING)
EWXWCONSTANTINT(EVT_PLOT_VALUE_SEL_CREATED,wxEVT_PLOT_VALUE_SEL_CREATED)
EWXWCONSTANTINT(EVT_PLOT_VALUE_SEL_CHANGING,wxEVT_PLOT_VALUE_SEL_CHANGING)
EWXWCONSTANTINT(EVT_PLOT_VALUE_SEL_CHANGED,wxEVT_PLOT_VALUE_SEL_CHANGED)
EWXWCONSTANTINT(EVT_PLOT_AREA_SEL_CREATING,wxEVT_PLOT_AREA_SEL_CREATING)
EWXWCONSTANTINT(EVT_PLOT_AREA_SEL_CREATED,wxEVT_PLOT_AREA_SEL_CREATED)
EWXWCONSTANTINT(EVT_PLOT_AREA_SEL_CHANGING,wxEVT_PLOT_AREA_SEL_CHANGING)
EWXWCONSTANTINT(EVT_PLOT_AREA_SEL_CHANGED,wxEVT_PLOT_AREA_SEL_CHANGED)
EWXWCONSTANTINT(EVT_PLOT_BEGIN_X_LABEL_EDIT,wxEVT_PLOT_BEGIN_X_LABEL_EDIT)
EWXWCONSTANTINT(EVT_PLOT_END_X_LABEL_EDIT,wxEVT_PLOT_END_X_LABEL_EDIT)
EWXWCONSTANTINT(EVT_PLOT_BEGIN_Y_LABEL_EDIT,wxEVT_PLOT_BEGIN_Y_LABEL_EDIT)
EWXWCONSTANTINT(EVT_PLOT_END_Y_LABEL_EDIT,wxEVT_PLOT_END_Y_LABEL_EDIT)
EWXWCONSTANTINT(EVT_PLOT_BEGIN_TITLE_EDIT,wxEVT_PLOT_BEGIN_TITLE_EDIT)
EWXWCONSTANTINT(EVT_PLOT_END_TITLE_EDIT,wxEVT_PLOT_END_TITLE_EDIT)
EWXWCONSTANTINT(EVT_PLOT_AREA_CREATE,wxEVT_PLOT_AREA_CREATE)
EWXWCONSTANTINT(EVT_USER_FIRST,wxEVT_USER_FIRST)
EWXWCONSTANTINT(EVT_DYNAMIC_SASH_SPLIT,wxEVT_DYNAMIC_SASH_SPLIT)
EWXWCONSTANTINT(EVT_DYNAMIC_SASH_UNIFY,wxEVT_DYNAMIC_SASH_UNIFY)

#endif /* USE_CONTRIB */

EWXWCONSTANTINT(EVT_HELP,wxEVT_HELP)
EWXWCONSTANTINT(EVT_DETAILED_HELP,wxEVT_DETAILED_HELP)
EWXWCONSTANTINT(EVT_GRID_CELL_LEFT_CLICK,wxEVT_GRID_CELL_LEFT_CLICK)
EWXWCONSTANTINT(EVT_GRID_CELL_RIGHT_CLICK,wxEVT_GRID_CELL_RIGHT_CLICK)
EWXWCONSTANTINT(EVT_GRID_CELL_LEFT_DCLICK,wxEVT_GRID_CELL_LEFT_DCLICK)
EWXWCONSTANTINT(EVT_GRID_CELL_RIGHT_DCLICK,wxEVT_GRID_CELL_RIGHT_DCLICK)
EWXWCONSTANTINT(EVT_GRID_LABEL_LEFT_CLICK,wxEVT_GRID_LABEL_LEFT_CLICK)
EWXWCONSTANTINT(EVT_GRID_LABEL_RIGHT_CLICK,wxEVT_GRID_LABEL_RIGHT_CLICK)
EWXWCONSTANTINT(EVT_GRID_LABEL_LEFT_DCLICK,wxEVT_GRID_LABEL_LEFT_DCLICK)
EWXWCONSTANTINT(EVT_GRID_LABEL_RIGHT_DCLICK,wxEVT_GRID_LABEL_RIGHT_DCLICK)
EWXWCONSTANTINT(EVT_GRID_ROW_SIZE,wxEVT_GRID_ROW_SIZE)
EWXWCONSTANTINT(EVT_GRID_COL_SIZE,wxEVT_GRID_COL_SIZE)
EWXWCONSTANTINT(EVT_GRID_RANGE_SELECT,wxEVT_GRID_RANGE_SELECT)
EWXWCONSTANTINT(EVT_GRID_CELL_CHANGE,wxEVT_GRID_CELL_CHANGE)
EWXWCONSTANTINT(EVT_GRID_SELECT_CELL,wxEVT_GRID_SELECT_CELL)
EWXWCONSTANTINT(EVT_GRID_EDITOR_SHOWN,wxEVT_GRID_EDITOR_SHOWN)
EWXWCONSTANTINT(EVT_GRID_EDITOR_HIDDEN,wxEVT_GRID_EDITOR_HIDDEN)
EWXWCONSTANTINT(EVT_GRID_EDITOR_CREATED,wxEVT_GRID_EDITOR_CREATED)
EWXWCONSTANTINT(K_BACK,WXK_BACK)
EWXWCONSTANTINT(K_TAB,WXK_TAB)
EWXWCONSTANTINT(K_RETURN,WXK_RETURN)
EWXWCONSTANTINT(K_ESCAPE,WXK_ESCAPE)
EWXWCONSTANTINT(K_SPACE,WXK_SPACE)
EWXWCONSTANTINT(K_DELETE,WXK_DELETE)
EWXWCONSTANTINT(K_START,WXK_START)
EWXWCONSTANTINT(K_LBUTTON,WXK_LBUTTON)
EWXWCONSTANTINT(K_RBUTTON,WXK_RBUTTON)
EWXWCONSTANTINT(K_CANCEL,WXK_CANCEL)
EWXWCONSTANTINT(K_MBUTTON,WXK_MBUTTON)
EWXWCONSTANTINT(K_CLEAR,WXK_CLEAR)
EWXWCONSTANTINT(K_SHIFT,WXK_SHIFT)
EWXWCONSTANTINT(K_ALT,WXK_ALT)
EWXWCONSTANTINT(K_CONTROL,WXK_CONTROL)
EWXWCONSTANTINT(K_MENU,WXK_MENU)
EWXWCONSTANTINT(K_PAUSE,WXK_PAUSE)
EWXWCONSTANTINT(K_CAPITAL,WXK_CAPITAL)
EWXWCONSTANTINT(K_END,WXK_END)
EWXWCONSTANTINT(K_HOME,WXK_HOME)
EWXWCONSTANTINT(K_LEFT,WXK_LEFT)
EWXWCONSTANTINT(K_UP,WXK_UP)
EWXWCONSTANTINT(K_RIGHT,WXK_RIGHT)
EWXWCONSTANTINT(K_DOWN,WXK_DOWN)
EWXWCONSTANTINT(K_SELECT,WXK_SELECT)
EWXWCONSTANTINT(K_PRINT,WXK_PRINT)
EWXWCONSTANTINT(K_EXECUTE,WXK_EXECUTE)
EWXWCONSTANTINT(K_SNAPSHOT,WXK_SNAPSHOT)
EWXWCONSTANTINT(K_INSERT,WXK_INSERT)
EWXWCONSTANTINT(K_HELP,WXK_HELP)
EWXWCONSTANTINT(K_NUMPAD0,WXK_NUMPAD0)
EWXWCONSTANTINT(K_NUMPAD1,WXK_NUMPAD1)
EWXWCONSTANTINT(K_NUMPAD2,WXK_NUMPAD2)
EWXWCONSTANTINT(K_NUMPAD3,WXK_NUMPAD3)
EWXWCONSTANTINT(K_NUMPAD4,WXK_NUMPAD4)
EWXWCONSTANTINT(K_NUMPAD5,WXK_NUMPAD5)
EWXWCONSTANTINT(K_NUMPAD6,WXK_NUMPAD6)
EWXWCONSTANTINT(K_NUMPAD7,WXK_NUMPAD7)
EWXWCONSTANTINT(K_NUMPAD8,WXK_NUMPAD8)
EWXWCONSTANTINT(K_NUMPAD9,WXK_NUMPAD9)
EWXWCONSTANTINT(K_MULTIPLY,WXK_MULTIPLY)
EWXWCONSTANTINT(K_ADD,WXK_ADD)
EWXWCONSTANTINT(K_SEPARATOR,WXK_SEPARATOR)
EWXWCONSTANTINT(K_SUBTRACT,WXK_SUBTRACT)
EWXWCONSTANTINT(K_DECIMAL,WXK_DECIMAL)
EWXWCONSTANTINT(K_DIVIDE,WXK_DIVIDE)
EWXWCONSTANTINT(K_F1,WXK_F1)
EWXWCONSTANTINT(K_F2,WXK_F2)
EWXWCONSTANTINT(K_F3,WXK_F3)
EWXWCONSTANTINT(K_F4,WXK_F4)
EWXWCONSTANTINT(K_F5,WXK_F5)
EWXWCONSTANTINT(K_F6,WXK_F6)
EWXWCONSTANTINT(K_F7,WXK_F7)
EWXWCONSTANTINT(K_F8,WXK_F8)
EWXWCONSTANTINT(K_F9,WXK_F9)
EWXWCONSTANTINT(K_F10,WXK_F10)
EWXWCONSTANTINT(K_F11,WXK_F11)
EWXWCONSTANTINT(K_F12,WXK_F12)
EWXWCONSTANTINT(K_F13,WXK_F13)
EWXWCONSTANTINT(K_F14,WXK_F14)
EWXWCONSTANTINT(K_F15,WXK_F15)
EWXWCONSTANTINT(K_F16,WXK_F16)
EWXWCONSTANTINT(K_F17,WXK_F17)
EWXWCONSTANTINT(K_F18,WXK_F18)
EWXWCONSTANTINT(K_F19,WXK_F19)
EWXWCONSTANTINT(K_F20,WXK_F20)
EWXWCONSTANTINT(K_F21,WXK_F21)
EWXWCONSTANTINT(K_F22,WXK_F22)
EWXWCONSTANTINT(K_F23,WXK_F23)
EWXWCONSTANTINT(K_F24,WXK_F24)
EWXWCONSTANTINT(K_NUMLOCK,WXK_NUMLOCK)
EWXWCONSTANTINT(K_SCROLL,WXK_SCROLL)
EWXWCONSTANTINT(K_PAGEUP,WXK_PAGEUP)
EWXWCONSTANTINT(K_PAGEDOWN,WXK_PAGEDOWN)
EWXWCONSTANTINT(K_NUMPAD_SPACE,WXK_NUMPAD_SPACE)
EWXWCONSTANTINT(K_NUMPAD_TAB,WXK_NUMPAD_TAB)
EWXWCONSTANTINT(K_NUMPAD_ENTER,WXK_NUMPAD_ENTER)
EWXWCONSTANTINT(K_NUMPAD_F1,WXK_NUMPAD_F1)
EWXWCONSTANTINT(K_NUMPAD_F2,WXK_NUMPAD_F2)
EWXWCONSTANTINT(K_NUMPAD_F3,WXK_NUMPAD_F3)
EWXWCONSTANTINT(K_NUMPAD_F4,WXK_NUMPAD_F4)
EWXWCONSTANTINT(K_NUMPAD_HOME,WXK_NUMPAD_HOME)
EWXWCONSTANTINT(K_NUMPAD_LEFT,WXK_NUMPAD_LEFT)
EWXWCONSTANTINT(K_NUMPAD_UP,WXK_NUMPAD_UP)
EWXWCONSTANTINT(K_NUMPAD_RIGHT,WXK_NUMPAD_RIGHT)
EWXWCONSTANTINT(K_NUMPAD_DOWN,WXK_NUMPAD_DOWN)
EWXWCONSTANTINT(K_NUMPAD_PAGEUP,WXK_NUMPAD_PAGEUP)
EWXWCONSTANTINT(K_NUMPAD_PAGEDOWN,WXK_NUMPAD_PAGEDOWN)
EWXWCONSTANTINT(K_NUMPAD_END,WXK_NUMPAD_END)
EWXWCONSTANTINT(K_NUMPAD_BEGIN,WXK_NUMPAD_BEGIN)
EWXWCONSTANTINT(K_NUMPAD_INSERT,WXK_NUMPAD_INSERT)
EWXWCONSTANTINT(K_NUMPAD_DELETE,WXK_NUMPAD_DELETE)
EWXWCONSTANTINT(K_NUMPAD_EQUAL,WXK_NUMPAD_EQUAL)
EWXWCONSTANTINT(K_NUMPAD_MULTIPLY,WXK_NUMPAD_MULTIPLY)
EWXWCONSTANTINT(K_NUMPAD_ADD,WXK_NUMPAD_ADD)
EWXWCONSTANTINT(K_NUMPAD_SEPARATOR,WXK_NUMPAD_SEPARATOR)
EWXWCONSTANTINT(K_NUMPAD_SUBTRACT,WXK_NUMPAD_SUBTRACT)
EWXWCONSTANTINT(K_NUMPAD_DECIMAL,WXK_NUMPAD_DECIMAL)
EWXWCONSTANTINT(K_NUMPAD_DIVIDE,WXK_NUMPAD_DIVIDE)
EWXWCONSTANTINT(K_WINDOWS_LEFT,WXK_WINDOWS_LEFT)
EWXWCONSTANTINT(K_WINDOWS_RIGHT,WXK_WINDOWS_RIGHT)
EWXWCONSTANTINT(K_WINDOWS_MENU,WXK_WINDOWS_MENU)
EWXWCONSTANTINT(K_COMMAND,WXK_COMMAND)
EWXWCONSTANTINT(K_SPECIAL1,WXK_SPECIAL1)
EWXWCONSTANTINT(K_SPECIAL2,WXK_SPECIAL2)
EWXWCONSTANTINT(K_SPECIAL3,WXK_SPECIAL3)
EWXWCONSTANTINT(K_SPECIAL4,WXK_SPECIAL4)
EWXWCONSTANTINT(K_SPECIAL5,WXK_SPECIAL5)
EWXWCONSTANTINT(K_SPECIAL6,WXK_SPECIAL6)
EWXWCONSTANTINT(K_SPECIAL7,WXK_SPECIAL7)
EWXWCONSTANTINT(K_SPECIAL8,WXK_SPECIAL8)
EWXWCONSTANTINT(K_SPECIAL9,WXK_SPECIAL9)
EWXWCONSTANTINT(K_SPECIAL10,WXK_SPECIAL10)
EWXWCONSTANTINT(K_SPECIAL11,WXK_SPECIAL11)
EWXWCONSTANTINT(K_SPECIAL12,WXK_SPECIAL12)
EWXWCONSTANTINT(K_SPECIAL13,WXK_SPECIAL13)
EWXWCONSTANTINT(K_SPECIAL14,WXK_SPECIAL14)
EWXWCONSTANTINT(K_SPECIAL15,WXK_SPECIAL15)
EWXWCONSTANTINT(K_SPECIAL16,WXK_SPECIAL16)
EWXWCONSTANTINT(K_SPECIAL17,WXK_SPECIAL17)
EWXWCONSTANTINT(K_SPECIAL18,WXK_SPECIAL18)
EWXWCONSTANTINT(K_SPECIAL19,WXK_SPECIAL19)
EWXWCONSTANTINT(K_SPECIAL20,WXK_SPECIAL20)
}
