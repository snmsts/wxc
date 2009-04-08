#include "wrapper.h"

extern "C"
{

typedef int (*TGetPlotInt)(void* _obj);
typedef double (*TGetPlotDouble)(void* _obj, int _x);

}

class ELJPlotCurve : public wxPlotCurve
{
	private:
		void* EiffelObject;
		TGetPlotInt EGetStartX;
		TGetPlotInt EGetEndX;
		TGetPlotDouble EGetY;
	public:
		ELJPlotCurve(void* _obj, void* _str, void* _end, void* _y, int offsetY, double startY, double endY) : wxPlotCurve(offsetY, startY, endY)
		{
			EiffelObject = _obj;
			EGetStartX = (TGetPlotInt)_str;
			EGetEndX = (TGetPlotInt)_end;
			EGetY = (TGetPlotDouble)_y;
		}
    virtual wxInt32 GetStartX()
	{ return (wxInt32)EGetStartX(EiffelObject); }

    virtual wxInt32 GetEndX()
	{ return (wxInt32)EGetEndX(EiffelObject); }

    virtual double GetY(wxInt32 x)
	{ return EGetY(EiffelObject, (int)x); }
};

extern "C"
{

EWXWEXPORT(void*,wxPlotWindow_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int flags)
{
    return (void*)new wxPlotWindow(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), flags);
}

EWXWEXPORT(void,wxPlotWindow_Add)(void* self,void* curve)
{
	((wxPlotWindow*)self)->Add((wxPlotCurve*)curve);
}
	
EWXWEXPORT(void,wxPlotWindow_Delete)(void* self,void* curve)
{
	((wxPlotWindow*)self)->Delete((wxPlotCurve*)curve);
}
	
EWXWEXPORT(int,wxPlotWindow_GetCount)(wxPlotWindow* self)
{
	return (int)self->GetCount();
}
	
EWXWEXPORT(void*,wxPlotWindow_GetAt)(void* self,int n)
{
	return (void*)((wxPlotWindow*)self)->GetAt((size_t)n);
}
	
EWXWEXPORT(void,wxPlotWindow_SetCurrentCurve)(void* self,void* current)
{
	((wxPlotWindow*)self)->SetCurrentCurve((wxPlotCurve*)current);
}
	
EWXWEXPORT(void*,wxPlotWindow_GetCurrentCurve)(void* self)
{
	return (void*)((wxPlotWindow*)self)->GetCurrentCurve();
}
	
EWXWEXPORT(void,wxPlotWindow_AddOnOff)(void* self,void* curve)
{
	((wxPlotWindow*)self)->Add((wxPlotOnOffCurve*)curve);
}
	
EWXWEXPORT(void,wxPlotWindow_DeleteOnOff)(void* self,void* curve)
{
	((wxPlotWindow*)self)->Delete((wxPlotOnOffCurve*)curve);
}
	
EWXWEXPORT(int,wxPlotWindow_GetOnOffCurveCount)(wxPlotWindow* self)
{
	return (int)self->GetOnOffCurveCount();
}
	
EWXWEXPORT(void*,wxPlotWindow_GetOnOffCurveAt)(void* self,int n)
{
	return (void*)((wxPlotWindow*)self)->GetOnOffCurveAt((size_t)n);
}
	
EWXWEXPORT(void,wxPlotWindow_Move)(void* self,void* curve,int pixels_up)
{
	((wxPlotWindow*)self)->Move((wxPlotCurve*)curve, pixels_up);
}
	
EWXWEXPORT(void,wxPlotWindow_Enlarge)(void* self,void* curve,double factor)
{
	((wxPlotWindow*)self)->Enlarge((wxPlotCurve*)curve, factor);
}
	
EWXWEXPORT(void,wxPlotWindow_SetUnitsPerValue)(void* self,double upv)
{
	((wxPlotWindow*)self)->SetUnitsPerValue(upv);
}
	
EWXWEXPORT(double,wxPlotWindow_GetUnitsPerValue)(void* self)
{
	return ((wxPlotWindow*)self)->GetUnitsPerValue();
}
	
EWXWEXPORT(void,wxPlotWindow_SetZoom)(void* self,double zoom)
{
	((wxPlotWindow*)self)->SetZoom(zoom);
}
	
EWXWEXPORT(double,wxPlotWindow_GetZoom)(void* self)
{
	return ((wxPlotWindow*)self)->GetZoom();
}
	
EWXWEXPORT(void,wxPlotWindow_SetScrollOnThumbRelease)(void* self,bool scrollOnThumbRelease)
{
	((wxPlotWindow*)self)->SetScrollOnThumbRelease(scrollOnThumbRelease);
}
	
EWXWEXPORT(int,wxPlotWindow_GetScrollOnThumbRelease)(wxPlotWindow* self)
{
	return (int)self->GetScrollOnThumbRelease();
}
	
EWXWEXPORT(void,wxPlotWindow_SetEnlargeAroundWindowCentre)(void* self,bool enlargeAroundWindowCentre)
{
	((wxPlotWindow*)self)->SetEnlargeAroundWindowCentre(enlargeAroundWindowCentre);
}
	
EWXWEXPORT(int,wxPlotWindow_GetEnlargeAroundWindowCentre)(wxPlotWindow* self)
{
	return (int)self->GetEnlargeAroundWindowCentre();
}
	
EWXWEXPORT(void,wxPlotWindow_RedrawEverything)(void* self)
{
	((wxPlotWindow*)self)->RedrawEverything();
}
	
EWXWEXPORT(void,wxPlotWindow_RedrawXAxis)(void* self)
{
	((wxPlotWindow*)self)->RedrawXAxis();
}
	
EWXWEXPORT(void,wxPlotWindow_RedrawYAxis)(void* self)
{
	((wxPlotWindow*)self)->RedrawYAxis();
}
	
EWXWEXPORT(void,wxPlotWindow_ResetScrollbar)(void* self)
{
	((wxPlotWindow*)self)->ResetScrollbar();
}
	

EWXWEXPORT(void*,wxPlotOnOffCurve_Create)(int offsetY)
{
	return (void*)new wxPlotOnOffCurve(offsetY);
}

EWXWEXPORT(void,wxPlotOnOffCurve_Delete)(void* self)
{
	delete (wxPlotOnOffCurve*)self;
}

EWXWEXPORT(int,wxPlotOnOffCurve_GetStartX)(wxPlotOnOffCurve* self)
{
	return (int)self->GetStartX();
}
	
EWXWEXPORT(int,wxPlotOnOffCurve_GetEndX)(wxPlotOnOffCurve* self)
{
	return (int)self->GetEndX();
}
	
EWXWEXPORT(void,wxPlotOnOffCurve_SetOffsetY)(void* self,int offsetY)
{
	((wxPlotOnOffCurve*)self)->SetOffsetY(offsetY);
}
	
EWXWEXPORT(int,wxPlotOnOffCurve_GetOffsetY)(void* self)
{
	return ((wxPlotOnOffCurve*)self)->GetOffsetY();
}
	
EWXWEXPORT(void,wxPlotOnOffCurve_Add)(void* self,int on,int off,void* clientData)
{
	((wxPlotOnOffCurve*)self)->Add((wxInt32)on, (wxInt32)off, clientData);
}
	
EWXWEXPORT(int,wxPlotOnOffCurve_GetCount)(wxPlotOnOffCurve* self)
{
	return (int)self->GetCount();
}
	
EWXWEXPORT(int,wxPlotOnOffCurve_GetOn)(wxPlotOnOffCurve* self,int index)
{
	return (int)self->GetOn((size_t)index);
}
	
EWXWEXPORT(int,wxPlotOnOffCurve_GetOff)(wxPlotOnOffCurve* self,int index)
{
	return (int)self->GetOff((size_t)index);
}
	
EWXWEXPORT(void*,wxPlotOnOffCurve_GetClientData)(void* self,int index)
{
	return (void*)((wxPlotOnOffCurve*)self)->GetClientData((size_t)index);
}
	
EWXWEXPORT(void*,wxPlotOnOffCurve_GetAt)(void* self,int index)
{
	return (void*)((wxPlotOnOffCurve*)self)->GetAt((size_t)index);
}
	
EWXWEXPORT(void,wxPlotOnOffCurve_DrawOnLine)(void* self,wxDC* dc,int y,int start,int end,void* clientData)
{
	((wxPlotOnOffCurve*)self)->DrawOnLine(*dc, (wxCoord)y, (wxCoord)start, (wxCoord)end, clientData);
}
	
EWXWEXPORT(void,wxPlotOnOffCurve_DrawOffLine)(void* self,wxDC* dc,int y,int start,int end)
{
	((wxPlotOnOffCurve*)self)->DrawOffLine(*dc, (wxCoord)y, (wxCoord)start, (wxCoord)end);
}
	

EWXWEXPORT(void*,ELJPlotCurve_Create)(void* self,void* _str,void* _end,void* _y,int offsetY,double startY,double endY)
{
	return (void*)new ELJPlotCurve(self, _str, _end, _y, offsetY, startY, endY);
}

EWXWEXPORT(void,ELJPlotCurve_Delete)(void* self)
{
	delete (ELJPlotCurve*)self;
}

EWXWEXPORT(void,ELJPlotCurve_SetStartY)(void* self,double startY)
{
	((ELJPlotCurve*)self)->SetStartY(startY);
}
	
EWXWEXPORT(double,ELJPlotCurve_GetStartY)(void* self)
{
	return ((ELJPlotCurve*)self)->GetStartY();
}
	
EWXWEXPORT(void,ELJPlotCurve_SetEndY)(void* self,double endY)
{
	((ELJPlotCurve*)self)->SetEndY(endY);
}
	
EWXWEXPORT(double,ELJPlotCurve_GetEndY)(void* self)
{
	return ((ELJPlotCurve*)self)->GetEndY();
}
	
EWXWEXPORT(void,ELJPlotCurve_SetOffsetY)(void* self,int offsetY)
{
	((ELJPlotCurve*)self)->SetOffsetY(offsetY);
}
	
EWXWEXPORT(int,ELJPlotCurve_GetOffsetY)(void* self)
{
	return ((ELJPlotCurve*)self)->GetOffsetY();
}
	
EWXWEXPORT(void,ELJPlotCurve_SetPenNormal)(void* self,void* pen)
{
	((ELJPlotCurve*)self)->SetPenNormal(*((wxPen*)pen));
}
	
EWXWEXPORT(void,ELJPlotCurve_SetPenSelected)(void* self,void* pen)
{
	((ELJPlotCurve*)self)->SetPenSelected(*((wxPen*)pen));
}
	

EWXWEXPORT(void*,wxPlotEvent_GetCurve)(void* self)
{
	return (void*)((wxPlotEvent*)self)->GetCurve();
}
	
EWXWEXPORT(double,wxPlotEvent_GetZoom)(void* self)
{
	return ((wxPlotEvent*)self)->GetZoom();
}
	
EWXWEXPORT(void,wxPlotEvent_SetZoom)(void* self,double zoom)
{
	((wxPlotEvent*)self)->SetZoom(zoom);
}
	
EWXWEXPORT(int,wxPlotEvent_GetPosition)(wxPlotEvent* self)
{
	return (int)self->GetPosition();
}
	
EWXWEXPORT(void,wxPlotEvent_SetPosition)(void* self,int pos)
{
	((wxPlotEvent*)self)->SetPosition((wxInt32)pos);
}
	
}
