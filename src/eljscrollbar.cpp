#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxScrollBar_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxScrollBar (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(int,wxScrollBar_GetThumbPosition)(void* self)
{
	return ((wxScrollBar*)self)->GetThumbPosition();
}
	
EWXWEXPORT(int,wxScrollBar_GetThumbSize)(void* self)
{
	return ((wxScrollBar*)self)->GetThumbSize();
}
	
EWXWEXPORT(int,wxScrollBar_GetPageSize)(void* self)
{
	return ((wxScrollBar*)self)->GetPageSize();
}
	
EWXWEXPORT(int,wxScrollBar_GetRange)(void* self)
{
	return ((wxScrollBar*)self)->GetRange();
}
	
EWXWEXPORT(void,wxScrollBar_SetThumbPosition)(void* self,int viewStart)
{
	((wxScrollBar*)self)->SetThumbPosition(viewStart);
}
	
EWXWEXPORT(void,wxScrollBar_SetScrollbar)(void* self,int position,int thumbSize,int range,int pageSize,bool refresh)
{
	((wxScrollBar*)self)->SetScrollbar(position, thumbSize, range, pageSize, refresh);
}

}
