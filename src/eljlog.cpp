#include "wrapper.h"

extern "C"
{

typedef void (*TLogFunc) (void*, int, void*, int);

}

class ELJLog : public wxLog
{
	private:
		TLogFunc func;
		void*    EiffelObject;
		
    protected:
		virtual void DoLog(wxLogLevel level, const wxChar *szString, time_t t)
                  {
                    wxString s(szString);
                    func (EiffelObject, (int)level, (void*)&s , (int)t);
                  }

	public:
		ELJLog (void* _obj, void* _fnc) : wxLog()
		{
			func = (TLogFunc)_fnc;
			EiffelObject = _obj;
		}
};

extern "C"
{

EWXWEXPORT(void*,ELJLog_Create)(void* self,void* _fnc)
{
	return (void*)new ELJLog(self, _fnc);
}

EWXWEXPORT(void,ELJLog_Delete)(void* self)
{
	delete (ELJLog*)self;
}

EWXWEXPORT(bool,ELJLog_IsEnabled)(ELJLog* self)
{
	return self->IsEnabled();
}
	
EWXWEXPORT(int,ELJLog_EnableLogging)(void* self,bool doIt)
{
	return (int)((ELJLog*)self)->EnableLogging(doIt);
}
	
EWXWEXPORT(void,ELJLog_OnLog)(void* self,int level,void* szString,int t)
{
	((ELJLog*)self)->OnLog((wxLogLevel)level, (const wxChar*)szString, (time_t)t);
}
	
EWXWEXPORT(void,ELJLog_Flush)(void* self)
{
	((ELJLog*)self)->Flush();
}
	
EWXWEXPORT(int,ELJLog_HasPendingMessages)(ELJLog* self)
{
	return (int)self->HasPendingMessages();
}
	
EWXWEXPORT(void,ELJLog_FlushActive)(void* self)
{
	((ELJLog*)self)->FlushActive();
}
	
EWXWEXPORT(void*,ELJLog_GetActiveTarget)()
{
	return (void*)ELJLog::GetActiveTarget();
}
	
EWXWEXPORT(void*,ELJLog_SetActiveTarget)(void* pLogger)
{
	return (void*)ELJLog::SetActiveTarget((wxLog*)pLogger);
}
	
EWXWEXPORT(void,ELJLog_Suspend)(void* self)
{
	((ELJLog*)self)->Suspend();
}
	
EWXWEXPORT(void,ELJLog_Resume)(void* self)
{
	((ELJLog*)self)->Resume();
}
	
EWXWEXPORT(void,ELJLog_SetVerbose)(void* self,bool bVerbose)
{
	((ELJLog*)self)->SetVerbose(bVerbose);
}
	
EWXWEXPORT(void,ELJLog_DontCreateOnDemand)(void* self)
{
	((ELJLog*)self)->DontCreateOnDemand();
}
	
EWXWEXPORT(void,ELJLog_SetTraceMask)(void* self,int ulMask)
{
	((ELJLog*)self)->SetTraceMask((wxTraceMask)ulMask);
}
	
EWXWEXPORT(void,ELJLog_AddTraceMask)(void* self,void* str)
{
	((ELJLog*)self)->AddTraceMask((const wxChar*)str);
}
	
EWXWEXPORT(void,ELJLog_RemoveTraceMask)(void* self,void* str)
{
	((ELJLog*)self)->RemoveTraceMask((const wxChar*)str);
}
	
EWXWEXPORT(void,ELJLog_SetTimestamp)(void* self,void* ts)
{
	((ELJLog*)self)->SetTimestamp((const wxChar*)ts);
}
	
EWXWEXPORT(int,ELJLog_GetVerbose)(ELJLog* self)
{
	return (int)self->GetVerbose();
}
	
EWXWEXPORT(int,ELJLog_GetTraceMask)(ELJLog* self)
{
	return (int)self->GetTraceMask();
}
	
EWXWEXPORT(bool,ELJLog_IsAllowedTraceMask)(ELJLog* self,void* mask)
{
	return self->IsAllowedTraceMask((const wxChar*)mask);
}
	
EWXWEXPORT(void*,ELJLog_GetTimestamp)(void* self)
{
	return (void*)((ELJLog*)self)->GetTimestamp();
}

EWXWEXPORT(int,ELJSysErrorCode)()
{
	return (int)wxSysErrorCode();
}

EWXWEXPORT(void*,ELJSysErrorMsg)(int nErrCode)
{
	return (void*)wxSysErrorMsg((unsigned long)nErrCode);
}

EWXWEXPORT(void,LogErrorMsg)(wxString* _msg)
{
	wxLogError(*_msg);
}

EWXWEXPORT(void,LogFatalErrorMsg)(wxString* _msg)
{
	wxLogFatalError(*_msg);
}

EWXWEXPORT(void,LogWarningMsg)(wxString* _msg)
{
	wxLogWarning(*_msg);
}

EWXWEXPORT(void,LogMessageMsg)(wxString* _msg)
{
	wxLogMessage(*_msg);
}


EWXWEXPORT(void*,wxLogChain_Create)(void* logger)
{
	return new wxLogChain ((wxLog*)logger);
}

EWXWEXPORT(void,wxLogChain_Delete)(void* self)
{
	delete (wxLogChain*)self;
}

EWXWEXPORT(void,wxLogChain_SetLog)(void* self,void* logger)
{
	((wxLogChain*)self)->SetLog((wxLog*)logger);
}
	
EWXWEXPORT(void,wxLogChain_PassMessages)(void* self,bool bDoPass)
{
	((wxLogChain*)self)->PassMessages(bDoPass);
}
	
EWXWEXPORT(bool,wxLogChain_IsPassingMessages)(wxLogChain* self)
{
	return self->IsPassingMessages();
}
	
EWXWEXPORT(void*,wxLogChain_GetOldLog)(wxLogChain* self)
{
	return (void*)self->GetOldLog();
}
	

}
