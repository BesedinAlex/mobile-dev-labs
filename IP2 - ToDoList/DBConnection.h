//---------------------------------------------------------------------------

#ifndef DBConnectionH
#define DBConnectionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
class TDataModuleSQLite : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection;
	TFDQuery *FDQueryTasks;
	TFDAutoIncField *FDQueryTasksid;
	TWideMemoField *FDQueryTasksname;
	TIntegerField *FDQueryTasksdone;
	TIntegerField *FDQueryTasksmainTaskId;
	void __fastcall FDConnectionBeforeConnect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModuleSQLite(TComponent* Owner);
};
const UnicodeString cNameDb = "db.sqlite";
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleSQLite *DataModuleSQLite;
//---------------------------------------------------------------------------
#endif
