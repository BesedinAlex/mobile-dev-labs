//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TEdit *editURL;
	TButton *buttonGo;
	TToolBar *ToolBar2;
	TButton *buttonBack;
	TButton *buttonForward;
	TButton *buttonReload;
	TButton *buttonStop;
	TButton *buttonInfo;
	TWebBrowser *WebBrowser;
	void __fastcall buttonGoClick(TObject *Sender);
	void __fastcall buttonBackClick(TObject *Sender);
	void __fastcall buttonForwardClick(TObject *Sender);
	void __fastcall buttonReloadClick(TObject *Sender);
	void __fastcall buttonStopClick(TObject *Sender);
	void __fastcall buttonInfoClick(TObject *Sender);
	void __fastcall editURLKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall WebBrowserDidFinishLoad(TObject *ASender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
