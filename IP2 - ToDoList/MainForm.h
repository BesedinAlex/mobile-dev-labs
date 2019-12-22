//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
#include "DBConnection.h"
#include <FMX.Layouts.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TButton *ButtonReturn;
	TButton *ButtonInfo;
	TLabel *Label1;
	TListView *ListViewTasks;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkListControlToField *LinkListControlToField1;
	TToolBar *ToolBarTask;
	TEdit *EditName;
	TCheckBox *CheckBoxDone;
	TButton *ButtonAdd;
	TButton *ButtonSave;
	TButton *ButtonDelete;
	TLinkPropertyToField *LinkPropertyToFieldOwnerTag;
	TLinkPropertyToField *LinkPropertyToFieldParentTag;
	void __fastcall ButtonInfoClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ListViewTasksItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall ButtonReturnClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
private:	// User declarations
	int currentTask;
    int parentTask;
	void select(int a);
	void updateForm();

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
