#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxBusyInfo*,wxBusyInfo_Create)(wxString* _txt)
{
	return new wxBusyInfo (*_txt);
}

EWXWEXPORT(void,wxBusyInfo_Delete)(wxBusyInfo* self)
{
	delete self;
}

EWXWEXPORT(wxBusyCursor*,wxBusyCursor_Create)()
{
	return new wxBusyCursor ();
}

EWXWEXPORT(wxBusyCursor*,wxBusyCursor_CreateWithCursor)(wxCursor* _cur)
{
	return new wxBusyCursor (_cur);
}

EWXWEXPORT(void,wxBusyCursor_Delete)(wxBusyCursor* self)
{
	delete self;
}

}
