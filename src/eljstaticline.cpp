#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxStaticLine_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxStaticLine (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(bool,wxStaticLine_IsVertical)(wxStaticLine* self)
{
	return self->IsVertical ();
}
	
EWXWEXPORT(int,wxStaticLine_GetDefaultSize)(void* self)
{
	return ((wxStaticLine*)self)->GetDefaultSize ();
}

}
