#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxFileDialog*,wxFileDialog_Create)(wxWindow* _prt,wxString* _msg,wxString* _dir,wxString* _fle,wxString* _wcd,int _stl)
{
	return new wxFileDialog (_prt,*_msg,*_dir,*_fle,*_wcd);
}

EWXWEXPORT(void,wxFileDialog_SetMessage)(wxFileDialog* self,wxString* message)
{
	self->SetMessage(*message);
}
	
EWXWEXPORT(void,wxFileDialog_SetPath)(wxFileDialog* self,wxString* path)
{
	self->SetPath(*path);
}
	
EWXWEXPORT(void,wxFileDialog_SetDirectory)(wxFileDialog* self,wxString* dir)
{
	self->SetDirectory(*dir);
}
	
EWXWEXPORT(void,wxFileDialog_SetFilename)(wxFileDialog* self,wxString* name)
{
	self->SetFilename(*name);
}
	
EWXWEXPORT(void,wxFileDialog_SetWildcard)(wxFileDialog* self,wxString* wildCard)
{
	self->SetWildcard(*wildCard);
}
	
EWXWEXPORT(void,wxFileDialog_SetStyle)(wxFileDialog* self,int style)
{
#if WXWIN_COMPATIBILITY_2_6
	self->SetStyle((long)style);
#endif
}
	
EWXWEXPORT(void,wxFileDialog_SetFilterIndex)(wxFileDialog* self,int filterIndex)
{
	self->SetFilterIndex(filterIndex);
}
	
EWXWEXPORT(wxString*,wxFileDialog_GetMessage)(wxFileDialog* self)
{
  return new wxString(self->GetMessage());
}
	
EWXWEXPORT(wxString*,wxFileDialog_GetPath)(wxFileDialog* self)
{
  return new wxString(self->GetPath());
}
	
EWXWEXPORT(int,wxFileDialog_GetPaths)(wxFileDialog* self,void* paths)
{
	wxArrayString arr;
	self->GetPaths(arr);
	if (paths)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((const wxChar**)paths)[i] = wxStrdup (arr.Item(i).c_str());
	}
	return arr.GetCount();
}
	
EWXWEXPORT(wxString*,wxFileDialog_GetDirectory)(wxFileDialog* self)
{
  return new wxString(self->GetDirectory());
}
	
EWXWEXPORT(wxString*,wxFileDialog_GetFilename)(wxFileDialog* self)
{
  return new wxString(self->GetFilename());
}
	
EWXWEXPORT(int,wxFileDialog_GetFilenames)(wxFileDialog* self,void* paths)
{
	wxArrayString arr;
	self->GetFilenames(arr);
	if (paths)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((const wxChar**)paths)[i] = wxStrdup (arr.Item(i).c_str());
	}
	return arr.GetCount();
}
	
EWXWEXPORT(wxString*,wxFileDialog_GetWildcard)(wxFileDialog* self)
{
  return new wxString(self->GetWildcard());
}
	
EWXWEXPORT(long,wxFileDialog_GetStyle)(wxFileDialog* self)
{
#if WXWIN_COMPATIBILITY_2_6
	return self->GetStyle();
#else
  return 0;
#endif
}
	
EWXWEXPORT(int,wxFileDialog_GetFilterIndex)(wxFileDialog* self)
{
	return self->GetFilterIndex();
}
	
}
