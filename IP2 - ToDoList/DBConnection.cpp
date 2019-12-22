//---------------------------------------------------------------------------


#pragma hdrstop

#include "DBConnection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
TDataModuleSQLite *DataModuleSQLite;
//---------------------------------------------------------------------------
__fastcall TDataModuleSQLite::TDataModuleSQLite(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModuleSQLite::FDConnectionBeforeConnect(TObject *Sender)
{
	FDConnection->Params->Values["Database"] =
	#ifdef _Windows
	"..\\..\\" + cNameDb;
	#else
	System::Ioutils::TPath::GetDocumentPath() + PathDelim + cNameDb;
	#endif
}
//---------------------------------------------------------------------------
