//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitSRV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::ButtonStartClick(TObject *Sender)
{
	IdTCPServer->Active = true;
	MemoText->Lines->Add("Active = true");
}
//-------------------------------------------------------------------------—
void __fastcall TForm1::ButtonStopClick(TObject *Sender)
{
	IdTCPServer->Active = false;
	MemoText->Lines->Add("Active = false");
}
//-------------------------------------------------------------------------—
void __fastcall TForm1::IdTCPServer1Connect(TIdContext *AContext)
{
	MemoText->Lines->Add(Format("[%s] - Client connected",
		ARRAYOFCONST((AContext->Connection->Socket->Binding->PeerIP))
	));
}
//-------------------------------------------------------------------------—
void __fastcall TForm1::IdTCPServer1Disconnect(TIdContext *AContext)
{
	MemoText->Lines->Add(Format("[%s] - Client disconnected",
		ARRAYOFCONST((AContext->Connection->Socket->Binding->PeerIP))
	));
}
//-------------------------------------------------------------------------—
void __fastcall TForm1::IdTCPServer1Execute(TIdContext *AContext)
{
	UnicodeString x = AContext->Connection->Socket->ReadLn();
	MemoText->Lines->Add("Input = " - x);

	if (x == "time") {
		AContext->Connection->Socket->WriteLn(TimeToStr(Now()));
	}
	if (x == "str") {
		AContext->Connection->Socket->WriteLn(editStr->Text,
		IndyTextEncoding_UTF8());
	}
	if (x == "image") {
		TMemoryStream *x = new TMemoryStream();
		try {
			image->Bitmap->SaveToStream(x);
			x->Seek(0, 0);
			AContext->Connection->Socket->Write(x->Size);
			AContext->Connection->Socket->Write(x);
		}
		__finally {
			delete x;
		}
	}
}
//---------------------------------------------------------------------------

