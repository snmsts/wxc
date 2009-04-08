#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxStatusBar_Create)(wxWindow* _prt,int _id,int _stl)
{
#if wxVERSION_NUMBER >= 2400
	return (void*)new wxStatusBar (_prt, _id, _stl);
#else
	return (void*)new wxStatusBar (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
#endif
}

EWXWEXPORT(void,wxStatusBar_SetFieldsCount)(wxStatusBar* self,int number,int* widths)
{
	self->SetFieldsCount(number, widths);
}
	
EWXWEXPORT(int,wxStatusBar_GetFieldsCount)(wxStatusBar* self)
{
	return self->GetFieldsCount();
}
	
EWXWEXPORT(void,wxStatusBar_SetStatusText)(wxStatusBar* self,wxString* text,int number)
{
	self->SetStatusText(*text, number);
}
	
EWXWEXPORT(wxString*,wxStatusBar_GetStatusText)(wxStatusBar* self,int number)
{
  return new wxString(self->GetStatusText(number));
}
	
EWXWEXPORT(void,wxStatusBar_SetStatusWidths)(wxStatusBar* self,int n,int* widths)
{
	self->SetStatusWidths(n, widths);
}

/*	
EWXWEXPORT(int,wxStatusBar_GetFieldRect)(wxStatusBar* self,int i,wxRect& rect)
{
	return (int)self->GetFieldRect(int i, wxRect& rect);
}
*/
	
EWXWEXPORT(void,wxStatusBar_SetMinHeight)(wxStatusBar* self,int height)
{
	self->SetMinHeight(height);
}
	
EWXWEXPORT(int,wxStatusBar_GetBorderX)(wxStatusBar* self)
{
	return self->GetBorderX();
}
	
EWXWEXPORT(int,wxStatusBar_GetBorderY)(wxStatusBar* self)
{
	return self->GetBorderY();
}
	
}
