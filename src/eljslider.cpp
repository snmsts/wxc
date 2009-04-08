#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxSlider_Create)(wxWindow* _prt,int _id,int _init,int _min,int _max,long _stl)
{
	return (void*)new wxSlider (_prt, _id, _init, _min, _max, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(int,wxSlider_GetValue)(wxSlider* self)
{
	return self->GetValue();
}
	
EWXWEXPORT(void,wxSlider_SetValue)(wxSlider* self,int value)
{
	self->SetValue(value);
}
	
EWXWEXPORT(void,wxSlider_SetRange)(wxSlider* self,int minValue,int maxValue)
{
	self->SetRange(minValue, maxValue);
}
	
EWXWEXPORT(int,wxSlider_GetMin)(wxSlider* self)
{
	return self->GetMin();
}
	
EWXWEXPORT(int,wxSlider_GetMax)(wxSlider* self)
{
	return self->GetMax();
}
	
EWXWEXPORT(void,wxSlider_SetTickFreq)(wxSlider* self,int n,int pos)
{
	self->SetTickFreq(n, pos);
}
	
EWXWEXPORT(int,wxSlider_GetTickFreq)(wxSlider* self)
{
	return self->GetTickFreq();
}
	
EWXWEXPORT(void,wxSlider_SetPageSize)(wxSlider* self,int pageSize)
{
	self->SetPageSize(pageSize);
}
	
EWXWEXPORT(int,wxSlider_GetPageSize)(wxSlider* self)
{
	return self->GetPageSize();
}
	
EWXWEXPORT(void,wxSlider_ClearSel)(wxSlider* self)
{
	self->ClearSel();
}
	
EWXWEXPORT(void,wxSlider_ClearTicks)(wxSlider* self)
{
	self->ClearTicks();
}
	
EWXWEXPORT(void,wxSlider_SetLineSize)(wxSlider* self,int lineSize)
{
	self->SetLineSize(lineSize);
}
	
EWXWEXPORT(int,wxSlider_GetLineSize)(wxSlider* self)
{
	return self->GetLineSize();
}
	
EWXWEXPORT(int,wxSlider_GetSelEnd)(wxSlider* self)
{
	return self->GetSelEnd();
}
	
EWXWEXPORT(int,wxSlider_GetSelStart)(wxSlider* self)
{
	return self->GetSelStart();
}
	
EWXWEXPORT(void,wxSlider_SetSelection)(wxSlider* self,int minPos,int maxPos)
{
	self->SetSelection(minPos, maxPos);
}
	
EWXWEXPORT(void,wxSlider_SetThumbLength)(wxSlider* self,int len)
{
	self->SetThumbLength(len);
}
	
EWXWEXPORT(int,wxSlider_GetThumbLength)(wxSlider* self)
{
	return self->GetThumbLength();
}
	
EWXWEXPORT(void,wxSlider_SetTick)(wxSlider* self,int tickPos)
{
	self->SetTick(tickPos);
}
	
} 
