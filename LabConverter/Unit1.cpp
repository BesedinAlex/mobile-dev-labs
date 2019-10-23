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
	TabControl->TabPosition = TTabPosition::None;
    TabControl->ActiveTab = TabItemMenu;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonTimeClick(TObject *Sender)
{
	TabControl->GotoVisibleTab(TabItemTime->Index);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDistanceClick(TObject *Sender)
{
	TabControl->GotoVisibleTab(TabItemDistance->Index);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDataClick(TObject *Sender)
{
    TabControl->GotoVisibleTab(TabItemData->Index);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonTemperatureClick(TObject *Sender)
{
    TabControl->GotoVisibleTab(TabItemTemperature->Index);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonBackClick(TObject *Sender)
{
    TabControl->GotoVisibleTab(TabItemMenu->Index);
}
//---------------------------------------------------------------------------

