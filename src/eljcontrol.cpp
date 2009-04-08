#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void,wxControl_SetLabel)(wxControl* self,wxString* text)
{
	self->SetLabel(*text);
}
	
EWXWEXPORT(wxString*,wxControl_GetLabel)(wxControl* self)
{
  return new wxString(self->GetLabel());
}

EWXWEXPORT(void,wxControl_Command)(wxControl* self,wxCommandEvent* event)
{
	self->Command(*event);
}

}
