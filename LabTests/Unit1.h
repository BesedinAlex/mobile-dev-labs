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
#include <FMX.Objects.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TLabel *Label1;
	TButton *ButtonInfo;
	TTabControl *TabControl;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TTabItem *TabItem3;
	TTabItem *TabItem4;
	TTabItem *TabItem5;
	TButton *ButtonStart;
	TImage *Image1;
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox2;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TLabel *Label3;
	TScrollBox *ScrollBox3;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TLabel *Label4;
	TButton *ButtonRestart;
	TMemo *Memo;
	void __fastcall ButtonStartClick(TObject *Sender);
	void __fastcall ButtonAnswerClick(TObject *Sender);
	void __fastcall ButtonRestartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
