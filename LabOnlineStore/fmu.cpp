//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include "dmu.h"
#include "fruCategory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;
//---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfm::FormCreate(TObject *Sender)
{
	x = 0;
	tc->ActiveTab = tiMenu;
	tc->TabPosition = TTabPosition :: None;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buFeedbackClick(TObject *Sender)
{
	edFeedbackFIO->Text = "";
	edFeedbackPhone->Text = "";
	edFeedbackEmail->Text = "";
	meFeedbackNote->Lines->Clear();
	tc->ActiveTab = tiFeedback;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buBackAllClick(TObject *Sender)
{
	tc->ActiveTab = tiMenu;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buStoreClick(TObject *Sender)
{
	tc->ActiveTab = tiCategory;
//	if (x == 0) {
//		ReloadCategoryList();
//		x++;
//	}
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buSendFeedbackClick(TObject *Sender)
{
	dm->FeedbackIns(
	edFeedbackFIO->Text
	,edFeedbackPhone->Text
	,edFeedbackEmail->Text
	,meFeedbackNote->Text
	);
	ShowMessage("Feedback was sended!");
	tc->GotoVisibleTab(tiMenu->Index);
}
//---------------------------------------------------------------------------
void Tfm::ReloadCategoryList()
{
	dm->quCategory->First();
	while (!dm->quCategory->Eof){
		TfrCategory *x = new TfrCategory(glCategory);
		x->Parent = glCategory;
		x->Align = TAlignLayout::Client;
		x->Name = "frCategory"+IntToStr(dm->quCategoryID->Value);
		x->la->Text = dm->quCategoryNAME->Value;
		x->im->Bitmap->Assign(dm->quCategoryIMAGE);
		x->Tag = dm->quCategoryID->Value;
		x->OnClick = CategoryCellOnClick;
		dm->quCategory->Next();
	}
	glCategory->RecalcSize();
}

void __fastcall Tfm::CategoryCellOnClick(TObject *Sender)
{
	int xCategoryID = ((TControl*)Sender)->Tag;
	TLocateOptions xLO;
	dm->quCategory->Locate(dm->quCategoryID->FieldName, xCategoryID, xLO);

	tc->ActiveTab = tiProductList;
	//tc->GotoVisibleTab(tiProductList->Index);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::FormShow(TObject *Sender)
{
	ReloadCategoryList();
}
//---------------------------------------------------------------------------

void __fastcall Tfm::glCategoryResize(TObject *Sender)
{
	float x = (glCategory->Width < 400) ? glCategory->Width: glCategory->Width / 2;
	glCategory->ItemHeight = x;
	glCategory->ItemWidth = x;

	glCategory->Height =
		Ceil((glCategory->ComponentCount - 1)/(glCategory->Width/glCategory->ItemWidth))
		* glCategory->ItemHeight;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buBackToCategoryClick(TObject *Sender)
{
	tc->ActiveTab = tiCategory;
}
//---------------------------------------------------------------------------


void __fastcall Tfm::lvProductItemClick(TObject * const Sender, TListViewItem * const AItem)
{
	tc->ActiveTab = tiProduct;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buProdClick(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buBackTOProductListClick(TObject *Sender)
{
    tc->ActiveTab = tiProductList;
}
//---------------------------------------------------------------------------

