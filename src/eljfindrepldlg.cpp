#include "wrapper.h"
#if wxVERSION_NUMBER >= 2400

extern "C"
{

EWXWEXPORT(wxFindReplaceData*,wxFindReplaceData_CreateDefault)()
{
	return new wxFindReplaceData();
}
	
EWXWEXPORT(wxFindReplaceData*,wxFindReplaceData_Create)(int flags)
{
	return new wxFindReplaceData((wxUint32)flags);
}

EWXWEXPORT(void,wxFindReplaceData_Delete)(wxFindReplaceData* self)
{
	delete self;
}
	
EWXWEXPORT(wxString*,wxFindReplaceData_GetFindString)(wxFindReplaceData* self)
{
  return new wxString(self->GetFindString());
}
	
EWXWEXPORT(wxString*,wxFindReplaceData_GetReplaceString)(wxFindReplaceData* self)
{
  return new wxString(self->GetFindString());
}
	
EWXWEXPORT(int,wxFindReplaceData_GetFlags)(wxFindReplaceData* self)
{
	return self->GetFlags();
}
	
EWXWEXPORT(void,wxFindReplaceData_SetFlags)(wxFindReplaceData* self,int flags)
{
	self->SetFlags((wxUint32)flags);
}
	
EWXWEXPORT(void,wxFindReplaceData_SetFindString)(wxFindReplaceData* self,wxString* str)
{
	self->SetFindString(*str);
}
	
EWXWEXPORT(void,wxFindReplaceData_SetReplaceString)(wxFindReplaceData* self,wxString* str)
{
	self->SetReplaceString(*str);
}
	

EWXWEXPORT(int,wxFindDialogEvent_GetFlags)(wxFindDialogEvent* self)
{
	return self->GetFlags();
}
	
EWXWEXPORT(wxString*,wxFindDialogEvent_GetFindString)(wxFindReplaceData* self)
{
  return new wxString(self->GetFindString());
}
	
EWXWEXPORT(wxString*,wxFindDialogEvent_GetReplaceString)(wxFindReplaceData* self)
{
  return new wxString(self->GetFindString());
}
	

EWXWEXPORT(wxFindReplaceDialog*,wxFindReplaceDialog_Create)(wxWindow* parent,wxFindReplaceData* data,wxString* title,int style)
{
	return new wxFindReplaceDialog(parent,data,*title, style);
}
	
EWXWEXPORT(void*,wxFindReplaceDialog_GetData)(wxFindReplaceDialog* self)
{
	return (void*)self->GetData();
}
	
EWXWEXPORT(void,wxFindReplaceDialog_SetData)(wxFindReplaceDialog* self,wxFindReplaceData* data)
{
	self->SetData(data);
}
	

EWXWCONSTANTINT(EVT_COMMAND_FIND,wxEVT_COMMAND_FIND)
EWXWCONSTANTINT(EVT_COMMAND_FIND_NEXT,wxEVT_COMMAND_FIND_NEXT)
EWXWCONSTANTINT(EVT_COMMAND_FIND_REPLACE,wxEVT_COMMAND_FIND_REPLACE)
EWXWCONSTANTINT(EVT_COMMAND_FIND_REPLACE_ALL,wxEVT_COMMAND_FIND_REPLACE_ALL)
EWXWCONSTANTINT(EVT_COMMAND_FIND_CLOSE,wxEVT_COMMAND_FIND_CLOSE)
}
#endif
