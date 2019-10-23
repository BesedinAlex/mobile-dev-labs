//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "LabMemTable.h"
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    tb->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    tb->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonFilterOnClick(TObject *Sender)
{
    tb->Filter = EditFilter->Text;
    tb->Filtered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonFilterOffClick(TObject *Sender)
{
    tb->Filtered = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSaveFileClick(TObject *Sender)
{
	tb->SaveToFile(Ioutils::TPath::GetDocumentsPath() + PathDelim + EditFileName->Text + ".json");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonLoadFileClick(TObject *Sender)
{
	tb->LoadFromFile(Ioutils::TPath::GetDocumentsPath() + PathDelim + EditFileName->Text + ".json");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddAgeClick(TObject *Sender)
{
	tb->Edit();
	tbAge->Value += 1;
	tb->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddMoneyClick(TObject *Sender)
{
	tb->First();
	while (!tb->Eof) {
		tb->Edit();
		tbMoney->Value += 100;
		tb->Post();
        tb->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxReadOnlyGridChange(TObject *Sender)
{
	Grid1->ReadOnly = CheckBoxReadOnlyGrid->IsChecked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxReadOnlyTableChange(TObject *Sender)
{
	tb->ReadOnly = CheckBoxReadOnlyTable->IsChecked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonLocateClick(TObject *Sender)
{
	tb->Locate(tbAge->FieldName, EditL->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonLookupClick(TObject *Sender)
{
    ShowMessage(tb->Lookup(tbAge->FieldName, EditL->Text, tbFIO->FieldName));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSumClick(TObject *Sender)
{
	double x = 0;
	tb->First();
	while (!tb->Eof) {
		x += tbMoney->Value;
		tb->Next();
	}
	ShowMessage(FloatToStr(x));
}
//---------------------------------------------------------------------------
