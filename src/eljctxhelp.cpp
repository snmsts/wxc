#include "wrapper.h"
#if wxVERSION_NUMBER >= 2400

extern "C"
{

EWXWEXPORT(wxContextHelp*,wxContextHelp_Create)(wxWindow* win,bool beginHelp)
{
	return new wxContextHelp(win, beginHelp);
}
	
EWXWEXPORT(void,wxContextHelp_Delete)(wxContextHelp* self)
{
	delete self;
}
	
EWXWEXPORT(bool,wxContextHelp_BeginContextHelp)(wxContextHelp* self,wxWindow* win)
{
	return self->BeginContextHelp(win);
}
	
EWXWEXPORT(bool,wxContextHelp_EndContextHelp)(wxContextHelp* self)
{
	return self->EndContextHelp();
}
	

EWXWEXPORT(void*,wxContextHelpButton_Create)(wxWindow* parent,int id,long style)
{
	return (void*)new wxContextHelpButton(parent, (wxWindowID)id,wxDefaultPosition,wxDefaultSize, style);
}


EWXWEXPORT(void*,wxHelpProvider_Get)()
{
	return (void*)wxHelpProvider::Get();
}
	
EWXWEXPORT(void*,wxHelpProvider_Set)(wxHelpProvider* helpProvider)
{
	return (void*)wxHelpProvider::Set(helpProvider);
}
	
EWXWEXPORT(wxString*,wxHelpProvider_GetHelp)(wxHelpProvider* self,wxWindowBase* window)
{
  return new wxString(self->GetHelp(window));
}
	
EWXWEXPORT(bool,wxHelpProvider_ShowHelp)(wxHelpProvider* self,wxWindowBase* window)
{
	return self->ShowHelp(window);
}
	
EWXWEXPORT(void,wxHelpProvider_AddHelp)(wxHelpProvider* self,wxWindowBase* window,wxString* text)
{
	self->AddHelp(window,*text);
}
	
EWXWEXPORT(void,wxHelpProvider_AddHelpById)(wxHelpProvider* self,int id,wxString* text)
{
	self->AddHelp((wxWindowID)id,*text);
}
	
EWXWEXPORT(void,wxHelpProvider_RemoveHelp)(wxHelpProvider* self,wxWindowBase* window)
{
	self->RemoveHelp(window);
}
	
EWXWEXPORT(void,wxHelpProvider_Delete)(wxHelpProvider* self)
{
	delete self;
}


EWXWEXPORT(void*,wxSimpleHelpProvider_Create)()
{
	return (void*)new wxSimpleHelpProvider();
}
	

EWXWEXPORT(void*,wxHelpControllerHelpProvider_Create)(wxHelpControllerBase* ctr)
{
	return (void*)new wxHelpControllerHelpProvider(ctr);
}
	
EWXWEXPORT(void,wxHelpControllerHelpProvider_SetHelpController)(wxHelpControllerHelpProvider* self,wxHelpControllerBase* hc)
{
	self->SetHelpController(hc);
}
	
EWXWEXPORT(void*,wxHelpControllerHelpProvider_GetHelpController)(wxHelpControllerHelpProvider* self)
{
	return (void*)self->GetHelpController();
}
	
}
#endif
