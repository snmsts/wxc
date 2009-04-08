#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxSashWindow_Create)(wxWindow* _par,int _id,int _stl)
{
	return (void*)new wxSashWindow (_par, _id, wxDefaultPosition, wxDefaultSize, (long)_stl);
}

EWXWEXPORT(void,wxSashWindow_SetSashVisible)(void* self,int edge,bool sash)
{
	((wxSashWindow*)self)->SetSashVisible((wxSashEdgePosition)edge, sash);
}
	
EWXWEXPORT(bool,wxSashWindow_GetSashVisible)(wxSashWindow* self,int edge)
{
	return self->GetSashVisible((wxSashEdgePosition)edge);
}
	
EWXWEXPORT(void,wxSashWindow_SetSashBorder)(void* self,int edge,bool border)
{
#if WXWIN_COMPATIBILITY_2_6
	((wxSashWindow*)self)->SetSashBorder((wxSashEdgePosition)edge, border);
#endif
}
	
EWXWEXPORT(bool,wxSashWindow_HasBorder)(wxSashWindow* self,int edge)
{
#if WXWIN_COMPATIBILITY_2_6
	return self->HasBorder((wxSashEdgePosition)edge);
#else
  return FALSE;
#endif
}
	
EWXWEXPORT(int,wxSashWindow_GetEdgeMargin)(void* self,int edge)
{
	return ((wxSashWindow*)self)->GetEdgeMargin((wxSashEdgePosition)edge);
}
	
EWXWEXPORT(void,wxSashWindow_SetDefaultBorderSize)(void* self,int width)
{
	((wxSashWindow*)self)->SetDefaultBorderSize(width);
}
	
EWXWEXPORT(int,wxSashWindow_GetDefaultBorderSize)(void* self)
{
	return ((wxSashWindow*)self)->GetDefaultBorderSize();
}
	
EWXWEXPORT(void,wxSashWindow_SetExtraBorderSize)(void* self,int width)
{
	((wxSashWindow*)self)->SetExtraBorderSize(width);
}
	
EWXWEXPORT(int,wxSashWindow_GetExtraBorderSize)(void* self)
{
	return ((wxSashWindow*)self)->GetExtraBorderSize();
}
	
EWXWEXPORT(void,wxSashWindow_SetMinimumSizeX)(void* self,int min)
{
	((wxSashWindow*)self)->SetMinimumSizeX(min);
}
	
EWXWEXPORT(void,wxSashWindow_SetMinimumSizeY)(void* self,int min)
{
	((wxSashWindow*)self)->SetMinimumSizeY(min);
}
	
EWXWEXPORT(int,wxSashWindow_GetMinimumSizeX)(void* self)
{
	return ((wxSashWindow*)self)->GetMinimumSizeX();
}
	
EWXWEXPORT(int,wxSashWindow_GetMinimumSizeY)(void* self)
{
	return ((wxSashWindow*)self)->GetMinimumSizeY();
}
	
EWXWEXPORT(void,wxSashWindow_SetMaximumSizeX)(void* self,int max)
{
	((wxSashWindow*)self)->SetMaximumSizeX(max);
}
	
EWXWEXPORT(void,wxSashWindow_SetMaximumSizeY)(void* self,int max)
{
	((wxSashWindow*)self)->SetMaximumSizeY(max);
}
	
EWXWEXPORT(int,wxSashWindow_GetMaximumSizeX)(void* self)
{
	return ((wxSashWindow*)self)->GetMaximumSizeX();
}
	
EWXWEXPORT(int,wxSashWindow_GetMaximumSizeY)(void* self)
{
	return ((wxSashWindow*)self)->GetMaximumSizeY();
}


EWXWEXPORT(void*,wxSashEvent_Create)(int id,int edge)
{
	return (void*)new wxSashEvent(id, (wxSashEdgePosition)edge);
}

EWXWEXPORT(void,wxSashEvent_SetEdge)(void* self,int edge)
{
	((wxSashEvent*)self)->SetEdge((wxSashEdgePosition)edge);
}
	
EWXWEXPORT(int,wxSashEvent_GetEdge)(wxSashEvent* self)
{
	return (int)self->GetEdge();
}
	
EWXWEXPORT(void,wxSashEvent_SetDragRect)(void* self,int x,int y,int w,int h)
{
	((wxSashEvent*)self)->SetDragRect(wxRect (x, y , w, h));
}
	
EWXWEXPORT(wxRect*,wxSashEvent_GetDragRect)(void* self)
{
  return new wxRect(((wxSashEvent*)self)->GetDragRect());
}
	
EWXWEXPORT(void,wxSashEvent_SetDragStatus)(void* self,int status)
{
	((wxSashEvent*)self)->SetDragStatus((wxSashDragStatus)status);
}
	
EWXWEXPORT(int,wxSashEvent_GetDragStatus)(wxSashEvent* self)
{
	return (int)self->GetDragStatus();
}
	

EWXWEXPORT(void*,wxSashLayoutWindow_Create)(wxWindow* _par,int _id,int _stl)
{
	return (void*)new wxSashLayoutWindow (_par, _id, wxDefaultPosition, wxDefaultSize, (long)_stl);
}

EWXWEXPORT(int,wxSashLayoutWindow_GetAlignment)(wxSashLayoutWindow* self)
{
	return (int)self->GetAlignment();
}
	
EWXWEXPORT(int,wxSashLayoutWindow_GetOrientation)(wxSashLayoutWindow* self)
{
	return (int)self->GetOrientation();
}
	
EWXWEXPORT(void,wxSashLayoutWindow_SetAlignment)(void* self,int align)
{
	((wxSashLayoutWindow*)self)->SetAlignment((wxLayoutAlignment)align);
}
	
EWXWEXPORT(void,wxSashLayoutWindow_SetOrientation)(void* self,int orient)
{
	((wxSashLayoutWindow*)self)->SetOrientation((wxLayoutOrientation)orient);
}
	
EWXWEXPORT(void,wxSashLayoutWindow_SetDefaultSize)(void* self,int w,int h)
{
	((wxSashLayoutWindow*)self)->SetDefaultSize(wxSize(w, h));
}
	

EWXWEXPORT(void*,wxQueryLayoutInfoEvent_Create)(int id)
{
	return (void*)new wxQueryLayoutInfoEvent(id);
}

EWXWEXPORT(void,wxQueryLayoutInfoEvent_SetRequestedLength)(void* self,int length)
{
	((wxQueryLayoutInfoEvent*)self)->SetRequestedLength(length);
}
	
EWXWEXPORT(int,wxQueryLayoutInfoEvent_GetRequestedLength)(void* self)
{
	return ((wxQueryLayoutInfoEvent*)self)->GetRequestedLength();
}
	
EWXWEXPORT(void,wxQueryLayoutInfoEvent_SetFlags)(void* self,int flags)
{
	((wxQueryLayoutInfoEvent*)self)->SetFlags(flags);
}
	
EWXWEXPORT(int,wxQueryLayoutInfoEvent_GetFlags)(void* self)
{
	return ((wxQueryLayoutInfoEvent*)self)->GetFlags();
}
	
EWXWEXPORT(void,wxQueryLayoutInfoEvent_SetSize)(void* self,int w,int h)
{
	((wxQueryLayoutInfoEvent*)self)->SetSize(wxSize(w, h));
}
	
EWXWEXPORT(wxSize*,wxQueryLayoutInfoEvent_GetSize)(void* self)
{
  return new wxSize(((wxQueryLayoutInfoEvent*)self)->GetSize());
}
	
EWXWEXPORT(void,wxQueryLayoutInfoEvent_SetOrientation)(void* self,int orient)
{
	((wxQueryLayoutInfoEvent*)self)->SetOrientation((wxLayoutOrientation)orient);
}
	
EWXWEXPORT(int,wxQueryLayoutInfoEvent_GetOrientation)(wxQueryLayoutInfoEvent* self)
{
	return (int)self->GetOrientation();
}
	
EWXWEXPORT(void,wxQueryLayoutInfoEvent_SetAlignment)(void* self,int align)
{
	((wxQueryLayoutInfoEvent*)self)->SetAlignment((wxLayoutAlignment)align);
}
	
EWXWEXPORT(int,wxQueryLayoutInfoEvent_GetAlignment)(wxQueryLayoutInfoEvent* self)
{
	return (int)self->GetAlignment();
}
	

EWXWEXPORT(void*,wxCalculateLayoutEvent_Create)(int id)
{
	return (void*)new wxCalculateLayoutEvent(id);
}

EWXWEXPORT(void,wxCalculateLayoutEvent_SetFlags)(void* self,int flags)
{
	((wxCalculateLayoutEvent*)self)->SetFlags(flags);
}
	
EWXWEXPORT(int,wxCalculateLayoutEvent_GetFlags)(void* self)
{
	return ((wxCalculateLayoutEvent*)self)->GetFlags();
}
	
EWXWEXPORT(void,wxCalculateLayoutEvent_SetRect)(void* self,int x,int y,int w,int h)
{
	((wxCalculateLayoutEvent*)self)->SetRect(wxRect(x, y, w, h));
}
	
EWXWEXPORT(wxRect*,wxCalculateLayoutEvent_GetRect)(void* self)
{
  return new wxRect(((wxCalculateLayoutEvent*)self)->GetRect());
}

EWXWEXPORT(void*,wxLayoutAlgorithm_Create)()
{
	return (void*)new wxLayoutAlgorithm();
}

EWXWEXPORT(void,wxLayoutAlgorithm_Delete)(void* self)
{
	delete (wxLayoutAlgorithm*)self;
}

EWXWEXPORT(bool,wxLayoutAlgorithm_LayoutMDIFrame)(wxLayoutAlgorithm* self,wxMDIParentFrame* frame,int x,int y,int w,int h,int use)
{
	wxRect* r = NULL;
	if (use) r = new wxRect(x, y, w, h);
	
	bool result = self->LayoutMDIFrame(frame, r);
	
	if (r) delete r;
	return result;
}
	
EWXWEXPORT(bool,wxLayoutAlgorithm_LayoutFrame)(wxLayoutAlgorithm* self,wxFrame* frame,wxWindow* mainWindow)
{
	return self->LayoutFrame(frame, mainWindow);
}
	
EWXWEXPORT(bool,wxLayoutAlgorithm_LayoutWindow)(wxLayoutAlgorithm* self,wxFrame* frame,wxWindow* mainWindow)
{
	return self->LayoutWindow(frame, mainWindow);
}
	
}
