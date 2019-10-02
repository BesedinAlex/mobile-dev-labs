//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
	TabControl->First();
	TabControl->TabPosition = TTabPosition::None;
	ProgressBar->Max = TabControl->TabCount - 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonStartClick(TObject *Sender)
{
	TabControl->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAnswerClick(TObject *Sender)
{
	UnicodeString x = ((TControl *) Sender)->Tag == 1 ? L"Right" : L"Wrong";
	CountRight += ((TControl *) Sender)->Tag;
	CountWrong += ((TControl *) Sender)->Tag == 0 ? 1 : 0;
	Memo->Lines->Add(L"Question " + TabControl->ActiveTab->Text + " - " + x);
	Label5->Text = L"Correct = " + IntToStr(CountRight) + "\nWrong = " + IntToStr(CountWrong);
	Image2->Visible = CountRight > CountWrong;
	Image3->Visible = CountWrong > CountRight;
	TabControl->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRestartClick(TObject *Sender)
{
	CountRight = 0;
	CountWrong = 0;
	Memo->Lines->Clear();
	TabControl->First();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControlChange(TObject *Sender)
{
	LabelCount->Text = L"(" + TabControl->ActiveTab->Text + " of " + IntToStr(TabControl->TabCount - 2) +")";
	ProgressBar->Value = TabControl->ActiveTab->Index;
	LabelCount->Visible = (TabControl->ActiveTab != TabItem1) & (TabControl->ActiveTab != TabItem5);
}
//---------------------------------------------------------------------------

