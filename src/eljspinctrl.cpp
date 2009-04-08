#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxSpinCtrl_Create)(wxWindow* _prt,int _id,wxString* _txt,long _stl,int _min,int _max,int _init)
{
	return (void*)new wxSpinCtrl (_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _stl, _min, _max, _init);
}

EWXWEXPORT(void,wxSpinCtrl_SetValue)(void* self,int val)
{
	((wxSpinCtrl*)self)->SetValue(val);
}
	
EWXWEXPORT(int,wxSpinCtrl_GetValue)(void* self)
{
	return ((wxSpinCtrl*)self)->GetValue();
}
	
EWXWEXPORT(void,wxSpinCtrl_SetRange)(void* self,int min_val,int max_val)
{
	((wxSpinCtrl*)self)->SetRange(min_val, max_val);
}
	
EWXWEXPORT(int,wxSpinCtrl_GetMin)(void* self)
{
	return ((wxSpinCtrl*)self)->GetMin();
}
	
EWXWEXPORT(int,wxSpinCtrl_GetMax)(void* self)
{
	return ((wxSpinCtrl*)self)->GetMax();
}

EWXWEXPORT(void*,wxSpinButton_Create)(wxWindow* _prt,int _id,long _stl)
{
	return (void*)new wxSpinButton (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(int,wxSpinButton_GetValue)(void* self)
{
	return ((wxSpinButton*)self)->GetValue();
}
	
EWXWEXPORT(int,wxSpinButton_GetMin)(void* self)
{
	return ((wxSpinButton*)self)->GetMin();
}
	
EWXWEXPORT(int,wxSpinButton_GetMax)(void* self)
{
	return ((wxSpinButton*)self)->GetMax();
}
	
EWXWEXPORT(void,wxSpinButton_SetValue)(void* self,int val)
{
	((wxSpinButton*)self)->SetValue(val);
}
	
EWXWEXPORT(void,wxSpinButton_SetRange)(void* self,int minVal,int maxVal)
{
	((wxSpinButton*)self)->SetRange(minVal, maxVal);
}
	
}
