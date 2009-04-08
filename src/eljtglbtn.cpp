#include "wrapper.h"
#if wxVERSION_NUMBER >= 2400

extern "C"
{

EWXWEXPORT(void*,wxToggleButton_Create)(wxWindow* parent,int id,wxString* label,int style)
{
	return (void*)new wxToggleButton(parent, (wxWindowID)id,*label, wxDefaultPosition, wxDefaultSize, (long)style);
}
	
EWXWEXPORT(void,wxToggleButton_SetValue)(void* self,bool state)
{
	((wxToggleButton*)self)->SetValue(state);
}
	
EWXWEXPORT(int,wxToggleButton_GetValue)(void* self)
{
	return (int)((wxToggleButton*)self)->GetValue();
}
	
EWXWEXPORT(void,wxToggleButton_SetLabel)(void* self,wxString* label)
{
	((wxToggleButton*)self)->SetLabel(*label);
}
	
EWXWEXPORT(int,wxToggleButton_Enable)(void* self,bool enable)
{
	return (int)((wxToggleButton*)self)->Enable(enable);
}

EWXWCONSTANTINT(EVT_COMMAND_TOGGLEBUTTON_CLICKED,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED)
}
#endif
