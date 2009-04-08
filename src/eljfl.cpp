#include "wrapper.h"
#include "wx/fl/toolwnd.h"
#include "wx/fl/antiflickpl.h"
#include "wx/fl/bardragpl.h"
#include "wx/fl/barhintspl.h"
#include "wx/fl/cbcustom.h"
#include "wx/fl/dyntbar.h"
#include "wx/fl/dyntbarhnd.h"
#include "wx/fl/gcupdatesmgr.h"
#include "wx/fl/hintanimpl.h"
#include "wx/fl/newbmpbtn.h"
#include "wx/fl/panedrawpl.h"
#include "wx/fl/rowdragpl.h"
#include "wx/fl/rowlayoutpl.h"

typedef void (*TButtonClick)(void* self, int _btn);
typedef int  (*TTitleClick)(void* self, void* _evt);
typedef void (*TMiniDraw)(void* self, void* _dct);

class ELJToolWindow : public wxToolWindow
{
    private:
        void*        EifObj;
        TButtonClick BtnCb;
        TTitleClick  TtlCb;
    public:
        ELJToolWindow(void* self, void* _btn, void* _ttl) : wxToolWindow()
        {
        	EifObj = self;
        	BtnCb = (TButtonClick)_btn;
        	TtlCb = (TTitleClick)_ttl;
        }
    
    virtual void OnMiniButtonClicked( int btnIdx ) {BtnCb (EifObj, btnIdx);}
    virtual bool HandleTitleClick( wxMouseEvent& event ) { return TtlCb (EifObj, (void*)&event) != 0; }
};

class ELJMiniButton : public cbMiniButton
{
    private:
        void*     EifObj;
        TMiniDraw DrwCb;
	public:
        ELJMiniButton(void* self, void* _drw) : cbMiniButton()
        {
        	EifObj = self;
        	DrwCb = (TMiniDraw)_drw;
		}
		
		virtual void Draw(wxDC& dc) {DrwCb(EifObj, (void*)&dc);}
};

extern "C"
{

EWXWEXPORT(void*,wxToolWindow_Create)(void* self,void* _btn,void* _ttl)
{
    return (void*)new ELJToolWindow(self, _btn, _ttl);
}
EWXWEXPORT(void,wxToolWindow_SetClient)(void* self,wxWindow* _wnd)
{
	((ELJToolWindow*)self)->SetClient(_wnd);
}

EWXWEXPORT(void*,wxToolWindow_GetClient)(void* self)
{
	return (void*)((ELJToolWindow*)self)->GetClient();
}

EWXWEXPORT(void,wxToolWindow_SetTitleFont)(void* self,wxFont* _fnt)
{
	((ELJToolWindow*)self)->SetTitleFont (*_fnt);
}

EWXWEXPORT(void,wxToolWindow_AddMiniButton)(void* self,void* _btn)
{
	((ELJToolWindow*)self)->AddMiniButton((cbMiniButton*)_btn);
}

EWXWEXPORT(void*,cbMiniButton_Create)()
{
	return (void*)new cbMiniButton();
}
	
EWXWEXPORT(void,cbMiniButton_Delete)(void* self)
{
	delete (cbMiniButton*)self;
}
	
EWXWEXPORT(wxPoint*,cbMiniButton_Pos)(void* self)
{
  return new wxPoint(((cbMiniButton*)self)->mPos);
}
	
EWXWEXPORT(wxSize*,cbMiniButton_Dim)(void* self)
{
  return new wxSize(((cbMiniButton*)self)->mDim);
}
	
EWXWEXPORT(int,cbMiniButton_Visible)(cbMiniButton* self)
{
	return (int)self->mVisible;
}
	
EWXWEXPORT(int,cbMiniButton_Enabled)(cbMiniButton* self)
{
	return (int)self->mEnabled;
}
	
EWXWEXPORT(void*,cbMiniButton_Layout)(void* self)
{
	return (void*)((cbMiniButton*)self)->mpLayout;
}
	
EWXWEXPORT(void*,cbMiniButton_Pane)(void* self)
{
	return (void*)((cbMiniButton*)self)->mpPane;
}
	
EWXWEXPORT(void*,cbMiniButton_Plugin)(void* self)
{
	return (void*)((cbMiniButton*)self)->mpPlugin;
}
	
EWXWEXPORT(void*,cbMiniButton_Wnd)(void* self)
{
	return (void*)((cbMiniButton*)self)->mpWnd;
}
	
EWXWEXPORT(int,cbMiniButton_DragStarted)(cbMiniButton* self)
{
	return (int)self->mDragStarted;
}
	
EWXWEXPORT(int,cbMiniButton_Pressed)(cbMiniButton* self)
{
	return (int)self->mPressed;
}
	
EWXWEXPORT(void,cbMiniButton_SetPos)(void* self,int x,int y)
{
	((cbMiniButton*)self)->SetPos(wxPoint(x, y));
}
	
EWXWEXPORT(int,cbMiniButton_HitTest)(cbMiniButton* self,int x,int y)
{
	return (int)self->HitTest(wxPoint(x, y));
}
	
EWXWEXPORT(void,cbMiniButton_Refresh)(void* self)
{
	((cbMiniButton*)self)->Refresh();
}
	
EWXWEXPORT(int,cbMiniButton_WasClicked)(cbMiniButton* self)
{
	return (int)self->WasClicked();
}
	
EWXWEXPORT(void,cbMiniButton_Reset)(void* self)
{
	((cbMiniButton*)self)->Reset();
}
	
EWXWEXPORT(void,cbMiniButton_Enable)(void* self,bool enable)
{
	((cbMiniButton*)self)->Enable(enable);
}
	
EWXWEXPORT(bool,cbMiniButton_IsPressed)(cbMiniButton* self)
{
	return self->IsPressed();
}
	
EWXWEXPORT(void*,cbCloseBox_Create)()
{
	return (void*)new cbCloseBox();
}
	
EWXWEXPORT(void*,cbCollapseBox_Create)()
{
	return (void*)new cbCollapseBox();
}
	
EWXWEXPORT(void*,cbDockBox_Create)()
{
	return (void*)new cbDockBox();
}
	
EWXWEXPORT(void*,cbFloatedBarWindow_Create)(void* self)
{
	return (void*)new cbFloatedBarWindow();
}
	
EWXWEXPORT(void,cbFloatedBarWindow_SetBar)(void* self,void* _bar)
{
	((cbFloatedBarWindow*)self)->SetBar((cbBarInfo*)_bar);
}
	
EWXWEXPORT(void,cbFloatedBarWindow_SetLayout)(void* self,void* _layout)
{
	((cbFloatedBarWindow*)self)->SetLayout((wxFrameLayout*)_layout);
}
	
EWXWEXPORT(void*,cbFloatedBarWindow_GetBar)(void* self)
{
	return (void*)((cbFloatedBarWindow*)self)->GetBar();
}
	
EWXWEXPORT(void,cbFloatedBarWindow_PositionFloatedWnd)(void* self,int _x,int _y,int _w,int _h)
{
	((cbFloatedBarWindow*)self)->PositionFloatedWnd(_x, _y, _w, _h);
}
	
EWXWEXPORT(void*,wxFrameLayout_Create)(wxWindow* pParentFrame,wxWindow* pFrameClient,bool activateNow)
{
	return (void*)new wxFrameLayout(pParentFrame, pFrameClient, activateNow);
}
	
EWXWEXPORT(void,wxFrameLayout_Delete)(void* self)
{
	delete (wxFrameLayout*)self;
}

EWXWEXPORT(void,wxFrameLayout_EnableFloating)(void* self,bool enable)
{
	((wxFrameLayout*)self)->EnableFloating(enable);
}
	
EWXWEXPORT(void,wxFrameLayout_Activate)(void* self)
{
	((wxFrameLayout*)self)->Activate();
}
	
EWXWEXPORT(void,wxFrameLayout_Deactivate)(void* self)
{
	((wxFrameLayout*)self)->Deactivate();
}

EWXWEXPORT(void,wxFrameLayout_HideBarWindows)(void* self)
{
	((wxFrameLayout*)self)->HideBarWindows();
}
	
EWXWEXPORT(void,wxFrameLayout_DestroyBarWindows)(void* self)
{
	return ((wxFrameLayout*)self)->DestroyBarWindows();
}
	
EWXWEXPORT(void,wxFrameLayout_SetFrameClient)(void* self,wxWindow* pFrameClient)
{
	((wxFrameLayout*)self)->SetFrameClient(pFrameClient);
}
	
EWXWEXPORT(void*,wxFrameLayout_GetFrameClient)(void* self)
{
	return (void*)((wxFrameLayout*)self)->GetFrameClient();
}
	
EWXWEXPORT(void*,wxFrameLayout_GetParentFrame)(void* self)
{
	return (void*)((wxFrameLayout*)self)->mpFrame;
}
	
EWXWEXPORT(void*,wxFrameLayout_GetPane)(void* self,int alignment)
{
	return (void*)((wxFrameLayout*)self)->GetPane(alignment);
}
	
EWXWEXPORT(void,wxFrameLayout_AddBar)(void* self,wxWindow* pBarWnd,void* dimInfo,int alignment,int rowNo,int columnPos,void* name,bool spyEvents,int state)
{
	((wxFrameLayout*)self)->AddBar(pBarWnd,*((cbDimInfo*)dimInfo), alignment, rowNo, columnPos, (char*)name, spyEvents, state);
}
	
EWXWEXPORT(int,wxFrameLayout_RedockBar)(wxFrameLayout* self,cbBarInfo* pBar,int x,int y,int w,int h,cbDockPane* pToPane,bool updateNow)
{
	return (int)self->RedockBar(pBar, wxRect(x, y, w, h), pToPane, updateNow);
}
	
EWXWEXPORT(void*,wxFrameLayout_FindBarByName)(void* self,void* name)
{
	return (void*)((wxFrameLayout*)self)->FindBarByName((char*)name);
}
	
EWXWEXPORT(void*,wxFrameLayout_FindBarByWindow)(void* self,wxWindow* pWnd)
{
	return (void*)((wxFrameLayout*)self)->FindBarByWindow(pWnd);
}
	
EWXWEXPORT(int,wxFrameLayout_GetBars)(void* self,void* _ref)
{
	BarArrayT arr = ((wxFrameLayout*)self)->GetBars();
	
	if (_ref)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((void**)_ref)[i] = arr.Item(i);
	}
	
	return arr.GetCount();
}
	
EWXWEXPORT(void,wxFrameLayout_SetBarState)(void* self,void* pBar,int newStatem,bool updateNow)
{
	((wxFrameLayout*)self)->SetBarState((cbBarInfo*)pBar, newStatem, updateNow);
}
	
EWXWEXPORT(void,wxFrameLayout_InverseVisibility)(void* self,void* pBar)
{
	((wxFrameLayout*)self)->InverseVisibility((cbBarInfo*)pBar);
}
	
EWXWEXPORT(void,wxFrameLayout_ApplyBarProperties)(void* self,void* pBar)
{
	((wxFrameLayout*)self)->ApplyBarProperties((cbBarInfo*)pBar);
}
	
EWXWEXPORT(void,wxFrameLayout_RemoveBar)(void* self,void* pBar)
{
	((wxFrameLayout*)self)->RemoveBar((cbBarInfo*)pBar);
}
	
EWXWEXPORT(void,wxFrameLayout_RecalcLayout)(void* self,bool repositionBarsNow)
{
	((wxFrameLayout*)self)->RecalcLayout(repositionBarsNow);
}
	
EWXWEXPORT(int,wxFrameLayout_GetClientHeight)(void* self)
{
	return ((wxFrameLayout*)self)->GetClientHeight();
}
	
EWXWEXPORT(int,wxFrameLayout_GetClientWidth)(void* self)
{
	return ((wxFrameLayout*)self)->GetClientWidth();
}
	
EWXWEXPORT(wxRect*,wxFrameLayout_GetClientRect)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((wxFrameLayout*)self)->GetClientRect();
  return r;
}
	
EWXWEXPORT(void*,wxFrameLayout_GetUpdatesManager)(void* self)
{
	return (void*)((wxFrameLayout*)self)->mpUpdatesMgr;
}
	
EWXWEXPORT(void,wxFrameLayout_SetUpdatesManager)(void* self,void* pUMgr)
{
	((wxFrameLayout*)self)->SetUpdatesManager((cbUpdatesManagerBase*)pUMgr);
}
	
EWXWEXPORT(void,wxFrameLayout_GetPaneProperties)(void* self,void* props,int alignment)
{
	((wxFrameLayout*)self)->GetPaneProperties(*((cbCommonPaneProperties*)props), alignment);
}
	
EWXWEXPORT(void,wxFrameLayout_SetPaneProperties)(void* self,void* props,int paneMask)
{
	((wxFrameLayout*)self)->SetPaneProperties(*((cbCommonPaneProperties*)props), paneMask);
}
	
EWXWEXPORT(void,wxFrameLayout_SetMargins)(void* self,int top,int bottom,int left,int right,int paneMask)
{
	((wxFrameLayout*)self)->SetMargins(top, bottom, left, right, paneMask);
}
	
EWXWEXPORT(void,wxFrameLayout_SetPaneBackground)(void* self,wxColour* colour)
{
	((wxFrameLayout*)self)->SetPaneBackground(*colour);
}
	
EWXWEXPORT(void,wxFrameLayout_RefreshNow)(void* self,bol recalcLayout)
{
	((wxFrameLayout*)self)->RefreshNow(recalcLayout);
}
	
EWXWEXPORT(void,wxFrameLayout_OnSize)(void* self,void* event)
{
	((wxFrameLayout*)self)->OnSize(*((wxSizeEvent*)event));
}
	
EWXWEXPORT(void,wxFrameLayout_OnLButtonDown)(void* self,wxMouseEvent* event)
{
	((wxFrameLayout*)self)->OnLButtonDown(*event);
}
	
EWXWEXPORT(void,wxFrameLayout_OnLDblClick)(void* self,wxMouseEvent* event)
{
	((wxFrameLayout*)self)->OnLDblClick(*event);
}
	
EWXWEXPORT(void,wxFrameLayout_OnLButtonUp)(void* self,wxMouseEvent* event)
{
	((wxFrameLayout*)self)->OnLButtonUp(*event);
}
	
EWXWEXPORT(void,wxFrameLayout_OnRButtonDown)(void* self,wxMouseEvent* event)
{
	((wxFrameLayout*)self)->OnRButtonDown(*event);
}
	
EWXWEXPORT(void,wxFrameLayout_OnRButtonUp)(void* self,wxMouseEvent* event)
{
	((wxFrameLayout*)self)->OnRButtonUp(*event);
}
	
EWXWEXPORT(void,wxFrameLayout_OnMouseMove)(void* self,wxMouseEvent* event)
{
	((wxFrameLayout*)self)->OnMouseMove(*event);
}
	
EWXWEXPORT(void,wxFrameLayout_FirePluginEvent)(void* self,void* event)
{
	((wxFrameLayout*)self)->FirePluginEvent(*((cbPluginEvent*)event));
}
	
EWXWEXPORT(void,wxFrameLayout_CaptureEventsForPlugin)(void* self,void* pPlugin)
{
	((wxFrameLayout*)self)->CaptureEventsForPlugin((cbPluginBase*)pPlugin);
}
	
EWXWEXPORT(void,wxFrameLayout_ReleaseEventsFromPlugin)(void* self,void* pPlugin)
{
	((wxFrameLayout*)self)->ReleaseEventsFromPlugin((cbPluginBase*)pPlugin);
}
	
EWXWEXPORT(void,wxFrameLayout_CaptureEventsForPane)(void* self,void* toPane)
{
	((wxFrameLayout*)self)->CaptureEventsForPane((cbDockPane*)toPane);
}
	
EWXWEXPORT(void,wxFrameLayout_ReleaseEventsFromPane)(void* self,void* fromPane)
{
	((wxFrameLayout*)self)->ReleaseEventsFromPane((cbDockPane*)fromPane);
}
	
EWXWEXPORT(void*,wxFrameLayout_GetTopPlugin)(void* self)
{
	return (void*)((wxFrameLayout*)self)->mpTopPlugin;
}
	
EWXWEXPORT(void,wxFrameLayout_SetTopPlugin)(void* self,void* pPlugin)
{
	((wxFrameLayout*)self)->SetTopPlugin((cbPluginBase*)pPlugin);
}
	
EWXWEXPORT(void,wxFrameLayout_PushPlugin)(void* self,void* pPugin)
{
	((wxFrameLayout*)self)->PushPlugin((cbPluginBase*)pPugin);
}
	
EWXWEXPORT(void,wxFrameLayout_PopPlugin)(void* self)
{
	((wxFrameLayout*)self)->PopPlugin();
}
	
EWXWEXPORT(void,wxFrameLayout_PopAllPlugins)(void* self)
{
	((wxFrameLayout*)self)->PopAllPlugins();
}
	
EWXWEXPORT(void,wxFrameLayout_PushDefaultPlugins)(void* self)
{
	((wxFrameLayout*)self)->PushDefaultPlugins();
}
	
EWXWEXPORT(void,wxFrameLayout_AddPlugin)(void* self,void* pPlInfo,int paneMask)
{
	((wxFrameLayout*)self)->AddPlugin((wxClassInfo*)pPlInfo, paneMask);
}
	
EWXWEXPORT(void,wxFrameLayout_AddPluginBefore)(void* self,void* pNextPlInfo,void* pPlInfo,int paneMask)
{
	((wxFrameLayout*)self)->AddPluginBefore((wxClassInfo*)pNextPlInfo, (wxClassInfo*)pPlInfo, paneMask);
}
	
EWXWEXPORT(void,wxFrameLayout_RemovePlugin)(void* self,void* pPlInfo)
{
	((wxFrameLayout*)self)->RemovePlugin((wxClassInfo*)pPlInfo);
}
	
EWXWEXPORT(void*,wxFrameLayout_FindPlugin)(void* self,void* pPlInfo)
{
	return (void*)((wxFrameLayout*)self)->FindPlugin((wxClassInfo*)pPlInfo);
}
	
EWXWEXPORT(int,wxFrameLayout_HasTopPlugin)(wxFrameLayout* self)
{
	return (int)self->HasTopPlugin();
}
	
EWXWEXPORT(void*,cbDimInfo_CreateDefault)()
{
	return (void*)new cbDimInfo();
}
	
EWXWEXPORT(void*,cbDimInfo_CreateWithHandler)(void* pDimHandler,bool isFixed)
{
	return (void*)new cbDimInfo((cbBarDimHandlerBase*)pDimHandler, isFixed);
}
	
EWXWEXPORT(void*,cbDimInfo_CreateWithInfo)(int dh_x,int dh_y,int dv_x,int dv_y,int f_x,int f_y,bool isFixed,int horizGap,int vertGap,void* pDimHandler)
{
	return (void*)new cbDimInfo(dh_x, dh_y, dv_x, dv_y, f_x, f_y, isFixed, horizGap, vertGap, (cbBarDimHandlerBase*)pDimHandler);
}
	
EWXWEXPORT(void*,cbDimInfo_Create)(int x,int y,bool isFixed,int gap,void* pDimHandler)
{
	return (void*)new cbDimInfo(x, y, isFixed , gap, (cbBarDimHandlerBase*)pDimHandler);
}
	
EWXWEXPORT(void,cbDimInfo_Delete)(void* self)
{
	delete (cbDimInfo*)self;
}

EWXWEXPORT(void,cbDimInfo_Assign)(void* self,void* other)
{
	*((cbDimInfo*)self) = *((cbDimInfo*)other);
}
	
EWXWEXPORT(void*,cbDimInfo_GetDimHandler)(void* self)
{
	return (void*)((cbDimInfo*)self)->GetDimHandler();
}
	
EWXWEXPORT(void*,cbBarInfo_Create)()
{
	return (void*)new cbBarInfo();
}
	
EWXWEXPORT(void,cbBarInfo_Delete)(void* self)
{
	delete (cbBarInfo*)self;
}
	
EWXWEXPORT(bool,cbBarInfo_IsFixed)(cbBarInfo* self)
{
	return self->IsFixed();
}
	
EWXWEXPORT(bool,cbBarInfo_IsExpanded)(cbBarInfo* self)
{
	return self->IsExpanded();
}
	
EWXWEXPORT(void*,cbBarSpy_CreateDefault)()
{
	return (void*)new cbBarSpy();
}
	
EWXWEXPORT(void*,cbBarSpy_Create)(void* pPanel)
{
	return (void*)new cbBarSpy((wxFrameLayout*)pPanel);
}
	
EWXWEXPORT(void,cbBarSpy_Delete)(void* self)
{
	delete (cbBarSpy*)self;
}
	
EWXWEXPORT(void,cbBarSpy_SetBarWindow)(void* self,wxWindow* pWnd)
{
	((cbBarSpy*)self)->SetBarWindow(pWnd);
}
	
EWXWEXPORT(int,cbBarSpy_ProcessEvent)(cbBarSpy* self,wxEvent* event)
{
	return (int)self->ProcessEvent(*event);
}
	
EWXWEXPORT(void*,cbRowInfo_Create)()
{
	return (void*)new cbRowInfo();
}
	
EWXWEXPORT(void,cbRowInfo_Delete)(void* self)
{
	delete (cbRowInfo*)self;
}
	
EWXWEXPORT(void*,cbRowInfo_GetFirstBar)(void* self)
{
	return (void*)((cbRowInfo*)self)->GetFirstBar();
}
	
EWXWEXPORT(void*,cbDockPane_CreateDefault)()
{
	return (void*)new cbDockPane();
}
	
EWXWEXPORT(void*,cbDockPane_Create)(int alignment,void* pPanel)
{
	return (void*)new cbDockPane(alignment, (wxFrameLayout*)pPanel);
}
	
EWXWEXPORT(void,cbDockPane_Delete)(void* self)
{
	delete (cbDockPane*)self;
}
	
EWXWEXPORT(void,cbDockPane_SetMargins)(void* self,int top,int bottom,int left,int right)
{
	((cbDockPane*)self)->SetMargins(top, bottom, left, right);
}
	
EWXWEXPORT(void,cbDockPane_RemoveBar)(void* self,void* pBar)
{
	((cbDockPane*)self)->RemoveBar((cbBarInfo*)pBar);
}
	
EWXWEXPORT(void,cbDockPane_InsertBarByCoord)(void* self,void* pBar,int x,int y,int w,int h)
{
	((cbDockPane*)self)->InsertBar((cbBarInfo*)pBar, wxRect(x, y, w, h));
}
	
EWXWEXPORT(void,cbDockPane_InsertBarToRow)(void* self,void* pBar,void* pIntoRow)
{
	((cbDockPane*)self)->InsertBar((cbBarInfo*)pBar, (cbRowInfo*)pIntoRow);
}
	
EWXWEXPORT(void,cbDockPane_InsertBarByInfo)(void* self,void* pBarInfo)
{
	((cbDockPane*)self)->InsertBar((cbBarInfo*)pBarInfo);
}
	
EWXWEXPORT(void,cbDockPane_RemoveRow)(void* self,void* pRow)
{
	((cbDockPane*)self)->RemoveRow((cbRowInfo*)pRow);
}
	
EWXWEXPORT(void,cbDockPane_InsertRow)(void* self,void* pRow,void* pBeforeRow)
{
	((cbDockPane*)self)->InsertRow((cbRowInfo*)pRow, (cbRowInfo*)pBeforeRow);
}
	
EWXWEXPORT(void,cbDockPane_SetPaneWidth)(void* self,int width)
{
	((cbDockPane*)self)->SetPaneWidth(width);
}
	
EWXWEXPORT(void,cbDockPane_SetBoundsInParent)(void* self,int _x,int _y,int _w,int _h)
{
	((cbDockPane*)self)->SetBoundsInParent(wxRect(_x, _y, _w, _h));
}
	
EWXWEXPORT(wxRect*,cbDockPane_GetRealRect)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((cbDockPane*)self)->GetRealRect();
  return r;
}
	
EWXWEXPORT(int,cbDockPane_GetRowList)(void* self,void* _ref)
{
	RowArrayT arr = ((cbDockPane*)self)->GetRowList();
	
	if (_ref)
	{
		for (unsigned int i = 0; i < arr.GetCount(); i++)
			((void**)_ref)[i] = (void*)arr.Item(i);
	}
	
	return arr.GetCount();
}
	
EWXWEXPORT(void*,cbDockPane_GetFirstRow)(void* self)
{
	return (void*)((cbDockPane*)self)->GetFirstRow();
}
	
EWXWEXPORT(int,cbDockPane_BarPresent)(cbDockPane* self,cbBarInfo* pBar)
{
	return (int)self->BarPresent(pBar);
}
	
EWXWEXPORT(int,cbDockPane_GetPaneHeight)(void* self)
{
	return ((cbDockPane*)self)->GetPaneHeight();
}
	
EWXWEXPORT(int,cbDockPane_GetAlignment)(void* self)
{
	return ((cbDockPane*)self)->GetAlignment();
}
	
EWXWEXPORT(int,cbDockPane_MatchesMask)(cbDockPane* self,int paneMask)
{
	return (int)self->MatchesMask(paneMask);
}
	
EWXWEXPORT(bool,cbDockPane_IsHorizontal)(cbDockPane* self)
{
	return self->IsHorizontal();
}
	
EWXWEXPORT(int,cbDockPane_GetDockingState)(void* self)
{
	return ((cbDockPane*)self)->GetDockingState();
}
	
EWXWEXPORT(int,cbDockPane_HitTestPaneItems)(void* self,int x,int y,void* ppRow,void* ppBar)
{
	return ((cbDockPane*)self)->HitTestPaneItems(wxPoint(x, y), (cbRowInfo**)ppRow, (cbBarInfo**)ppBar);
}
	
EWXWEXPORT(void,cbDockPane_GetBarResizeRange)(void* self,void* pBar,int* from,int* till,bool forLeftHandle)
{
	((cbDockPane*)self)->GetBarResizeRange((cbBarInfo*)pBar, from, till, forLeftHandle);
}
	
EWXWEXPORT(void,cbDockPane_GetRowResizeRange)(void* self,void* pRow,int* from,int* till,bool forUpperHandle)
{
	((cbDockPane*)self)->GetRowResizeRange((cbRowInfo*)pRow, from, till, forUpperHandle);
}
	
EWXWEXPORT(void*,cbDockPane_GetBarInfoByWindow)(void* self,wxWindow* pBarWnd)
{
	return (void*)((cbDockPane*)self)->GetBarInfoByWindow(pBarWnd);
}
	
EWXWEXPORT(int,cbPluginBase_GetPaneMask)(void* self)
{
	return ((cbPluginBase*)self)->GetPaneMask();
}

EWXWEXPORT(void,cbPluginBase_Delete)(void* self)
{
	delete (cbPluginBase*)self;
}

EWXWEXPORT(bool,cbPluginBase_IsReady)(cbPluginBase* self)
{
	return self->IsReady();
}
	
EWXWEXPORT(int,cbPluginBase_ProcessEvent)(cbPluginBase* self,wxEvent* event)
{
	return (int)self->ProcessEvent(*event);
}
	
EWXWEXPORT(void*,cbPluginEvent_Pane)(void* self)
{
	return ((cbPluginEvent*)self)->mpPane;
}

EWXWEXPORT(wxPoint*,cbLeftDownEvent_Pos)(void* self)
{
  return new wxPoint(((cbLeftDownEvent*)self)->mPos)
}
	
EWXWEXPORT(wxPoint*,cbLeftUpEvent_Pos)(void* self)
{
  return new wxPoint(((cbLeftUpEvent*)self)->mPos);
}
	
EWXWEXPORT(wxPoint*,cbRightDownEvent_Pos)(void* self)
{
  return new wxPoint(((cbRightDownEvent*)self)->mPos);
}
	
EWXWEXPORT(void,cbRightUpEvent_Pos)(void* self)
{
  return new wxPoint(((cbRightUpEvent*)self)->mPos);
}
	
EWXWEXPORT(wxPoint*,cbMotionEvent_Pos)(void* self)
{
  return new wxPoint(((cbMotionEvent*)self)->mPos);
}
	
EWXWEXPORT(wxPoint*,cbLeftDClickEvent_Pos)(void* self)
{
  return new wxPoint(((cbLeftDClickEvent*)self)->mPos);
}
	
EWXWEXPORT(void*,cbLayoutRowEvent_Row)(void* self)
{
	return (void*)((cbLayoutRowEvent*)self)->mpRow;
}

EWXWEXPORT(void*,cbResizeRowEvent_Row)(void* self)
{
	return (void*)((cbResizeRowEvent*)self)->mpRow;
}

EWXWEXPORT(int,cbResizeRowEvent_HandleOfs)(void* self)
{
	return ((cbResizeRowEvent*)self)->mHandleOfs;
}
	
EWXWEXPORT(int,cbResizeRowEvent_ForUpperHandle)(cbResizeRowEvent* self)
{
	return (int)self->mForUpperHandle;
}
	
EWXWEXPORT(void*,cbInsertBarEvent_Bar)(void* self)
{
	return (void*)((cbInsertBarEvent*)self)->mpBar;
}
	
EWXWEXPORT(void*,cbInsertBarEvent_Row)(void* self)
{
	return (void*)((cbInsertBarEvent*)self)->mpRow;
}
	
EWXWEXPORT(void*,cbResizeBarEvent_Bar)(void* self)
{
	return (void*)((cbResizeBarEvent*)self)->mpBar;
}
	
EWXWEXPORT(void*,cbResizeBarEvent_Row)(void* self)
{
	return (void*)((cbResizeBarEvent*)self)->mpRow;
}
	
EWXWEXPORT(void*,cbRemoveBarEvent_Bar)(void* self)
{
	return (void*)((cbRemoveBarEvent*)self)->mpBar;
}
	
EWXWEXPORT(void*,cbSizeBarWndEvent_Bar)(void* self)
{
	return (void*)((cbSizeBarWndEvent*)self)->mpBar;
}
	
EWXWEXPORT(wxRect*,cbSizeBarWndEvent_BoundsInParent)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((cbSizeBarWndEvent*)self)->mBoundsInParent;
  return r;
}
	
EWXWEXPORT(void*,cbDrawBarDecorEvent_Bar)(void* self)
{
	return (void*)((cbDrawBarDecorEvent*)self)->mpBar;
}
	
EWXWEXPORT(wxRect*,cbDrawBarDecorEvent_BoundsInParent)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((cbDrawBarDecorEvent*)self)->mBoundsInParent;
  return r;
}
	
EWXWEXPORT(void*,cbDrawBarDecorEvent_Dc)(void* self)
{
	return (void*)((cbDrawBarDecorEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbDrawRowDecorEvent_Row)(void* self)
{
	return (void*)((cbDrawRowDecorEvent*)self)->mpRow;
}
	
EWXWEXPORT(void*,cbDrawRowDecorEvent_Dc)(void* self)
{
	return (void*)((cbDrawRowDecorEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbDrawPaneDecorEvent_Dc)(void* self)
{
	return (void*)((cbDrawPaneDecorEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbDrawBarHandlesEvent_Bar)(void* self)
{
	return (void*)((cbDrawBarHandlesEvent*)self)->mpBar;
}
	
EWXWEXPORT(void*,cbDrawBarHandlesEvent_Dc)(void* self)
{
	return (void*)((cbDrawBarHandlesEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbDrawRowHandlesEvent_Row)(void* self)
{
	return (void*)((cbDrawRowHandlesEvent*)self)->mpRow;
}
	
EWXWEXPORT(void*,cbDrawRowHandlesEvent_Dc)(void* self)
{
	return (void*)((cbDrawRowHandlesEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbDrawRowBkGroundEvent_Row)(void* self)
{
	return (void*)((cbDrawRowBkGroundEvent*)self)->mpRow;
}
	
EWXWEXPORT(void*,cbDrawRowBkGroundEvent_Dc)(void* self)
{
	return (void*)((cbDrawRowBkGroundEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbDrawPaneBkGroundEvent_Dc)(void* self)
{
	return (void*)((cbDrawPaneBkGroundEvent*)self)->mpDc;
}
	
EWXWEXPORT(void*,cbStartBarDraggingEvent_Bar)(void* self)
{
	return (void*)((cbStartBarDraggingEvent*)self)->mpBar;
}
	
EWXWEXPORT(wxPoint*,cbStartBarDraggingEvent_Pos)(void* self)
{
  return new wxPoint(((cbStartBarDraggingEvent*)self)->mPos);
}
	
EWXWEXPORT(wxRect*,cbDrawHintRectEvent_Rect)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((cbDrawHintRectEvent*)self)->mRect;
  return r;
}
	
EWXWEXPORT(int,cbDrawHintRectEvent_LastTime)(cbDrawHintRectEvent* self)
{
	return (int)self->mLastTime;
}
	
EWXWEXPORT(int,cbDrawHintRectEvent_EraseRect)(cbDrawHintRectEvent* self)
{
	return (int)self->mEraseRect;
}
	
EWXWEXPORT(bool,cbDrawHintRectEvent_IsInClient)(cbDrawHintRectEvent* self)
{
	return self->mIsInClient;
}
	
EWXWEXPORT(wxRect*,cbStartDrawInAreaEvent_Area)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((cbStartDrawInAreaEvent*)self)->mArea;
  return r;
}
	
EWXWEXPORT(wxRect*,cbFinishDrawInAreaEvent_Area)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((cbFinishDrawInAreaEvent*)self)->mArea;
  return r;
}
	
EWXWEXPORT(wxPoint*,cbCustomizeBarEvent_ClickPos)(void* self)
{
  return new wxPoint(((cbCustomizeBarEvent*)self)->mClickPos);
}
	
EWXWEXPORT(void*,cbCustomizeBarEvent_Bar)(void* self)
{
	return (void*)((cbCustomizeBarEvent*)self)->mpBar;
}
	
EWXWEXPORT(wxPoint*,cbCustomizeLayoutEvent_ClickPos)(void* self)
{
  return new wxPoint(((cbCustomizeLayoutEvent*)self)->mClickPos);
}
	
EWXWEXPORT(void*,cbAntiflickerPlugin_CreateDefault)()
{
	return (void*)new cbAntiflickerPlugin();
}
	
EWXWEXPORT(void*,cbAntiflickerPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbAntiflickerPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbAntiflickerPlugin_Delete)(void* self)
{
	delete (cbAntiflickerPlugin*)self;
}

EWXWEXPORT(void*,cbBarDragPlugin_CreateDefault)()
{
	return (void*)new cbBarDragPlugin();
}
	
EWXWEXPORT(void*,cbBarDragPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbBarDragPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbBarDragPlugin_Delete)(void* self)
{
	delete (cbBarDragPlugin*)self;
}

EWXWEXPORT(void*,cbBarHintsPlugin_CreateDefault)()
{
	return (void*)new cbBarHintsPlugin();
}
	
EWXWEXPORT(void*,cbBarHintsPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbBarHintsPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbBarHintsPlugin_Delete)(void* self)
{
	delete (cbBarHintsPlugin*)self;
}

EWXWEXPORT(void,cbBarHintsPlugin_SetGrooveCount)(void* self,int nGrooves)
{
	((cbBarHintsPlugin*)self)->SetGrooveCount(nGrooves);
}
	
EWXWEXPORT(void*,cbSimpleCustomizationPlugin_CreateDefault)()
{
	return (void*)new cbSimpleCustomizationPlugin();
}
	
EWXWEXPORT(void*,cbSimpleCustomizationPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbSimpleCustomizationPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbSimpleCustomizationPlugin_Delete)(void* self)
{
	delete (cbSimpleCustomizationPlugin*)self;
}

EWXWEXPORT(bool,wxToolLayoutItem_IsSeparator)(wxToolLayoutItem* self)
{
	return self->mIsSeparator;
}
	
EWXWEXPORT(void,wxToolLayoutItem_Rect)(void* self)
{
  wxRect* r = new wxRect();
  *r = ((wxToolLayoutItem*)self)->mRect;
  return r;
}
	
EWXWEXPORT(void*,wxDynToolInfo_pToolWnd)(void* self)
{
	return (void*)((wxDynToolInfo*)self)->mpToolWnd;
}
	
EWXWEXPORT(int,wxDynToolInfo_Index)(void* self)
{
	return ((wxDynToolInfo*)self)->mIndex;
}
	
EWXWEXPORT(wxSize*,wxDynToolInfo_RealSize)(void* self)
{
  return new wxSize(((wxDynToolInfo*)self)->mRealSize);
}
	
EWXWEXPORT(void*,wxDynamicToolBar_CreateDefault)()
{
	return (void*)new wxDynamicToolBar();
}
	
EWXWEXPORT(void*,wxDynamicToolBar_Create)(wxWindow* parent,int id,int x,int y,int w,int h,int style,int orientation,int RowsOrColumns)
{
	return (void*)new wxDynamicToolBar(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style, orientation, RowsOrColumns);
}

EWXWEXPORT(void,wxDynamicToolBar_Delete)(void* self)
{
	delete (wxDynamicToolBar*)self;
}

EWXWEXPORT(int,wxDynamicToolBar_CreateParams)(wxDynamicToolBar* self,wxWindow* parent,int id,int x,int y,int w,int h,int style,int orientation,int RowsOrColumns)
{
	return (int)self->Create(parent, (wxWindowID)id, wxPoint(x, y), wxSize(w, h), (long)style, orientation, RowsOrColumns);
}
	
EWXWEXPORT(void,wxDynamicToolBar_AddTool)(void* self,int toolIndex,wxWindow* pToolWindow,int w,int h)
{
	((wxDynamicToolBar*)self)->AddTool(toolIndex, pToolWindow, wxSize(w, h));
}
	
EWXWEXPORT(void,wxDynamicToolBar_AddToolImage)(void* self,int toolIndex,void* imageFileName,int imageFileType,void* labelText,bool alignTextRight,bool isFlat)
{
	((wxDynamicToolBar*)self)->AddTool(toolIndex, (char*)imageFileName, (wxBitmapType)imageFileType, (char*)labelText, alignTextRight , isFlat );
}
	
EWXWEXPORT(void,wxDynamicToolBar_AddToolLabel)(void* self,int toolIndex,wxBitmap* labelBmp,void* labelText,bool alignTextRight,bool isFlat)
{
	((wxDynamicToolBar*)self)->AddTool(toolIndex,*labelBmp, (char*)labelText, alignTextRight , isFlat);
}
	
EWXWEXPORT(void*,wxDynamicToolBar_AddToolBitmap)(void* self,int toolIndex,wxBitmap* bitmap,wxBitmap* pushedBitmap,bool toggle,int x,int y,wxObject* clientData,void* helpString1,void* helpString2)
{
	return (void*)((wxDynamicToolBar*)self)->AddTool(toolIndex,*bitmap,*pushedBitmap, toggle , (long)x, (long)y, clientData, (char*)helpString1, (char*)helpString2);
}
	
EWXWEXPORT(void,wxDynamicToolBar_AddSeparator)(void* self,wxWindow* pSepartorWnd)
{
	((wxDynamicToolBar*)self)->AddSeparator(pSepartorWnd);
}
	
EWXWEXPORT(void*,wxDynamicToolBar_GetToolInfo)(void* self,int toolIndex)
{
	return (void*)((wxDynamicToolBar*)self)->GetToolInfo(toolIndex);
}
	
EWXWEXPORT(void,wxDynamicToolBar_RemoveTool)(void* self,int toolIndex)
{
	((wxDynamicToolBar*)self)->RemveTool(toolIndex);
}
	
EWXWEXPORT(void,wxDynamicToolBar_DrawSeparator)(void* self,void* info,wxDC* dc)
{
	((wxDynamicToolBar*)self)->DrawSeparator(*((wxDynToolInfo*)info),*dc);
}
	
EWXWEXPORT(int,wxDynamicToolBar_Layout)(wxDynamicToolBar* self)
{
	return (int)self->Layout();
}
	
EWXWEXPORT(wxSize*,wxDynamicToolBar_GetPreferredDim)(void* self,int gw,int gh)
{
  return new wxSize(((wxDynamicToolBar*)self)->GetPreferredDim(wxSize(gw, gh), size));
}
	
EWXWEXPORT(void*,wxDynamicToolBar_CreateDefaultLayout)(void* self)
{
	return (void*)((wxDynamicToolBar*)self)->CreateDefaultLayout();
}
	
EWXWEXPORT(void,wxDynamicToolBar_SetLayout)(void* self,void* pLayout)
{
	((wxDynamicToolBar*)self)->SetLayout((LayoutManagerBase*)pLayout);
}
	
EWXWEXPORT(void,wxDynamicToolBar_EnableTool)(void* self,int toolIndex,bool enable)
{
	((wxDynamicToolBar*)self)->EnableTool(toolIndex, enable);
}
	
EWXWEXPORT(void*,wxDynamicToolBar_FindToolForPosition)(void* self,int x,int y)
{
	return (void*)((wxDynamicToolBar*)self)->FindToolForPosition((wxCoord)x, (wxCoord)y);
}
	
EWXWEXPORT(int,wxDynamicToolBar_DoInsertTool)(wxDynamicToolBar* self,int pos,wxToolBarToolBase* tool)
{
	return (int)self->DoInsertTool((size_t)pos, tool);
}
	
EWXWEXPORT(int,wxDynamicToolBar_DoDeleteTool)(wxDynamicToolBar* self,int pos,wxToolBarToolBase* tool)
{
	return (int)self->DoDeleteTool((size_t)pos, tool);
}
	
EWXWEXPORT(void,wxDynamicToolBar_DoEnableTool)(void* self,void* tool,bool enable)
{
	((wxDynamicToolBar*)self)->DoEnableTool((wxToolBarToolBase*)tool, enable);
}
	
EWXWEXPORT(void,wxDynamicToolBar_DoToggleTool)(void* self,void* tool,bool toggle)
{
	((wxDynamicToolBar*)self)->DoToggleTool((wxToolBarToolBase*)tool, toggle);
}
	
EWXWEXPORT(void,wxDynamicToolBar_DoSetToggle)(void* self,void* tool,bool toggle)
{
	((wxDynamicToolBar*)self)->DoSetToggle((wxToolBarToolBase*)tool, toggle);
}
	
EWXWEXPORT(void*,wxDynamicToolBar_CreateTool)(void* self,int id,void* label,wxBitmap* bmpNormal,wxBitmap* bmpDisabled,int kind,wxObject* clientData,void* shortHelp,void* longHelp)
{
	return (void*)((wxDynamicToolBar*)self)->CreateTool(id, (char*)label,*bmpNormal,*bmpDisabled, (wxItemKind)kind, clientData, (char*)shortHelp, (char*)longHelp);
}
	
EWXWEXPORT(void*,wxDynamicToolBar_CreateToolControl)(void* self,wxControl* control)
{
	return (void*)((wxDynamicToolBar*)self)->CreateTool(control);
}
	
EWXWEXPORT(void*,cbDynToolBarDimHandler_Create)()
{
	return (void*)new cbDynToolBarDimHandler();
}
	
EWXWEXPORT(void,cbDynToolBarDimHandler_Delete)(void* self)
{
	delete (cbDynToolBarDimHandler*)self;
}

EWXWEXPORT(void*,cbGCUpdatesMgr_Create)(void* pPanel)
{
	return (void*)new cbGCUpdatesMgr((wxFrameLayout*)pPanel);
}
	
EWXWEXPORT(void*,cbGCUpdatesMgr_CreateDefault)()
{
	return (void*)new cbGCUpdatesMgr();
}
	
EWXWEXPORT(void,cbGCUpdatesMgr_Delete)(void* self)
{
	delete (cbGCUpdatesMgr*)self;
}
	
EWXWEXPORT(void,cbGCUpdatesMgr_UpdateNow)(void* self)
{
	((cbGCUpdatesMgr*)self)->UpdateNow();
}

EWXWEXPORT(void*,cbHintAnimationPlugin_CreateDefault)()
{
	return (void*)new cbHintAnimationPlugin();
}
	
EWXWEXPORT(void*,cbHintAnimationPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbHintAnimationPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbHintAnimationPlugin_Delete)(void* self)
{
	delete (cbHintAnimationPlugin*)self;
}

EWXWEXPORT(void*,wxNewBitmapButton_Create)(wxBitmap* labelBitmap,void* labelText,int alignText,bool isFlat,int firedEventType,int marginX,int marginY,int textToLabelGap,bool isSticky)
{
	return (void*)new wxNewBitmapButton(*labelBitmap, (char*)labelText, alignText, isFlat , firedEventType, marginX, marginY, textToLabelGap, isSticky );
}
	
EWXWEXPORT(void*,wxNewBitmapButton_CreateFromFile)(void* bitmapFileName,int bitmapFileType,void* labelText,int alignText,bool isFlat,int firedEventType,int marginX,int marginY,int textToLabelGap,bool isSticky)
{
	return (void*)new wxNewBitmapButton((char*)bitmapFileName, (wxBitmapType)bitmapFileType, (char*)labelText, alignText, isFlat , firedEventType, marginX, marginY, textToLabelGap, isSticky);
}

EWXWEXPORT(void,wxNewBitmapButton_Realize)(void* self,wxWindow* _prt,int _id,int _x,int _y,int _w,int _h)
{
	((wxNewBitmapButton*)self)->Create(_prt, (wxWindowID)_id, wxPoint(_x, _y), wxSize(_w, _h));
}

EWXWEXPORT(void,wxNewBitmapButton_Delete)(void* self)
{
	delete (wxNewBitmapButton*)self;
}

EWXWEXPORT(void,wxNewBitmapButton_Reshape)(void* self)
{
	((wxNewBitmapButton*)self)->Reshape();
}
	
EWXWEXPORT(void,wxNewBitmapButton_SetLabel)(void* self,wxBitmap* labelBitmap,void* labelText)
{
	((wxNewBitmapButton*)self)->SetLabel(*labelBitmap, (char*)labelText);
}
	
EWXWEXPORT(void,wxNewBitmapButton_SetAlignments)(void* self,int alignText,int marginX,int marginY,int textToLabelGap)
{
	((wxNewBitmapButton*)self)->SetAlignments(alignText, marginX, marginY, textToLabelGap);
}
	
EWXWEXPORT(void,wxNewBitmapButton_DrawDecorations)(void* self,wxDC* dc)
{
	((wxNewBitmapButton*)self)->DrawDecorations(*dc);
}
	
EWXWEXPORT(void,wxNewBitmapButton_DrawLabel)(void* self,wxDC* dc)
{
	((wxNewBitmapButton*)self)->DrawLabel(*dc);
}
	
EWXWEXPORT(void,wxNewBitmapButton_RenderLabelImage)(void* self,wxBitmap* destBmp,wxBitmap* srcBmp,bool isEnabled,bool isPressed)
{
	((wxNewBitmapButton*)self)->RenderLabelImage(destBmp, srcBmp, isEnabled , isPressed);
}
	
EWXWEXPORT(void,wxNewBitmapButton_RenderLabelImages)(void* self)
{
	((wxNewBitmapButton*)self)->RenderLabelImages();
}
	
EWXWEXPORT(void,wxNewBitmapButton_RenderAllLabelImages)(void* self)
{
	((wxNewBitmapButton*)self)->RenderAllLabelImages();
}
	
EWXWEXPORT(int,wxNewBitmapButton_Enable)(wxNewBitmapButton* self,bool enable)
{
	return (int)self->Enable(enable);
}
	
EWXWEXPORT(void*,cbPaneDrawPlugin_CreateDefault)()
{
	return (void*)new cbPaneDrawPlugin();
}
	
EWXWEXPORT(void*,cbPaneDrawPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbPaneDrawPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbPaneDrawPlugin_Delete)(void* self)
{
	delete (cbPaneDrawPlugin*)self;
}

EWXWEXPORT(void*,cbRowDragPlugin_CreateDefault)()
{
	return (void*)new cbRowDragPlugin();
}
	
EWXWEXPORT(void*,cbRowDragPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbRowDragPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbRowDragPlugin_Delete)(void* self)
{
	delete (cbRowDragPlugin*)self;
}

EWXWEXPORT(void*,cbRowLayoutPlugin_CreateDefault)()
{
	return (void*)new cbRowLayoutPlugin();
}
	
EWXWEXPORT(void*,cbRowLayoutPlugin_Create)(void* pPanel,int paneMask)
{
	return (void*)new cbRowLayoutPlugin((wxFrameLayout*)pPanel, paneMask);
}
	
EWXWEXPORT(void,cbRowLayoutPlugin_Delete)(void* self)
{
	delete (cbRowLayoutPlugin*)self;
}

EWXWEXPORT(void*,cbPluginBase_Plugin)(int _swt)
{
	switch (_swt)
	{
		case 0:
			return CLASSINFO(cbAntiflickerPlugin);
		
		case 1:
			return CLASSINFO(cbBarDragPlugin);
		
		case 2:
			return CLASSINFO(cbBarHintsPlugin);
		
		case 3:
			return CLASSINFO(cbSimpleCustomizationPlugin);
		
		case 4:
			return CLASSINFO(cbHintAnimationPlugin);
		
		case 5:
			return CLASSINFO(cbPaneDrawPlugin);
		
		case 6:
			return CLASSINFO(cbRowDragPlugin);
		
		case 7:
			return CLASSINFO(cbRowLayoutPlugin);
		
		default:
			return NULL;
	}
}

EWXWEXPORT(void*,cbCommonPaneProperties_CreateDefault)()
{
	return (void*)new cbCommonPaneProperties();
}
	
EWXWEXPORT(void,cbCommonPaneProperties_Delete)(void* self)
{
	delete (cbCommonPaneProperties*)self;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_RealTimeUpdatesOn)(cbCommonPaneProperties* self)
{
	return (int)self->mRealTimeUpdatesOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_OutOfPaneDragOn)(cbCommonPaneProperties* self)
{
	return (int)self->mOutOfPaneDragOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_ExactDockPredictionOn)(cbCommonPaneProperties* self)
{
	return (int)self->mExactDockPredictionOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_NonDestructFrictionOn)(cbCommonPaneProperties* self)
{
	return (int)self->mNonDestructFrictionOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_Show3DPaneBorderOn)(cbCommonPaneProperties* self)
{
	return (int)self->mShow3DPaneBorderOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_BarFloatingOn)(cbCommonPaneProperties* self)
{
	return (int)self->mBarFloatingOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_RowProportionsOn)(cbCommonPaneProperties* self)
{
	return (int)self->mRowProportionsOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_ColProportionsOn)(cbCommonPaneProperties* self)
{
	return (int)self->mColProportionsOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_BarCollapseIconsOn)(cbCommonPaneProperties* self)
{
	return (int)self->mBarCollapseIconsOn;
}
	
EWXWEXPORT(int,cbCommonPaneProperties_BarDragHintsOn)(cbCommonPaneProperties* self)
{
	return (int)self->mBarDragHintsOn;
}
	
EWXWEXPORT(wxSize*,cbCommonPaneProperties_MinCBarDim)(void* self)
{
  return new wxSize(((cbCommonPaneProperties*)self)->mMinCBarDim);
}
	
EWXWEXPORT(int,cbCommonPaneProperties_ResizeHandleSize)(void* self)
{
	return ((cbCommonPaneProperties*)self)->mResizeHandleSize;
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetRealTimeUpdatesOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mRealTimeUpdatesOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetOutOfPaneDragOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mOutOfPaneDragOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetExactDockPredictionOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mExactDockPredictionOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetNonDestructFrictionOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mNonDestructFrictionOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetShow3DPaneBorderOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mShow3DPaneBorderOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetBarFloatingOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mBarFloatingOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetRowProportionsOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mRowProportionsOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetColProportionsOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mColProportionsOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetBarCollapseIconsOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mBarCollapseIconsOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetBarDragHintsOn)(void* self,bool _val)
{
	((cbCommonPaneProperties*)self)->mBarDragHintsOn = (_val);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetMinCBarDim)(void* self,int _w,int _h)
{
	((cbCommonPaneProperties*)self)->mMinCBarDim = wxSize (_w, _h);
}
	
EWXWEXPORT(void,cbCommonPaneProperties_SetResizeHandleSize)(void* self,int _val)
{
	((cbCommonPaneProperties*)self)->mResizeHandleSize = _val;
}
	
EWXWEXPORT(void,cbCommonPaneProperties_Assign)(void* self,void* _other)
{
	*((cbCommonPaneProperties*)self) = *((cbCommonPaneProperties*)_other);
}
	
}
