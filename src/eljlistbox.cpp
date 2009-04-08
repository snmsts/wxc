#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxListBox_Create)(wxWindow* _prt,int _id,int _n,void* _str,int _stl)
{
	wxListBox* result = new wxListBox (_prt, _id, wxDefaultPosition, wxDefaultSize, 0, NULL, _stl, wxDefaultValidator);

	for (int i = 0; i < _n; i++)
		result->Append(((wxChar**)_str)[i]);

	return (void*)result;
}

EWXWEXPORT(void,wxListBox_Clear)(void* self)
{
	((wxListBox*)self)->Clear();
}
	
EWXWEXPORT(void,wxListBox_Delete)(void* self,int n)
{
	((wxListBox*)self)->Delete(n);
}
	
EWXWEXPORT(int,wxListBox_GetCount)(void* self)
{
	return ((wxListBox*)self)->GetCount();
}
	
EWXWEXPORT(wxString*,wxListBox_GetString)(void* self,int n)
{
  return new wxString(((wxListBox*)self)->GetString(n));
}
	
EWXWEXPORT(void,wxListBox_SetString)(void* self,int n,wxString* s)
{
	((wxListBox*)self)->SetString(n,*s);
}
	
EWXWEXPORT(int,wxListBox_FindString)(void* self,wxString* s)
{
	return ((wxListBox*)self)->FindString(*s);
}
	
EWXWEXPORT(bool,wxListBox_IsSelected)(wxListBox* self,int n)
{
	return self->IsSelected(n);
}
	
EWXWEXPORT(void,wxListBox_SetSelection)(void* self,int n,bool select)
{
	((wxListBox*)self)->SetSelection(n, select);
}
	
EWXWEXPORT(int,wxListBox_GetSelection)(void* self)
{
	return ((wxListBox*)self)->GetSelection();
}
	
EWXWEXPORT(int,wxListBox_GetSelections)(void* self,int* aSelections,int allocated)
{
	wxArrayInt sel;
	int result = ((wxListBox*)self)->GetSelections(sel);
	
	if (allocated < result) return -result;
	
	for (int i = 0; i < result; i++) aSelections[i] = sel[i];
	return result;
}
	
EWXWEXPORT(void,wxListBox_Append)(void* self,wxString* item)
{
	((wxListBox*)self)->Append(*item);
}
	
EWXWEXPORT(void,wxListBox_AppendData)(void* self,wxString* item,void* _data)
{
	((wxListBox*)self)->Append(*item, _data);
}
	
EWXWEXPORT(void,wxListBox_InsertItems)(void* self,void* items,int pos,int count)
{
	wxArrayString array;
	
	for (int i = 0; i< count; i++)
		array[i] = ((wxChar**)items)[i];
	
	((wxListBox*)self)->InsertItems(array, pos);
}
	
EWXWEXPORT(void,wxListBox_SetFirstItem)(void* self,int n)
{
	((wxListBox*)self)->SetFirstItem(n);
}
	
EWXWEXPORT(void,wxListBox_SetClientData)(void* self,int n,void* clientData)
{
	((wxListBox*)self)->SetClientData(n, clientData);
}
	
EWXWEXPORT(void*,wxListBox_GetClientData)(void* self,int n)
{
	return (void*)((wxListBox*)self)->GetClientData(n);
}
	
EWXWEXPORT(void,wxListBox_SetStringSelection)(void* self,wxString* str,bool sel)
{
	((wxListBox*)self)->SetStringSelection(*str, sel);
}
	
}
