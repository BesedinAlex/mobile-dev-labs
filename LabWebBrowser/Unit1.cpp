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
void __fastcall TForm1::buttonGoClick(TObject *Sender)
{
	WebBrowser->URL = editURL->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonBackClick(TObject *Sender)
{
	WebBrowser->GoBack();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonForwardClick(TObject *Sender)
{
	WebBrowser->GoForward();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonReloadClick(TObject *Sender)
{
	WebBrowser->Reload();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonStopClick(TObject *Sender)
{
	WebBrowser->Stop();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonInfoClick(TObject *Sender)
{
	ShowMessage("Besedin Alexey is the best developer in the world!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::editURLKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key == vkReturn) {
        WebBrowser->URL = editURL->Text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WebBrowserDidFinishLoad(TObject *ASender)
{
    editURL->Text = WebBrowser->URL;
}
//---------------------------------------------------------------------------

