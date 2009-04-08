#include "wrapper.h"

/* testing */
// #define wxUSE_MEDIACTRL 0

/*-----------------------------------------------------------------------------
  We want to include the function signatures always -- even on 
  systems that don't support MediaCtrl. This means that every function body is
  surrounded by #ifdef wxUSE_MEDIACTRL directives :-(
-----------------------------------------------------------------------------*/
#if defined(wxUSE_MEDIACTRL) && (wxUSE_MEDIACTRL==0)
# undef wxUSE_MEDIACTRL
#endif

#if defined(wxcREFUSE_MEDIACTRL)
# undef wxUSE_MEDIACTRL
#endif

#ifndef wxUSE_MEDIACTRL
# define wxMediaCtrl      void
#endif

#if (wxVERSION_NUMBER <= 2600)
# define wxFileOffset      long
#endif

extern "C" {
/*-----------------------------------------------------------------------------
  MediaCtrl
-----------------------------------------------------------------------------*/
EWXWEXPORT(wxMediaCtrl*,wxMediaCtrl_Create)(wxWindow* parent,int id,wxString* fileName,long style,wxString* szBackend,wxString* name)
{
#ifdef wxUSE_MEDIACTRL
  return new wxMediaCtrl(parent,(wxWindowID)id,
    (fileName ? *fileName : wxString(wxT(""))),
    wxDefaultPosition, wxDefaultSize,style,
    (szBackend ? *szBackend : wxString(wxT(""))), wxDefaultValidator,
    (name ? *name : wxString(wxT("MediaCtrl"))));
#else
  return NULL;
#endif
}

/* we don't need this.
EWXWEXPORT(wxMediaCtrl*,wxMediaCtrl_Create)(wxWindow* parent,int id,wxString* fileName,long style,wxString* szBackend,wxString* name)
{
#ifdef wxUSE_MEDIACTRL
  return wxMediaCtrl->Create(parent,(wxWindowID)id,
    (fileName ? *fileName : wxString(wxT(""))),
    wxDefaultPosition, wxDefaultSize,style,
    (szBackend ? *szBackend : wxString(wxT(""))), wxDefaultValidator,
    (name ? *name : wxString(wxT("MediaCtrl"))));
#else
  return NULL;
#endif
}
*/

EWXWEXPORT(void,wxMediaCtrl_Delete)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  if (self) delete self;
#endif
}

EWXWEXPORT(wxSize*,wxMediaCtrl_GetBestSize)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return new wxSize(self->GetBestSize());
#endif
}

EWXWEXPORT(double,wxMediaCtrl_GetPlaybackRate)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->GetPlaybackRate();
#else
  return NULL;
#endif
}

EWXWEXPORT(double,wxMediaCtrl_GetVolume)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->GetVolume();
#else
  return NULL;
#endif
}

EWXWEXPORT(int,wxMediaCtrl_GetState)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->GetState();
#else
  return NULL;
#endif
}

EWXWEXPORT(wxFileOffset,wxMediaCtrl_Length)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->Length();
#else
  return NULL;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_Load)(wxMediaCtrl* self,wxString* fileName)
{
#ifdef wxUSE_MEDIACTRL
  return self->Load(*fileName);
#else
  return NULL;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_LoadURI)(wxMediaCtrl* self,wxString* uri)
{
#ifdef wxUSE_MEDIACTRL
  return self->LoadURI(*uri);
#else
  return NULL;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_LoadURIWithProxy)(wxMediaCtrl* self,wxString* uri,wxString* proxy)
{
#ifdef wxUSE_MEDIACTRL
  return self->LoadURIWithProxy(*uri,*proxy);
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_Pause)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->Pause();
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_Play)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->Play();
#else
  return false;
#endif
}

EWXWEXPORT(wxFileOffset,wxMediaCtrl_Seek)(wxMediaCtrl* self,wxFileOffset offsetWhere,int mode)
{
#ifdef wxUSE_MEDIACTRL
  return self->Seek(offsetWhere, static_cast<wxSeekMode>(mode));
#else
  return NULL;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_SetPlaybackRate)(wxMediaCtrl* self,double dRate)
{
#ifdef wxUSE_MEDIACTRL
  return self->SetPlaybackRate(dRate);
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_SetVolume)(wxMediaCtrl* self,double dVolume)
{
#ifdef wxUSE_MEDIACTRL
  return self->SetVolume(dVolume);
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_ShowPlayerControls)(wxMediaCtrl* self,int flags)
{
#ifdef wxUSE_MEDIACTRL
  return self->ShowPlayerControls(static_cast<wxMediaCtrlPlayerControls>(flags));
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxMediaCtrl_Stop)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->Stop();
#else
  return false;
#endif
}

EWXWEXPORT(wxFileOffset,wxMediaCtrl_Tell)(wxMediaCtrl* self)
{
#ifdef wxUSE_MEDIACTRL
  return self->Tell();
#else
  return NULL;
#endif
}


/*-----------------------------------------------------------------------------
  MediaEvent
-----------------------------------------------------------------------------*/
#ifdef wxUSE_MEDIACTRL
EWXWCONSTANTINT(EVT_MEDIA_LOADED,wxEVT_MEDIA_LOADED)
EWXWCONSTANTINT(EVT_MEDIA_STOP,wxEVT_MEDIA_STOP)
EWXWCONSTANTINT(EVT_MEDIA_FINISHED,wxEVT_MEDIA_FINISHED)
EWXWCONSTANTINT(EVT_MEDIA_STATECHANGED,wxEVT_MEDIA_STATECHANGED)
EWXWCONSTANTINT(EVT_MEDIA_PLAY,wxEVT_MEDIA_PLAY)
EWXWCONSTANTINT(EVT_MEDIA_PAUSE,wxEVT_MEDIA_PAUSE)
#endif

}


