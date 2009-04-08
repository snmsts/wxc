#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxCheckBox*,wxCheckBox_Create)(wxWindow* _prt,int _id,wxString* _txt,int _stl)
{
	return new wxCheckBox (_prt, _id,*_txt,wxDefaultPosition,wxDefaultSize, _stl, wxDefaultValidator);
}

EWXWEXPORT(void,wxCheckBox_Delete)(wxCheckBox* self)
{
  delete self;
}

EWXWEXPORT(void,wxCheckBox_SetValue)(wxCheckBox* self,bool value)
{
	self->SetValue(value);
}
	
EWXWEXPORT(bool,wxCheckBox_GetValue)(wxCheckBox* self)
{
	return self->GetValue();
}

} 
