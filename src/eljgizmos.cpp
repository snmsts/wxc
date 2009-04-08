#include "wrapper.h"
#include "wx/gizmos/dynamicsash.h"
#include "wx/gizmos/editlbox.h"
#include "wx/gizmos/ledctrl.h"
#include "wx/gizmos/multicell.h"
#include "wx/gizmos/splittree.h"

class ELJSCTreeControl : public wxRemotelyScrolledTreeCtrl
{
	private:
		TreeCompareFunc compare_func;
		void* EiffelObject;

	public:
	    ELJSCTreeControl(void* self,
		                 void* _cmp,
		                 wxWindow *parent,
		                 wxWindowID id = -1,
                         const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxDefaultSize,
                         long style = wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT) :
		wxRemotelyScrolledTreeCtrl (parent, id, pos, size, style)
		{
			EiffelObject = self;
			compare_func = (TreeCompareFunc)_cmp;
		};

		virtual int OnCompareItems(const wxTreeItemId& item1, const wxTreeItemId& item2)
		{
			return EiffelObject ? compare_func (EiffelObject, (void*)&item1, (void*)&item2) : wxRemotelyScrolledTreeCtrl::OnCompareItems(item1, item2);
		}

};

extern "C"
{

EWXWEXPORT(void*,wxDynamicSashWindow_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int style)
{
	return (void*)new wxDynamicSashWindow(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(void,wxDynamicSashWindow_Delete)(void* self)
{
	delete (wxDynamicSashWindow*)self;
}

EWXWEXPORT(void*,wxDynamicSashWindow_GetHScrollBar)(void* self,wxWindow* child)
{
	return (void*)((wxDynamicSashWindow*)self)->GetHScrollBar(child);
}
	
EWXWEXPORT(void*,wxDynamicSashWindow_GetVScrollBar)(void* self,wxWindow* child)
{
	return (void*)((wxDynamicSashWindow*)self)->GetVScrollBar(child);
}
	
EWXWEXPORT(void*,wxEditableListBox_Create)(wxWindow* parent,int id,void* label,int x,int y,int w,int h,int style)
{
	return (void*)new wxEditableListBox(parent, (wxWindowID)id, (char*)label, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(void,wxEditableListBox_SetStrings)(void* self,void* strings,int _n)
{
	wxArrayString list;

	for (int i = 0; i < _n; i++)
		list.Add(((char**)strings)[i]);

	((wxEditableListBox*)self)->SetStrings(list);
}
	
EWXWEXPORT(int,wxEditableListBox_GetStrings)(void* self,void* _ref)
{
	wxArrayString list;
	((wxEditableListBox*)self)->GetStrings(list);
	
	if (_ref)
	{
		for (unsigned int i = 0; i < list.GetCount(); i++)
			((char**)_ref)[i] = strdup (list.Item(i).c_str());
	}

	return list.GetCount();
}
	
EWXWEXPORT(void*,wxEditableListBox_GetListCtrl)(void* self)
{
	return (void*)((wxEditableListBox*)self)->GetListCtrl();
}
	
EWXWEXPORT(void*,wxEditableListBox_GetDelButton)(void* self)
{
	return (void*)((wxEditableListBox*)self)->GetDelButton();
}
	
EWXWEXPORT(void*,wxEditableListBox_GetNewButton)(void* self)
{
	return (void*)((wxEditableListBox*)self)->GetNewButton();
}
	
EWXWEXPORT(void*,wxEditableListBox_GetUpButton)(void* self)
{
	return (void*)((wxEditableListBox*)self)->GetUpButton();
}
	
EWXWEXPORT(void*,wxEditableListBox_GetDownButton)(void* self)
{
	return (void*)((wxEditableListBox*)self)->GetDownButton();
}
	
EWXWEXPORT(void*,wxEditableListBox_GetEditButton)(void* self)
{
	return (void*)((wxEditableListBox*)self)->GetEditButton();
}
	
EWXWEXPORT(void*,wxLEDNumberCtrl_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int style)
{
	return (void*)new wxLEDNumberCtrl(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(int,wxLEDNumberCtrl_GetAlignment)(wxLEDNumberCtrl* self)
{
	return (int)self->GetAlignment();
}
	
EWXWEXPORT(int,wxLEDNumberCtrl_GetDrawFaded)(wxLEDNumberCtrl* self)
{
	return (int)self->GetDrawFaded();
}
	
EWXWEXPORT(wxString*,wxLEDNumberCtrl_GetValue)(void* self)
{
  return new wxString(((wxLEDNumberCtrl*)self)->GetValue());
}
	
EWXWEXPORT(void,wxLEDNumberCtrl_SetAlignment)(void* self,int Alignment,bool Redraw)
{
	((wxLEDNumberCtrl*)self)->SetAlignment((wxLEDValueAlign)Alignment, Redraw);
}
	
EWXWEXPORT(void,wxLEDNumberCtrl_SetDrawFaded)(void* self,bool DrawFaded,bool Redraw)
{
	((wxLEDNumberCtrl*)self)->SetDrawFaded(DrawFaded , Redraw);
}
	
EWXWEXPORT(void,wxLEDNumberCtrl_SetValue)(void* self,void* Value,bool Redraw)
{
	((wxLEDNumberCtrl*)self)->SetValue((char*)Value, Redraw);
}
	
EWXWEXPORT(void*,wxMultiCellItemHandle_Create)(int row,int column,int height,int width,int sx,int sy,int style,int wx,int wy,int align)
{
	return (void*)new wxMultiCellItemHandle(row, column, height, width, wxSize(sx, sy), (wxResizable)style, wxSize(wx, wy), align);
}
	
EWXWEXPORT(void*,wxMultiCellItemHandle_CreateWithSize)(void* self,int row,int column,int sx,int sy,int style,int wx,int wy,int align)
{
	return (void*)new wxMultiCellItemHandle(row, column, wxSize(sx, sy), (wxResizable)style, wxSize(wx, wy), align);
}
	
EWXWEXPORT(void*,wxMultiCellItemHandle_CreateWithStyle)(void* self,int row,int column,int style,int wx,int wy,int align)
{
	return (void*)new wxMultiCellItemHandle(row, column, (wxResizable)style, wxSize(wx, wy), align);
}
	
EWXWEXPORT(int,wxMultiCellItemHandle_GetColumn)(void* self)
{
	return ((wxMultiCellItemHandle*)self)->GetColumn();
}
	
EWXWEXPORT(int,wxMultiCellItemHandle_GetRow)(void* self)
{
	return ((wxMultiCellItemHandle*)self)->GetRow();
}
	
EWXWEXPORT(int,wxMultiCellItemHandle_GetWidth)(void* self)
{
	return ((wxMultiCellItemHandle*)self)->GetWidth();
}
	
EWXWEXPORT(int,wxMultiCellItemHandle_GetHeight)(void* self)
{
	return ((wxMultiCellItemHandle*)self)->GetHeight();
}
	
EWXWEXPORT(int,wxMultiCellItemHandle_GetStyle)(wxMultiCellItemHandle* self)
{
	return (int)self->GetStyle();
}
	
EWXWEXPORT(wxSize*,wxMultiCellItemHandle_GetLocalSize)(void* self)
{
  return new wxSize(((wxMultiCellItemHandle*)self)->GetLocalSize());
}
	
EWXWEXPORT(int,wxMultiCellItemHandle_GetAlignment)(void* self)
{
	return ((wxMultiCellItemHandle*)self)->GetAlignment();
}
	
EWXWEXPORT(wxSize*,wxMultiCellItemHandle_GetWeight)(void* self)
{
  return new wxSize(((wxMultiCellItemHandle*)self)->GetWeight());
}
	
EWXWEXPORT(void*,wxMultiCellSizer_Create)(int rows,int cols)
{
	return (void*)new wxMultiCellSizer(rows, cols);
}
	
EWXWEXPORT(void,wxMultiCellSizer_Delete)(void* self)
{
	delete (wxMultiCellSizer*)self;
}

EWXWEXPORT(void,wxMultiCellSizer_RecalcSizes)(void* self)
{
	((wxMultiCellSizer*)self)->RecalcSizes();
}
	
EWXWEXPORT(wxSize*,wxMultiCellSizer_CalcMin)(void* self)
{
  return new wxSize(((wxMultiCellSizer*)self)->CalcMin());
}
	
EWXWEXPORT(int,wxMultiCellSizer_SetDefaultCellSize)(wxMultiCellSizer* self,int w,int h)
{
	return (int)self->SetDefaultCellSize(wxSize(w, h));
}
	
EWXWEXPORT(int,wxMultiCellSizer_SetColumnWidth)(wxMultiCellSizer* self,int column,int colSize,bool expandable)
{
	return (int)self->SetColumnWidth(column, colSize, expandable);
}
	
EWXWEXPORT(int,wxMultiCellSizer_SetRowHeight)(wxMultiCellSizer* self,int row,int rowSize,bool expandable)
{
	return (int)self->SetRowHeight(row, rowSize, expandable);
}
	
EWXWEXPORT(int,wxMultiCellSizer_EnableGridLines)(wxMultiCellSizer* self,wxWindow* win)
{
	return (int)self->EnableGridLines(win);
}
	
EWXWEXPORT(int,wxMultiCellSizer_SetGridPen)(wxMultiCellSizer* self,void* pen)
{
	return (int)self->SetGridPen((wxPen*)pen);
}
	
EWXWEXPORT(void*,wxMultiCellCanvas_Create)(wxWindow* parent,int numRows,int numCols)
{
	return (void*)new wxMultiCellCanvas(parent, numRows, numCols);
}
	
EWXWEXPORT(void,wxMultiCellCanvas_Add)(void* self,wxWindow* win,int row,int col)
{
	((wxMultiCellCanvas*)self)->Add(win, (unsigned int)row, (unsigned int)col);
}
	
EWXWEXPORT(int,wxMultiCellCanvas_MaxRows)(void* self)
{
	return ((wxMultiCellCanvas*)self)->MaxRows();
}
	
EWXWEXPORT(int,wxMultiCellCanvas_MaxCols)(void* self)
{
	return ((wxMultiCellCanvas*)self)->MaxCols();
}
	
EWXWEXPORT(void,wxMultiCellCanvas_CalculateConstraints)(void* self)
{
	((wxMultiCellCanvas*)self)->CalculateConstraints();
}
	
EWXWEXPORT(void,wxMultiCellCanvas_SetMinCellSize)(void* self,int w,int h)
{
	((wxMultiCellCanvas*)self)->SetMinCellSize(wxSize(w, h));
}
	
EWXWEXPORT(void*,wxSplitterScrolledWindow_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int style)
{
	return (void*)new wxSplitterScrolledWindow(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(void*,wxThinSplitterWindow_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int style)
{
	return (void*)new wxThinSplitterWindow(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(void,wxThinSplitterWindow_SizeWindows)(void* self)
{
	((wxThinSplitterWindow*)self)->SizeWindows();
}
	
EWXWEXPORT(int,wxThinSplitterWindow_SashHitTest)(wxThinSplitterWindow* self,int x,int y,int tolerance)
{
	return (int)self->SashHitTest(x, y, tolerance);
}
	
EWXWEXPORT(void,wxThinSplitterWindow_DrawSash)(void* self,wxDC* dc)
{
	((wxThinSplitterWindow*)self)->DrawSash(*dc);
}
	
EWXWEXPORT(void*,wxTreeCompanionWindow_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int style)
{
	return (void*)new wxTreeCompanionWindow(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(void,wxTreeCompanionWindow_DrawItem)(void* self,wxDC* dc,wxTreeItemId* id,int x,int y,int w,int h)
{
	((wxTreeCompanionWindow*)self)->DrawItem(*dc,*id, wxRect(x, y, w, h));
}
	
EWXWEXPORT(void*,wxTreeCompanionWindow_GetTreeCtrl)(void* self)
{
	return (void*)((wxTreeCompanionWindow*)self)->GetTreeCtrl();
}
	
EWXWEXPORT(void,wxTreeCompanionWindow_SetTreeCtrl)(void* self,void* treeCtrl)
{
	((wxTreeCompanionWindow*)self)->SetTreeCtrl((wxRemotelyScrolledTreeCtrl*)treeCtrl);
}
	
EWXWEXPORT(void*,wxRemotelyScrolledTreeCtrl_Create)(void* self,void* _cmp,wxWindow* parent,int id,int x,int y,int w,int h,int style)
{
	return (void*)new ELJSCTreeControl(self, _cmp, parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style);
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_Delete)(void* self)
{
	delete (ELJSCTreeControl*)self;
}

EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_SetScrollbars)(void* self,int pixelsPerUnitX,int pixelsPerUnitY,int noUnitsX,int noUnitsY,int xPos,int yPos,bool noRefresh)
{
	((ELJSCTreeControl*)self)->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY, xPos, yPos, noRefresh);
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_GetViewStart)(void* self,int* x,int* y)
{
	((ELJSCTreeControl*)self)->GetViewStart(x, y);
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_PrepareDC)(void* self,wxDC* dc)
{
	((ELJSCTreeControl*)self)->PrepareDC(*dc);
}
	
EWXWEXPORT(int,wxRemotelyScrolledTreeCtrl_GetScrollPos)(void* self,int orient)
{
	return ((ELJSCTreeControl*)self)->GetScrollPos(orient);
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_HideVScrollbar)(void* self)
{
	((ELJSCTreeControl*)self)->HideVScrollbar();
}
	
EWXWEXPORT(wxRect*,wxRemotelyScrolledTreeCtrl_CalcTreeSize)(void* self)
{
  wxRect* r = new wxRect();
  ((ELJSCTreeControl*)self)->CalcTreeSize(*r);
  return r;
}
	
EWXWEXPORT(wxRect*,wxRemotelyScrolledTreeCtrl_CalcTreeSizeItem)(void* self,wxTreeItemId* id)
{
  wxRect* r = new wxRect();
  ((ELJSCTreeControl*)self)->CalcTreeSize(*id,*r);
  return r;
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_AdjustRemoteScrollbars)(void* self)
{
	((ELJSCTreeControl*)self)->AdjustRemoteScrollbars();
}
	
EWXWEXPORT(void*,wxRemotelyScrolledTreeCtrl_GetScrolledWindow)(void* self)
{
	return (void*)((ELJSCTreeControl*)self)->GetScrolledWindow();
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_ScrollToLine)(void* self,int posHoriz,int posVert)
{
	((ELJSCTreeControl*)self)->ScrollToLine(posHoriz, posVert);
}
	
EWXWEXPORT(void,wxRemotelyScrolledTreeCtrl_SetCompanionWindow)(void* self,wxWindow* companion)
{
	((ELJSCTreeControl*)self)->SetCompanionWindow(companion);
}
	
EWXWEXPORT(void*,wxRemotelyScrolledTreeCtrl_GetCompanionWindow)(void* self)
{
	return (void*)((ELJSCTreeControl*)self)->GetCompanionWindow();
}
	
}
