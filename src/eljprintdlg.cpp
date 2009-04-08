#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxPrintDialog_Create)(wxWindow* parent,void* data)
{
    return (void*)new wxPrintDialog(parent, (wxPrintDialogData*)data);
}

EWXWEXPORT(void,wxPrintDialog_GetPrintData)(void* self,void* _ref)
{
	*((wxPrintData*)_ref) = ((wxPrintDialog*)self)->GetPrintData();
}

	
EWXWEXPORT(void*,wxPrintDialog_GetPrintDC)(void* self)
{
	return (void*)((wxPrintDialog*)self)->GetPrintDC();
}
	
EWXWEXPORT(void*,wxPageSetupDialog_Create)(wxWindow* parent,void* data)
{
    return (void*)new wxPageSetupDialog(parent, (wxPageSetupData*)data);
}

EWXWEXPORT(void,wxPageSetupDialog_GetPageSetupData)(void* self,void* _ref)
{
	*((wxPageSetupData*)_ref) = ((wxPageSetupDialog*)self)->GetPageSetupData();
}
	
EWXWEXPORT(void*,wxPageSetupDialogData_Create)()
{
    return (void*)new wxPageSetupDialogData();
}

EWXWEXPORT(void*,wxPageSetupDialogData_CreateFromData)(void* printData)
{
    return (void*)new wxPageSetupDialogData(*((wxPrintData*)printData));
}

EWXWEXPORT(void,wxPageSetupDialogData_Delete)(void* self)
{
    delete (wxPageSetupDialogData*)self;
}

EWXWEXPORT(wxSize*,wxPageSetupDialogData_GetPaperSize)(void* self)
{
  return new wxSize(((wxPageSetupDialogData*)self)->GetPaperSize());
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetPaperId)(wxPageSetupDialogData* self)
{
	return (int)self->GetPaperId();
}
	
EWXWEXPORT(wxPoint*,wxPageSetupDialogData_GetMinMarginTopLeft)(void* self)
{
  return new wxPoint(((wxPageSetupDialogData*)self)->GetMinMarginTopLeft());
}
	
EWXWEXPORT(wxPoint*,wxPageSetupDialogData_GetMinMarginBottomRight)(void* self)
{
  return new wxPoint(((wxPageSetupDialogData*)self)->GetMinMarginBottomRight());
}
	
EWXWEXPORT(wxPoint*,wxPageSetupDialogData_GetMarginTopLeft)(void* self)
{
  return new wxPoint(((wxPageSetupDialogData*)self)->GetMarginTopLeft());
}
	
EWXWEXPORT(wxPoint*,wxPageSetupDialogData_GetMarginBottomRight)(void* self)
{
  return new wxPoint(((wxPageSetupDialogData*)self)->GetMarginBottomRight());
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetDefaultMinMargins)(wxPageSetupDialogData* self)
{
	return (int)self->GetDefaultMinMargins();
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetEnableMargins)(wxPageSetupDialogData* self)
{
	return (int)self->GetEnableMargins();
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetEnableOrientation)(wxPageSetupDialogData* self)
{
	return (int)self->GetEnableOrientation();
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetEnablePaper)(wxPageSetupDialogData* self)
{
	return (int)self->GetEnablePaper();
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetEnablePrinter)(wxPageSetupDialogData* self)
{
	return (int)self->GetEnablePrinter();
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetDefaultInfo)(wxPageSetupDialogData* self)
{
	return (int)self->GetDefaultInfo();
}
	
EWXWEXPORT(int,wxPageSetupDialogData_GetEnableHelp)(wxPageSetupDialogData* self)
{
	return (int)self->GetEnableHelp();
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetPaperSize)(void* self,int w,int h)
{
	((wxPageSetupDialogData*)self)->SetPaperSize(wxSize(w, h));
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetPaperId)(void* self,void* id)
{
	((wxPageSetupDialogData*)self)->SetPaperId(*((wxPaperSize*)id));
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetPaperSizeId)(void* self,int id)
{
	((wxPageSetupDialogData*)self)->SetPaperSize((wxPaperSize)id);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetMinMarginTopLeft)(void* self,int x,int y)
{
	((wxPageSetupDialogData*)self)->SetMinMarginTopLeft(wxPoint(x, y));
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetMinMarginBottomRight)(void* self,int x,int y)
{
	((wxPageSetupDialogData*)self)->SetMinMarginBottomRight(wxPoint(x, y));
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetMarginTopLeft)(void* self,int x,int y)
{
	((wxPageSetupDialogData*)self)->SetMarginTopLeft(wxPoint(x, y));
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetMarginBottomRight)(void* self,int x,int y)
{
	((wxPageSetupDialogData*)self)->SetMarginBottomRight(wxPoint(x, y));
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetDefaultMinMargins)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->SetDefaultMinMargins(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetDefaultInfo)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->SetDefaultInfo(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_EnableMargins)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->EnableMargins(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_EnableOrientation)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->EnableOrientation(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_EnablePaper)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->EnablePaper(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_EnablePrinter)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->EnablePrinter(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_EnableHelp)(void* self,bool flag)
{
	((wxPageSetupDialogData*)self)->EnableHelp(flag);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_CalculateIdFromPaperSize)(void* self)
{
	((wxPageSetupDialogData*)self)->CalculateIdFromPaperSize();
}
	
EWXWEXPORT(void,wxPageSetupDialogData_CalculatePaperSizeFromId)(void* self)
{
	((wxPageSetupDialogData*)self)->CalculatePaperSizeFromId();
}
	
EWXWEXPORT(void,wxPageSetupDialogData_Assign)(void* self,void* data)
{
	*((wxPageSetupDialogData*)self) = *((wxPageSetupDialogData*)data);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_AssignData)(void* self,void* data)
{
	*((wxPageSetupDialogData*)self) = *((wxPrintData*)data);
}
	
EWXWEXPORT(void,wxPageSetupDialogData_GetPrintData)(void* self,void* _ref)
{
	*((wxPrintData*)_ref) = ((wxPageSetupDialogData*)self)->GetPrintData();
}
	
EWXWEXPORT(void,wxPageSetupDialogData_SetPrintData)(void* self,void* printData)
{
	((wxPageSetupDialogData*)self)->SetPrintData(*((wxPrintData*)printData));
}
	
}
