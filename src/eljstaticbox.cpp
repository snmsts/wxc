#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxStaticBox_Create)(wxWindow* _prt,int _id,wxString* _txt,int _stl)
{
	return (void*)new wxStaticBox (_prt, _id,*_txt, wxDefaultPosition, wxDefaultSize, _stl);
}

}
