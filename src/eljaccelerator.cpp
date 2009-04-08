#include "wrapper.h"
extern "C"
{

EWXWEXPORT(void*,wxAcceleratorEntry_Create)(int flags,int keyCode,int cmd)
{
	return (void*)new wxAcceleratorEntry(flags, keyCode, cmd);
}

EWXWEXPORT(void,wxAcceleratorEntry_Delete)(wxAcceleratorEntry* self)
{
	delete self;
}

EWXWEXPORT(void,wxAcceleratorEntry_Set)(wxAcceleratorEntry* self,int flags,int keyCode,int cmd)
{
	self->Set(flags, keyCode, cmd);
}
	
EWXWEXPORT(int,wxAcceleratorEntry_GetFlags)(wxAcceleratorEntry* self)
{
	return self->GetFlags();
}
	
EWXWEXPORT(int,wxAcceleratorEntry_GetKeyCode)(wxAcceleratorEntry* self)
{
	return self->GetKeyCode();
}
	
EWXWEXPORT(int,wxAcceleratorEntry_GetCommand)(wxAcceleratorEntry* self)
{
	return self->GetCommand();
}
	
EWXWEXPORT(void*,wxAcceleratorTable_Create)(int n,void* entries)
{
	wxAcceleratorEntry* list = new wxAcceleratorEntry[n];
	
	for (int i = 0; i< n; i++)
		list[i] = *(((wxAcceleratorEntry**)entries)[i]);
	
	wxAcceleratorTable* result = new wxAcceleratorTable(n, list);
	
	delete [] list;
	
	return (void*)result;
}

EWXWEXPORT(void,wxAcceleratorTable_Delete)(void* self)
{
	delete self;
}

}
