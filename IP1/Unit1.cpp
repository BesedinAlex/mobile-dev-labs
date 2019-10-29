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
	"searcheditbutton",
	"stoptoolbutton"
	};
	for (int i = 0; i < 16; i++) {
		getButton(i)->Enabled = !game.cards[i].isMatched;
        getButton(i)->StyleLookup = game.cards[i].isFaceUp ? icons[game.cards[i].identifier] : "";
	}
}

TButton *TForm1::getButton(int id)
{
	switch (id)
	{
		case 0: return Button1;
		case 1: return Button2;
		case 2: return Button3;
		case 3: return Button4;
		case 4: return Button5;
		case 5: return Button6;
		case 6: return Button7;
		case 7: return Button8;
		case 8: return Button9;
		case 9: return Button10;
		case 10: return Button11;
		case 11: return Button12;
		case 12: return Button13;
		case 13: return Button14;
		case 14: return Button15;
		case 15: return Button16;
		default: return nullptr;
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (((TButton*)Sender)->StyleLookup != "") {
		return;
	}
	game.chooseCard(((TButton*)Sender)->Tag);
	Form1->updateView();
}
//---------------------------------------------------------------------------

