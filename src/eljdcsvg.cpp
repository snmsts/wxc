#include "wrapper.h"

#ifdef wxUSE_SVG

extern "C"
{

EWXWEXPORT(wxSVGFileDC*,wxSVGFileDC_Create)(wxString* a_filename)
{
	return new wxSVGFileDC(a_filename);
}

EWXWEXPORT(wxSVGFileDC*,wxSVGFileDC_CreateWithSize)(wxString* a_filename,int a_width,int a_height)
{
	return new wxSVGFileDC(*a_filename, a_width, a_height);
}

EWXWEXPORT(wxSVGFileDC*,wxSVGFileDC_CreateWithSizeAndResolution)(wxString* a_filename,int a_width,int a_height,float a_dpi)
{
	return new wxSVGFileDC(*a_filename, a_width, a_height, a_dpi);
}

EWXWEXPORT(void,wxSVGFileDC_Delete)(wxSVGFileDC* self)
{
	delete self;
}

}
#endif
