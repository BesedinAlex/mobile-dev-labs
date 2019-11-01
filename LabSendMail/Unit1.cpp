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
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
	IdSMTP1->Host = "smtp.mail.ru";
	IdSMTP1->Port = 587;
	IdSMTP1->Username = "test123210@mail.ru";
	IdSMTP1->Password = "Pa$$word";
	IdSMTP1->UseTLS = utUseExplicitTLS;
	IdSMTP1->ReadTimeout = 15000;
	IdSMTP1->Connect();
	if (IdSMTP1->Connected() == true)
	{
		TIdMessage *x = new TIdMessage();
		try
		{
			x->From->Address = IdSMTP1->Username;
			x->Recipients->Add()->Address = Trim(EditTo->Text);
			x->Subject = Trim(EditSubject->Text);
			x->Body->Assign(MemoBody->Lines);
			x->CharSet = "Windows-1251";
			if (CheckBoxIncludeAttachment->IsChecked)
			{
				UnicodeString xFileName = Ioutils::TPath::ChangeExtension(Ioutils::TPath::GetTempFileName(), ".txt");
				MemoBody->Lines->SaveToFile(xFileName, TEncoding::UTF8);
				new TIdAttachmentFile (x->MessageParts, xFileName);
			}
			IdSMTP1->Send(x);
			ShowMessage(L"Письмо отправлено");
		}
		__finally
		{
			delete x;
			IdSMTP1->Disconnect();
		}
	}
}
//---------------------------------------------------------------------------
