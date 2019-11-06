//---------------------------------------------------------------------------

#ifndef UnitCNTH
#define UnitCNTH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.ActnList.hpp>
#include <System.Actions.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TMemo *Memo1;
	TEdit *EditIP;
	TEdit *EditPort;
	TButton *ButtonConnect;
	TButton *ButtonDisconnect;
	TButton *ButtonGetTime;
	TButton *ButtonGetLine;
	TButton *ButtonGetImage;
	TActionList *ActionList1;
	TAction *ActionConnect;
	TAction *ActionDisconnect;
	TAction *ActionGetTime;
	TAction *ActionGetLine;
	TAction *ActionGetImage;
	TIdTCPClient *IdTCPClient1;
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
