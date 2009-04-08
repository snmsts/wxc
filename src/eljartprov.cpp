#include "wrapper.h"
#if wxVERSION_NUMBER >= 2400

extern "C"
{
typedef void* _cdecl (*TCreateBmp)(void* _obj, void* id, void* clt, int w, int h);
}


class ELJArtProv: public wxArtProvider
{
	private:
		void* EiffelObject;
		TCreateBmp cb;
	protected:
    	virtual wxBitmap CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size)
		{
			if (EiffelObject)
			{
				wxBitmap* res = (wxBitmap*)cb(EiffelObject, (void*)id.c_str(), (void*)client.c_str(), size.GetWidth(), size.GetHeight());
				
				if (res)
					return (*res);
				else
					return wxNullBitmap;
			}
			return wxNullBitmap;
		}
	public:
		ELJArtProv (void* obj, void* clb){EiffelObject = obj; cb = (TCreateBmp)clb;};
		void Release(){EiffelObject = NULL; cb = NULL;};
};

extern "C"
{

EWXWEXPORT(void*,ELJArtProv_Create)(void* _obj,void* _clb)
{
	return (void*)new ELJArtProv(_obj, _clb);
}
	
EWXWEXPORT(void,ELJArtProv_Release)(ELJArtProv* self)
{
	self->Release();
	delete self;
}

EWXWEXPORT(wxBitmap*,wxArtProvider_GetBitmap)(wxString* artid,wxString* artclient,wxSize* sz)
{
  return new wxBitmap(wxArtProvider::GetBitmap(*artid,*artclient,
                                               sz ? *sz : wxDefaultSize));
}

EWXWEXPORT(wxIcon*,wxArtProvider_GetIcon)(wxString* artid,wxString* artclient,wxSize* sz)
{
  return new wxIcon(wxArtProvider::GetIcon(*artid,*artclient,
                                           sz ? *sz : wxDefaultSize));
}

EWXWEXPORT(void,wxArtProvider_Insert)(wxArtProvider* provider)
{
  wxArtProvider::Insert(provider);
}

EWXWEXPORT(bool,wxArtProvider_Pop)()
{
#if WXWIN_COMPATIBILITY_2_6
	return wxArtProvider::PopProvider();
#else
  return wxArtProvider::Pop();
#endif
}

EWXWEXPORT(void,wxArtProvider_Push)(wxArtProvider* provider)
{
#if WXWIN_COMPATIBILITY_2_6
	wxArtProvider::PushProvider(provider);
#else
  wxArtProvider::Push(provider);
#endif
}

EWXWEXPORT(bool,wxArtProvider_Remove)(wxArtProvider* provider)
{
#if WXWIN_COMPATIBILITY_2_6
	return wxArtProvider::RemoveProvider(provider);
#else
  return wxArtProvider::Remove(provider);
#endif
}

}
#endif
