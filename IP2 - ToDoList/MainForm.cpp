//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	parentTask = 0;
	currentTask = 0;
}
//---------------------------------------------------------------------------
void TForm1::select(int a)
{
	if (a != 0) {
		DataModuleSQLite->FDQueryTasks->SQL->Text = "select * from Tasks where id = " + IntToStr(a);
		DataModuleSQLite->FDQueryTasks->Open();
		EditName->Text = DataModuleSQLite->FDQueryTasksname->Value;
		CheckBoxDone->IsChecked = DataModuleSQLite->FDQueryTasksdone->Value == 0 ? false : true;
		parentTask = DataModuleSQLite->FDQueryTasksmainTaskId->Value;
	} else {
		EditName->Text = "";
        CheckBoxDone->IsChecked = false;
		parentTask = 0;
	}
	DataModuleSQLite->FDQueryTasks->SQL->Text = "select * from Tasks where mainTaskId = " + IntToStr(a);
	DataModuleSQLite->FDQueryTasks->Open();
	currentTask = a;
	updateForm();
}
//---------------------------------------------------------------------------
void TForm1::updateForm()
{
    bool topTask = currentTask == 0;
	EditName->Enabled = !topTask;
	CheckBoxDone->Enabled = !topTask;
	ButtonSave->Enabled = !topTask;
	ButtonDelete->Enabled = !topTask;
	ButtonReturn->Enabled = !topTask;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonInfoClick(TObject *Sender)
{
    ShowMessage("To-Do List\nCreated by Alexey Besedin (c) 2019");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	select(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListViewTasksItemClick(TObject * const Sender, TListViewItem * const AItem)
{
	select(AItem->Detail.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonReturnClick(TObject *Sender)
{
	select(parentTask);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	DataModuleSQLite->FDConnection->ExecSQL("insert into Tasks (name, done, mainTaskId) values ('New task', 0, "+IntToStr(currentTask)+")");
    select(currentTask);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	DataModuleSQLite->FDConnection->ExecSQL("delete from Tasks where id = "+IntToStr(currentTask)+"");
    select(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSaveClick(TObject *Sender)
{
	int done = CheckBoxDone ? 1 : 0;
    DataModuleSQLite->FDConnection->ExecSQL("update Tasks set name = '"+EditName->Text+"', done = "+IntToStr(done)+" where id = "+currentTask+"");
}
//---------------------------------------------------------------------------
