#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxCheckListBox*,wxCheckListBox_Create)(wxWindow* _prt,int _id,int _n,void* _str,int _stl)
{
	wxCheckListBox* result = new wxCheckListBox (_prt, _id,wxDefaultPosition,wxDefaultSize, 0, NULL, _stl, wxDefaultValidator);

	for (int i = 0; i < _n; i++)
		result->Append(((wxChar**)_str)[i]);

	return result;
}

EWXWEXPORT(void,wxCheckListBox_Delete)(wxCheckListBox* self)
{
  delete self;
}

EWXWEXPORT(void,wxCheckListBox_Check)(wxCheckListBox* self,int item,bool check)
{
	self->Check(item, check);
}
	
EWXWEXPORT(bool,wxCheckListBox_IsChecked)(wxCheckListBox* self,int item)
{
	return self->IsChecked(item);
}

}
