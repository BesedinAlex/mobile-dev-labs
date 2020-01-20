//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Edit.hpp>
#include "Squares.cpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TLabel *Label1;
	TTabControl *TabControl;
	TTabItem *TabItemMenu;
	TTabItem *TabItemGame;
	TTabItem *TabItemSettings;
	TImage *Image1;
	TButton *ButtonGame;
	TButton *ButtonSettings;
	TButton *ButtonBack;
	TButton *ButtonInfo;
	TTabItem *TabItemGameSetup;
	TGridPanelLayout *GridPanelLayout1;
	TButton *ButtonMore;
	TButton *ButtonLess;
	TToolBar *ToolBar2;
	TToolBar *ToolBar3;
	TEdit *EditAnswer;
	TToolBar *ToolBar4;
	TLabel *LabelDifficulty;
	TLabel *LabelScore;
	TLabel *LabelTime;
	TRectangle *Rectangle1;
	TButton *ButtonEnter;
	TRectangle *Rectangle2;
	TRectangle *Rectangle3;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	TRectangle *Rectangle6;
	TRectangle *Rectangle7;
	TRectangle *Rectangle8;
	TRectangle *Rectangle9;
	TRectangle *Rectangle10;
	TRectangle *Rectangle11;
	TRectangle *Rectangle12;
	TRectangle *Rectangle13;
	TRectangle *Rectangle14;
	TRectangle *Rectangle15;
	TRectangle *Rectangle16;
	TRectangle *Rectangle17;
	TRectangle *Rectangle18;
	TRectangle *Rectangle19;
	TRectangle *Rectangle20;
	TRectangle *Rectangle21;
	TRectangle *Rectangle22;
	TRectangle *Rectangle23;
	TRectangle *Rectangle24;
	TRectangle *Rectangle25;
	TButton *ButtonMoreOrLess;
	TButton *ButtonCount;
	TButton *ButtonTwoColors;
	TButton *ButtonThreeColors;
	TButton *ButtonFourColors;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *LabelTask;
	TTimer *Timer1;
	TTabItem *TabItemGameOver;
	TLabel *LabelResultDifficulty;
	TLabel *LabelResultAttempts;
	TLabel *LabelResultSuccesses;
	TButton *ButtonRestart;
	TButton *ButtonEqual;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonGameClick(TObject *Sender);
	void __fastcall ButtonSettingsClick(TObject *Sender);
	void __fastcall ButtonBackClick(TObject *Sender);
	void __fastcall ButtonInfoClick(TObject *Sender);
	void __fastcall ButtonCountClick(TObject *Sender);
	void __fastcall ButtonTwoColorsClick(TObject *Sender);
	void __fastcall ButtonThreeColorsClick(TObject *Sender);
	void __fastcall ButtonFourColorsClick(TObject *Sender);
	void __fastcall ButtonMoreOrLessClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ButtonEnterClick(TObject *Sender);
	void __fastcall ButtonMoreClick(TObject *Sender);
	void __fastcall ButtonLessClick(TObject *Sender);
	void __fastcall ButtonRestartClick(TObject *Sender);
	void __fastcall ButtonEqualClick(TObject *Sender);
private:	// User declarations
    Squares game;
	void updateView();
	TList *squares;
	int difficulty;
	double time;
	int attempts;
    int successes;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
