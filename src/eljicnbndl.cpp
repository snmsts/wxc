#include "wrapper.h"
#if wxVERSION_NUMBER >= 2400

extern "C"
{

EWXWEXPORT(void*,wxIconBundle_CreateDefault)()
{
	return (void*)new wxIconBundle();
}
	
EWXWEXPORT(void*,wxIconBundle_CreateFromFile)(wxString* file,int type)
{
	return (void*)new wxIconBundle(*file, (long)type);
}
	
EWXWEXPORT(void*,wxIconBundle_CreateFromIcon)(wxIcon* icon)
{
	return (void*)new wxIconBundle(*icon);
}
	
EWXWEXPORT(void,wxIconBundle_Assign)(void* self,void* _ref)
{
	*((wxIconBundle*)_ref) = *((wxIconBundle*)self);
}
	
EWXWEXPORT(void,wxIconBundle_Delete)(void* self)
{
	delete (wxIconBundle*)self;
}
	
EWXWEXPORT(void,wxIconBundle_AddIconFromFile)(void* self,wxString* file,int type)
{
	((wxIconBundle*)self)->AddIcon(*file, (long)type);
}
	
EWXWEXPORT(void,wxIconBundle_AddIcon)(void* self,wxIcon* icon)
{
	((wxIconBundle*)self)->AddIcon(*icon);
}
	
EWXWEXPORT(void,wxIconBundle_GetIcon)(void* self,int w,int h,wxIcon* _ref)
{
	*_ref = ((wxIconBundle*)self)->GetIcon(wxSize(w, h));
}

}
#endif
