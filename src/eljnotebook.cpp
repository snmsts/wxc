#include "wrapper.h"

extern "C"
{

EWXWEXPORT(void*,wxNotebook_Create)(wxWindow* _prt,int _id,int _stl)
{
	return (void*)new wxNotebook (_prt, _id, wxDefaultPosition, wxDefaultSize, _stl);
}

EWXWEXPORT(int,wxNotebook_GetPageCount)(void* self)
{
	return ((wxNotebook*)self)->GetPageCount();
}
	
EWXWEXPORT(int,wxNotebook_SetSelection)(void* self,int nPage)
{
	return ((wxNotebook*)self)->SetSelection(nPage);
}
	
EWXWEXPORT(void,wxNotebook_AdvanceSelection)(void* self,bool bForward)
{
	((wxNotebook*)self)->AdvanceSelection(bForward);
}
	
EWXWEXPORT(int,wxNotebook_GetSelection)(void* self)
{
	return ((wxNotebook*)self)->GetSelection();
}
	
EWXWEXPORT(bool,wxNotebook_SetPageText)(wxNotebook* self,int nPage,wxString* strText)
{
	return self->SetPageText(nPage,*strText);
}
	
EWXWEXPORT(wxString*,wxNotebook_GetPageText)(void* self,int nPage)
{
  return new wxString(((wxNotebook*)self)->GetPageText(nPage));
}
	
EWXWEXPORT(void,wxNotebook_SetImageList)(void* self,void* imageList)
{
	((wxNotebook*)self)->SetImageList((wxImageList*)imageList);
}
	
EWXWEXPORT(void*,wxNotebook_GetImageList)(void* self)
{
	return (void*)((wxNotebook*)self)->GetImageList();
}
	
EWXWEXPORT(int,wxNotebook_GetPageImage)(void* self,int nPage)
{
	return ((wxNotebook*)self)->GetPageImage(nPage);
}
	
EWXWEXPORT(bool,wxNotebook_SetPageImage)(wxNotebook* self,int nPage,int nImage)
{
	return self->SetPageImage(nPage, nImage);
}
	
EWXWEXPORT(int,wxNotebook_GetRowCount)(void* self)
{
	return ((wxNotebook*)self)->GetRowCount();
}
	
EWXWEXPORT(void,wxNotebook_SetPageSize)(void* self,int _w,int _h)
{
	((wxNotebook*)self)->SetPageSize(wxSize(_w, _h));
}
	
EWXWEXPORT(void,wxNotebook_SetPadding)(void* self,int _w,int _h)
{
	((wxNotebook*)self)->SetPadding(wxSize(_w, _h));
}
	
EWXWEXPORT(bool,wxNotebook_DeletePage)(wxNotebook* self,int nPage)
{
	return self->DeletePage(nPage);
}
	
EWXWEXPORT(bool,wxNotebook_RemovePage)(wxNotebook* self,int nPage)
{
	return self->RemovePage(nPage);
}
	
EWXWEXPORT(bool,wxNotebook_DeleteAllPages)(wxNotebook* self)
{
	return self->DeleteAllPages();
}
	
EWXWEXPORT(bool,wxNotebook_AddPage)(wxNotebook* self,wxNotebookPage* pPage,wxString* strText,bool bSelect,int imageId)
{
	return self->AddPage( pPage,* strText, bSelect, imageId);
}
	
EWXWEXPORT(bool,wxNotebook_InsertPage)(wxNotebook* self,int nPage,wxNotebookPage* pPage,wxString* strText,bool bSelect,int imageId)
{
	return self->InsertPage(nPage,  pPage,* strText, bSelect, imageId);
}
	
EWXWEXPORT(void*,wxNotebook_GetPage)(void* self,int nPage)
{
	return (void*)((wxNotebook*)self)->GetPage(nPage);
}
	
}
