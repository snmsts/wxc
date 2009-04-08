#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxLocale_Create)(int _lang,int _flags)
{
	return (void*)new wxLocale(_lang, _flags);
}

EWXWEXPORT(void,wxLocale_Delete)(void* self)
{
	delete (wxLocale*)self;
}

EWXWEXPORT(bool,wxLocale_IsOk)(wxLocale* self)
{
	return self->IsOk();
}
	
EWXWEXPORT(void*,wxLocale_GetLocale)(void* self)
{
	return (void*)((wxLocale*)self)->GetLocale();
}
	
EWXWEXPORT(void,wxLocale_AddCatalogLookupPathPrefix)(void* self,void* prefix)
{
	((wxLocale*)self)->AddCatalogLookupPathPrefix((const wxChar*)prefix);
}
	
EWXWEXPORT(bool,wxLocale_AddCatalog)(wxLocale* self,void* szDomain)
{
	return self->AddCatalog((const wxChar*)szDomain);
}
	
EWXWEXPORT(bool,wxLocale_IsLoaded)(wxLocale* self,void* szDomain)
{
	return self->IsLoaded((const wxChar*)szDomain);
}
	
EWXWEXPORT(void*,wxLocale_GetString)(void* self,void* szOrigString,void* szDomain)
{
	return (void*)((wxLocale*)self)->GetString((const wxChar*)szOrigString, (const wxChar*)szDomain);
}
	
EWXWEXPORT(wxString*,wxLocale_GetName)(void* self)
{
  return new wxString(((wxLocale*)self)->GetName());
}
	

EWXWEXPORT(void*,wxGetELJLocale)()
{
	return (void*)wxGetLocale();
}
	
EWXWEXPORT(void*,wxGetELJTranslation)(void* sz)
{
	return (void*)wxGetTranslation((const wxChar*)sz);
}
	
}
