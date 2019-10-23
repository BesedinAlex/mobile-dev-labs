//---------------------------------------------------------------------------

#ifndef LabMemTableH
#define LabMemTableH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.StorageBin.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <System.IOUtils.hpp>
#include <Data.Bind.Controls.hpp>
#include <Fmx.Bind.Navigator.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FireDAC.Stan.StorageJSON.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TFDMemTable *tb;
	TStringField *tbFIO;
	TStringField *tbTel;
	TIntegerField *tbAge;
	TCurrencyField *tbMoney;
	TGrid *Grid1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TBindNavigator *NavigatorBindSourceDB1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TLinkControlToField *LinkControlToField1;
	TLinkControlToField *LinkControlToField2;
	TLinkControlToField *LinkControlToField3;
	TLinkControlToField *LinkControlToField4;
	TButton *Button1;
	TButton *Button2;
	TEdit *EditFilter;
	TButton *ButtonFilterOn;
	TButton *ButtonFilterOff;
	TEdit *EditFileName;
	TButton *ButtonSaveFile;
	TButton *ButtonLoadFile;
	TFDStanStorageJSONLink *FDStanStorageJSONLink1;
	TButton *ButtonAddMoney;
	TButton *ButtonAddAge;
	TCheckBox *CheckBoxReadOnlyGrid;
	TCheckBox *CheckBoxReadOnlyTable;
	TButton *ButtonLocate;
	TButton *ButtonLookup;
	TEdit *EditL;
	TButton *ButtonSum;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ButtonFilterOnClick(TObject *Sender);
	void __fastcall ButtonFilterOffClick(TObject *Sender);
	void __fastcall ButtonSaveFileClick(TObject *Sender);
	void __fastcall ButtonLoadFileClick(TObject *Sender);
	void __fastcall ButtonAddAgeClick(TObject *Sender);
	void __fastcall ButtonAddMoneyClick(TObject *Sender);
	void __fastcall CheckBoxReadOnlyGridChange(TObject *Sender);
	void __fastcall CheckBoxReadOnlyTableChange(TObject *Sender);
	void __fastcall ButtonLocateClick(TObject *Sender);
	void __fastcall ButtonLookupClick(TObject *Sender);
	void __fastcall ButtonSumClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
