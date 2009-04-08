#include "wrapper.h"
#if wxVERSION_NUMBER >= 2400

extern "C"
{

EWXWEXPORT(void*,wxTipWindow_Create)(wxWindow* parent,wxString* text,int maxLength)
{
	return (void*)new wxTipWindow(parent,*text, (wxCoord)maxLength);
}
	
EWXWEXPORT(void,wxTipWindow_SetTipWindowPtr)(void* self,void* windowPtr)
{
	((wxTipWindow*)self)->SetTipWindowPtr((wxTipWindow**)windowPtr);
}
	
EWXWEXPORT(void,wxTipWindow_SetBoundingRect)(void* self,int x,int y,int w,int h)
{
	((wxTipWindow*)self)->SetBoundingRect(wxRect(x, y, w, h));
}
	
EWXWEXPORT(void,wxTipWindow_Close)(void* self)
{
	((wxTipWindow*)self)->Close();
}

}
#endif
