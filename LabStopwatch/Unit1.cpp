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
void __fastcall TForm1::buttonStartClick(TObject *Sender)
{
	timerStart = Now();
    timer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonStopClick(TObject *Sender)
{
    timer->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerTimer(TObject *Sender)
{
	UnicodeString x;
	DateTimeToString(x, L"h:nn:ss.zzz", Now() - timerStart);
	labelTime->Text = x.Delete(x.Length() - 2, 2);

//	labelTime->Text = TimeToStr(Now() - timerStart);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    memo->Lines->Add(labelTime->Text);
}
//---------------------------------------------------------------------------
