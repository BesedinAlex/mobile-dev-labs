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
	: TForm(Owner), game(8)
{
	
	Form1->updateView();
}
//---------------------------------------------------------------------------
void TForm1::updateView()
{
	UnicodeString icons[] = {
	"infotoolbutton",
	"additembutton",
	"arrowdowntoolbutton",
	"bookmarkstoolbutton",
	"drawertoolbutton",
	"refreshtoolbutton",
	"refreshtoolbutton",
	""
	};
	Button1->Enabled = !game.cards[0].isMatched;
	Button2->Enabled = !game.cards[1].isMatched;
	Button3->Enabled = !game.cards[2].isMatched;
	Button4->Enabled = !game.cards[3].isMatched;
	Button5->Enabled = !game.cards[4].isMatched;
	Button6->Enabled = !game.cards[5].isMatched;
	Button7->Enabled = !game.cards[6].isMatched;
	Button8->Enabled = !game.cards[7].isMatched;
	Button9->Enabled = !game.cards[8].isMatched;
	Button10->Enabled = !game.cards[9].isMatched;
	Button1->StyleLookup = icons[game.cards[0].identifier];
	Button2->StyleLookup = icons[game.cards[1].identifier];
	Button3->StyleLookup = icons[game.cards[2].identifier];
	Button4->StyleLookup = icons[game.cards[3].identifier];
	Button5->StyleLookup = icons[game.cards[4].identifier];
	Button6->StyleLookup = icons[game.cards[5].identifier];
	Button7->StyleLookup = icons[game.cards[6].identifier];
	Button8->StyleLookup = icons[game.cards[7].identifier];
	Button9->StyleLookup = icons[game.cards[8].identifier];
	Button10->StyleLookup = icons[game.cards[9].identifier];
	Button11->StyleLookup = icons[game.cards[10].identifier];
	Button12->StyleLookup = icons[game.cards[11].identifier];
	Button13->StyleLookup = icons[game.cards[12].identifier];
	Button14->StyleLookup = icons[game.cards[13].identifier];
	Button15->StyleLookup = icons[game.cards[14].identifier];
	Button16->StyleLookup = icons[game.cards[15].identifier];
}
