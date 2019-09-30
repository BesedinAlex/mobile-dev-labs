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
	Memo->Lines->Add(L"Question " + TabControl->ActiveTab->Text + " - " + x);

    TabControl->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRestartClick(TObject *Sender)
{
    Memo->Lines->Clear();
	TabControl->First();
}
//---------------------------------------------------------------------------
