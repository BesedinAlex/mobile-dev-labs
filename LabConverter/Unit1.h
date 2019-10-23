//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TButton *ButtonBack;
	TButton *ButtonAbout;
	TLabel *Label1;
	TTabControl *TabControl;
	TTabItem *TabItemMenu;
	TTabItem *TabItemTime;
	TTabItem *TabItemDistance;
	TTabItem *TabItemTemperature;
	TTabItem *TabItemData;
	TGridPanelLayout *GridPanelLayout1;
	TButton *ButtonTime;
	TButton *ButtonDistance;
	TButton *ButtonData;
	TButton *ButtonTemperature;
	TListBox *ListBox1;
	TListBoxItem *ListBoxItem1;
	TListBoxItem *ListBoxItem2;
	TListBoxItem *ListBoxItem3;
	TListBoxItem *ListBoxItem4;
	TListBoxItem *ListBoxItem5;
	TEdit *EditMs;
	TEdit *EditSec;
	TEdit *EditMin;
	TEdit *EditHour;
	TEdit *EditDay;
	void __fastcall ButtonTimeClick(TObject *Sender);
	void __fastcall ButtonDistanceClick(TObject *Sender);
	void __fastcall ButtonDataClick(TObject *Sender);
	void __fastcall ButtonTemperatureClick(TObject *Sender);
	void __fastcall ButtonBackClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
