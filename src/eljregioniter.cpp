#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxRegionIterator_Create)()
{
	return (void*)new wxRegionIterator();
}

EWXWEXPORT(void*,wxRegionIterator_CreateFromRegion)(void* region)
{
	return (void*)new wxRegionIterator(*((wxRegion*)region));
}

EWXWEXPORT(void,wxRegionIterator_Delete)(void* self)
{
	delete (wxRegionIterator*)self;
}

EWXWEXPORT(void,wxRegionIterator_Reset)(void* self)
{
	((wxRegionIterator*)self)->Reset();
}
	
EWXWEXPORT(void,wxRegionIterator_ResetToRegion)(void* self,void* region)
{
	((wxRegionIterator*)self)->Reset(*((wxRegion*)region));
}
	
EWXWEXPORT(bool,wxRegionIterator_HaveRects)(wxRegionIterator* self)
{
	return self->HaveRects();
}

EWXWEXPORT(void,wxRegionIterator_Next)(void* self)
{
	(*((wxRegionIterator*)self))++;
}
	
EWXWEXPORT(int,wxRegionIterator_GetX)(void* self)
{
	return ((wxRegionIterator*)self)->GetX();
}
	
EWXWEXPORT(int,wxRegionIterator_GetY)(void* self)
{
	return ((wxRegionIterator*)self)->GetY();
}
	
EWXWEXPORT(int,wxRegionIterator_GetWidth)(void* self)
{
	return ((wxRegionIterator*)self)->GetWidth();
}
	
EWXWEXPORT(int,wxRegionIterator_GetHeight)(void* self)
{
	return ((wxRegionIterator*)self)->GetHeight();
}
	
}
