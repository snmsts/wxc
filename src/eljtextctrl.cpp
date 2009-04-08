#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxTextCtrl_Create)(wxWindow* _prt,int _id,wxString* _txt,long _stl)
{
	return (void*)new wxTextCtrl (_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _stl, wxDefaultValidator);
}

EWXWEXPORT(wxString*,wxTextCtrl_GetValue)(void* self)
{
  return new wxString(((wxTextCtrl*)self)->GetValue());
}
	
EWXWEXPORT(void,wxTextCtrl_SetValue)(void* self,wxString* value)
{
	((wxTextCtrl*)self)->SetValue(*value);
}
	
EWXWEXPORT(int,wxTextCtrl_GetLineLength)(void* self,long lineNo)
{
	return ((wxTextCtrl*)self)->GetLineLength(lineNo);
}
	
EWXWEXPORT(wxString*,wxTextCtrl_GetLineText)(void* self,long lineNo)
{
  return new wxString(((wxTextCtrl*)self)->GetLineText(lineNo));
}
	
EWXWEXPORT(int,wxTextCtrl_GetNumberOfLines)(void* self)
{
	return ((wxTextCtrl*)self)->GetNumberOfLines();
}
	
EWXWEXPORT(bool,wxTextCtrl_IsModified)(wxTextCtrl* self)
{
	return self->IsModified();
}
	
EWXWEXPORT(bool,wxTextCtrl_IsEditable)(wxTextCtrl* self)
{
	return self->IsEditable();
}
	
EWXWEXPORT(void,wxTextCtrl_GetSelection)(void* self,void* from,void* to)
{
	((wxTextCtrl*)self)->GetSelection((long*)from, (long*)to);
}
	
EWXWEXPORT(void,wxTextCtrl_Clear)(void* self)
{
	((wxTextCtrl*)self)->Clear();
}
	
EWXWEXPORT(void,wxTextCtrl_Replace)(void* self,long from,long to,wxString* value)
{
	((wxTextCtrl*)self)->Replace(from, to,*value);
}
	
EWXWEXPORT(void,wxTextCtrl_Remove)(void* self,long from,long to)
{
	((wxTextCtrl*)self)->Remove(from, to);
}
	
EWXWEXPORT(int,wxTextCtrl_LoadFile)(void* self,wxString* file)
{
	return (int)((wxTextCtrl*)self)->LoadFile(*file);
}
	
EWXWEXPORT(int,wxTextCtrl_SaveFile)(void* self,wxString* file)
{
	return (int)((wxTextCtrl*)self)->SaveFile(*file);
}
	
EWXWEXPORT(void,wxTextCtrl_DiscardEdits)(void* self)
{
	((wxTextCtrl*)self)->DiscardEdits();
}
	
EWXWEXPORT(void,wxTextCtrl_WriteText)(void* self,wxString* text)
{
	((wxTextCtrl*)self)->WriteText(*text);
}
	
EWXWEXPORT(void,wxTextCtrl_AppendText)(void* self,wxString* text)
{
	((wxTextCtrl*)self)->AppendText(*text);
}
	
EWXWEXPORT(long,wxTextCtrl_XYToPosition)(void* self,long x,long y)
{
	return ((wxTextCtrl*)self)->XYToPosition(x, y);
}
	
EWXWEXPORT(int,wxTextCtrl_PositionToXY)(void* self,long pos,long* x,long* y)
{
	return (int)((wxTextCtrl*)self)->PositionToXY(pos, x, y);
}
	
EWXWEXPORT(void,wxTextCtrl_ShowPosition)(void* self,long pos)
{
	((wxTextCtrl*)self)->ShowPosition(pos);
}
	
EWXWEXPORT(void,wxTextCtrl_Copy)(void* self)
{
	((wxTextCtrl*)self)->Copy();
}
	
EWXWEXPORT(void,wxTextCtrl_Cut)(void* self)
{
	((wxTextCtrl*)self)->Cut();
}
	
EWXWEXPORT(void,wxTextCtrl_Paste)(void* self)
{
	((wxTextCtrl*)self)->Paste();
}
	
EWXWEXPORT(bool,wxTextCtrl_CanCopy)(void* self)
{
	return ((wxTextCtrl*)self)->CanCopy();
}
	
EWXWEXPORT(bool,wxTextCtrl_CanCut)(void* self)
{
	return ((wxTextCtrl*)self)->CanCut();
}
	
EWXWEXPORT(bool,wxTextCtrl_CanPaste)(void* self)
{
	return ((wxTextCtrl*)self)->CanPaste();
}
	
EWXWEXPORT(void,wxTextCtrl_Undo)(void* self)
{
	((wxTextCtrl*)self)->Undo();
}
	
EWXWEXPORT(void,wxTextCtrl_Redo)(void* self)
{
	((wxTextCtrl*)self)->Redo();
}
	
EWXWEXPORT(bool,wxTextCtrl_CanUndo)(void* self)
{
	return ((wxTextCtrl*)self)->CanUndo();
}
	
EWXWEXPORT(bool,wxTextCtrl_CanRedo)(void* self)
{
	return ((wxTextCtrl*)self)->CanRedo();
}
	
EWXWEXPORT(void,wxTextCtrl_SetInsertionPoint)(void* self,long pos)
{
	((wxTextCtrl*)self)->SetInsertionPoint(pos);
}
	
EWXWEXPORT(void,wxTextCtrl_SetInsertionPointEnd)(void* self)
{
	((wxTextCtrl*)self)->SetInsertionPointEnd();
}
	
EWXWEXPORT(long,wxTextCtrl_GetInsertionPoint)(void* self)
{
	return ((wxTextCtrl*)self)->GetInsertionPoint();
}
	
EWXWEXPORT(long,wxTextCtrl_GetLastPosition)(void* self)
{
	return ((wxTextCtrl*)self)->GetLastPosition();
}
	
EWXWEXPORT(void,wxTextCtrl_SetSelection)(void* self,long from,long to)
{
	((wxTextCtrl*)self)->SetSelection(from, to);
}
	
EWXWEXPORT(void,wxTextCtrl_SetEditable)(void* self,bool editable)
{
	((wxTextCtrl*)self)->SetEditable(editable);
}
	
}
