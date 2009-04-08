#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxMDIParentFrame_Create)(wxWindow* _prt,int _id,wxString* _txt,int _stl)
{
	return (void*)new wxMDIParentFrame (_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(void*,wxMDIParentFrame_GetActiveChild)(void* self)
{
	return (void*)((wxMDIParentFrame*)self)->GetActiveChild();
}
	
EWXWEXPORT(void*,wxMDIParentFrame_GetClientWindow)(void* self)
{
	return (void*)((wxMDIParentFrame*)self)->GetClientWindow();
}
	
EWXWEXPORT(void*,wxMDIParentFrame_OnCreateClient)(void* self)
{
	return (void*)((wxMDIParentFrame*)self)->OnCreateClient();
}
	
EWXWEXPORT(void*,wxMDIParentFrame_GetWindowMenu)(void* self)
{
#ifdef __WIN32__
	return (void*)((wxMDIParentFrame*)self)->GetWindowMenu();
#else
	return NULL;
#endif
}
	
EWXWEXPORT(void,wxMDIParentFrame_SetWindowMenu)(void* self,wxMenu* menu)
{
#ifdef __WIN32__
	((wxMDIParentFrame*)self)->SetWindowMenu( menu);
#endif
}
	
EWXWEXPORT(void,wxMDIParentFrame_Cascade)(void* self)
{
	((wxMDIParentFrame*)self)->Cascade();
}
	
EWXWEXPORT(void,wxMDIParentFrame_Tile)(void* self)
{
	((wxMDIParentFrame*)self)->Tile();
}
	
EWXWEXPORT(void,wxMDIParentFrame_ArrangeIcons)(void* self)
{
	((wxMDIParentFrame*)self)->ArrangeIcons();
}
	
EWXWEXPORT(void,wxMDIParentFrame_ActivateNext)(void* self)
{
	((wxMDIParentFrame*)self)->ActivateNext();
}
	
EWXWEXPORT(void,wxMDIParentFrame_ActivatePrevious)(void* self)
{
	((wxMDIParentFrame*)self)->ActivatePrevious();
}
	
EWXWEXPORT(void*,wxMDIChildFrame_Create)(void* _prt,int _id,wxString* _txt,int _stl)
{
	return (void*)new wxMDIChildFrame ((wxMDIParentFrame *)_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(void,wxMDIChildFrame_Activate)(void* self)
{
	((wxMDIChildFrame*)self)->Activate();
}
	
}
