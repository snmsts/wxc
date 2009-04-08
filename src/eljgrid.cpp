#include "wrapper.h"
#include "eljgrid.h"

extern "C"
{

EWXWEXPORT(wxGridCellCoordsArray*,wxGridCellCoordsArray_Create)()
{
	return new wxGridCellCoordsArray();
}

EWXWEXPORT(void,wxGridCellCoordsArray_Delete)(wxGridCellCoordsArray* self)
{
	delete self;
}

EWXWEXPORT(int,wxGridCellCoordsArray_GetCount)(wxGridCellCoordsArray* self)
{
	return self->GetCount();
}

EWXWEXPORT(void,wxGridCellCoordsArray_Item)(wxGridCellCoordsArray* self,int _idx,int* _c,int* _r)
{
	*_c = self->Item(_idx).GetCol();
	*_r = self->Item(_idx).GetRow();
}


EWXWEXPORT(bool,wxGridCellEditor_IsCreated)(wxGridCellEditor* self)
{
	return self->IsCreated();
}
	
EWXWEXPORT(void*,wxGridCellEditor_GetControl)(wxGridCellEditor* self)
{
	return (void*)self->GetControl();
}
	
EWXWEXPORT(void,wxGridCellEditor_SetControl)(wxGridCellEditor* self,wxControl* control)
{
	self->SetControl(control);
}
	
EWXWEXPORT(void,wxGridCellEditor_Create)(wxGridCellEditor* self,wxWindow* parent,int id,wxEvtHandler* evtHandler)
{
	self->Create(parent, (wxWindowID) id, evtHandler);
}
	
EWXWEXPORT(void,wxGridCellEditor_SetSize)(wxGridCellEditor* self,int x,int y,int w,int h)
{
	self->SetSize(wxRect(x, y, w, h));
}
	
EWXWEXPORT(void,wxGridCellEditor_Show)(wxGridCellEditor* self,bool show,void* attr)
{
	self->Show(show, (wxGridCellAttr*)attr);
}
	
EWXWEXPORT(void,wxGridCellEditor_PaintBackground)(wxGridCellEditor* self,int x,int y,int w,int h,void* attr)
{
	self->PaintBackground(wxRect(x, y, w, h), (wxGridCellAttr*)attr);
}
	
EWXWEXPORT(void,wxGridCellEditor_BeginEdit)(wxGridCellEditor* self,int row,int col,void* grid)
{
	self->BeginEdit(row, col, (wxGrid*)grid);
}
	
EWXWEXPORT(bool,wxGridCellEditor_EndEdit)(wxGridCellEditor* self,int row,int col,wxGrid* grid)
{
	return self->EndEdit(row, col,  grid);
}
	
EWXWEXPORT(void,wxGridCellEditor_Reset)(wxGridCellEditor* self)
{
	self->Reset();
}
	
EWXWEXPORT(bool,wxGridCellEditor_IsAcceptedKey)(wxGridCellEditor* self,wxKeyEvent* event)
{
	return self->IsAcceptedKey(*event);
}
	
EWXWEXPORT(void,wxGridCellEditor_StartingKey)(wxGridCellEditor* self,wxKeyEvent* event)
{
	self->StartingKey(*event);
}
	
EWXWEXPORT(void,wxGridCellEditor_StartingClick)(wxGridCellEditor* self)
{
	self->StartingClick();
}
	
EWXWEXPORT(void,wxGridCellEditor_HandleReturn)(wxGridCellEditor* self,wxKeyEvent* event)
{
	self->HandleReturn(*event);
}
	
EWXWEXPORT(void,wxGridCellEditor_Destroy)(wxGridCellEditor* self)
{
	self->Destroy();
}
	
EWXWEXPORT(void,wxGridCellEditor_SetParameters)(wxGridCellEditor* self,wxString* params)
{
	self->SetParameters(*params);
}
	
EWXWEXPORT(void*,wxGridCellTextEditor_Ctor)()
{
	return (void*)new wxGridCellTextEditor();
}

EWXWEXPORT(void*,wxGridCellNumberEditor_Ctor)(int min,int max)
{
	return (void*)new wxGridCellNumberEditor(min, max);
}

EWXWEXPORT(void*,wxGridCellFloatEditor_Ctor)(int width,int precision)
{
	return (void*)new wxGridCellFloatEditor(width, precision);
}

EWXWEXPORT(void*,wxGridCellBoolEditor_Ctor)()
{
	return (void*)new wxGridCellBoolEditor();
}

EWXWEXPORT(void*,wxGridCellChoiceEditor_Ctor)(int count,void* choices,bool allowOthers)
{
	wxString items[256];

	for (int i = 0; i < count; i++)
		items[i] = ((wxChar**)choices)[i];

	return (void*)new wxGridCellChoiceEditor (count, items, allowOthers);
}

EWXWEXPORT(void*,wxGridCellAttr_Ctor)()
{
	return (void*)new wxGridCellAttr();
}

EWXWEXPORT(void,wxGridCellAttr_IncRef)(void* self)
{
	((wxGridCellAttr*)self)->IncRef();
}
	
EWXWEXPORT(void,wxGridCellAttr_DecRef)(void* self)
{
	((wxGridCellAttr*)self)->DecRef();
}
	
EWXWEXPORT(void,wxGridCellAttr_SetTextColour)(void* self,wxColour* colText)
{
	((wxGridCellAttr*)self)->SetTextColour(*colText);
}
	
EWXWEXPORT(void,wxGridCellAttr_SetBackgroundColour)(void* self,wxColour* colBack)
{
	((wxGridCellAttr*)self)->SetBackgroundColour(*colBack);
}
	
EWXWEXPORT(void,wxGridCellAttr_SetFont)(void* self,wxFont* font)
{
	((wxGridCellAttr*)self)->SetFont(*font);
}
	
EWXWEXPORT(void,wxGridCellAttr_SetAlignment)(void* self,int hAlign,int vAlign)
{
	((wxGridCellAttr*)self)->SetAlignment(hAlign, vAlign);
}
	
EWXWEXPORT(void,wxGridCellAttr_SetReadOnly)(void* self,bool isReadOnly)
{
	((wxGridCellAttr*)self)->SetReadOnly(isReadOnly);
}
	
EWXWEXPORT(void,wxGridCellAttr_SetRenderer)(void* self,void* renderer)
{
	((wxGridCellAttr*)self)->SetRenderer((wxGridCellRenderer*)renderer);
}
	
EWXWEXPORT(void,wxGridCellAttr_SetEditor)(void* self,wxGridCellEditor* editor)
{
	((wxGridCellAttr*)self)->SetEditor(editor);
}
	
EWXWEXPORT(bool,wxGridCellAttr_HasTextColour)(wxGridCellAttr* self)
{
	return self->HasTextColour();
}
	
EWXWEXPORT(bool,wxGridCellAttr_HasBackgroundColour)(wxGridCellAttr* self)
{
	return self->HasBackgroundColour();
}
	
EWXWEXPORT(bool,wxGridCellAttr_HasFont)(wxGridCellAttr* self)
{
	return self->HasFont();
}
	
EWXWEXPORT(bool,wxGridCellAttr_HasAlignment)(wxGridCellAttr* self)
{
	return self->HasAlignment();
}
	
EWXWEXPORT(bool,wxGridCellAttr_HasRenderer)(wxGridCellAttr* self)
{
	return self->HasRenderer();
}
	
EWXWEXPORT(bool,wxGridCellAttr_HasEditor)(wxGridCellAttr* self)
{
	return self->HasEditor();
}
	
EWXWEXPORT(void,wxGridCellAttr_GetTextColour)(void* self,wxColour* colour)
{
	*colour = ((wxGridCellAttr*)self)->GetTextColour();
}
	
EWXWEXPORT(void,wxGridCellAttr_GetBackgroundColour)(void* self,wxColour* colour)
{
	*colour = ((wxGridCellAttr*)self)->GetBackgroundColour();
}
	
EWXWEXPORT(void,wxGridCellAttr_GetFont)(void* self,wxFont* font)
{
	*font = ((wxGridCellAttr*)self)->GetFont();
}
	
EWXWEXPORT(void,wxGridCellAttr_GetAlignment)(void* self,int* hAlign,int* vAlign)
{
	((wxGridCellAttr*)self)->GetAlignment(hAlign, vAlign);
}
	
EWXWEXPORT(void*,wxGridCellAttr_GetRenderer)(void* self,void* grid,int row,int col)
{
	return (void*)((wxGridCellAttr*)self)->GetRenderer((wxGrid*)grid, row, col);
}
	
EWXWEXPORT(void*,wxGridCellAttr_GetEditor)(void* self,void* grid,int row,int col)
{
	return (void*)((wxGridCellAttr*)self)->GetEditor((wxGrid*)grid, row, col);
}
	
EWXWEXPORT(bool,wxGridCellAttr_IsReadOnly)(wxGridCellAttr* self)
{
	return self->IsReadOnly();
}
	
EWXWEXPORT(void,wxGridCellAttr_SetDefAttr)(void* self,void* defAttr)
{
	((wxGridCellAttr*)self)->SetDefAttr((wxGridCellAttr*)defAttr);
}
	
EWXWEXPORT(void*,wxGrid_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxGrid (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl | wxWANTS_CHARS);
}

EWXWEXPORT(void,wxGrid_CreateGrid)(void* self,int rows,int cols,int selmode)
{
	((wxGrid*)self)->CreateGrid (rows, cols, (wxGrid::wxGridSelectionModes)selmode);
}

EWXWEXPORT(void,wxGrid_SetSelectionMode)(void* self,int selmode)
{
	((wxGrid*)self)->SetSelectionMode((wxGrid::wxGridSelectionModes) selmode);
}
	
EWXWEXPORT(int,wxGrid_GetNumberRows)(void* self)
{
	return ((wxGrid*)self)->GetNumberRows();
}
	
EWXWEXPORT(int,wxGrid_GetNumberCols)(void* self)
{
	return ((wxGrid*)self)->GetNumberCols();
}
	
EWXWEXPORT(void,wxGrid_CalcRowLabelsExposed)(void* self,void* reg)
{
	((wxGrid*)self)->CalcRowLabelsExposed(*((wxRegion*)reg));
}
	
EWXWEXPORT(void,wxGrid_CalcColLabelsExposed)(void* self,void* reg)
{
	((wxGrid*)self)->CalcColLabelsExposed(*((wxRegion*)reg));
}
	
EWXWEXPORT(void,wxGrid_CalcCellsExposed)(void* self,void* reg)
{
	((wxGrid*)self)->CalcCellsExposed(*((wxRegion*)reg));
}
	
EWXWEXPORT(void,wxGrid_NewCalcCellsExposed)(void* self,void* reg,wxGridCellCoordsArray* arr)
{
#if wxVERSION_NUMBER >= 2400
	*arr = ((wxGrid*)self)->CalcCellsExposed(*((wxRegion*)reg));
#endif
}
	
EWXWEXPORT(void,wxGrid_ProcessRowLabelMouseEvent)(void* self,wxMouseEvent* event)
{
	((wxGrid*)self)->ProcessRowLabelMouseEvent(*event);
}
	
EWXWEXPORT(void,wxGrid_ProcessColLabelMouseEvent)(void* self,wxMouseEvent* event)
{
	((wxGrid*)self)->ProcessColLabelMouseEvent(*event);
}
	
EWXWEXPORT(void,wxGrid_ProcessCornerLabelMouseEvent)(void* self,wxMouseEvent* event)
{
	((wxGrid*)self)->ProcessCornerLabelMouseEvent(*event);
}
	
EWXWEXPORT(void,wxGrid_ProcessGridCellMouseEvent)(void* self,wxMouseEvent* event)
{
	((wxGrid*)self)->ProcessGridCellMouseEvent(*event);
}
	
EWXWEXPORT(bool,wxGrid_ProcessTableMessage)(wxGrid* self,wxGridTableMessage* evt)
{
	return self->ProcessTableMessage(*evt);
}
	
EWXWEXPORT(void,wxGrid_DoEndDragResizeRow)(void* self)
{
	((wxGrid*)self)->DoEndDragResizeRow();
}
	
EWXWEXPORT(void,wxGrid_DoEndDragResizeCol)(void* self)
{
	((wxGrid*)self)->DoEndDragResizeCol();
}
	
EWXWEXPORT(void*,wxGrid_GetTable)(void* self)
{
	return (void*)((wxGrid*)self)->GetTable();
}
	
EWXWEXPORT(bool,wxGrid_SetTable)(wxGrid* self,wxGridTableBase* table,bool takeOwnership,int selmode)
{
	return self->SetTable(table, takeOwnership , (wxGrid::wxGridSelectionModes) selmode);
}
	
EWXWEXPORT(void,wxGrid_ClearGrid)(void* self)
{
	((wxGrid*)self)->ClearGrid();
}
	
EWXWEXPORT(bool,wxGrid_InsertRows)(wxGrid* self,int pos,int numRows,bool updateLabels)
{
	return self->InsertRows(pos, numRows, updateLabels);
}
	
EWXWEXPORT(bool,wxGrid_AppendRows)(wxGrid* self,int numRows,bool updateLabels)
{
	return self->AppendRows(numRows, updateLabels);
}
	
EWXWEXPORT(bool,wxGrid_DeleteRows)(wxGrid* self,int pos,int numRows,bool updateLabels)
{
	return self->DeleteRows(pos, numRows, updateLabels);
}
	
EWXWEXPORT(bool,wxGrid_InsertCols)(wxGrid* self,int pos,int numCols,bool updateLabels)
{
	return self->InsertCols(pos, numCols, updateLabels);
}
	
EWXWEXPORT(bool,wxGrid_AppendCols)(wxGrid* self,int numCols,int updateLabels)
{
	return self->AppendCols( numCols, updateLabels);
}
	
EWXWEXPORT(bool,wxGrid_DeleteCols)(wxGrid* self,int pos,int numCols,bool updateLabels)
{
	return self->DeleteCols(pos, numCols, updateLabels);
}
	
EWXWEXPORT(void,wxGrid_DrawGridCellArea)(void* self,wxDC* dc)
{
#if wxVERSION_NUMBER >= 2400
	wxGridCellCoordsArray arr;
	((wxGrid*)self)->DrawGridCellArea(*dc, arr);
#else
	((wxGrid*)self)->DrawGridCellArea(*dc);
#endif
}
	
EWXWEXPORT(void,wxGrid_NewDrawGridCellArea)(void* self,wxDC* dc,wxGridCellCoordsArray* arr)
{
#if wxVERSION_NUMBER >= 2400
	((wxGrid*)self)->DrawGridCellArea(*dc,*arr);
#endif
}
	
EWXWEXPORT(void,wxGrid_DrawGridSpace)(void* self,wxDC* dc)
{
	((wxGrid*)self)->DrawGridSpace(*dc);
}
	
EWXWEXPORT(void,wxGrid_DrawCellBorder)(void* self,wxDC* dc,int _row,int _col)
{
	((wxGrid*)self)->DrawCellBorder(*dc, wxGridCellCoords(_row, _col));
}
	
EWXWEXPORT(void,wxGrid_DrawAllGridLines)(void* self,wxDC* dc,void* reg)
{
	((wxGrid*)self)->DrawAllGridLines(*dc,*((wxRegion*)reg));
}
	
EWXWEXPORT(void,wxGrid_DrawCell)(void* self,wxDC* dc,int _row,int _col)
{
	((wxGrid*)self)->DrawCell(*dc, wxGridCellCoords(_row, _col));
}
	
EWXWEXPORT(void,wxGrid_DrawHighlight)(void* self,wxDC* dc)
{
#if wxVERSION_NUMBER >= 2400
	wxGridCellCoordsArray arr;
	((wxGrid*)self)->DrawHighlight(*dc, arr);
#else
	((wxGrid*)self)->DrawHighlight(*dc);
#endif
}
	
EWXWEXPORT(void,wxGrid_NewDrawHighlight)(void* self,wxDC* dc,wxGridCellCoordsArray* arr)
{
#if wxVERSION_NUMBER >= 2400
	((wxGrid*)self)->DrawHighlight(*dc,*arr);
#endif
}
	
EWXWEXPORT(void,wxGrid_DrawCellHighlight)(void* self,wxDC* dc,void* attr)
{
	((wxGrid*)self)->DrawCellHighlight(*dc, (const wxGridCellAttr*)attr);
}
	
EWXWEXPORT(void,wxGrid_DrawRowLabels)(void* self,wxDC* dc)
{
#if wxVERSION_NUMBER >= 2400
	wxArrayInt arr;
	((wxGrid*)self)->DrawRowLabels(*dc, arr);
#else
	((wxGrid*)self)->DrawRowLabels(*dc);
#endif
}
	
EWXWEXPORT(void,wxGrid_DrawRowLabel)(void* self,wxDC* dc,int row)
{
	((wxGrid*)self)->DrawRowLabel(*dc, row);
}
	
EWXWEXPORT(void,wxGrid_DrawColLabels)(void* self,wxDC* dc)
{
#if wxVERSION_NUMBER >= 2400
	wxArrayInt arr;
	((wxGrid*)self)->DrawColLabels(*dc, arr);
#else
	((wxGrid*)self)->DrawColLabels(*dc);
#endif
}
	
EWXWEXPORT(void,wxGrid_DrawColLabel)(void* self,wxDC* dc,int col)
{
	((wxGrid*)self)->DrawColLabel(*dc, col);
}
	
EWXWEXPORT(void,wxGrid_DrawTextRectangle)(void* self,wxDC* dc,wxString* txt,int x,int y,int w,int h,int horizontalAlignment,int verticalAlignment)
{
	((wxGrid*)self)->DrawTextRectangle(*dc,*txt, wxRect(x, y, w, h), horizontalAlignment, verticalAlignment);
}
	
EWXWEXPORT(int,wxGrid_StringToLines)(void* self,wxString* value,void* lines)
{
	int result = 0;
	wxArrayString arr;
	
	((wxGrid*)self)->StringToLines(*value, arr);
	
	result = arr.GetCount();
	
	if (lines)
	{
		for (int i = 0; i < result; i++)
			((const wxChar**)lines)[i] = wxStrdup (arr[i].c_str());
	}
	return result;
}
	
EWXWEXPORT(void,wxGrid_GetTextBoxSize)(void* self,wxDC* dc,int count,void* lines,void* width,void* height)
{
	wxArrayString arr;

	for (int i = 0; i < count; i++)
		arr[i] = ((wxChar**)lines)[i];

	((wxGrid*)self)->GetTextBoxSize(*dc, arr, (long*)width, (long*)height);
}
	
EWXWEXPORT(void,wxGrid_BeginBatch)(void* self)
{
	((wxGrid*)self)->BeginBatch();
}
	
EWXWEXPORT(void,wxGrid_EndBatch)(void* self)
{
	((wxGrid*)self)->EndBatch();
}
	
EWXWEXPORT(int,wxGrid_GetBatchCount)(void* self)
{
	return ((wxGrid*)self)->GetBatchCount();
}
	
EWXWEXPORT(bool,wxGrid_IsEditable)(wxGrid* self)
{
	return self->IsEditable();
}
	
EWXWEXPORT(void,wxGrid_EnableEditing)(void* self,bool edit)
{
	((wxGrid*)self)->EnableEditing(edit);
}
	
EWXWEXPORT(void,wxGrid_EnableCellEditControl)(void* self,bool enable)
{
	((wxGrid*)self)->EnableCellEditControl(enable);
}
	
EWXWEXPORT(void,wxGrid_DisableCellEditControl)(void* self)
{
	((wxGrid*)self)->DisableCellEditControl();
}
	
EWXWEXPORT(bool,wxGrid_CanEnableCellControl)(wxGrid* self)
{
	return self->CanEnableCellControl();
}
	
EWXWEXPORT(bool,wxGrid_IsCellEditControlEnabled)(wxGrid* self)
{
	return self->IsCellEditControlEnabled();
}
	
EWXWEXPORT(bool,wxGrid_IsCellEditControlShown)(wxGrid* self)
{
	return self->IsCellEditControlShown();
}
	
EWXWEXPORT(bool,wxGrid_IsCurrentCellReadOnly)(wxGrid* self)
{
	return self->IsCurrentCellReadOnly();
}
	
EWXWEXPORT(void,wxGrid_ShowCellEditControl)(void* self)
{
	((wxGrid*)self)->ShowCellEditControl();
}
	
EWXWEXPORT(void,wxGrid_HideCellEditControl)(void* self)
{
	((wxGrid*)self)->HideCellEditControl();
}
	
EWXWEXPORT(void,wxGrid_SaveEditControlValue)(void* self)
{
	((wxGrid*)self)->SaveEditControlValue();
}
	
EWXWEXPORT(void,wxGrid_XYToCell)(void* self,int x,int y,int* r,int* c)
{
	wxGridCellCoords cds;
	((wxGrid*)self)->XYToCell(x, y, cds);
	*r = cds.GetRow();
	*c = cds.GetCol();
}
	
EWXWEXPORT(int,wxGrid_YToRow)(void* self,int y)
{
	return ((wxGrid*)self)->YToRow(y);
}
	
EWXWEXPORT(int,wxGrid_XToCol)(void* self,int x)
{
	return ((wxGrid*)self)->XToCol(x);
}
	
EWXWEXPORT(int,wxGrid_YToEdgeOfRow)(void* self,int y)
{
	return ((wxGrid*)self)->YToEdgeOfRow(y);
}
	
EWXWEXPORT(int,wxGrid_XToEdgeOfCol)(void* self,int x)
{
	return ((wxGrid*)self)->XToEdgeOfCol(x);
}
	
EWXWEXPORT(wxRect*,wxGrid_CellToRect)(void* self,int row,int col)
{
  wxRect* r = new wxRect();
  *r = ((wxGrid*)self)->CellToRect(row, col);
  return r;
}
	
EWXWEXPORT(int,wxGrid_GetGridCursorRow)(void* self)
{
	return ((wxGrid*)self)->GetGridCursorRow();
}
	
EWXWEXPORT(int,wxGrid_GetGridCursorCol)(void* self)
{
	return ((wxGrid*)self)->GetGridCursorCol();
}
	
EWXWEXPORT(bool,wxGrid_IsVisible)(wxGrid* self,int row,int col,bool wholeCellVisible)
{
	return self->IsVisible(row, col, wholeCellVisible);
}
	
EWXWEXPORT(void,wxGrid_MakeCellVisible)(void* self,int row,int col)
{
	((wxGrid*)self)->MakeCellVisible(row, col);
}
	
EWXWEXPORT(void,wxGrid_SetGridCursor)(void* self,int row,int col)
{
	((wxGrid*)self)->SetGridCursor(row, col);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorUp)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorUp(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorDown)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorDown(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorLeft)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorLeft(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorRight)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorRight(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MovePageDown)(wxGrid* self)
{
	return self->MovePageDown();
}
	
EWXWEXPORT(bool,wxGrid_MovePageUp)(wxGrid* self)
{
	return self->MovePageUp();
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorUpBlock)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorUpBlock(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorDownBlock)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorDownBlock(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorLeftBlock)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorLeftBlock(expandSelection);
}
	
EWXWEXPORT(bool,wxGrid_MoveCursorRightBlock)(wxGrid* self,bool expandSelection)
{
	return self->MoveCursorRightBlock(expandSelection);
}
	
EWXWEXPORT(int,wxGrid_GetDefaultRowLabelSize)(void* self)
{
	return ((wxGrid*)self)->GetDefaultRowLabelSize();
}
	
EWXWEXPORT(int,wxGrid_GetRowLabelSize)(void* self)
{
	return ((wxGrid*)self)->GetRowLabelSize();
}
	
EWXWEXPORT(int,wxGrid_GetDefaultColLabelSize)(void* self)
{
	return ((wxGrid*)self)->GetDefaultColLabelSize();
}
	
EWXWEXPORT(int,wxGrid_GetColLabelSize)(void* self)
{
	return ((wxGrid*)self)->GetColLabelSize();
}
	
EWXWEXPORT(void,wxGrid_GetLabelBackgroundColour)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetLabelBackgroundColour();
}
	
EWXWEXPORT(void,wxGrid_GetLabelTextColour)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetLabelTextColour();
}
	
EWXWEXPORT(void,wxGrid_GetLabelFont)(void* self,wxFont* font)
{
	*font = ((wxGrid*)self)->GetLabelFont();
}
	
EWXWEXPORT(void,wxGrid_GetRowLabelAlignment)(void* self,int* horiz,int* vert)
{
	((wxGrid*)self)->GetRowLabelAlignment(horiz,vert);
}
	
EWXWEXPORT(void,wxGrid_GetColLabelAlignment)(void* self,int* horiz,int* vert)
{
	((wxGrid*)self)->GetColLabelAlignment(horiz,vert);
}
	
EWXWEXPORT(wxString*,wxGrid_GetRowLabelValue)(void* self,int row)
{
  return new wxString(((wxGrid*)self)->GetRowLabelValue(row));
}
	
EWXWEXPORT(wxString*,wxGrid_GetColLabelValue)(void* self,int col)
{
  return new wxString(((wxGrid*)self)->GetColLabelValue(col));
}
	
EWXWEXPORT(void,wxGrid_GetGridLineColour)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetGridLineColour();
}
	
EWXWEXPORT(void,wxGrid_GetCellHighlightColour)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetCellHighlightColour();
}
	
EWXWEXPORT(void,wxGrid_SetRowLabelSize)(void* self,int width)
{
	((wxGrid*)self)->SetRowLabelSize(width);
}
	
EWXWEXPORT(void,wxGrid_SetColLabelSize)(void* self,int height)
{
	((wxGrid*)self)->SetColLabelSize(height);
}
	
EWXWEXPORT(void,wxGrid_SetLabelBackgroundColour)(void* self,wxColour* colour)
{
	((wxGrid*)self)->SetLabelBackgroundColour(*colour);
}
	
EWXWEXPORT(void,wxGrid_SetLabelTextColour)(void* self,wxColour* colour)
{
	((wxGrid*)self)->SetLabelTextColour(*colour);
}
	
EWXWEXPORT(void,wxGrid_SetLabelFont)(void* self,wxFont* font)
{
	((wxGrid*)self)->SetLabelFont(*font);
}
	
EWXWEXPORT(void,wxGrid_SetRowLabelAlignment)(void* self,int horiz,int vert)
{
	((wxGrid*)self)->SetRowLabelAlignment(horiz, vert);
}
	
EWXWEXPORT(void,wxGrid_SetColLabelAlignment)(void* self,int horiz,int vert)
{
	((wxGrid*)self)->SetColLabelAlignment(horiz, vert);
}
	
EWXWEXPORT(void,wxGrid_SetRowLabelValue)(void* self,int row,wxString* label)
{
	((wxGrid*)self)->SetRowLabelValue(row,*label);
}
	
EWXWEXPORT(void,wxGrid_SetColLabelValue)(void* self,int col,wxString* label)
{
	((wxGrid*)self)->SetColLabelValue(col,*label);
}
	
EWXWEXPORT(void,wxGrid_SetGridLineColour)(void* self,wxColour* col)
{
	((wxGrid*)self)->SetGridLineColour(*col);
}
	
EWXWEXPORT(void,wxGrid_SetCellHighlightColour)(void* self,wxColour* col)
{
	((wxGrid*)self)->SetCellHighlightColour(*col);
}
	
EWXWEXPORT(void,wxGrid_EnableDragRowSize)(void* self,bool enable)
{
	((wxGrid*)self)->EnableDragRowSize(enable);
}
	
EWXWEXPORT(void,wxGrid_DisableDragRowSize)(void* self)
{
	((wxGrid*)self)->DisableDragRowSize();
}
	
EWXWEXPORT(bool,wxGrid_CanDragRowSize)(wxGrid* self)
{
	return self->CanDragRowSize();
}
	
EWXWEXPORT(void,wxGrid_EnableDragColSize)(void* self,bool enable)
{
	((wxGrid*)self)->EnableDragColSize(enable);
}
	
EWXWEXPORT(void,wxGrid_DisableDragColSize)(void* self)
{
	((wxGrid*)self)->DisableDragColSize();
}
	
EWXWEXPORT(bool,wxGrid_CanDragColSize)(wxGrid* self)
{
	return self->CanDragColSize();
}
	
EWXWEXPORT(void,wxGrid_EnableDragGridSize)(void* self,bool enable)
{
	((wxGrid*)self)->EnableDragGridSize(enable);
}
	
EWXWEXPORT(void,wxGrid_DisableDragGridSize)(void* self)
{
	((wxGrid*)self)->DisableDragGridSize();
}
	
EWXWEXPORT(bool,wxGrid_CanDragGridSize)(wxGrid* self)
{
	return self->CanDragGridSize();
}
	
EWXWEXPORT(void,wxGrid_SetRowAttr)(void* self,int row,void* attr)
{
	((wxGrid*)self)->SetRowAttr(row, (wxGridCellAttr*)attr);
}
	
EWXWEXPORT(void,wxGrid_SetColAttr)(void* self,int col,void* attr)
{
	((wxGrid*)self)->SetColAttr(col, (wxGridCellAttr*)attr);
}
	
EWXWEXPORT(void,wxGrid_SetColFormatBool)(void* self,int col)
{
	((wxGrid*)self)->SetColFormatBool(col);
}
	
EWXWEXPORT(void,wxGrid_SetColFormatNumber)(void* self,int col)
{
	((wxGrid*)self)->SetColFormatNumber(col);
}
	
EWXWEXPORT(void,wxGrid_SetColFormatFloat)(void* self,int col,int width,int precision)
{
	((wxGrid*)self)->SetColFormatFloat(col, width, precision);
}
	
EWXWEXPORT(void,wxGrid_SetColFormatCustom)(void* self,int col,wxString* typeName)
{
	((wxGrid*)self)->SetColFormatCustom(col,*typeName);
}
	
EWXWEXPORT(void,wxGrid_EnableGridLines)(void* self,bool enable)
{
	((wxGrid*)self)->EnableGridLines(enable);
}
	
EWXWEXPORT(bool,wxGrid_GridLinesEnabled)(wxGrid* self)
{
	return self->GridLinesEnabled();
}
	
EWXWEXPORT(int,wxGrid_GetDefaultRowSize)(void* self)
{
	return ((wxGrid*)self)->GetDefaultRowSize();
}
	
EWXWEXPORT(int,wxGrid_GetRowSize)(void* self,int row)
{
	return ((wxGrid*)self)->GetRowSize(row);
}
	
EWXWEXPORT(int,wxGrid_GetDefaultColSize)(void* self)
{
	return ((wxGrid*)self)->GetDefaultColSize();
}
	
EWXWEXPORT(int,wxGrid_GetColSize)(void* self,int col)
{
	return ((wxGrid*)self)->GetColSize(col);
}
	
EWXWEXPORT(void,wxGrid_GetDefaultCellBackgroundColour)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetDefaultCellBackgroundColour();
}
	
EWXWEXPORT(void,wxGrid_GetCellBackgroundColour)(void* self,int row,int col,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetCellBackgroundColour(row, col);
}
	
EWXWEXPORT(void,wxGrid_GetDefaultCellTextColour)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetDefaultCellTextColour();
}
	
EWXWEXPORT(void,wxGrid_GetCellTextColour)(void* self,int row,int col,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetCellTextColour(row, col);
}
	
EWXWEXPORT(void,wxGrid_GetDefaultCellFont)(void* self,wxFont* font)
{
	*font = ((wxGrid*)self)->GetDefaultCellFont();
}
	
EWXWEXPORT(void,wxGrid_GetCellFont)(void* self,int row,int col,wxFont* font)
{
	*font = ((wxGrid*)self)->GetCellFont(row, col);
}
	
EWXWEXPORT(void,wxGrid_GetDefaultCellAlignment)(void* self,int* horiz,int* vert)
{
	((wxGrid*)self)->GetDefaultCellAlignment(horiz,vert);
}
	
EWXWEXPORT(void,wxGrid_GetCellAlignment)(void* self,int row,int col,int* horiz,int* vert)
{
	((wxGrid*)self)->GetCellAlignment(row, col, horiz,vert);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultRowSize)(void* self,int height,bool resizeExistingRows)
{
	((wxGrid*)self)->SetDefaultRowSize(height, resizeExistingRows);
}
	
EWXWEXPORT(void,wxGrid_SetRowSize)(void* self,int row,int height)
{
	((wxGrid*)self)->SetRowSize(row, height);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultColSize)(void* self,int width,bool resizeExistingCols)
{
	((wxGrid*)self)->SetDefaultColSize(width, resizeExistingCols);
}
	
EWXWEXPORT(void,wxGrid_SetColSize)(void* self,int col,int width)
{
	((wxGrid*)self)->SetColSize(col, width);
}
	
EWXWEXPORT(void,wxGrid_AutoSizeColumn)(void* self,int col,bool setAsMin)
{
	((wxGrid*)self)->AutoSizeColumn(col, setAsMin);
}
	
EWXWEXPORT(void,wxGrid_AutoSizeRow)(void* self,int row,bool setAsMin)
{
	((wxGrid*)self)->AutoSizeRow(row, setAsMin);
}
	
EWXWEXPORT(void,wxGrid_AutoSizeColumns)(void* self,bool setAsMin)
{
	((wxGrid*)self)->AutoSizeColumns(setAsMin);
}
	
EWXWEXPORT(void,wxGrid_AutoSizeRows)(void* self,bool setAsMin)
{
	((wxGrid*)self)->AutoSizeRows(setAsMin);
}
	
EWXWEXPORT(void,wxGrid_AutoSize)(void* self)
{
	((wxGrid*)self)->AutoSize();
}
	
EWXWEXPORT(void,wxGrid_SetColMinimalWidth)(void* self,int col,int width)
{
	((wxGrid*)self)->SetColMinimalWidth(col, width);
}
	
EWXWEXPORT(void,wxGrid_SetRowMinimalHeight)(void* self,int row,int width)
{
	((wxGrid*)self)->SetRowMinimalHeight(row, width);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultCellBackgroundColour)(void* self,wxColour* colour)
{
	((wxGrid*)self)->SetDefaultCellBackgroundColour(*colour);
}
	
EWXWEXPORT(void,wxGrid_SetCellBackgroundColour)(void* self,int row,int col,wxColour* colour)
{
	((wxGrid*)self)->SetCellBackgroundColour(row, col,* colour);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultCellTextColour)(void* self,wxColour* colour)
{
	((wxGrid*)self)->SetDefaultCellTextColour(*colour);
}
	
EWXWEXPORT(void,wxGrid_SetCellTextColour)(void* self,int row,int col,wxColour* colour)
{
	((wxGrid*)self)->SetCellTextColour(row, col,* colour);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultCellFont)(void* self,wxFont* font)
{
	((wxGrid*)self)->SetDefaultCellFont(*font);
}
	
EWXWEXPORT(void,wxGrid_SetCellFont)(void* self,int row,int col,wxFont* font)
{
	((wxGrid*)self)->SetCellFont(row, col,*font );
}
	
EWXWEXPORT(void,wxGrid_SetDefaultCellAlignment)(void* self,int horiz,int vert)
{
	((wxGrid*)self)->SetDefaultCellAlignment(horiz, vert);
}
	
EWXWEXPORT(void,wxGrid_SetCellAlignment)(void* self,int row,int col,int horiz,int vert)
{
	((wxGrid*)self)->SetCellAlignment(row, col, horiz, vert);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultRenderer)(void* self,void* renderer)
{
	((wxGrid*)self)->SetDefaultRenderer((wxGridCellRenderer*)renderer);
}
	
EWXWEXPORT(void,wxGrid_SetCellRenderer)(void* self,int row,int col,void* renderer)
{
	((wxGrid*)self)->SetCellRenderer(row, col, (wxGridCellRenderer*)renderer);
}
	
EWXWEXPORT(void*,wxGrid_GetDefaultRenderer)(void* self)
{
	return (void*)((wxGrid*)self)->GetDefaultRenderer();
}
	
EWXWEXPORT(void*,wxGrid_GetCellRenderer)(void* self,int row,int col)
{
	return (void*)((wxGrid*)self)->GetCellRenderer(row, col);
}
	
EWXWEXPORT(void,wxGrid_SetDefaultEditor)(void* self,wxGridCellEditor* editor)
{
	((wxGrid*)self)->SetDefaultEditor(editor);
}
	
EWXWEXPORT(void,wxGrid_SetCellEditor)(void* self,int row,int col,wxGridCellEditor* editor)
{
	((wxGrid*)self)->SetCellEditor(row, col,editor);
}
	
EWXWEXPORT(void*,wxGrid_GetDefaultEditor)(void* self)
{
	return (void*)((wxGrid*)self)->GetDefaultEditor();
}
	
EWXWEXPORT(void*,wxGrid_GetCellEditor)(void* self,int row,int col)
{
	return (void*)((wxGrid*)self)->GetCellEditor(row, col);
}
	
EWXWEXPORT(wxString*,wxGrid_GetCellValue)(void* self,int row,int col)
{
  return new wxString(((wxGrid*)self)->GetCellValue(row, col));
}
	
EWXWEXPORT(void,wxGrid_SetCellValue)(void* self,int row,int col,wxString* s)
{
	((wxGrid*)self)->SetCellValue(row, col,* s);
}
	
EWXWEXPORT(bool,wxGrid_IsReadOnly)(wxGrid* self,int row,int col)
{
	return self->IsReadOnly(row, col);
}
	
EWXWEXPORT(void,wxGrid_SetReadOnly)(void* self,int row,int col,bool isReadOnly)
{
	((wxGrid*)self)->SetReadOnly(row, col, isReadOnly);
}
	
EWXWEXPORT(void,wxGrid_SelectRow)(void* self,int row,bool addToSelected)
{
	((wxGrid*)self)->SelectRow(row, addToSelected);
}
	
EWXWEXPORT(void,wxGrid_SelectCol)(void* self,int col,bool addToSelected)
{
	((wxGrid*)self)->SelectCol(col, addToSelected);
}
	
EWXWEXPORT(void,wxGrid_SelectBlock)(void* self,int topRow,int leftCol,int bottomRow,int rightCol,bool addToSelected)
{
	((wxGrid*)self)->SelectBlock(topRow, leftCol, bottomRow, rightCol, addToSelected);
}
	
EWXWEXPORT(void,wxGrid_SelectAll)(void* self)
{
	((wxGrid*)self)->SelectAll();
}
	
EWXWEXPORT(bool,wxGrid_IsSelection)(wxGrid* self)
{
	return self->IsSelection();
}
	
EWXWEXPORT(void,wxGrid_ClearSelection)(void* self)
{
	((wxGrid*)self)->ClearSelection();
}
	
EWXWEXPORT(bool,wxGrid_IsInSelection)(wxGrid* self,int row,int col)
{
	return self->IsInSelection(row, col );
}
	
EWXWEXPORT(wxRect*,wxGrid_BlockToDeviceRect)(void* self,int top,int left,int bottom,int right)
{
  wxRect* r = new wxRect();
  *r = ((wxGrid*)self)->BlockToDeviceRect(wxGridCellCoords(top, left), wxGridCellCoords(bottom, right));
  return r;
}
	
EWXWEXPORT(void,wxGrid_GetSelectionBackground)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetSelectionBackground();
}
	
EWXWEXPORT(void,wxGrid_GetSelectionForeground)(void* self,wxColour* colour)
{
	*colour = ((wxGrid*)self)->GetSelectionForeground();
}
	
EWXWEXPORT(void,wxGrid_SetSelectionBackground)(void* self,wxColour* c)
{
	((wxGrid*)self)->SetSelectionBackground(*c);
}
	
EWXWEXPORT(void,wxGrid_SetSelectionForeground)(void* self,wxColour* c)
{
	((wxGrid*)self)->SetSelectionForeground(*c);
}
	
EWXWEXPORT(void,wxGrid_RegisterDataType)(void* self,wxString* typeName,void* renderer,wxGridCellEditor* editor)
{
	((wxGrid*)self)->RegisterDataType(*typeName, (wxGridCellRenderer*)renderer, editor);
}
	
EWXWEXPORT(void*,wxGrid_GetDefaultEditorForCell)(void* self,int row,int col)
{
	return (void*)((wxGrid*)self)->GetDefaultEditorForCell(row, col);
}
	
EWXWEXPORT(void*,wxGrid_GetDefaultRendererForCell)(void* self,int row,int col)
{
	return (void*)((wxGrid*)self)->GetDefaultRendererForCell(row, col);
}
	
EWXWEXPORT(void*,wxGrid_GetDefaultEditorForType)(void* self,wxString* typeName)
{
	return (void*)((wxGrid*)self)->GetDefaultEditorForType(*typeName);
}
	
EWXWEXPORT(void*,wxGrid_GetDefaultRendererForType)(void* self,wxString* typeName)
{
	return (void*)((wxGrid*)self)->GetDefaultRendererForType(*typeName);
}
	
EWXWEXPORT(void,wxGrid_SetMargins)(void* self,int extraWidth,int extraHeight)
{
	((wxGrid*)self)->SetMargins(extraWidth, extraHeight);
}

EWXWEXPORT(void,wxGrid_GetSelectedCells)(void* self,wxGridCellCoordsArray* _arr)
{
	*_arr = ((wxGrid*)self)->GetSelectedCells();
}
	
EWXWEXPORT(void,wxGrid_GetSelectionBlockTopLeft)(void* self,wxGridCellCoordsArray* _arr)
{
	*_arr = ((wxGrid*)self)->GetSelectionBlockTopLeft();
}
	
EWXWEXPORT(void,wxGrid_GetSelectionBlockBottomRight)(void* self,wxGridCellCoordsArray* _arr)
{
	*_arr = ((wxGrid*)self)->GetSelectionBlockBottomRight();
}
	
EWXWEXPORT(int,wxGrid_GetSelectedRows)(void* self,void* _arr)
{
	wxArrayInt arr = ((wxGrid*)self)->GetSelectedRows();
	if (_arr)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((int*)_arr)[i] = arr.Item(i);
	}
	return arr.GetCount();
}
	
EWXWEXPORT(int,wxGrid_GetSelectedCols)(void* self,void* _arr)
{
	wxArrayInt arr = ((wxGrid*)self)->GetSelectedCols();
	if (_arr)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((int*)_arr)[i] = arr.Item(i);
	}
	return arr.GetCount();
}
	


EWXWEXPORT(void*,ELJGridTable_Create)(void* self,void* _EifGetNumberRows,void* _EifGetNumberCols,void* _EifGetValue,void* _EifSetValue,void* _EifIsEmptyCell,void* _EifClear,void* _EifInsertRows,void* _EifAppendRows,void* _EifDeleteRows,void* _EifInsertCols,void* _EifAppendCols,void* _EifDeleteCols,void* _EifSetRowLabelValue,void* _EifSetColLabelValue,void* _EifGetRowLabelValue,void* _EifGetColLabelValue)
{
	return (void*)new ELJGridTable (self,
	                                _EifGetNumberRows,
	                                _EifGetNumberCols,
	                                _EifGetValue,
	                                _EifSetValue,
	                                _EifIsEmptyCell,
	                                _EifClear,
	                                _EifInsertRows,
	                                _EifAppendRows,
	                                _EifDeleteRows,
	                                _EifInsertCols,
	                                _EifAppendCols,
	                                _EifDeleteCols,
	                                _EifSetRowLabelValue,
	                                _EifSetColLabelValue,
	                                _EifGetRowLabelValue,
	                                _EifGetColLabelValue);
}
	
EWXWEXPORT(void,ELJGridTable_Delete)(void* self)
{
	delete (ELJGridTable*)self;
}

EWXWEXPORT(void*,ELJGridTable_GetView)(void* self)
{
	return (void*)((ELJGridTable*)self)->GetView();
}

EWXWEXPORT(void,ELJGridTable_SendTableMessage)(void* self,int id,int val1,int val2)
{
	wxGridTableMessage msg((ELJGridTable*)self, id, val1, val2);
	((ELJGridTable*)self)->GetView()->ProcessTableMessage(msg);
}

EWXWEXPORT(int,wxGridEvent_GetRow)(void* self)
{
	return ((wxGridEvent*)self)->GetRow();
}
	
EWXWEXPORT(int,wxGridEvent_GetCol)(void* self)
{
	return ((wxGridEvent*)self)->GetCol();
}
	
EWXWEXPORT(wxPoint*,wxGridEvent_GetPosition)(void* self)
{
  return new wxPoint(((wxGridEvent*)self)->GetPosition());
}
	
EWXWEXPORT(bool,wxGridEvent_Selecting)(wxGridEvent* self)
{
	return self->Selecting();
}
	
EWXWEXPORT(bool,wxGridEvent_ControlDown)(wxGridEvent* self)
{
	return self->ControlDown();
}
	
EWXWEXPORT(bool,wxGridEvent_MetaDown)(wxGridEvent* self)
{
	return self->MetaDown();
}
	
EWXWEXPORT(bool,wxGridEvent_ShiftDown)(wxGridEvent* self)
{
	return self->ShiftDown();
}
	
EWXWEXPORT(bool,wxGridEvent_AltDown)(wxGridEvent* self)
{
	return self->AltDown();
}
	

EWXWEXPORT(int,wxGridSizeEvent_GetRowOrCol)(void* self)
{
	return ((wxGridSizeEvent*)self)->GetRowOrCol();
}
	
EWXWEXPORT(wxPoint*,wxGridSizeEvent_GetPosition)(void* self)
{
  return new wxPoint(((wxGridSizeEvent*)self)->GetPosition());
}
	
EWXWEXPORT(bool,wxGridSizeEvent_ControlDown)(wxGridSizeEvent* self)
{
	return self->ControlDown();
}
	
EWXWEXPORT(bool,wxGridSizeEvent_MetaDown)(wxGridSizeEvent* self)
{
	return self->MetaDown();
}
	
EWXWEXPORT(bool,wxGridSizeEvent_ShiftDown)(wxGridSizeEvent* self)
{
	return self->ShiftDown();
}
	
EWXWEXPORT(bool,wxGridSizeEvent_AltDown)(wxGridSizeEvent* self)
{
	return self->AltDown();
}
	

EWXWEXPORT(void,wxGridRangeSelectEvent_GetTopLeftCoords)(void* self,int* _c,int* _r)
{
	wxGridCellCoords crd = ((wxGridRangeSelectEvent*)self)->GetTopLeftCoords();
	*_c = crd.GetRow();
	*_r = crd.GetCol();
}
	
EWXWEXPORT(void,wxGridRangeSelectEvent_GetBottomRightCoords)(void* self,int* _c,int* _r)
{
	wxGridCellCoords crd = ((wxGridRangeSelectEvent*)self)->GetBottomRightCoords();
	*_c = crd.GetRow();
	*_r = crd.GetCol();
}
	
EWXWEXPORT(int,wxGridRangeSelectEvent_GetTopRow)(void* self)
{
	return ((wxGridRangeSelectEvent*)self)->GetTopRow();
}
	
EWXWEXPORT(int,wxGridRangeSelectEvent_GetBottomRow)(void* self)
{
	return ((wxGridRangeSelectEvent*)self)->GetBottomRow();
}
	
EWXWEXPORT(int,wxGridRangeSelectEvent_GetLeftCol)(void* self)
{
	return ((wxGridRangeSelectEvent*)self)->GetLeftCol();
}
	
EWXWEXPORT(int,wxGridRangeSelectEvent_GetRightCol)(void* self)
{
	return ((wxGridRangeSelectEvent*)self)->GetRightCol();
}
	
EWXWEXPORT(bool,wxGridRangeSelectEvent_Selecting)(wxGridRangeSelectEvent* self)
{
	return self->Selecting();
}
	
EWXWEXPORT(bool,wxGridRangeSelectEvent_ControlDown)(wxGridRangeSelectEvent* self)
{
	return self->ControlDown();
}
	
EWXWEXPORT(bool,wxGridRangeSelectEvent_MetaDown)(wxGridRangeSelectEvent* self)
{
	return self->MetaDown();
}
	
EWXWEXPORT(bool,wxGridRangeSelectEvent_ShiftDown)(wxGridRangeSelectEvent* self)
{
	return self->ShiftDown();
}
	
EWXWEXPORT(bool,wxGridRangeSelectEvent_AltDown)(wxGridRangeSelectEvent* self)
{
	return self->AltDown();
}
	

EWXWEXPORT(int,wxGridEditorCreatedEvent_GetRow)(void* self)
{
	return ((wxGridEditorCreatedEvent*)self)->GetRow();
}
	
EWXWEXPORT(int,wxGridEditorCreatedEvent_GetCol)(void* self)
{
	return ((wxGridEditorCreatedEvent*)self)->GetCol();
}
	
EWXWEXPORT(void*,wxGridEditorCreatedEvent_GetControl)(void* self)
{
	return (void*)((wxGridEditorCreatedEvent*)self)->GetControl();
}
	
EWXWEXPORT(void,wxGridEditorCreatedEvent_SetRow)(void* self,int row)
{
	((wxGridEditorCreatedEvent*)self)->SetRow(row);
}
	
EWXWEXPORT(void,wxGridEditorCreatedEvent_SetCol)(void* self,int col)
{
	((wxGridEditorCreatedEvent*)self)->SetCol(col);
}
	
EWXWEXPORT(void,wxGridEditorCreatedEvent_SetControl)(void* self,wxControl* ctrl)
{
	((wxGridEditorCreatedEvent*)self)->SetControl(ctrl);
}
	

} 
