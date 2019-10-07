//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

inline int Low(UnicodeString &)
{
#ifdef _DELPHI_STRING_ONE_BASED
	return 1;
#else
	return 0;
#endif
}

inline int High(UnicodeString &S)
{
#ifdef _DELPHI_STRING_ONE_BASED
	return S.Length();
#else
	return S.Length() - 1;
#endif
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TabControl1->First();

	UnicodeString text;

	for (int i = 0; i < Memo1->Lines->Count; i++) {
		text = Memo1->Lines->Strings[i];
		if (i % 2 == 1) {
			for (int j = Low(text); j <= High(text); j++) {
				if (text[j] != ' ') {
					text[j] = 'x';
				}
			}
		}
		Memo2->Lines->Add(text);
	}

	bool flag;
	for (int i = 0; i < Memo1->Lines->Count; i++) {
		text = Memo1->Lines->Strings[i];
		flag = false;
		for (int j = Low(text); j <= High(text); j++) {
			if (flag && text[j] != ' ') {
				text[j] = 'x';
			}
			if (!flag && text[j] == ' ') {
                flag = true;
			}
		}
		Memo3->Lines->Add(text);
	}

	for (int i = 0; i < Memo1->Lines->Count; i++) {
		text = Memo1->Lines->Strings[i];
		for (int j = Low(text); j <= High(text); j++) {
			if (text[j] != ' ') {
				if (j != Low(text)) {
					if (text[j - 1] != ' ') {
						text[j] = 'x';
					}
				}
			}
		}
		Memo4->Lines->Add(text);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonZoomInClick(TObject *Sender)
{
	Memo1->TextSettings->Font->Size += 1;
	Memo2->TextSettings->Font->Size += 1;
	Memo3->TextSettings->Font->Size += 1;
	Memo4->TextSettings->Font->Size += 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonZoomOutClick(TObject *Sender)
{
	Memo1->TextSettings->Font->Size -= 1;
	Memo2->TextSettings->Font->Size -= 1;
	Memo3->TextSettings->Font->Size -= 1;
    Memo4->TextSettings->Font->Size -= 1;
}
//---------------------------------------------------------------------------

