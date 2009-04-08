#include "wrapper.h"

extern "C"

{

EWXWEXPORT(void*,wxProcess_CreateDefault)(wxEvtHandler* _prt,int _id)
{
	return (void*)new wxProcess (_prt, _id);
}

EWXWEXPORT(void*,wxProcess_CreateRedirect)(wxEvtHandler* _prt,bool _rdr)
{
	return (void*)new wxProcess (_prt, _rdr);
}

EWXWEXPORT(void,wxProcess_Delete)(void* self)
{
    delete (wxProcess*)self;
}

EWXWEXPORT(void,wxProcess_Redirect)(void* self)
{
	((wxProcess*)self)->Redirect();
}
	
EWXWEXPORT(bool,wxProcess_IsRedirected)(wxProcess* self)
{
	return self->IsRedirected();
}
	
EWXWEXPORT(void,wxProcess_Detach)(void* self)
{
	((wxProcess*)self)->Detach();
}
	
EWXWEXPORT(void*,wxProcess_GetInputStream)(void* self)
{
	return (void*)((wxProcess*)self)->GetInputStream();
}
	
EWXWEXPORT(void*,wxProcess_GetErrorStream)(void* self)
{
	return (void*)((wxProcess*)self)->GetErrorStream();
}
	
EWXWEXPORT(void*,wxProcess_GetOutputStream)(void* self)
{
	return (void*)((wxProcess*)self)->GetOutputStream();
}
	
EWXWEXPORT(void,wxProcess_CloseOutput)(void* self)
{
	((wxProcess*)self)->CloseOutput();
}
	

EWXWEXPORT(int,wxProcessEvent_GetPid)(void* self)
{
	return ((wxProcessEvent*)self)->GetPid();
}

EWXWEXPORT(int,wxProcessEvent_GetExitCode)(void* self)
{
	return ((wxProcessEvent*)self)->GetExitCode();
}


EWXWEXPORT(int,wxStreamBase_GetLastError)(wxStreamBase* self)
{
	return (int)self->GetLastError();
}
	
EWXWEXPORT(bool,wxStreamBase_IsOk)(wxStreamBase* self)
{
	return self->IsOk();
}
	
EWXWEXPORT(int,wxStreamBase_GetSize)(wxStreamBase* self)
{
	return (int)self->GetSize();
}
	

EWXWEXPORT(void,wxOutputStream_Delete)(void* self)
{
	delete (wxOutputStream*)self;
}

EWXWEXPORT(void,wxOutputStream_PutC)(void* self,char c)
{
	((wxOutputStream*)self)->PutC(c);
}
	
EWXWEXPORT(void,wxOutputStream_Write)(void* self,void* buffer,int size)
{
	((wxOutputStream*)self)->Write((const void*)buffer, (size_t)size);
}
	
EWXWEXPORT(int,wxOutputStream_Seek)(wxOutputStream* self,int pos,int mode)
{
	return (int)self->SeekO((off_t)pos, (wxSeekMode)mode);
}
	
EWXWEXPORT(int,wxOutputStream_Tell)(wxOutputStream* self)
{
	return (int)self->TellO();
}
	
EWXWEXPORT(int,wxOutputStream_LastWrite)(wxOutputStream* self)
{
	return (int)self->LastWrite();
}
	
EWXWEXPORT(void,wxOutputStream_Sync)(void* self)
{
	((wxOutputStream*)self)->Sync();
}
	

EWXWEXPORT(void,wxInputStream_Delete)(void* self)
{
	delete (wxInputStream*)self;
}

EWXWEXPORT(bool,wxInputStream_Eof)(wxInputStream* self)
{
	return self->Eof();
}
	
EWXWEXPORT(char,wxInputStream_Peek)(void* self)
{
	return ((wxInputStream*)self)->Peek();
}
	
EWXWEXPORT(char,wxInputStream_GetC)(void* self)
{
	return ((wxInputStream*)self)->GetC();
}
	
EWXWEXPORT(void,wxInputStream_Read)(void* self,void* buffer,int size)
{
	((wxInputStream*)self)->Read(buffer, (size_t)size);
}
	
EWXWEXPORT(int,wxInputStream_SeekI)(wxInputStream* self,int pos,int mode)
{
	return (int)self->SeekI((off_t)pos, (wxSeekMode)mode);
}
	
EWXWEXPORT(int,wxInputStream_Tell)(wxInputStream* self)
{
	return (int)self->TellI();
}
	
EWXWEXPORT(int,wxInputStream_LastRead)(wxInputStream* self)
{
	return (int)self->LastRead();
}	

EWXWEXPORT(int,wxInputStream_UngetBuffer)(wxInputStream* self,void* buffer,int size)
{
	return (int)self->Ungetch((const void*)buffer, (size_t)size);
}
	
EWXWEXPORT(int,wxInputStream_Ungetch)(wxInputStream* self,char c)
{
	return (int)self->Ungetch(c);
}
	
}
