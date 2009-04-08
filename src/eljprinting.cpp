#include "wrapper.h"



#ifndef wxUSE_POSTSCRIPT
# define wxPostScriptDC        void
#endif

extern "C"
{

EWXWEXPORT(void*,wxPrinter_Create)(void* data)
{
	return (void*)new wxPrinter((wxPrintDialogData*)data);
}

EWXWEXPORT(void,wxPrinter_Delete)(void* self)
{
	delete (wxPrinter*)self;
}

EWXWEXPORT(void*,wxPrinter_CreateAbortWindow)(void* self,wxWindow* parent,void* printout)
{
	return (void*)((wxPrinter*)self)->CreateAbortWindow(parent, (wxPrintout*)printout);
}
	
EWXWEXPORT(void,wxPrinter_ReportError)(void* self,wxWindow* parent,void* printout,wxString* message)
{
	((wxPrinter*)self)->ReportError(parent, (wxPrintout*)printout,*message);
}
	
EWXWEXPORT(void,wxPrinter_GetPrintDialogData)(void* self,void* _ref)
{
	*((wxPrintDialogData*)_ref) = ((wxPrinter*)self)->GetPrintDialogData();
}
	
EWXWEXPORT(bool,wxPrinter_GetAbort)(wxPrinter* self)
{
	return self->GetAbort();
}
	
EWXWEXPORT(int,wxPrinter_GetLastError)(void* self)
{
	return ((wxPrinter*)self)->GetLastError();
}
	
EWXWEXPORT(bool,wxPrinter_Setup)(wxPrinter* self,wxWindow* parent)
{
	return self->Setup(parent);
}
	
EWXWEXPORT(bool,wxPrinter_Print)(wxPrinter* self,wxWindow* parent,wxPrintout* printout,bool prompt)
{
	return self->Print(parent, printout, prompt);
}
	
EWXWEXPORT(void*,wxPrinter_PrintDialog)(void* self,wxWindow* parent)
{
	return (void*)((wxPrinter*)self)->PrintDialog(parent);
}
	
EWXWEXPORT(void*,ELJPrintout_Create)(void* title,void* self,void* _DoOnBeginDocument,void* _DoOnEndDocument,void* _DoOnBeginPrinting,void* _DoOnEndPrinting,void* _DoOnPreparePrinting,void* _DoOnPrintPage,void* _DoOnHasPage,void* DoOnPageInfo)
{
	return (void*)new ELJPrintout( title, self, _DoOnBeginDocument, _DoOnEndDocument, _DoOnBeginPrinting, _DoOnEndPrinting, _DoOnPreparePrinting, _DoOnPrintPage, _DoOnHasPage, DoOnPageInfo);
}
EWXWEXPORT(void,ELJPrintout_Delete)(void* self)
{
	delete (ELJPrintout*)self;
}

EWXWEXPORT(wxString*,ELJPrintout_GetTitle)(void* self)
{
	return new wxString(((ELJPrintout*)self)->GetTitle());
}
	
EWXWEXPORT(void*,ELJPrintout_GetDC)(void* self)
{
	return (void*)((ELJPrintout*)self)->GetDC();
}
	
EWXWEXPORT(void,ELJPrintout_SetDC)(void* self,wxDC* dc)
{
	((ELJPrintout*)self)->SetDC(dc);
}
	
EWXWEXPORT(void,ELJPrintout_SetPageSizePixels)(void* self,int w,int h)
{
	((ELJPrintout*)self)->SetPageSizePixels(w, h);
}
	
EWXWEXPORT(void,ELJPrintout_GetPageSizePixels)(void* self,int* w,int* h)
{
	((ELJPrintout*)self)->GetPageSizePixels(w,h);
}
	
EWXWEXPORT(void,ELJPrintout_SetPageSizeMM)(void* self,int w,int h)
{
	((ELJPrintout*)self)->SetPageSizeMM(w, h);
}
	
EWXWEXPORT(void,ELJPrintout_GetPageSizeMM)(void* self,int* w,int* h)
{
	((ELJPrintout*)self)->GetPageSizeMM(w,h);
}
	
EWXWEXPORT(void,ELJPrintout_SetPPIScreen)(void* self,int x,int y)
{
	((ELJPrintout*)self)->SetPPIScreen(x, y);
}
	
EWXWEXPORT(void,ELJPrintout_GetPPIScreen)(void* self,int* x,int* y)
{
	((ELJPrintout*)self)->GetPPIScreen(x,y);
}
	
EWXWEXPORT(void,ELJPrintout_SetPPIPrinter)(void* self,int x,int y)
{
	((ELJPrintout*)self)->SetPPIPrinter(x, y);
}
	
EWXWEXPORT(void,ELJPrintout_GetPPIPrinter)(void* self,int* x,int* y)
{
	((ELJPrintout*)self)->GetPPIPrinter(x,y);
}
	
EWXWEXPORT(bool,ELJPrintout_IsPreview)(ELJPrintout* self)
{
	return self->IsPreview();
}
	
EWXWEXPORT(void,ELJPrintout_SetIsPreview)(void* self,bool p)
{
	((ELJPrintout*)self)->SetIsPreview(p);
}

EWXWEXPORT(void*,wxPreviewCanvas_Create)(void* preview,wxWindow* parent,int style)
{
	return (void*)new wxPreviewCanvas(	(wxPrintPreviewBase*)preview,parent,
                                                 wxDefaultPosition, wxDefaultSize,
                    					(long)style);
}

EWXWEXPORT(void*,ELJPreviewFrame_Create)(void* self,void* _init,void* _create_canvas,void* _create_toolbar,void* preview,void* parent,void* title,int style)
{
    return (void*)new ELJPreviewFrame(self, _init, _create_canvas, _create_toolbar, preview, parent, title, style);
}

EWXWEXPORT(void,ELJPreviewFrame_Initialize)(void* self)
{
	((ELJPreviewFrame*)self)->Initialize();
}
	
EWXWEXPORT(void,ELJPreviewFrame_SetPreviewCanvas)(void* self,void* obj)
{
	((ELJPreviewFrame*)self)->SetPreviewCanvas (obj);
}
	
EWXWEXPORT(void,ELJPreviewFrame_SetControlBar)(void* self,void* obj)
{
	((ELJPreviewFrame*)self)->SetControlBar (obj);
}
	
EWXWEXPORT(void,ELJPreviewFrame_SetPrintPreview)(void* self,void* obj)
{
	((ELJPreviewFrame*)self)->SetPrintPreview (obj);
}
	
EWXWEXPORT(void*,ELJPreviewFrame_GetPreviewCanvas)(void* self)
{
	return (void*)((ELJPreviewFrame*)self)->GetPreviewCanvas ();
}
	
EWXWEXPORT(void*,ELJPreviewFrame_GetControlBar)(void* self)
{
	return (void*)((ELJPreviewFrame*)self)->GetControlBar ();
}
	
EWXWEXPORT(void*,ELJPreviewFrame_GetPrintPreview)(void* self)
{
	return (void*)((ELJPreviewFrame*)self)->GetPrintPreview ();
}
	
EWXWEXPORT(void*,ELJPreviewControlBar_Create)(void* preview,int buttons,wxWindow* parent,void* title,int style)
{
    return (void*)new wxPreviewControlBar((wxPrintPreviewBase*)preview, (long)buttons, parent, wxDefaultPosition, wxDefaultSize, (long)style);
}

EWXWEXPORT(void*,wxPrintPreview_CreateFromDialogData)(void* printout,void* printoutForPrinting,void* data)
{
    return (void*)new wxPrintPreview((wxPrintout*)printout, (wxPrintout*)printoutForPrinting, (wxPrintDialogData*)data);
}

EWXWEXPORT(void*,wxPrintPreview_CreateFromData)(void* printout,void* printoutForPrinting,void* data)
{
    return (void*)new wxPrintPreview((wxPrintout*)printout, (wxPrintout*)printoutForPrinting, (wxPrintData*)data);
}

EWXWEXPORT(void,wxPrintPreview_Delete)(void* self)
{
	delete (wxPrintPreview*)self;
}

EWXWEXPORT(void,wxPrintPreview_SetCurrentPage)(wxPrintPreview* self,int pageNum)
{
	self->SetCurrentPage(pageNum);
}
	
EWXWEXPORT(int,wxPrintPreview_GetCurrentPage)(void* self)
{
	return ((wxPrintPreview*)self)->GetCurrentPage();
}
	
EWXWEXPORT(void,wxPrintPreview_SetPrintout)(void* self,void* printout)
{
	((wxPrintPreview*)self)->SetPrintout((wxPrintout*)printout);
}
	
EWXWEXPORT(void*,wxPrintPreview_GetPrintout)(void* self)
{
	return (void*)((wxPrintPreview*)self)->GetPrintout();
}
	
EWXWEXPORT(void*,wxPrintPreview_GetPrintoutForPrinting)(void* self)
{
	return (void*)((wxPrintPreview*)self)->GetPrintoutForPrinting();
}
	
EWXWEXPORT(void,wxPrintPreview_SetFrame)(void* self,wxFrame* frame)
{
	((wxPrintPreview*)self)->SetFrame(frame);
}
	
EWXWEXPORT(void,wxPrintPreview_SetCanvas)(void* self,void* canvas)
{
	((wxPrintPreview*)self)->SetCanvas((wxPreviewCanvas*)canvas);
}
	
EWXWEXPORT(void*,wxPrintPreview_GetFrame)(void* self)
{
	return (void*)((wxPrintPreview*)self)->GetFrame();
}
	
EWXWEXPORT(void*,wxPrintPreview_GetCanvas)(void* self)
{
	return (void*)((wxPrintPreview*)self)->GetCanvas();
}
	
EWXWEXPORT(bool,wxPrintPreview_PaintPage)(wxPrintPreview* self,wxPreviewCanvas* canvas,wxDC* dc)
{
	return self->PaintPage(canvas,*dc);
}
	
EWXWEXPORT(int,wxPrintPreview_DrawBlankPage)(wxPrintPreview* self,wxPreviewCanvas* canvas,wxDC* dc)
{
	return (int)self->DrawBlankPage(canvas,*dc);
}
	
EWXWEXPORT(bool,wxPrintPreview_RenderPage)(wxPrintPreview* self,int pageNum)
{
	return self->RenderPage(pageNum);
}
	
EWXWEXPORT(void,wxPrintPreview_GetPrintDialogData)(void* self,void* _ref)
{
	*((wxPrintDialogData*)_ref) = ((wxPrintPreview*)self)->GetPrintDialogData();
}
	
EWXWEXPORT(void,wxPrintPreview_SetZoom)(void* self,int percent)
{
	((wxPrintPreview*)self)->SetZoom(percent);
}
	
EWXWEXPORT(int,wxPrintPreview_GetZoom)(void* self)
{
	return ((wxPrintPreview*)self)->GetZoom();
}
	
EWXWEXPORT(int,wxPrintPreview_GetMaxPage)(void* self)
{
	return ((wxPrintPreview*)self)->GetMaxPage();
}
	
EWXWEXPORT(int,wxPrintPreview_GetMinPage)(void* self)
{
	return ((wxPrintPreview*)self)->GetMinPage();
}
	
EWXWEXPORT(bool,wxPrintPreview_IsOk)(wxPrintPreview* self)
{
	return self->IsOk();
}
	
EWXWEXPORT(void,wxPrintPreview_SetOk)(void* self,bool ok)
{
	((wxPrintPreview*)self)->SetOk(ok);
}
	
EWXWEXPORT(bool,wxPrintPreview_Print)(wxPrintPreview* self,bool interactive)
{
	return self->Print(interactive);
}
	
EWXWEXPORT(void,wxPrintPreview_DetermineScaling)(void* self)
{
	((wxPrintPreview*)self)->DetermineScaling();
}
	
EWXWEXPORT(void*,wxPrintData_Create)()
{
	return (void*)new wxPrintData();
}

EWXWEXPORT(void,wxPrintData_Delete)(void* self)
{
    delete (wxPrintData*)self;
}

EWXWEXPORT(void*,wxPostScriptPrintNativeData_Create)()
{
#ifdef wxUSE_POSTSCRIPT
	return (void*)new wxPostScriptPrintNativeData();
#else
	return NULL;
#endif
}

EWXWEXPORT(void,wxPostScriptPrintNativeData_Delete)(void* self)
{
#ifdef wxUSE_POSTSCRIPT
    delete (wxPostScriptPrintNativeData*)self;
#endif
}

EWXWEXPORT(int,wxPrintData_GetNoCopies)(void* self)
{
	return ((wxPrintData*)self)->GetNoCopies();
}
	
EWXWEXPORT(bool,wxPrintData_GetCollate)(wxPrintData* self)
{
	return self->GetCollate();
}
	
EWXWEXPORT(int,wxPrintData_GetOrientation)(void* self)
{
	return ((wxPrintData*)self)->GetOrientation();
}
	
EWXWEXPORT(wxString*,wxPrintData_GetPrinterName)(void* self)
{
	return new wxString(((wxPrintData*)self)->GetPrinterName());
}
	
EWXWEXPORT(bool,wxPrintData_GetColour)(wxPrintData* self)
{
	return self->GetColour();
}
	
EWXWEXPORT(int,wxPrintData_GetDuplex)(wxPrintData* self)
{
	return (int)self->GetDuplex();
}
	
EWXWEXPORT(int,wxPrintData_GetPaperId)(wxPrintData* self)
{
	return (int)self->GetPaperId();
}
	
EWXWEXPORT(wxSize*,wxPrintData_GetPaperSize)(void* self)
{
  return new wxSize(((wxPrintData*)self)->GetPaperSize());
}
	
EWXWEXPORT(int,wxPrintData_GetQuality)(wxPrintData* self)
{
	return (int)self->GetQuality();
}
	
EWXWEXPORT(void,wxPrintData_SetNoCopies)(void* self,int v)
{
	((wxPrintData*)self)->SetNoCopies(v);
}
	
EWXWEXPORT(void,wxPrintData_SetCollate)(void* self,bool flag)
{
	((wxPrintData*)self)->SetCollate(flag);
}
	
EWXWEXPORT(void,wxPrintData_SetOrientation)(void* self,int orient)
{
	((wxPrintData*)self)->SetOrientation(orient);
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterName)(void* self,wxString* name)
{
	((wxPrintData*)self)->SetPrinterName(*name);
}
	
EWXWEXPORT(void,wxPrintData_SetColour)(void* self,bool colour)
{
	((wxPrintData*)self)->SetColour(colour);
}
	
EWXWEXPORT(void,wxPrintData_SetDuplex)(void* self,int duplex)
{
	((wxPrintData*)self)->SetDuplex((wxDuplexMode)duplex);
}
	
EWXWEXPORT(void,wxPrintData_SetPaperId)(void* self,int sizeId)
{
	((wxPrintData*)self)->SetPaperId((wxPaperSize)sizeId);
}
	
EWXWEXPORT(void,wxPrintData_SetPaperSize)(void* self,int w,int h)
{
	((wxPrintData*)self)->SetPaperSize(wxSize(w, h));
}
	
EWXWEXPORT(void,wxPrintData_SetQuality)(void* self,int quality)
{
	((wxPrintData*)self)->SetQuality((wxPrintQuality)quality);
}
	
EWXWEXPORT(wxString*,wxPrintData_GetPrinterCommand)(void* self)
{
#if wxVERSION_NUMBER < 2600 || defined (wxUSE_POSTSCRIPT)
#ifdef wxUSE_POSTSCRIPT
	wxString tmp = ((wxPostScriptPrintNativeData*)self)->GetPrinterCommand();
#else
	wxString tmp = ((wxPrintData*)self)->GetPrinterCommand();
#endif
	return new wxString(tmp);
#else
	return false;
#endif
}
	
EWXWEXPORT(wxString*,wxPrintData_GetPrinterOptions)(void* self)
{
#if wxVERSION_NUMBER < 2600 || defined (wxUSE_POSTSCRIPT)
#ifdef wxUSE_POSTSCRIPT
	wxString tmp = ((wxPostScriptPrintNativeData*)self)->GetPrinterOptions();
#else
	wxString tmp = ((wxPrintData*)self)->GetPrinterOptions();
#endif
	return new wxString(tmp);
#else
	return false;
#endif
}
	
EWXWEXPORT(wxString*,wxPrintData_GetPreviewCommand)(void* self)
{
#if wxVERSION_NUMBER < 2600 || defined (wxUSE_POSTSCRIPT)
#ifdef wxUSE_POSTSCRIPT
	wxString tmp = ((wxPostScriptPrintNativeData*)self)->GetPreviewCommand();
#else
	wxString tmp = ((wxPrintData*)self)->GetPreviewCommand();
#endif
	return new wxString(tmp);
#else
	return false;
#endif
}
	
EWXWEXPORT(wxString*,wxPrintData_GetFilename)(void* self)
{
	wxString tmp = ((wxPrintData*)self)->GetFilename();
	return new wxString(tmp);
}
	
EWXWEXPORT(wxString*,wxPrintData_GetFontMetricPath)(void* self)
{
#if wxVERSION_NUMBER < 2600 || defined (wxUSE_POSTSCRIPT)
#ifdef wxUSE_POSTSCRIPT
	wxString tmp = ((wxPostScriptPrintNativeData*)self)->GetFontMetricPath();
#else
	wxString tmp = ((wxPrintData*)self)->GetFontMetricPath();
#endif
	return new wxString(tmp);
#else
	return false;
#endif
}
	
EWXWEXPORT(double,wxPrintData_GetPrinterScaleX)(void* self)
{
#ifdef wxUSE_POSTSCRIPT
	return ((wxPostScriptPrintNativeData*)self)->GetPrinterScaleX();
#elif wxVERSION_NUMBER < 2600
	return ((wxPrintData*)self)->GetPrinterScaleX();
#else
	return false;
#endif
}
	
EWXWEXPORT(double,wxPrintData_GetPrinterScaleY)(void* self)
{
#ifdef wxUSE_POSTSCRIPT
	return ((wxPostScriptPrintNativeData*)self)->GetPrinterScaleY();
#elif wxVERSION_NUMBER < 2600
	return ((wxPrintData*)self)->GetPrinterScaleY();
#else
	return false;
#endif
}
	
EWXWEXPORT(int,wxPrintData_GetPrinterTranslateX)(void* self)
{
#ifdef wxUSE_POSTSCRIPT
	return ((wxPostScriptPrintNativeData*)self)->GetPrinterTranslateX();
#elif wxVERSION_NUMBER < 2600
	return ((wxPrintData*)self)->GetPrinterTranslateX();
#else
	return false;
#endif
}
	
EWXWEXPORT(int,wxPrintData_GetPrinterTranslateY)(void* self)
{
#ifdef wxUSE_POSTSCRIPT
	return ((wxPostScriptPrintNativeData*)self)->GetPrinterTranslateY();
#elif wxVERSION_NUMBER < 2600
	return ((wxPrintData*)self)->GetPrinterTranslateY();
#else
	return false;
#endif
}
	
EWXWEXPORT(int,wxPrintData_GetPrintMode)(wxPrintData* self)
{
	return (int)self->GetPrintMode();
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterCommand)(void* self,wxString* command)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterCommand(*command);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterCommand(*command);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterOptions)(void* self,wxString* options)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterOptions(*options);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterOptions(*options);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPreviewCommand)(void* self,wxString* command)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPreviewCommand(*command);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPreviewCommand(*command);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetFilename)(void* self,wxString* filename)
{
	((wxPrintData*)self)->SetFilename(*filename);
}
	
EWXWEXPORT(void,wxPrintData_SetFontMetricPath)(void* self,wxString* path)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetFontMetricPath(*path);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetFontMetricPath(*path);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterScaleX)(void* self,double x)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterScaleX(x);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterScaleX(x);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterScaleY)(void* self,double y)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterScaleY(y);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterScaleY(y);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterScaling)(void* self,double x,double y)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterScaling(x, y);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterScaling(x, y);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterTranslateX)(void* self,int x)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterTranslateX((int)x);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterTranslateX((int)x);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterTranslateY)(void* self,int y)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterTranslateY((int)y);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterTranslateY((long)y);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrinterTranslation)(void* self,int x,int y)
{
#ifdef wxUSE_POSTSCRIPT
	((wxPostScriptPrintNativeData*)self)->SetPrinterTranslation((long)x, (long)y);
#elif wxVERSION_NUMBER < 2600
	((wxPrintData*)self)->SetPrinterTranslation((long)x, (long)y);
#endif
}
	
EWXWEXPORT(void,wxPrintData_SetPrintMode)(void* self,int printMode)
{
	((wxPrintData*)self)->SetPrintMode((wxPrintMode)printMode);
}
	
EWXWEXPORT(void,wxPrintData_Assign)(void* self,void* data)
{
	*((wxPrintData*)self) = *((wxPrintData*)data);
}
	
EWXWEXPORT(void*,wxPrintDialogData_CreateDefault)()
{
	return (void*)new wxPrintDialogData();
}

EWXWEXPORT(void*,wxPrintDialogData_CreateFromData)(void* printData)
{
	return (void*)new wxPrintDialogData(*((wxPrintData*)printData));
}

EWXWEXPORT(void,wxPrintDialogData_Delete)(void* self)
{
	delete (wxPrintDialogData*)self;
}

EWXWEXPORT(int,wxPrintDialogData_GetFromPage)(void* self)
{
	return ((wxPrintDialogData*)self)->GetFromPage();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetToPage)(void* self)
{
	return ((wxPrintDialogData*)self)->GetToPage();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetMinPage)(void* self)
{
	return ((wxPrintDialogData*)self)->GetMinPage();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetMaxPage)(void* self)
{
	return ((wxPrintDialogData*)self)->GetMaxPage();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetNoCopies)(void* self)
{
	return ((wxPrintDialogData*)self)->GetNoCopies();
}
	
EWXWEXPORT(bool,wxPrintDialogData_GetAllPages)(wxPrintDialogData* self)
{
	return self->GetAllPages();
}
	
EWXWEXPORT(bool,wxPrintDialogData_GetSelection)(wxPrintDialogData* self)
{
	return self->GetSelection();
}
	
EWXWEXPORT(bool,wxPrintDialogData_GetCollate)(wxPrintDialogData* self)
{
	return self->GetCollate();
}
	
EWXWEXPORT(bool,wxPrintDialogData_GetPrintToFile)(wxPrintDialogData* self)
{
	return self->GetPrintToFile();
}

EWXWEXPORT(void,wxPrintDialogData_SetFromPage)(void* self,int v)
{
	((wxPrintDialogData*)self)->SetFromPage(v);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetToPage)(void* self,int v)
{
	((wxPrintDialogData*)self)->SetToPage(v);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetMinPage)(void* self,int v)
{
	((wxPrintDialogData*)self)->SetMinPage(v);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetMaxPage)(void* self,int v)
{
	((wxPrintDialogData*)self)->SetMaxPage(v);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetNoCopies)(void* self,int v)
{
	((wxPrintDialogData*)self)->SetNoCopies(v);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetAllPages)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->SetAllPages(flag);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetSelection)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->SetSelection(flag);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetCollate)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->SetCollate(flag);
}
	
EWXWEXPORT(void,wxPrintDialogData_SetPrintToFile)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->SetPrintToFile(flag);
}

EWXWEXPORT(void,wxPrintDialogData_EnablePrintToFile)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->EnablePrintToFile(flag);
}
	
EWXWEXPORT(void,wxPrintDialogData_EnableSelection)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->EnableSelection(flag);
}
	
EWXWEXPORT(void,wxPrintDialogData_EnablePageNumbers)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->EnablePageNumbers(flag);
}
	
EWXWEXPORT(void,wxPrintDialogData_EnableHelp)(void* self,bool flag)
{
	((wxPrintDialogData*)self)->EnableHelp(flag);
}
	
EWXWEXPORT(int,wxPrintDialogData_GetEnablePrintToFile)(wxPrintDialogData* self)
{
	return (int)self->GetEnablePrintToFile();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetEnableSelection)(wxPrintDialogData* self)
{
	return (int)self->GetEnableSelection();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetEnablePageNumbers)(wxPrintDialogData* self)
{
	return (int)self->GetEnablePageNumbers();
}
	
EWXWEXPORT(int,wxPrintDialogData_GetEnableHelp)(wxPrintDialogData* self)
{
	return (int)self->GetEnableHelp();
}
	
EWXWEXPORT(void,wxPrintDialogData_GetPrintData)(void* self,void* _ref)
{
	*((wxPrintData*)_ref) = ((wxPrintDialogData*)self)->GetPrintData();
}
	
EWXWEXPORT(void,wxPrintDialogData_SetPrintData)(void* self,void* printData)
{
	((wxPrintDialogData*)self)->SetPrintData(*((wxPrintData*)printData));
}
	
EWXWEXPORT(void,wxPrintDialogData_Assign)(void* self,void* data)
{
	*((wxPrintDialogData*)self) = *((wxPrintDialogData*)data);
}
	
EWXWEXPORT(void,wxPrintDialogData_AssignData)(void* self,void* data)
{
	*((wxPrintDialogData*)self) = *((wxPrintData*)data);
}
	
EWXWEXPORT(wxPostScriptDC*,wxPostScriptDC_Create)(wxPrintData* printData)
{
#ifdef wxUSE_POSTSCRIPT
	return new wxPostScriptDC(*printData);
#else
	return NULL;
#endif
}

EWXWEXPORT(void,wxPostScriptDC_Delete)(wxPostScriptDC* self)
{
#ifdef wxUSE_POSTSCRIPT
	if (self) delete self;
#endif
}

EWXWEXPORT(void,wxPostScriptDC_SetResolution)(wxPostScriptDC* self,int ppi)
{
#ifdef wxUSE_POSTSCRIPT
	self->SetResolution(ppi);
#endif
}

EWXWEXPORT(int,wxPostScriptDC_GetResolution)(wxPostScriptDC* self,int ppi)
{
#ifdef wxUSE_POSTSCRIPT
	return self->GetResolution();
#else
	return 0;
#endif
}

EWXWEXPORT(void*,wxPrinterDC_Create)(wxPrintData* printData)
{
#if defined(__WXGTK__) 
	return NULL;
#else
	return new wxPrinterDC(*printData);
#endif
}

EWXWEXPORT(void,wxPrinterDC_Delete)(void* self)
{
#if !defined(__WXGTK__)
	delete (wxPrinterDC*)self;
#endif
}

EWXWEXPORT(wxRect*,wxPrinterDC_GetPaperRect)(void* self)
{
#if !defined(__WXGTK__)
  wxRect* rct =new wxRect(((wxPrinterDC*)self)->GetPaperRect());
  return rct;
#else
  return 0;
#endif
}

}
