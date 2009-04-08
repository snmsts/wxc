#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxDirDialog*,wxDirDialog_Create)(wxWindow* _prt,wxString* _msg,wxString* _dir,int _stl)
{
	return new wxDirDialog (_prt,*_msg,* _dir, _stl);
}

EWXWEXPORT(void,wxDirDialog_SetMessage)(wxDirDialog* self,wxString* msg)
{
	self->SetMessage(*msg);
}
	
EWXWEXPORT(void,wxDirDialog_SetPath)(wxDirDialog* self,wxString* pth)
{
	self->SetPath(*pth);
}
	
EWXWEXPORT(void,wxDirDialog_SetStyle)(wxDirDialog* self,int style)
{
#if WXWIN_COMPATIBILITY_2_6
	self->SetStyle((long)style);
#endif
}
	
EWXWEXPORT(wxString*,wxDirDialog_GetMessage)(wxDirDialog* self)
{
  return new wxString(self->GetMessage());
}
	
EWXWEXPORT(wxString*,wxDirDialog_GetPath)(wxDirDialog* self)
{
  return new wxString(self->GetPath());
}
	
EWXWEXPORT(long,wxDirDialog_GetStyle)(wxDirDialog* self)
{
#if WXWIN_COMPATIBILITY_2_6
	return self->GetStyle();
#else
  return 0;
#endif
}
	
}
