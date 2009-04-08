#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxMessageDialog_Create)(wxWindow* _prt,wxString* _msg,wxString* _cap,int _stl)
{
	return (void*)new wxMessageDialog(_prt,*_msg,*_cap, (long)_stl);
}

EWXWEXPORT(void,wxMessageDialog_Delete)(void* self)
{
	delete (wxMessageDialog*)self;
}

EWXWEXPORT(int,wxMessageDialog_ShowModal)(void* self)
{
	return ((wxMessageDialog*)self)->ShowModal();
}
EWXWEXPORT(int,wxcMessageBox)(wxString* message,wxString* caption,int style,wxWindow* parent,int x,int y)
{
  return ::wxMessageBox(*message,*caption,style,parent,x,y);
}
}
