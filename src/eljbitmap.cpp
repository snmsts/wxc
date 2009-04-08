#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxBitmap*,wxBitmap_Create)(void* _data,int _type,int _width,int _height,int _depth)
{
#ifdef __WIN32__
	return new wxBitmap(_data, _type, _width, _height, _depth);
#else
	return new wxBitmap((const char*)_data, _width, _height, _depth);
#endif
}

EWXWEXPORT(wxBitmap*,wxBitmap_CreateFromXPM)(void* _data)
{
	return new wxBitmap((const char**)_data);
}

EWXWEXPORT(wxBitmap*,wxBitmap_CreateEmpty)(int _width,int _height,int _depth)
{
	return new wxBitmap(_width, _height, _depth);
}

EWXWEXPORT(wxBitmap*,wxBitmap_CreateLoad)(wxString* name,int type)
{
#if wxVERSION_NUMBER >= 2400
	return new wxBitmap(*name, (wxBitmapType)type);
#else
	return new wxBitmap(*name, (long)type);
#endif
}

EWXWEXPORT(wxBitmap*,wxBitmap_CreateDefault)()
{
	return new wxBitmap();
}

EWXWEXPORT(void,wxBitmap_Delete)(wxBitmap* self)
{
	delete self;
}

EWXWEXPORT(void,wxBitmap_GetSubBitmap)(wxBitmap* self,int x,int y,int w,int h,wxBitmap* bitmap)
{
	*bitmap = self->GetSubBitmap(wxRect(x, y, w, h));
}

EWXWEXPORT(bool,wxBitmap_LoadFile)(wxBitmap* self,wxString* name,int type)
{
#if wxVERSION_NUMBER >= 2400
	return self->LoadFile(*name, (wxBitmapType)type);
#else
	return self->LoadFile(*name, (long)type);
#endif
}

EWXWEXPORT(bool,wxBitmap_SaveFile)(wxBitmap* self,wxString* name,int type,wxPalette* cmap)
{
#if wxVERSION_NUMBER >= 2400
	return self->SaveFile(*name, (wxBitmapType)type,  cmap);
#else
	return self->SaveFile(*name, type,  cmap);
#endif
}

EWXWEXPORT(wxMask*,wxBitmap_GetMask)(wxBitmap* self)
{
	return self->GetMask();
}

EWXWEXPORT(void,wxBitmap_SetMask)(wxBitmap* self,wxMask* mask)
{
	self->SetMask(mask);
}

/**/
#ifdef __WIN32__
EWXWEXPORT(void,wxBitmap_AddHandler)(wxGDIImageHandler* handler)
{
	wxBitmap::AddHandler( handler);
}

EWXWEXPORT(void,wxBitmap_InsertHandler)(wxGDIImageHandler* handler)
{
	wxBitmap::InsertHandler(handler);
}

EWXWEXPORT(bool,wxBitmap_RemoveHandler)(wxString* name)
{
	return wxBitmap::RemoveHandler(*name);
}

EWXWEXPORT(void*,wxBitmap_FindHandlerByName)(wxString* name)
{
	return (void*)wxBitmap::FindHandler(*name);
}

EWXWEXPORT(void*,wxBitmap_FindHandlerByExtension)(wxString* extension,int type)
{
	return (void*)wxBitmap::FindHandler(*extension, (long)type);
}

EWXWEXPORT(void*,wxBitmap_FindHandlerByType)(int type)
{
	return (void*)wxBitmap::FindHandler((long)type);
}

EWXWEXPORT(void,wxBitmap_InitStandardHandlers)()
{
	wxBitmap::InitStandardHandlers();
}

EWXWEXPORT(void,wxBitmap_CleanUpHandlers)()
{
	wxBitmap::CleanUpHandlers();
}
#endif //__WIN32__

/**/
EWXWEXPORT(bool,wxBitmap_IsOk)(wxBitmap* self)
{
	return self->IsOk();
}

EWXWEXPORT(int,wxBitmap_GetWidth)(wxBitmap* self)
{
	return self->GetWidth();
}

EWXWEXPORT(int,wxBitmap_GetHeight)(wxBitmap* self)
{
	return self->GetHeight();
}

EWXWEXPORT(int,wxBitmap_GetDepth)(wxBitmap* self)
{
	return self->GetDepth();
}

EWXWEXPORT(void,wxBitmap_SetWidth)(wxBitmap* self,int w)
{
	self->SetWidth(w);
}

EWXWEXPORT(void,wxBitmap_SetHeight)(wxBitmap* self,int h)
{
	self->SetHeight(h);
}

EWXWEXPORT(void,wxBitmap_SetDepth)(wxBitmap* self,int d)
{
	self->SetDepth(d);
}

EWXWEXPORT(wxStaticBitmap*,wxStaticBitmap_Create)(wxWindow* _prt,int _id,wxBitmap* bitmap,int _stl)
{
	return new wxStaticBitmap (_prt, _id,*bitmap, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(void,wxStaticBitmap_SetIcon)(wxStaticBitmap* self,wxIcon* icon)
{
	self->SetIcon(*icon);
}

EWXWEXPORT(void,wxStaticBitmap_SetBitmap)(wxStaticBitmap* self,wxBitmap* bitmap)
{
	self->SetBitmap(*bitmap);
}

EWXWEXPORT(void,wxStaticBitmap_GetIcon)(wxStaticBitmap* self,wxIcon* _ref)
{
	*_ref = self->GetIcon();
}

EWXWEXPORT(void,wxStaticBitmap_GetBitmap)(wxStaticBitmap* self,wxBitmap* _ref)
{
	*_ref = self->GetBitmap();
}

EWXWEXPORT(void,wxStaticBitmap_Delete)(wxStaticBitmap* self)
{
	delete self;
}

}
