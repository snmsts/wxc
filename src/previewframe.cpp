#include "wrapper.h"

/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/
extern "C" {

/*-----------------------------------------------------------------------------
  PreviewFrame
-----------------------------------------------------------------------------*/
EWXWEXPORT(wxPreviewFrame*,wxPreviewFrame_Create)(wxPrintPreview* preview,wxFrame* parent,wxString* title,int style,wxString* name)
{
  return new wxPreviewFrame( preview, parent,*title, wxDefaultPosition, wxDefaultSize, style,*name );
}

EWXWEXPORT(void,wxPreviewFrame_Delete)(wxPreviewFrame* self)
{
  if (self) delete self;
}

EWXWEXPORT(void,wxPreviewFrame_Initialize)(wxPreviewFrame* self)
{
  self->Initialize();
}


}
