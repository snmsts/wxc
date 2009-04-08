#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxDrawWindow_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxWindow (_prt, _id,wxDefaultPosition,wxDefaultSize, _stl);
}

EWXWEXPORT(void*,wxDrawControl_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxControl (_prt, _id,wxDefaultPosition,wxDefaultSize, _stl);
}

}
