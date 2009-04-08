#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxRadioButton_Create)(wxWindow* _prt,int _id,wxString* _txt,int _stl)
{
	return (void*)new wxRadioButton (_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _stl, wxDefaultValidator);
}

EWXWEXPORT(void,wxRadioButton_SetValue)(void* self,bool value)
{
	((wxRadioButton*)self)->SetValue(value);
}
	
EWXWEXPORT(bool,wxRadioButton_GetValue)(wxRadioButton* self)
{
	return self->GetValue();
}

} 
