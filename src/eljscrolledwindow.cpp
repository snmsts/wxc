#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxScrolledWindow_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxScrolledWindow (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(void,wxScrolledWindow_SetTargetWindow)(void* self,wxWindow* target)
{
	((wxScrolledWindow*)self)->SetTargetWindow(target);
}
	
EWXWEXPORT(void*,wxScrolledWindow_GetTargetWindow)(void* self)
{
	return (void*)((wxScrolledWindow*)self)->GetTargetWindow();
}
	
EWXWEXPORT(void,wxScrolledWindow_SetScrollbars)(void* self,int pixelsPerUnitX,int pixelsPerUnitY,int noUnitsX,int noUnitsY,int xPos,int yPos,bool noRefresh)
{
	((wxScrolledWindow*)self)->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY, xPos, yPos, noRefresh);
}
	
EWXWEXPORT(void,wxScrolledWindow_Scroll)(void* self,int x_pos,int y_pos)
{
	((wxScrolledWindow*)self)->Scroll(x_pos, y_pos);
}
	
EWXWEXPORT(int,wxScrolledWindow_GetScrollPageSize)(void* self,int orient)
{
	return ((wxScrolledWindow*)self)->GetScrollPageSize(orient);
}
	
EWXWEXPORT(void,wxScrolledWindow_SetScrollPageSize)(void* self,int orient,int pageSize)
{
	((wxScrolledWindow*)self)->SetScrollPageSize(orient, pageSize);
}
	
EWXWEXPORT(void,wxScrolledWindow_GetScrollPixelsPerUnit)(void* self,int* x_unit,int* y_unit)
{
	((wxScrolledWindow*)self)->GetScrollPixelsPerUnit(x_unit,y_unit);
}
	
EWXWEXPORT(void,wxScrolledWindow_EnableScrolling)(void* self,bool x_scrolling,bool y_scrolling)
{
	((wxScrolledWindow*)self)->EnableScrolling(x_scrolling, y_scrolling);
}
	
EWXWEXPORT(void,wxScrolledWindow_GetViewStart)(void* self,int* x,int* y)
{
	((wxScrolledWindow*)self)->GetViewStart(x,y);
}
	
EWXWEXPORT(void,wxScrolledWindow_ViewStart)(void* self,int* x,int* y)
{
	((wxScrolledWindow*)self)->GetViewStart(x,y);
}
	
EWXWEXPORT(void,wxScrolledWindow_GetVirtualSize)(void* self,int* x,int* y)
{
	((wxScrolledWindow*)self)->GetVirtualSize(x,y);
}
	
EWXWEXPORT(void,wxScrolledWindow_SetScale)(void* self,double xs,double ys)
{
	((wxScrolledWindow*)self)->SetScale(xs, ys);
}
	
EWXWEXPORT(double,wxScrolledWindow_GetScaleX)(void* self)
{
	return ((wxScrolledWindow*)self)->GetScaleX();
}
	
EWXWEXPORT(double,wxScrolledWindow_GetScaleY)(void* self)
{
	return ((wxScrolledWindow*)self)->GetScaleY();
}
	
EWXWEXPORT(void,wxScrolledWindow_CalcScrolledPosition)(void* self,int x,int y,int* xx,int* yy)
{
	((wxScrolledWindow*)self)->CalcScrolledPosition(x, y, xx, yy);
}
	
EWXWEXPORT(void,wxScrolledWindow_CalcUnscrolledPosition)(void* self,int x,int y,int* xx,int* yy)
{
	((wxScrolledWindow*)self)->CalcUnscrolledPosition(x, y, xx, yy);
}
	
EWXWEXPORT(void,wxScrolledWindow_AdjustScrollbars)(void* self)
{
	((wxScrolledWindow*)self)->AdjustScrollbars();
}
	
EWXWEXPORT(void,wxScrolledWindow_OnDraw)(void* self,wxDC* dc)
{
	((wxScrolledWindow*)self)->OnDraw(*dc);
}
	
EWXWEXPORT(void,wxScrolledWindow_PrepareDC)(void* self,wxDC* dc)
{
	((wxScrolledWindow*)self)->PrepareDC(*dc);
}

}
