//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MouseEnter(TObject *Sender)
{
	TButton *x = ((TButton *) Sender);
	x->Margins->Rect = TRect(0, 0, 0, 0);
	x->TextSettings->Font->Size += 10;
	x->TextSettings->Font->Style = x->TextSettings->Font->Style << TFontStyle::fsBold;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MouseLeave(TObject *Sender)
{
    TButton *x = ((TButton *) Sender);
	x->Margins->Rect = TRect(5, 5, 5, 5);
	x->TextSettings->Font->Size -= 10;
	x->TextSettings->Font->Style = x->TextSettings->Font->Style >> TFontStyle::fsBold;
}
//---------------------------------------------------------------------------
