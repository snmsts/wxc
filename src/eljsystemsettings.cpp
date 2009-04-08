#include "wrapper.h"

extern "C"
{

#if (wxVERSION_NUMBER < 2800)
EWXWEXPORT(void,wxSystemSettings_GetSystemColour)(wxSystemColour index,wxColour* _ref)
{
	*_ref = wxSystemSettings::GetColour(index);
}

EWXWEXPORT(void,wxSystemSettings_GetSystemFont)(wxSystemFont index,wxFont* _ref)
{
	*_ref = wxSystemSettings::GetFont(index);
}

EWXWEXPORT(int,wxSystemSettings_GetSystemMetric)(wxSystemMetric index)
{
	return wxSystemSettings::GetMetric(index);
}
#else
EWXWEXPORT(void,wxSystemSettings_GetColour)(wxSystemColour index,wxColour* _ref)
{
	*_ref = wxSystemSettings::GetColour(index);
}

EWXWEXPORT(void,wxSystemSettings_GetFont)(wxSystemFont index,wxFont* _ref)
{
	*_ref = wxSystemSettings::GetFont(index);
}

EWXWEXPORT(int,wxSystemSettings_GetMetric)(wxSystemMetric index)
{
	return wxSystemSettings::GetMetric(index);
}

EWXWEXPORT(int,wxSystemSettings_GetScreenType)()
{
  return (int) wxSystemSettings::GetScreenType();
}
#endif

}
