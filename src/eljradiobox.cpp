#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxRadioBox_Create)(wxWindow* _prt,int _id,wxString* _txt,int _n,void* _str,int _dim,int _stl)
{
	wxString items[256];

	for (int i = 0; i < _n; i++)
		items[i] = ((wxChar**)_str)[i];

	return (void*)new wxRadioBox (_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _n, items, _dim, _stl, wxDefaultValidator);
}

EWXWEXPORT(int,wxRadioBox_FindString)(void* self,wxString* s)
{
	return ((wxRadioBox*)self)->FindString(*s);
}

EWXWEXPORT(void,wxRadioBox_SetSelection)(void* self,int _n)
{
	((wxRadioBox*)self)->SetSelection(_n);
}

EWXWEXPORT(int,wxRadioBox_GetSelection)(void* self)
{
	return ((wxRadioBox*)self)->GetSelection();
}

EWXWEXPORT(void,wxRadioBox_SetItemLabel)(void* self,int item,wxString* label)
{
#if wxVERSION_NUMBER >= 2400
	((wxRadioBoxBase*)self)->SetString(item,*label);
#else
	((wxRadioBox*)self)->SetLabel(item,*label);
#endif
}

EWXWEXPORT(void,wxRadioBox_SetItemBitmap)(void* self,int item,wxBitmap* bitmap)
{
#if wxVERSION_NUMBER < 2400
	((wxRadioBox*)self)->SetLabel(item,  bitmap);
#endif
}

EWXWEXPORT(wxString*,wxRadioBox_GetItemLabel)(wxRadioBox* self,int item)
{
#if wxVERSION_NUMBER >= 2400
  return new wxString(self->GetString(item));
#else
  return new wxString(self->GetLabel(item));
#endif
}

EWXWEXPORT(void,wxRadioBox_EnableItem)(void* self,int item,bool enable)
{
	((wxRadioBox*)self)->Enable(item, enable);
}

EWXWEXPORT(void,wxRadioBox_ShowItem)(void* self,int item,bool show)
{
	((wxRadioBox*)self)->Show(item, show);
}

EWXWEXPORT(wxString*,wxRadioBox_GetStringSelection)(void* self)
{
  return new wxString(((wxRadioBox*)self)->GetStringSelection());
}

EWXWEXPORT(void,wxRadioBox_SetStringSelection)(void* self,wxString* s)
{
	((wxRadioBox*)self)->SetStringSelection(*s);
}

EWXWEXPORT(int,wxRadioBox_Number)(void* self)
{
#if wxVERSION_NUMBER >= 2400
	return ((wxRadioBox*)self)->GetCount();
#else
	return ((wxRadioBox*)self)->Number();
#endif
}

EWXWEXPORT(int,wxRadioBox_GetNumberOfRowsOrCols)(void* self)
{
#if wxVERSION_NUMBER >= 2600
	return ((wxRadioBox*)self)->GetCount();
#else
	return ((wxRadioBox*)self)->GetNumberOfRowsOrCols();
#endif
}

EWXWEXPORT(void,wxRadioBox_SetNumberOfRowsOrCols)(void* self,int n)
{
#if wxVERSION_NUMBER >= 2600
	return;
#else
	((wxRadioBox*)self)->SetNumberOfRowsOrCols(n);
#endif
}

}
