#include "wrapper.h"

extern "C"
{

EWXWEXPORT(wxGauge*,wxGauge_Create)(wxWindow* _prt,int _id,int _rng,int _stl)
{
	return new wxGauge (_prt, _id, _rng, wxDefaultPosition,wxDefaultSize, _stl);
}

EWXWEXPORT(void,wxGauge_SetShadowWidth)(wxGauge* self,int w)
{
	self->SetShadowWidth(w);
}
	
EWXWEXPORT(void,wxGauge_SetBezelFace)(wxGauge* self,int w)
{
	self->SetBezelFace(w);
}
	
EWXWEXPORT(void,wxGauge_SetRange)(wxGauge* self,int r)
{
	self->SetRange(r);
}
	
EWXWEXPORT(void,wxGauge_SetValue)(wxGauge* self,int pos)
{
	self->SetValue(pos);
}
	
EWXWEXPORT(int,wxGauge_GetShadowWidth)(wxGauge* self)
{
	return self->GetShadowWidth();
}
	
EWXWEXPORT(int,wxGauge_GetBezelFace)(wxGauge* self)
{
	return self->GetBezelFace();
}
	
EWXWEXPORT(int,wxGauge_GetRange)(wxGauge* self)
{
	return self->GetRange();
}
	
EWXWEXPORT(int,wxGauge_GetValue)(wxGauge* self)
{
	return self->GetValue();
}
	
}
