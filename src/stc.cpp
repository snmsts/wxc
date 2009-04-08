#include "wrapper.h"


extern "C"
{
#include "stc_gen.cpp"

/* wxStyledTextCtrl */

EWXWEXPORT(void*,wxStyledTextCtrl_Create)(wxWindow* _prt,int _id,wxString* _txt,int _stl)
{
#ifdef wxUSE_STC
  return (void*)new wxStyledTextCtrl(_prt, _id, wxDefaultPosition, wxDefaultSize,style, _stl,*_txt);
#else
  return false;
#endif
}

  /* tricky handwritten functions */

  EWXWEXPORT(wxColour*,wxStyledTextCtrl_IndicatorGetForeground)(void* self,int indic)
  {
#ifdef wxUSE_STC
    return new wxColour(((wxStyledTextCtrl*)self)->IndicatorGetForeground(indic));
#else
    return false;
#endif
  }
  EWXWEXPORT(void*,wxStyledTextCtrl_GetCaretLineBackground)(void* self)
  {
#ifdef wxUSE_STC
    return new wxColour(
#if (wxVERSION_NUMBER < 2800)
    ((wxStyledTextCtrl*)self)->GetCaretLineBack()
#else
    ((wxStyledTextCtrl*)self)->GetCaretLineBackground()
#endif
    );
#else
    return false;
#endif
  }
EWXWEXPORT(void,wxStyledTextCtrl_SetCaretLineBackground)(void* self,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
#if (wxVERSION_NUMBER < 2800)
   ((wxStyledTextCtrl*)self)->SetCaretLineBack(wxColour(back_r,back_g,back_b));
#else
    /* SetCaretLineBack is changed name to SetCaretLineBackground.
       So I avoid to use stc_gen.cpp for backward compatibility. */
   ((wxStyledTextCtrl*)self)->SetCaretLineBackground(wxColour(back_r,back_g,back_b));
#endif
#endif
}
  EWXWEXPORT(void*,wxStyledTextCtrl_GetCaretForeground)(void* self)
  {
#ifdef wxUSE_STC
    return new wxColour(((wxStyledTextCtrl*)self)->GetCaretForeground());
#else
    return false;
#endif
  }
  EWXWEXPORT(void*,wxStyledTextCtrl_GetLine)(void* self,int line)
  {
#ifdef wxUSE_STC
    return new wxString(((wxStyledTextCtrl*)self)->GetLine(line));
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_GetText)(void* self)
  {
#ifdef wxUSE_STC
    return new wxString(((wxStyledTextCtrl*)self)->GetText());
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_GetSelectedText)(void* self)
  {
#ifdef wxUSE_STC
    return new wxString(((wxStyledTextCtrl*)self)->GetSelectedText());
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_GetTextRange)(void* self,int startPos,int endPos)
  {
#ifdef wxUSE_STC
    return new wxString(((wxStyledTextCtrl*)self)->GetTextRange(startPos, endPos));
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_CreateDocument)(void* self)
  {
#ifdef wxUSE_STC
    return ((wxStyledTextCtrl*)self)->CreateDocument();
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_GetEdgeColour)(void* self)
  {
#ifdef wxUSE_STC
    return new wxColour(((wxStyledTextCtrl*)self)->GetEdgeColour());
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_GetDocPointer)(void* self)
  {
#ifdef wxUSE_STC
    return ((wxStyledTextCtrl*)self)->GetDocPointer();
#else
    return false;
#endif
  }

  EWXWEXPORT(void*,wxStyledTextCtrl_PointFromPosition)(void* self,int pos)
  {
#ifdef wxUSE_STC
    return new wxPoint(((wxStyledTextCtrl*)self)->PointFromPosition(pos));
#else
    return false;
#endif
  }

  /*
("wxMemoryBuffer","GetStyledText",[("int","startPos"),("int","endPos")])
("wxString","GetCurLine",[("int*","linePos")]) #returns both line and pos, hur göra?
--("wxColour","IndicatorGetForeground",[("int","indic")])
--("wxColour","GetCaretLineBack",[])
--("wxColour","GetCaretForeground",[])
--("wxString","GetLine",[("int","line")])
--("wxString","GetSelectedText",[])
--("wxString","GetTextRange",[("int","startPos"),("int","endPos")])
--("wxString","GetText",[])
--("wxSTCDoc*","GetDocPointer",[])
--("wxColour","GetEdgeColour",[])
--("wxSTCDoc*","CreateDocument",[])
--("wxPoint","PointFromPosition",[("int","pos")])
*/


/*************************************/
/* wxStyledTextEvent's get functions */
/*************************************/

EWXWEXPORT(int,wxStyledTextEvent_GetPosition)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetPosition();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetKey)(void* self)
{
#ifdef wxUSE_STC
  return (char)((wxStyledTextEvent*)self)->GetKey();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetModifiers)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetModifiers();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetModificationType)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetModificationType();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetLength)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetLength();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetLinesAdded)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetLinesAdded();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetLine)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetLine();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetFoldLevelNow)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetFoldLevelNow();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetFoldLevelPrev)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetFoldLevelPrev();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetMargin)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetMargin();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetMessage)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetMessage();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetWParam)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetWParam();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetLParam)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetLParam();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetListType)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetListType();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetX)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetX();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetY)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetY();
#else
  return false;
#endif
}

EWXWEXPORT(void*,wxStyledTextEvent_GetDragText)(void* self)
{
#ifdef wxUSE_STC
    return new wxString(((wxStyledTextEvent*)self)->GetDragText());
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxStyledTextEvent_GetDragAllowMove)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetDragAllowMove();
#else
  return false;
#endif
}

EWXWEXPORT(int,wxStyledTextEvent_GetDragResult)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetDragResult();
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxStyledTextEvent_GetShift)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetShift();
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxStyledTextEvent_GetControl)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetControl();
#else
  return false;
#endif
}

EWXWEXPORT(bool,wxStyledTextEvent_GetAlt)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextEvent*)self)->GetAlt();
#else
  return false;
#endif
}

EWXWEXPORT(wxString*,wxStyledTextEvent_GetText)(void* self)
{
#ifdef wxUSE_STC
  return new wxString(((wxStyledTextEvent*)self)->GetText());
#else
  return false;
#endif
}

EWXWEXPORT(void*,wxStyledTextEvent_Clone)(void* self)
{
#ifdef wxUSE_STC
  return (void*)((wxStyledTextEvent*)self)->Clone();
#else
  return false;
#endif
}

/*************************************/
/* wxStyledTextEvent's set functions */
/*************************************/

EWXWEXPORT(void,wxStyledTextEvent_SetPosition)(void* self,int pos)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetPosition(pos);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetKey)(void* self,int k)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetKey(k);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetModifiers)(void* self,int m)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetModifiers(m);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetModificationType)(void* self,int t)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetModificationType(t);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetText)(void* self,void* t)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetText(*(wxString*)t);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetLength)(void* self,int len)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetLength(len);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetLinesAdded)(void* self,int num)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetLinesAdded(num);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetLine)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetLine(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetFoldLevelNow)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetFoldLevelNow(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetFoldLevelPrev)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetFoldLevelPrev(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetMargin)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetMargin(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetMessage)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetMessage(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetWParam)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetWParam(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetLParam)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetLParam(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetListType)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetListType(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetX)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetX(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetY)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetY(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetDragText)(void* self,void* val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetDragText(*(wxString*)val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetDragAllowMove)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetDragAllowMove(val);
#endif
}

EWXWEXPORT(void,wxStyledTextEvent_SetDragResult)(void* self,int val)
{
#ifdef wxUSE_STC
  ((wxStyledTextEvent*)self)->SetDragResult(*(wxDragResult*)val);
#endif
}

/*************************************/
/* wxStyledTextEvent events          */
/*************************************/
#ifdef wxUSE_STC
EWXWCONSTANTINT(EVT_STC_CHANGE,wxEVT_STC_CHANGE)
EWXWCONSTANTINT(EVT_STC_STYLENEEDED,wxEVT_STC_STYLENEEDED)
EWXWCONSTANTINT(EVT_STC_CHARADDED,wxEVT_STC_CHARADDED)
EWXWCONSTANTINT(EVT_STC_SAVEPOINTREACHED,wxEVT_STC_SAVEPOINTREACHED)
EWXWCONSTANTINT(EVT_STC_SAVEPOINTLEFT,wxEVT_STC_SAVEPOINTLEFT)
EWXWCONSTANTINT(EVT_STC_ROMODIFYATTEMPT,wxEVT_STC_ROMODIFYATTEMPT)
EWXWCONSTANTINT(EVT_STC_KEY,wxEVT_STC_KEY)
EWXWCONSTANTINT(EVT_STC_DOUBLECLICK,wxEVT_STC_DOUBLECLICK)
EWXWCONSTANTINT(EVT_STC_UPDATEUI,wxEVT_STC_UPDATEUI)
EWXWCONSTANTINT(EVT_STC_MODIFIED,wxEVT_STC_MODIFIED)
EWXWCONSTANTINT(EVT_STC_MACRORECORD,wxEVT_STC_MACRORECORD)
EWXWCONSTANTINT(EVT_STC_MARGINCLICK,wxEVT_STC_MARGINCLICK)
EWXWCONSTANTINT(EVT_STC_NEEDSHOWN,wxEVT_STC_NEEDSHOWN)
/* expEVT_STC_POSCHANGED is removed in wxWidgets-2.6.x.
EWXWCONSTANTINT(EVT_STC_POSCHANGED,wxEVT_STC_POSCHANGED)
*/
EWXWCONSTANTINT(EVT_STC_PAINTED,wxEVT_STC_PAINTED)
EWXWCONSTANTINT(EVT_STC_USERLISTSELECTION,wxEVT_STC_USERLISTSELECTION)
EWXWCONSTANTINT(EVT_STC_URIDROPPED,wxEVT_STC_URIDROPPED)
EWXWCONSTANTINT(EVT_STC_DWELLSTART,wxEVT_STC_DWELLSTART)
EWXWCONSTANTINT(EVT_STC_DWELLEND,wxEVT_STC_DWELLEND)
EWXWCONSTANTINT(EVT_STC_START_DRAG,wxEVT_STC_START_DRAG)
EWXWCONSTANTINT(EVT_STC_DRAG_OVER,wxEVT_STC_DRAG_OVER)
EWXWCONSTANTINT(EVT_STC_DO_DROP,wxEVT_STC_DO_DROP)
EWXWCONSTANTINT(EVT_STC_ZOOM,wxEVT_STC_ZOOM)
EWXWCONSTANTINT(EVT_STC_HOTSPOT_CLICK,wxEVT_STC_HOTSPOT_CLICK)
EWXWCONSTANTINT(EVT_STC_HOTSPOT_DCLICK,wxEVT_STC_HOTSPOT_DCLICK)
EWXWCONSTANTINT(EVT_STC_CALLTIP_CLICK,wxEVT_STC_CALLTIP_CLICK)
EWXWCONSTANTINT(EVT_STC_AUTOCOMP_SELECTION,wxEVT_STC_AUTOCOMP_SELECTION)

#endif //wxUSE_STC
}
