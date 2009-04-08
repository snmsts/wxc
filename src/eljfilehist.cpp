#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxFileHistory_Create)(int maxFiles)
{
	return (void*)new wxFileHistory(maxFiles);
}
	
EWXWEXPORT(void,wxFileHistory_Delete)(void* self)
{
	delete (wxFileHistory*)self;
}
	
EWXWEXPORT(void,wxFileHistory_AddFileToHistory)(void* self,void* file)
{
	((wxFileHistory*)self)->AddFileToHistory((const wxChar*)file);
}
	
EWXWEXPORT(void,wxFileHistory_RemoveFileFromHistory)(void* self,int i)
{
	((wxFileHistory*)self)->RemoveFileFromHistory(i);
}
	
EWXWEXPORT(int,wxFileHistory_GetMaxFiles)(void* self)
{
	return ((wxFileHistory*)self)->GetMaxFiles();
}
	
EWXWEXPORT(void,wxFileHistory_UseMenu)(void* self,wxMenu* menu)
{
	((wxFileHistory*)self)->UseMenu(menu);
}
	
EWXWEXPORT(void,wxFileHistory_RemoveMenu)(void* self,wxMenu* menu)
{
	((wxFileHistory*)self)->RemoveMenu(menu);
}
	
EWXWEXPORT(void,wxFileHistory_Load)(void* self,wxConfigBase* config)
{
	((wxFileHistory*)self)->Load(*config);
}
	
EWXWEXPORT(void,wxFileHistory_Save)(void* self,wxConfigBase* config)
{
	((wxFileHistory*)self)->Save(*config);
}
	
EWXWEXPORT(void,wxFileHistory_AddFilesToMenu)(void* self,wxMenu* menu)
{
	if (menu)
		((wxFileHistory*)self)->AddFilesToMenu(menu);
	else
		((wxFileHistory*)self)->AddFilesToMenu();
}
	
EWXWEXPORT(wxString*,wxFileHistory_GetHistoryFile)(void* self,int i)
{
  return new wxString(((wxFileHistory*)self)->GetHistoryFile(i));
}
	
EWXWEXPORT(int,wxFileHistory_GetCount)(void* self)
{
#if (wxVERSION_NUMBER <= 2600)
	return ((wxFileHistory*)self)->GetNoHistoryFiles();
#else
	return ((wxFileHistory*)self)->GetCount();
#endif
}
	
EWXWEXPORT(int,wxFileHistory_GetMenus)(void* self,void* _ref)
{
	wxList lst = ((wxFileHistory*)self)->GetMenus();
	if (_ref)
	{
		for (unsigned int i = 0; i < lst.GetCount(); i++)
			((void**)_ref)[i] = (void*)lst.Item(i);
	}
	
	return lst.GetCount();
}
	
}
