EWXWEXPORT(void,wxStyledTextCtrl_AddText)(void* self,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AddText(*text);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AddStyledText)(void* self,void* data)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AddStyledText(*(wxMemoryBuffer*)data);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_InsertText)(void* self,int pos,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->InsertText(pos,*text);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ClearAll)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ClearAll();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ClearDocumentStyle)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ClearDocumentStyle();
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLength)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLength();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetCharAt)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCharAt(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetCurrentPos)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCurrentPos();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetAnchor)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetAnchor();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetStyleAt)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetStyleAt(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Redo)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Redo();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetUndoCollection)(void* self,bool collectUndo)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetUndoCollection(collectUndo);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SelectAll)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SelectAll();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSavePoint)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSavePoint();
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_CanRedo)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->CanRedo();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_MarkerLineFromHandle)(void* self,int handle)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->MarkerLineFromHandle(handle);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerDeleteHandle)(void* self,int handle)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerDeleteHandle(handle);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetUndoCollection)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetUndoCollection();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetViewWhiteSpace)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetViewWhiteSpace();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetViewWhiteSpace)(void* self,int viewWS)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetViewWhiteSpace(viewWS);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_PositionFromPoint)(void* self,int pt_x,int pt_y)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->PositionFromPoint(wxPoint(pt_x,pt_y));
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_PositionFromPointClose)(void* self,int x,int y)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->PositionFromPointClose(x, y);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_GotoLine)(void* self,int line)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->GotoLine(line);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_GotoPos)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->GotoPos(pos);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetAnchor)(void* self,int posAnchor)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetAnchor(posAnchor);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetEndStyled)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetEndStyled();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ConvertEOLs)(void* self,int eolMode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ConvertEOLs(eolMode);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetEOLMode)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetEOLMode();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetEOLMode)(void* self,int eolMode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetEOLMode(eolMode);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StartStyling)(void* self,int pos,int mask)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StartStyling(pos, mask);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetStyling)(void* self,int length,int style)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetStyling(length, style);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetBufferedDraw)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetBufferedDraw();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetBufferedDraw)(void* self,bool buffered)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetBufferedDraw(buffered);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetTabWidth)(void* self,int tabWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetTabWidth(tabWidth);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetTabWidth)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetTabWidth();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetCodePage)(void* self,int codePage)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetCodePage(codePage);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerDefine)(void* self,int markerNumber,int markerSymbol,int foreground_r,int foreground_g,int foreground_b,int background_r,int background_g,int background_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerDefine(markerNumber, markerSymbol, wxColour(foreground_r,foreground_g,foreground_b), wxColour(background_r,background_g,background_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerSetForeground)(void* self,int markerNumber,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerSetForeground(markerNumber, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerSetBackground)(void* self,int markerNumber,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerSetBackground(markerNumber, wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_MarkerAdd)(void* self,int line,int markerNumber)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->MarkerAdd(line, markerNumber);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerDelete)(void* self,int line,int markerNumber)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerDelete(line, markerNumber);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerDeleteAll)(void* self,int markerNumber)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerDeleteAll(markerNumber);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_MarkerGet)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->MarkerGet(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_MarkerNext)(void* self,int lineStart,int markerMask)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->MarkerNext(lineStart, markerMask);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_MarkerPrevious)(void* self,int lineStart,int markerMask)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->MarkerPrevious(lineStart, markerMask);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MarkerDefineBitmap)(void* self,int markerNumber,wxBitmap* bmp)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MarkerDefineBitmap(markerNumber,*bmp);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMarginType)(void* self,int margin,int marginType)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMarginType(margin, marginType);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMarginType)(void* self,int margin)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMarginType(margin);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMarginWidth)(void* self,int margin,int pixelWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMarginWidth(margin, pixelWidth);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMarginWidth)(void* self,int margin)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMarginWidth(margin);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMarginMask)(void* self,int margin,int mask)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMarginMask(margin, mask);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMarginMask)(void* self,int margin)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMarginMask(margin);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMarginSensitive)(void* self,int margin,bool sensitive)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMarginSensitive(margin, sensitive);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetMarginSensitive)(void* self,int margin)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMarginSensitive(margin);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleClearAll)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleClearAll();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetForeground)(void* self,int style,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetForeground(style, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetBackground)(void* self,int style,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetBackground(style, wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetBold)(void* self,int style,bool bold)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetBold(style, bold);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetItalic)(void* self,int style,bool italic)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetItalic(style, italic);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetSize)(void* self,int style,int sizePoints)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetSize(style, sizePoints);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetFaceName)(void* self,int style,wxString* fontName)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetFaceName(style,*fontName);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetEOLFilled)(void* self,int style,bool filled)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetEOLFilled(style, filled);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleResetDefault)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleResetDefault();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetUnderline)(void* self,int style,bool underline)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetUnderline(style, underline);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetCase)(void* self,int style,int caseForce)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetCase(style, caseForce);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetCharacterSet)(void* self,int style,int characterSet)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetCharacterSet(style, characterSet);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetHotSpot)(void* self,int style,bool hotspot)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetHotSpot(style, hotspot);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSelForeground)(void* self,bool useSetting,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSelForeground(useSetting, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSelBackground)(void* self,bool useSetting,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSelBackground(useSetting, wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetCaretForeground)(void* self,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetCaretForeground(wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CmdKeyAssign)(void* self,int key,int modifiers,int cmd)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CmdKeyAssign(key, modifiers, cmd);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CmdKeyClear)(void* self,int key,int modifiers)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CmdKeyClear(key, modifiers);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CmdKeyClearAll)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CmdKeyClearAll();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetStyleBytes)(void* self,int length,void* styleBytes)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetStyleBytes(length,*(char**)styleBytes);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetVisible)(void* self,int style,bool visible)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetVisible(style, visible);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetCaretPeriod)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCaretPeriod();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetCaretPeriod)(void* self,int periodMilliseconds)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetCaretPeriod(periodMilliseconds);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetWordChars)(void* self,wxString* characters)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetWordChars(*characters);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_BeginUndoAction)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->BeginUndoAction();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_EndUndoAction)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->EndUndoAction();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_IndicatorSetStyle)(void* self,int indic,int style)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->IndicatorSetStyle(indic, style);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_IndicatorGetStyle)(void* self,int indic)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->IndicatorGetStyle(indic);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_IndicatorSetForeground)(void* self,int indic,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->IndicatorSetForeground(indic, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetWhitespaceForeground)(void* self,bool useSetting,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetWhitespaceForeground(useSetting, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetWhitespaceBackground)(void* self,bool useSetting,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetWhitespaceBackground(useSetting, wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetStyleBits)(void* self,int bits)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetStyleBits(bits);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetStyleBits)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetStyleBits();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetLineState)(void* self,int line,int state)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetLineState(line, state);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLineState)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLineState(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMaxLineState)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMaxLineState();
#else
  return NULL;
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetCaretLineVisible)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCaretLineVisible();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetCaretLineVisible)(void* self,bool show)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetCaretLineVisible(show);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetChangeable)(void* self,int style,bool changeable)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetChangeable(style, changeable);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompShow)(void* self,int lenEntered,wxString* itemList)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompShow(lenEntered,*itemList);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompCancel)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompCancel();
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_AutoCompActive)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompActive();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_AutoCompPosStart)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompPosStart();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompComplete)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompComplete();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompStops)(void* self,wxString* characterSet)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompStops(*characterSet);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetSeparator)(void* self,int separatorCharacter)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetSeparator(separatorCharacter);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_AutoCompGetSeparator)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetSeparator();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSelect)(void* self,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSelect(*text);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetCancelAtStart)(void* self,bool cancel)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetCancelAtStart(cancel);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_AutoCompGetCancelAtStart)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetCancelAtStart();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetFillUps)(void* self,wxString* characterSet)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetFillUps(*characterSet);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetChooseSingle)(void* self,bool chooseSingle)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetChooseSingle(chooseSingle);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_AutoCompGetChooseSingle)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetChooseSingle();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetIgnoreCase)(void* self,bool ignoreCase)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetIgnoreCase(ignoreCase);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_AutoCompGetIgnoreCase)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetIgnoreCase();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_UserListShow)(void* self,int listType,wxString* itemList)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->UserListShow(listType,*itemList);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetAutoHide)(void* self,bool autoHide)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetAutoHide(autoHide);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_AutoCompGetAutoHide)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetAutoHide();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetDropRestOfWord)(void* self,bool dropRestOfWord)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetDropRestOfWord(dropRestOfWord);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_AutoCompGetDropRestOfWord)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetDropRestOfWord();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_RegisterImage)(void* self,int type,wxBitmap* bmp)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->RegisterImage(type,*bmp);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ClearRegisteredImages)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ClearRegisteredImages();
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_AutoCompGetTypeSeparator)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->AutoCompGetTypeSeparator();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AutoCompSetTypeSeparator)(void* self,int separatorCharacter)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AutoCompSetTypeSeparator(separatorCharacter);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetIndent)(void* self,int indentSize)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetIndent(indentSize);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetIndent)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetIndent();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetUseTabs)(void* self,bool useTabs)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetUseTabs(useTabs);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetUseTabs)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetUseTabs();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetLineIndentation)(void* self,int line,int indentSize)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetLineIndentation(line, indentSize);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLineIndentation)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLineIndentation(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLineIndentPosition)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLineIndentPosition(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetColumn)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetColumn(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetUseHorizontalScrollBar)(void* self,bool show)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetUseHorizontalScrollBar(show);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetUseHorizontalScrollBar)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetUseHorizontalScrollBar();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetIndentationGuides)(void* self,bool show)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetIndentationGuides(show);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetIndentationGuides)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetIndentationGuides();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetHighlightGuide)(void* self,int column)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetHighlightGuide(column);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetHighlightGuide)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetHighlightGuide();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLineEndPosition)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLineEndPosition(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetCodePage)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCodePage();
#else
  return NULL;
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetReadOnly)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetReadOnly();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetCurrentPos)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetCurrentPos(pos);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSelectionStart)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSelectionStart(pos);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetSelectionStart)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetSelectionStart();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSelectionEnd)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSelectionEnd(pos);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetSelectionEnd)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetSelectionEnd();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetPrintMagnification)(void* self,int magnification)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetPrintMagnification(magnification);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetPrintMagnification)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetPrintMagnification();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetPrintColourMode)(void* self,int mode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetPrintColourMode(mode);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetPrintColourMode)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetPrintColourMode();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_FindText)(void* self,int minPos,int maxPos,wxString* text,int flags)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->FindText(minPos, maxPos,*text, flags);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_FormatRange)(void* self,bool doDraw,int startPos,int endPos,void* draw,void* target,void* renderRect,void* pageRect)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->FormatRange(doDraw, startPos, endPos,*(wxDC**)draw,*(wxDC**)target,*(wxRect*)renderRect,*(wxRect*)pageRect);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetFirstVisibleLine)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetFirstVisibleLine();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLineCount)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLineCount();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMarginLeft)(void* self,int pixelWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMarginLeft(pixelWidth);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMarginLeft)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMarginLeft();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMarginRight)(void* self,int pixelWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMarginRight(pixelWidth);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMarginRight)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMarginRight();
#else
  return NULL;
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetModify)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetModify();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSelection)(void* self,int start,int end)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSelection(start, end);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_HideSelection)(void* self,bool normal)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->HideSelection(normal);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_LineFromPosition)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->LineFromPosition(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_PositionFromLine)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->PositionFromLine(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LineScroll)(void* self,int columns,int lines)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LineScroll(columns, lines);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_EnsureCaretVisible)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->EnsureCaretVisible();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ReplaceSelection)(void* self,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ReplaceSelection(*text);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetReadOnly)(void* self,bool readOnly)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetReadOnly(readOnly);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_CanPaste)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->CanPaste();
#else
  return NULL;
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_CanUndo)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->CanUndo();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_EmptyUndoBuffer)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->EmptyUndoBuffer();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Undo)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Undo();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Cut)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Cut();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Copy)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Copy();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Paste)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Paste();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Clear)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Clear();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetText)(void* self,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetText(*text);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetTextLength)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetTextLength();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetOvertype)(void* self,bool overtype)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetOvertype(overtype);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetOvertype)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetOvertype();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetCaretWidth)(void* self,int pixelWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetCaretWidth(pixelWidth);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetCaretWidth)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCaretWidth();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetTargetStart)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetTargetStart(pos);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetTargetStart)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetTargetStart();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetTargetEnd)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetTargetEnd(pos);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetTargetEnd)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetTargetEnd();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_ReplaceTarget)(void* self,wxString* text)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->ReplaceTarget(*text);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_ReplaceTargetRE)(void* self,wxString* text)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->ReplaceTargetRE(*text);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_SearchInTarget)(void* self,wxString* text)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->SearchInTarget(*text);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSearchFlags)(void* self,int flags)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSearchFlags(flags);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetSearchFlags)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetSearchFlags();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CallTipShow)(void* self,int pos,wxString* definition)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CallTipShow(pos,*definition);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CallTipCancel)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CallTipCancel();
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_CallTipActive)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->CallTipActive();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_CallTipPosAtStart)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->CallTipPosAtStart();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CallTipSetHighlight)(void* self,int start,int end)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CallTipSetHighlight(start, end);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CallTipSetBackground)(void* self,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CallTipSetBackground(wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CallTipSetForeground)(void* self,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CallTipSetForeground(wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CallTipSetForegroundHighlight)(void* self,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CallTipSetForegroundHighlight(wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_VisibleFromDocLine)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->VisibleFromDocLine(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_DocLineFromVisible)(void* self,int lineDisplay)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->DocLineFromVisible(lineDisplay);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetFoldLevel)(void* self,int line,int level)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetFoldLevel(line, level);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetFoldLevel)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetFoldLevel(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLastChild)(void* self,int line,int level)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLastChild(line, level);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetFoldParent)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetFoldParent(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ShowLines)(void* self,int lineStart,int lineEnd)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ShowLines(lineStart, lineEnd);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_HideLines)(void* self,int lineStart,int lineEnd)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->HideLines(lineStart, lineEnd);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetLineVisible)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLineVisible(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetFoldExpanded)(void* self,int line,bool expanded)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetFoldExpanded(line, expanded);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetFoldExpanded)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetFoldExpanded(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ToggleFold)(void* self,int line)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ToggleFold(line);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_EnsureVisible)(void* self,int line)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->EnsureVisible(line);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetFoldFlags)(void* self,int flags)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetFoldFlags(flags);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_EnsureVisibleEnforcePolicy)(void* self,int line)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->EnsureVisibleEnforcePolicy(line);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetTabIndents)(void* self,bool tabIndents)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetTabIndents(tabIndents);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetTabIndents)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetTabIndents();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetBackSpaceUnIndents)(void* self,bool bsUnIndents)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetBackSpaceUnIndents(bsUnIndents);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetBackSpaceUnIndents)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetBackSpaceUnIndents();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMouseDwellTime)(void* self,int periodMilliseconds)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMouseDwellTime(periodMilliseconds);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetMouseDwellTime)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMouseDwellTime();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_WordStartPosition)(void* self,int pos,bool onlyWordCharacters)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->WordStartPosition(pos, onlyWordCharacters);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_WordEndPosition)(void* self,int pos,bool onlyWordCharacters)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->WordEndPosition(pos, onlyWordCharacters);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetWrapMode)(void* self,int mode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetWrapMode(mode);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetWrapMode)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetWrapMode();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetLayoutCache)(void* self,int mode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetLayoutCache(mode);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLayoutCache)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLayoutCache();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetScrollWidth)(void* self,int pixelWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetScrollWidth(pixelWidth);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetScrollWidth)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetScrollWidth();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_TextWidth)(void* self,int style,wxString* text)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->TextWidth(style,*text);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetEndAtLastLine)(void* self,bool endAtLastLine)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetEndAtLastLine(endAtLastLine);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetEndAtLastLine)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetEndAtLastLine();
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_TextHeight)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->TextHeight(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetUseVerticalScrollBar)(void* self,bool show)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetUseVerticalScrollBar(show);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetUseVerticalScrollBar)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetUseVerticalScrollBar();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AppendText)(void* self,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AppendText(*text);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetTwoPhaseDraw)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetTwoPhaseDraw();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetTwoPhaseDraw)(void* self,bool twoPhase)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetTwoPhaseDraw(twoPhase);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_TargetFromSelection)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->TargetFromSelection();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LinesJoin)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LinesJoin();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LinesSplit)(void* self,int pixelWidth)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LinesSplit(pixelWidth);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetFoldMarginColour)(void* self,bool useSetting,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetFoldMarginColour(useSetting, wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetFoldMarginHiColour)(void* self,bool useSetting,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetFoldMarginHiColour(useSetting, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LineDuplicate)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LineDuplicate();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_HomeDisplay)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->HomeDisplay();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_HomeDisplayExtend)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->HomeDisplayExtend();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LineEndDisplay)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LineEndDisplay();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LineEndDisplayExtend)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LineEndDisplayExtend();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_LineCopy)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->LineCopy();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_MoveCaretInsideView)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->MoveCaretInsideView();
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_LineLength)(void* self,int line)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->LineLength(line);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_BraceHighlight)(void* self,int pos1,int pos2)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->BraceHighlight(pos1, pos2);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_BraceBadLight)(void* self,int pos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->BraceBadLight(pos);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_BraceMatch)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->BraceMatch(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetViewEOL)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetViewEOL();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetViewEOL)(void* self,bool visible)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetViewEOL(visible);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetDocPointer)(void* self,void* docPointer)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetDocPointer(docPointer);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetModEventMask)(void* self,int mask)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetModEventMask(mask);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetEdgeColumn)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetEdgeColumn();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetEdgeColumn)(void* self,int column)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetEdgeColumn(column);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetEdgeMode)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetEdgeMode();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetEdgeMode)(void* self,int mode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetEdgeMode(mode);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetEdgeColour)(void* self,int edgeColour_r,int edgeColour_g,int edgeColour_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetEdgeColour(wxColour(edgeColour_r,edgeColour_g,edgeColour_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SearchAnchor)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SearchAnchor();
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_SearchNext)(void* self,int flags,wxString* text)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->SearchNext(flags,*text);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_SearchPrev)(void* self,int flags,wxString* text)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->SearchPrev(flags,*text);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_LinesOnScreen)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->LinesOnScreen();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_UsePopUp)(void* self,bool allowPopUp)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->UsePopUp(allowPopUp);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_SelectionIsRectangle)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->SelectionIsRectangle();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetZoom)(void* self,int zoom)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetZoom(zoom);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetZoom)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetZoom();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_AddRefDocument)(void* self,void* docPointer)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->AddRefDocument(docPointer);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ReleaseDocument)(void* self,void* docPointer)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ReleaseDocument(docPointer);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetModEventMask)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetModEventMask();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSTCFocus)(void* self,bool focus)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSTCFocus(focus);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetSTCFocus)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetSTCFocus();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetStatus)(void* self,int statusCode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetStatus(statusCode);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetStatus)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetStatus();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMouseDownCaptures)(void* self,bool captures)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMouseDownCaptures(captures);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetMouseDownCaptures)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetMouseDownCaptures();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetSTCCursor)(void* self,int cursorType)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetSTCCursor(cursorType);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetSTCCursor)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetSTCCursor();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetControlCharSymbol)(void* self,int symbol)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetControlCharSymbol(symbol);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetControlCharSymbol)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetControlCharSymbol();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_WordPartLeft)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->WordPartLeft();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_WordPartLeftExtend)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->WordPartLeftExtend();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_WordPartRight)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->WordPartRight();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_WordPartRightExtend)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->WordPartRightExtend();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetVisiblePolicy)(void* self,int visiblePolicy,int visibleSlop)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetVisiblePolicy(visiblePolicy, visibleSlop);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_DelLineLeft)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->DelLineLeft();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_DelLineRight)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->DelLineRight();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetXOffset)(void* self,int newOffset)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetXOffset(newOffset);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetXOffset)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetXOffset();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ChooseCaretX)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ChooseCaretX();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetXCaretPolicy)(void* self,int caretPolicy,int caretSlop)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetXCaretPolicy(caretPolicy, caretSlop);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetYCaretPolicy)(void* self,int caretPolicy,int caretSlop)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetYCaretPolicy(caretPolicy, caretSlop);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetPrintWrapMode)(void* self,int mode)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetPrintWrapMode(mode);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetPrintWrapMode)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetPrintWrapMode();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetHotspotActiveForeground)(void* self,bool useSetting,int fore_r,int fore_g,int fore_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetHotspotActiveForeground(useSetting, wxColour(fore_r,fore_g,fore_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetHotspotActiveBackground)(void* self,bool useSetting,int back_r,int back_g,int back_b)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetHotspotActiveBackground(useSetting, wxColour(back_r,back_g,back_b));
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetHotspotActiveUnderline)(void* self,bool underline)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetHotspotActiveUnderline(underline);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_PositionBefore)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->PositionBefore(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_PositionAfter)(void* self,int pos)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->PositionAfter(pos);
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CopyRange)(void* self,int start,int end)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CopyRange(start, end);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CopyText)(void* self,int length,wxString* text)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CopyText(length,*text);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StartRecord)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StartRecord();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StopRecord)(void* self)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StopRecord();
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetLexer)(void* self,int lexer)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetLexer(lexer);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetLexer)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLexer();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_Colourise)(void* self,int start,int end)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->Colourise(start, end);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetProperty)(void* self,wxString* key,wxString* value)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetProperty(*key,*value);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetKeyWords)(void* self,int keywordSet,wxString* keyWords)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetKeyWords(keywordSet,*keyWords);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetLexerLanguage)(void* self,wxString* language)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetLexerLanguage(*language);
#endif
}
EWXWEXPORT(int,wxStyledTextCtrl_GetCurrentLine)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetCurrentLine();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetSpec)(void* self,int styleNum,wxString* spec)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetSpec(styleNum,*spec);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetFont)(void* self,int styleNum,void* font)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetFont(styleNum,*(wxFont*)font);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_StyleSetFontAttr)(void* self,int styleNum,int size,wxString* faceName,bool bold,bool italic,bool underline)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->StyleSetFontAttr(styleNum, size,*faceName, bold, italic, underline);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_CmdKeyExecute)(void* self,int cmd)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->CmdKeyExecute(cmd);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetMargins)(void* self,int left,int right)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetMargins(left, right);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_GetSelection)(void* self,void* startPos,void* endPos)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->GetSelection(*(int**)startPos,*(int**)endPos);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ScrollToLine)(void* self,int line)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ScrollToLine(line);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_ScrollToColumn)(void* self,int column)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->ScrollToColumn(column);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetVScrollBar)(void* self,void* bar)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetVScrollBar(*(wxScrollBar**)bar);
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetHScrollBar)(void* self,void* bar)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetHScrollBar(*(wxScrollBar**)bar);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_GetLastKeydownProcessed)(void* self)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->GetLastKeydownProcessed();
#else
  return NULL;
#endif
}
EWXWEXPORT(void,wxStyledTextCtrl_SetLastKeydownProcessed)(void* self,bool val)
{
#ifdef wxUSE_STC
   ((wxStyledTextCtrl*)self)->SetLastKeydownProcessed(val);
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_SaveFile)(void* self,wxString* filename)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->SaveFile(*filename);
#else
  return NULL;
#endif
}
EWXWEXPORT(bool,wxStyledTextCtrl_LoadFile)(void* self,wxString* filename)
{
#ifdef wxUSE_STC
  return ((wxStyledTextCtrl*)self)->LoadFile(*filename);
#else
  return NULL;
#endif
}
