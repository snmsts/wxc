#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxMenuBar_Create)(int _style)
{
	return new wxMenuBar(_style);
}
	
EWXWEXPORT(void,wxMenuBar_DeletePointer)(wxMenuBar* self)
{
	delete self;
}
	
EWXWEXPORT(bool,wxMenuBar_Append)(wxMenuBar* self,wxMenu* menu,wxString* title)
{
	return self->Append(menu,*title);
}
	
EWXWEXPORT(bool,wxMenuBar_Insert)(wxMenuBar* self,int pos,wxMenu* menu,wxString* title)
{
	return self->Insert((size_t)pos,menu,*title);
}
	
EWXWEXPORT(int,wxMenuBar_GetMenuCount)(wxMenuBar* self)
{
	return self->GetMenuCount();
}
	
EWXWEXPORT(wxMenu*,wxMenuBar_GetMenu)(wxMenuBar* self,size_t pos)
{
	return self->GetMenu(pos);
}
	
EWXWEXPORT(void*,wxMenuBar_Replace)(wxMenuBar* self,int pos,wxMenu* menu,wxString* title)
{
	return (void*)self->Replace((size_t) pos, menu,*title);
}
	
EWXWEXPORT(void*,wxMenuBar_Remove)(wxMenuBar* self,int pos)
{
	return (void*)self->Remove((size_t) pos);
}
	
EWXWEXPORT(void,wxMenuBar_EnableTop)(wxMenuBar* self,int pos,bool enable)
{
	self->EnableTop((size_t) pos, enable);
}
	
EWXWEXPORT(void,wxMenuBar_SetLabelTop)(wxMenuBar* self,int pos,wxString* label)
{
	self->SetLabelTop((size_t) pos,*label);
}
	
EWXWEXPORT(wxString*,wxMenuBar_GetLabelTop)(wxMenuBar* self,int pos)
{
  return new wxString(self->GetLabelTop((size_t) pos));
}
	
EWXWEXPORT(int,wxMenuBar_FindMenuItem)(wxMenuBar* self,wxString* menuString,wxString* itemString)
{
	return self->FindMenuItem(*menuString,*itemString);
}
	
EWXWEXPORT(void*,wxMenuBar_FindItem)(wxMenuBar* self,int id)
{
	return (void*)self->FindItem(id);
}
	
EWXWEXPORT(int,wxMenuBar_FindMenu)(wxMenuBar* self,wxString* title)
{
	return self->FindMenu(*title);
}
	
EWXWEXPORT(void,wxMenuBar_EnableItem)(wxMenuBar* self,int id,bool enable)
{
	self->Enable(id, enable);
}
	
EWXWEXPORT(void,wxMenuBar_Check)(wxMenuBar* self,int id,bool check)
{
	self->Check(id, check);
}
	
EWXWEXPORT(bool,wxMenuBar_IsChecked)(wxMenuBar* self,int id)
{
	return self->IsChecked(id);
}
	
EWXWEXPORT(bool,wxMenuBar_IsEnabled)(wxMenuBar* self,int id)
{
	return self->IsEnabled(id);
}
	
EWXWEXPORT(void,wxMenuBar_SetItemLabel)(wxMenuBar* self,int id,wxString* label)
{
	self->SetLabel(id,*label);
}
	
EWXWEXPORT(wxString*,wxMenuBar_GetLabel)(wxMenuBar* self,int id)
{
  return new wxString(self->GetLabel(id));
}
	
EWXWEXPORT(void,wxMenuBar_SetHelpString)(wxMenuBar* self,int id,wxString* helpString)
{
	self->SetHelpString(id,*helpString);
}
	
EWXWEXPORT(wxString*,wxMenuBar_GetHelpString)(wxMenuBar* self,int id)
{
  return new wxString(self->GetHelpString(id));
}
	
EWXWEXPORT(void,wxMenuBar_Enable)(wxMenuBar* self,bool enable)
{
	self->Enable(enable);
}
	
EWXWEXPORT(void,wxMenuBar_SetLabel)(wxMenuBar* self,wxString* s)
{
	self->SetLabel(*s);
}
	
}
