#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxPanel_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxPanel (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(void,wxPanel_InitDialog)(void* self)
{
	((wxPanel*)self)->InitDialog();
}
	
EWXWEXPORT(void*,wxPanel_GetDefaultItem)(void* self)
{
#if (wxVERSION_NUMBER <= 2800)
	return (void*)((wxPanel*)self)->GetDefaultItem();
#else
	return (void*)((wxTopLevelWindow*)self)->GetDefaultItem();
#endif
}
	
EWXWEXPORT(void,wxPanel_SetDefaultItem)(void* self,void* btn)
{
#if (wxVERSION_NUMBER <= 2800)
	((wxPanel*)self)->SetDefaultItem((wxButton*)btn);
#else
	((wxTopLevelWindow*)self)->SetDefaultItem((wxButton*)btn);
#endif
}

#if (wxVERSION_NUMBER >= 2800)
EWXWEXPORT(void,wxPanel_SetFocus)(void* self)
{
	((wxPanel*)self)->SetFocus();
}
#endif
}
