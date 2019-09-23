//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *labelTime;
	TButton *buttonStart;
	TButton *buttonStop;
	TTimer *timer;
	TButton *Button1;
	TMemo *memo;
	void __fastcall buttonStartClick(TObject *Sender);
	void __fastcall buttonStopClick(TObject *Sender);
	void __fastcall timerTimer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    TDateTime timerStart;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
