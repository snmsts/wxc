#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxMimeTypesManager_Create)()
{
        return (void*)wxTheMimeTypesManager;
}

EWXWEXPORT(void*,wxMimeTypesManager_GetFileTypeFromExtension)(void* self,void* _ext)
{
        return (void*)((wxMimeTypesManager*)self)->GetFileTypeFromExtension((const wxChar*)_ext);
}

EWXWEXPORT(void*,wxMimeTypesManager_GetFileTypeFromMimeType)(void* self,void* _name)
{
        return (void*)((wxMimeTypesManager*)self)->GetFileTypeFromMimeType((const wxChar*)_name);
}

EWXWEXPORT(bool,wxMimeTypesManager_ReadMailcap)(wxMimeTypesManager* self,wxString* _file,bool _fb)
{
        return self->ReadMailcap(*_file, _fb);
}

EWXWEXPORT(bool,wxMimeTypesManager_ReadMimeTypes)(wxMimeTypesManager* self,wxString* _file)
{
        return self->ReadMimeTypes(*_file);
}

EWXWEXPORT(int,wxMimeTypesManager_EnumAllFileTypes)(wxMimeTypesManager* self,void* _lst)
{
        wxArrayString arr;
        int result = (int)self->EnumAllFileTypes(arr);

        if (_lst)
        {
                for (unsigned int i = 0; i < arr.GetCount(); i++)
                        ((const wxChar**)_lst)[i] = wxStrdup (arr.Item(i).c_str());
        }

        return result;
}

EWXWEXPORT(void,wxMimeTypesManager_AddFallbacks)(void* self,void* _types)
{
        ((wxMimeTypesManager*)self)->AddFallbacks((const wxFileTypeInfo*)_types);
}

EWXWEXPORT(bool,wxMimeTypesManager_IsOfType)(wxMimeTypesManager* self,void* _type,void* _wildcard)
{
        return self->IsOfType ((const wxChar*)_type, (const wxChar*)_wildcard);
}


EWXWEXPORT(wxString*,wxFileType_GetMimeType)(void* self)
{
  wxString *result = new wxString();
  if ((((wxFileType*)self)->GetMimeType(result))!=true)
    result->Clear();
  return result;
}

EWXWEXPORT(int,wxFileType_GetMimeTypes)(void* self,void* _lst)
{
        wxArrayString arr;

        if (((wxFileType*)self)->GetMimeTypes(arr) && _lst)
        {
                for (unsigned int i = 0; i < arr.GetCount(); i++)
                        ((const wxChar**)_lst)[i] = wxStrdup (arr.Item(i).c_str());
        }

        return arr.GetCount();
}

EWXWEXPORT(int,wxFileType_GetExtensions)(void* self,void* _lst)
{
        wxArrayString arr;

        if (((wxFileType*)self)->GetExtensions(arr) && _lst)
        {
                for (unsigned int i = 0; i < arr.GetCount(); i++)
                        ((const wxChar**)_lst)[i] = wxStrdup (arr.Item(i).c_str());
        }

        return arr.GetCount();
}

EWXWEXPORT(bool,wxFileType_GetIcon)(wxFileType* self,wxIcon* icon)
{
#if wxCHECK_VERSION(2,5,0)
	wxIconLocation iconLoc;
	bool res = self->GetIcon(&iconLoc);
	*icon = wxIcon(iconLoc);
	return res;
#else
	return self->GetIcon(icon);
#endif
}

EWXWEXPORT(wxString*,wxFileType_GetDescription)(void* self)
{
  wxString *result = new wxString();
  if (((wxFileType*)self)->GetDescription(result) != true)
    result->Clear();
  return result;
}

EWXWEXPORT(wxString*,wxFileType_GetOpenCommand)(void* self,void* _params)
{
  wxString *result = new wxString();
  if (((wxFileType*)self)->GetOpenCommand(result,*((wxFileType::MessageParameters*)_params)) != true)
    result->Clear();
  return result;
}

EWXWEXPORT(wxString*,wxFileType_GetPrintCommand)(void* self,void* _params)
{
  wxString *result = new wxString();
  if (((wxFileType*)self)->GetPrintCommand(result,*((wxFileType::MessageParameters*)_params)) != true)
    result->Clear();
  return result;
}

EWXWEXPORT(wxString*,wxFileType_ExpandCommand)(void* self,void* _cmd,void* _params)
{
  return new wxString(((wxFileType*)self)->ExpandCommand((const wxChar*)_cmd,*((wxFileType::MessageParameters*)_params)));
}

EWXWEXPORT(void,wxFileType_Delete)(void* self)
{
        delete (wxFileType*)self;
}


}
