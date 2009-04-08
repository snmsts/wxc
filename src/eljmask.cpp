#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxMask*,wxMask_Create)(wxBitmap* bitmap)
{
	return new wxMask (*bitmap);
}

EWXWEXPORT(wxMask*,wxMask_CreateColoured)(wxBitmap* bitmap,wxColour* colour)
{
	return new wxMask (*bitmap,*colour);
}

}
