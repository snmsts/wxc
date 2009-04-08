#include "wrapper.h"

extern "C"
{

typedef int _cdecl (*EiffelSortFunc) (void* obj, int data1, int data2);

typedef struct _EiffelSort
{
	void*          obj;
	EiffelSortFunc fnc;
}EiffelSort;

int wxCALLBACK ListCmp (long item1, long item2, long sortData)
{
	return ((EiffelSort*)sortData)->fnc (((EiffelSort*)sortData)->obj, (int)item1, (int)item2);
}

EWXWEXPORT(wxListItem*,wxListItem_Create)()
{
	return new wxListItem();
}

EWXWEXPORT(void,wxListItem_Delete)(wxListItem* self)
{
	delete self;
}
EWXWEXPORT(void,wxListItem_Clear)(wxListItem* self)
{
	self->Clear();
}
	
EWXWEXPORT(void,wxListItem_ClearAttributes)(wxListItem* self)
{
	self->ClearAttributes();
}
	
EWXWEXPORT(void,wxListItem_SetMask)(wxListItem* self,int mask)
{
	self->SetMask((long)mask);
}
	
EWXWEXPORT(void,wxListItem_SetId)(wxListItem* self,int id)
{
	self->SetId((long)id);
}
	
EWXWEXPORT(void,wxListItem_SetColumn)(wxListItem* self,int col)
{
	self->SetColumn(col);
}
	
EWXWEXPORT(void,wxListItem_SetState)(wxListItem* self,int state)
{
	self->SetState((long)state);
}
	
EWXWEXPORT(void,wxListItem_SetStateMask)(wxListItem* self,int stateMask)
{
	self->SetStateMask((long)stateMask);
}
	
EWXWEXPORT(void,wxListItem_SetText)(wxListItem* self,wxString* text)
{
	self->SetText(*text);
}
	
EWXWEXPORT(void,wxListItem_SetImage)(wxListItem* self,int image)
{
	self->SetImage(image);
}
	
EWXWEXPORT(void,wxListItem_SetData)(wxListItem* self,int data)
{
	self->SetData((long)data);
}
	
EWXWEXPORT(void,wxListItem_SetDataPointer)(wxListItem* self,void* data)
{
	self->SetData(data);
}
	
EWXWEXPORT(void,wxListItem_SetWidth)(wxListItem* self,int width)
{
	self->SetWidth(width);
}
	
EWXWEXPORT(void,wxListItem_SetAlign)(wxListItem* self,int align)
{
	self->SetAlign((wxListColumnFormat)align);
}
	
EWXWEXPORT(void,wxListItem_SetTextColour)(wxListItem* self,wxColour* colText)
{
	self->SetTextColour(*colText);
}
	
EWXWEXPORT(void,wxListItem_SetBackgroundColour)(wxListItem* self,wxColour* colBack)
{
	self->SetBackgroundColour(*colBack);
}
	
EWXWEXPORT(void,wxListItem_SetFont)(wxListItem* self,wxFont* font)
{
	self->SetFont(*font);
}
	
EWXWEXPORT(long,wxListItem_GetMask)(wxListItem* self)
{
	return self->GetMask();
}
	
EWXWEXPORT(long,wxListItem_GetId)(wxListItem* self)
{
	return self->GetId();
}
	
EWXWEXPORT(int,wxListItem_GetColumn)(wxListItem* self)
{
	return self->GetColumn();
}
	
EWXWEXPORT(long,wxListItem_GetState)(wxListItem* self)
{
	return self->GetState();
}
	
EWXWEXPORT(wxString*,wxListItem_GetText)(wxListItem* self)
{
  return new wxString(self->GetText());
}
	
EWXWEXPORT(int,wxListItem_GetImage)(wxListItem* self)
{
	return self->GetImage();
}
	
EWXWEXPORT(long,wxListItem_GetData)(wxListItem* self)
{
	return self->GetData();
}
	
EWXWEXPORT(int,wxListItem_GetWidth)(wxListItem* self)
{
	return self->GetWidth();
}
	
EWXWEXPORT(int,wxListItem_GetAlign)(wxListItem* self)
{
	return (int)self->GetAlign();
}
	
EWXWEXPORT(void*,wxListItem_GetAttributes)(wxListItem* self)
{
	return (void*)self->GetAttributes();
}
	
EWXWEXPORT(int,wxListItem_HasAttributes)(wxListItem* self)
{
	return (int)self->HasAttributes();
}
	
EWXWEXPORT(void,wxListItem_GetTextColour)(wxListItem* self,wxColour* _ref)
{
	*_ref = self->GetTextColour();
}
	
EWXWEXPORT(void,wxListItem_GetBackgroundColour)(wxListItem* self,wxColour* _ref)
{
	*_ref = self->GetBackgroundColour();
}
	
EWXWEXPORT(void,wxListItem_GetFont)(wxListItem* self,wxFont* _ref)
{
	*_ref = self->GetFont();
}
	
EWXWEXPORT(void*,wxListCtrl_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxListCtrl (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(int,wxListCtrl_SetForegroundColour)(wxListCtrl* self,wxColour* col)
{
	return (int)self->SetForegroundColour(*col);
}
	
EWXWEXPORT(int,wxListCtrl_SetBackgroundColour)(wxListCtrl* self,wxColour* col)
{
	return (int)self->SetBackgroundColour(*col);
}
	
EWXWEXPORT(int,wxListCtrl_GetColumn)(wxListCtrl* self,int col,wxListItem* item)
{
	return (int)self->GetColumn(col,*item);
}
	
EWXWEXPORT(int,wxListCtrl_SetColumn)(wxListCtrl* self,int col,wxListItem* item)
{
	return (int)self->SetColumn(col,*item);
}
	
EWXWEXPORT(int,wxListCtrl_GetColumnWidth)(void* self,int col)
{
	return ((wxListCtrl*)self)->GetColumnWidth(col);
}
	
EWXWEXPORT(bool,wxListCtrl_SetColumnWidth)(wxListCtrl* self,int col,int width)
{
	return self->SetColumnWidth(col, width);
}
	
EWXWEXPORT(int,wxListCtrl_GetCountPerPage)(void* self)
{
	return ((wxListCtrl*)self)->GetCountPerPage();
}
	
EWXWEXPORT(void*,wxListCtrl_GetEditControl)(void* self)
{
#ifdef __WIN32__
	return (void*)((wxListCtrl*)self)->GetEditControl();
#else
	return NULL;
#endif
}
	
EWXWEXPORT(int,wxListCtrl_GetItem)(wxListCtrl* self,wxListItem* info)
{
	return (int)self->GetItem(*info);
}
	
EWXWEXPORT(bool,wxListCtrl_SetItemFromInfo)(wxListCtrl* self,wxListItem* info)
{
	return self->SetItem(*info);
}
	
EWXWEXPORT(bool,wxListCtrl_SetItem)(wxListCtrl* self,int index,int col,wxString* label,int imageId)
{
	return self->SetItem((long)index, col,*label, imageId);
}
	
EWXWEXPORT(int,wxListCtrl_GetItemState)(void* self,int item,int stateMask)
{
	return ((wxListCtrl*)self)->GetItemState((long)item, (long)stateMask);
}
	
EWXWEXPORT(bool,wxListCtrl_SetItemState)(wxListCtrl* self,int item,int state,int stateMask)
{
	return self->SetItemState((long)item, (long)state, (long)stateMask);
}
	
EWXWEXPORT(bool,wxListCtrl_SetItemImage)(wxListCtrl* self,int item,int image,int selImage)
{
	return self->SetItemImage((long)item, image, selImage);
}
	
EWXWEXPORT(wxString*,wxListCtrl_GetItemText)(void* self,int item)
{
  return new wxString(((wxListCtrl*)self)->GetItemText((long)item));
}
	
EWXWEXPORT(void,wxListCtrl_SetItemText)(void* self,int item,wxString* str)
{
	((wxListCtrl*)self)->SetItemText((long)item,*str);
}
	
EWXWEXPORT(int,wxListCtrl_GetItemData)(wxListCtrl* self,int item)
{
	return (int)self->GetItemData((long)item);
}
	
EWXWEXPORT(bool,wxListCtrl_SetItemData)(wxListCtrl* self,int item,int data)
{
	return self->SetItemData((long)item, (long)data);
}
	
EWXWEXPORT(wxRect*,wxListCtrl_GetItemRect)(wxListCtrl* self,int item,int code)
{
  wxRect rct;
  int result = (int)self->GetItemRect((long)item, rct, code);
  if (result)
    return new wxRect(rct);
  return 0;
}
	
EWXWEXPORT(wxPoint*,wxListCtrl_GetItemPosition)(void* self,int item)
{
  wxPoint pos;
  if(((wxListCtrl*)self)->GetItemPosition((long)item, pos))
    return new wxPoint(pos);
  return 0;
}
	
EWXWEXPORT(int,wxListCtrl_SetItemPosition)(void* self,int item,int x,int y)
{
  return ((wxListCtrl*)self)->SetItemPosition((long)item, wxPoint(x,y));
}
	
EWXWEXPORT(int,wxListCtrl_GetItemCount)(void* self)
{
	return ((wxListCtrl*)self)->GetItemCount();
}
	
EWXWEXPORT(int,wxListCtrl_GetColumnCount)(void* self)
{
	return ((wxListCtrl*)self)->GetColumnCount();
}
	
EWXWEXPORT(void,wxListCtrl_GetItemSpacing)(void* self,bool isSmall,int* h,int* w)
{
#if (wxVERSION_NUMBER <= 2600)
	int x = ((wxListCtrl*)self)->GetItemSpacing(isSmall);
        *h = x;
        *w = x;
#else
	wxSize res = ((wxListCtrl*)self)->GetItemSpacing();
	*h = res.GetHeight();
	*w = res.GetWidth();
#endif
}
	
EWXWEXPORT(int,wxListCtrl_GetSelectedItemCount)(void* self)
{
	return ((wxListCtrl*)self)->GetSelectedItemCount();
}
	
EWXWEXPORT(void,wxListCtrl_GetTextColour)(void* self,wxColour* colour)
{
	*colour = ((wxListCtrl*)self)->GetTextColour();
}
	
EWXWEXPORT(void,wxListCtrl_SetTextColour)(void* self,wxColour* col)
{
	((wxListCtrl*)self)->SetTextColour(*col);
}
	
EWXWEXPORT(int,wxListCtrl_GetTopItem)(wxListCtrl* self)
{
	return (int)self->GetTopItem();
}
	
EWXWEXPORT(void,wxListCtrl_SetSingleStyle)(void* self,int style,bool add)
{
	((wxListCtrl*)self)->SetSingleStyle((long)style, add);
}
	
EWXWEXPORT(void,wxListCtrl_SetWindowStyleFlag)(void* self,int style)
{
	((wxListCtrl*)self)->SetWindowStyleFlag((long)style);
}
	
EWXWEXPORT(int,wxListCtrl_GetNextItem)(void* self,int item,int geometry,int state)
{
	return ((wxListCtrl*)self)->GetNextItem((long)item, geometry, state);
}
	
EWXWEXPORT(void*,wxListCtrl_GetImageList)(void* self,int which)
{
	return (void*)((wxListCtrl*)self)->GetImageList(which);
}
	
EWXWEXPORT(void,wxListCtrl_SetImageList)(void* self,void* imageList,int which)
{
	((wxListCtrl*)self)->SetImageList((wxImageList*)imageList, which);
}
	
EWXWEXPORT(bool,wxListCtrl_Arrange)(wxListCtrl* self,int flag)
{
	return self->Arrange(flag);
}
	
EWXWEXPORT(bool,wxListCtrl_DeleteItem)(wxListCtrl* self,int item)
{
	return self->DeleteItem((long)item);
}
	
EWXWEXPORT(bool,wxListCtrl_DeleteAllItems)(wxListCtrl* self)
{
	return self->DeleteAllItems();
}
	
EWXWEXPORT(bool,wxListCtrl_DeleteColumn)(wxListCtrl* self,int col)
{
	return self->DeleteColumn(col);
}
	
EWXWEXPORT(int,wxListCtrl_DeleteAllColumns)(wxListCtrl* self)
{
	return (int)self->DeleteAllColumns();
}
	
EWXWEXPORT(void,wxListCtrl_ClearAll)(void* self)
{
	((wxListCtrl*)self)->ClearAll();
}
	
EWXWEXPORT(void,wxListCtrl_EditLabel)(void* self,int item)
{
	((wxListCtrl*)self)->EditLabel((long)item);
}
	
EWXWEXPORT(int,wxListCtrl_EndEditLabel)(wxListCtrl* self,bool cancel)
{
#ifdef __WIN32__
	return (int)self->EndEditLabel(cancel);
#else
	return 0;
#endif
}
	
EWXWEXPORT(bool,wxListCtrl_EnsureVisible)(wxListCtrl* self,int item)
{
	return self->EnsureVisible((long)item);
}
	
EWXWEXPORT(int,wxListCtrl_FindItem)(void* self,int start,wxString* str,bool partial)
{
	return (long)((wxListCtrl*)self)->FindItem((long)start,* str, partial);
}
	
EWXWEXPORT(int,wxListCtrl_FindItemByData)(wxListCtrl* self,int start,int data)
{
	return (int)self->FindItem((long)start, (long)data);
}
	
EWXWEXPORT(int,wxListCtrl_FindItemByPosition)(wxListCtrl* self,int start,int x,int y,int direction)
{
	return (int)self->FindItem((long)start, wxPoint(x, y), direction);
}
	
EWXWEXPORT(int,wxListCtrl_HitTest)(void* self,int x,int y,void* flags)
{
	return ((wxListCtrl*)self)->HitTest(wxPoint(x, y),*((int*)flags));
}
	
EWXWEXPORT(int,wxListCtrl_InsertItem)(wxListCtrl* self,wxListItem* info)
{
	return (int)self->InsertItem(*info);
}
	
EWXWEXPORT(int,wxListCtrl_InsertItemWithData)(wxListCtrl* self,int index,wxString* label)
{
	return (int)self->InsertItem((long)index,*label);
}
	
EWXWEXPORT(int,wxListCtrl_InsertItemWithImage)(wxListCtrl* self,int index,int imageIndex)
{
	return (int)self->InsertItem((long)index, imageIndex);
}
	
EWXWEXPORT(int,wxListCtrl_InsertItemWithLabel)(wxListCtrl* self,int index,wxString* label,int imageIndex)
{
	return (int)self->InsertItem((long)index,*label, imageIndex);
}
	
EWXWEXPORT(int,wxListCtrl_InsertColumnFromInfo)(wxListCtrl* self,int col,wxListItem* info)
{
	return (int)self->InsertColumn((long)col,*info);
}
	
EWXWEXPORT(int,wxListCtrl_InsertColumn)(wxListCtrl* self,int col,wxString* heading,int format,int width)
{
	return (int)self->InsertColumn((long)col,* heading, format, width);
}
	
EWXWEXPORT(bool,wxListCtrl_ScrollList)(wxListCtrl* self,int dx,int dy)
{
	return self->ScrollList(dx, dy);
}
	
EWXWEXPORT(bool,wxListCtrl_SortItems)(wxListCtrl* self,void* fnc,void* obj)
{
	EiffelSort srt = {obj, (EiffelSortFunc)fnc};
	return self->SortItems(ListCmp, (long)&srt);
}
	
EWXWEXPORT(void,wxListCtrl_UpdateStyle)(void* self)
{
#ifdef __WIN32__
	((wxListCtrl*)self)->UpdateStyle();
#endif
}
	
}
