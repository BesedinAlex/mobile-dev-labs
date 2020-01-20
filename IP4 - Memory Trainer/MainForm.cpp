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
	: TForm(Owner), game(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TabControl->TabPosition = TTabPosition::None;
	TabControl->ActiveTab = TabItemMenu;
	difficulty = 0;
	Timer1->Enabled = false;
    attempts = 0;
    successes = 0;
	updateView();
}
//---------------------------------------------------------------------------
void TForm1::updateView()
{
	time = Time().Val + (15 - attempts) / (24.0 * 60.0 * 60.0);
	Timer1->Enabled = true;
	squares = new TList;
	for (int i = 1; i < 26; i++) {
		squares->Add(this->FindComponent("Rectangle" + IntToStr(i)));
	}
    game.restart(difficulty);
	for (int i = 0; i < 25; i++)
	{
		auto color = TAlphaColor(claWhite);
		switch (game.squareColors[i]) {
		case 0:
			color = TAlphaColor(claBlue);
			break;
		case 1:
			color = TAlphaColor(claYellow);
			break;
		case 2:
			color = TAlphaColor(claRed);
			break;
		case 3:
			color = TAlphaColor(claGreen);
			break;
		case 4:
			color = TAlphaColor(claWhite);
			break;
		}
		((TRectangle*)squares->Items[i])->Fill->Color = color;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonGameClick(TObject *Sender)
{
	game.restart(difficulty);
    updateView();
	TabControl->ActiveTab = TabItemGameSetup;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSettingsClick(TObject *Sender)
{
	TabControl->ActiveTab = TabItemSettings;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonBackClick(TObject *Sender)
{
	TabControl->ActiveTab = TabItemMenu;
    Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonInfoClick(TObject *Sender)
{
    ShowMessage("Memory Trainer\nCreated by Alexey Besedin (c) 2020");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCountClick(TObject *Sender)
{
	LabelTask->Text = "Count white squares";
	ButtonEnter->Enabled = true;
	EditAnswer->Enabled = true;
	ButtonMore->Enabled = false;
	ButtonLess->Enabled = false;
	TabControl->ActiveTab = TabItemGame;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonTwoColorsClick(TObject *Sender)
{
	difficulty = 0;
	LabelDifficulty->Text = "Difficulty: " + IntToStr(difficulty + 1) + " / 3";
    TabControl->ActiveTab = TabItemMenu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonThreeColorsClick(TObject *Sender)
{
	difficulty = 1;
	LabelDifficulty->Text = "Difficulty: " + IntToStr(difficulty + 1) + " / 3";
    TabControl->ActiveTab = TabItemMenu;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFourColorsClick(TObject *Sender)
{
	difficulty = 2;
    LabelDifficulty->Text = "Difficulty: " + IntToStr(difficulty + 1) + " / 3";
    TabControl->ActiveTab = TabItemMenu;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonMoreOrLessClick(TObject *Sender)
{
    LabelTask->Text = "Compare blue to yellow";
	ButtonEnter->Enabled = false;
	EditAnswer->Enabled = false;
	ButtonMore->Enabled = true;
	ButtonLess->Enabled = true;
	TabControl->ActiveTab = TabItemGame;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	double currentTime = time - Time().Val;
	LabelTime->Text = FormatDateTime("ss.zz", currentTime);
	if (currentTime <= 0) {
		Timer1->Enabled = false;
		TabControl->ActiveTab = TabItemGameOver;
		LabelResultDifficulty->Text = "Difficulty: " + IntToStr(difficulty + 1);
		LabelResultAttempts->Text = "Levels played: " + IntToStr(attempts + 1);
		LabelResultSuccesses->Text = "Levels won: " + IntToStr(successes);
		attempts = 0;
        successes = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEnterClick(TObject *Sender)
{
	int answer = StrToInt(EditAnswer->Text);
	successes += answer == game.rightAnswer ? 1 : 0;
	attempts += 1;
    LabelScore->Text = "Score: " + IntToStr(successes);
	EditAnswer->Text = "";
    Timer1->Enabled = false;
	updateView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonMoreClick(TObject *Sender)
{
	successes += game.compareState == 0 ? 1 : 0;
	attempts += 1;
	LabelScore->Text = "Score: " + IntToStr(successes);
	EditAnswer->Text = "";
    Timer1->Enabled = false;
	updateView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonLessClick(TObject *Sender)
{
	successes += game.compareState == 2 ? 1 : 0;
	attempts += 1;
	LabelScore->Text = "Score: " + IntToStr(successes);
	EditAnswer->Text = "";
    Timer1->Enabled = false;
	updateView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRestartClick(TObject *Sender)
{
    game.restart(difficulty);
    updateView();
	TabControl->ActiveTab = TabItemGameSetup;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonEqualClick(TObject *Sender)
{
	successes += game.compareState == 1 ? 1 : 0;
	attempts += 1;
	LabelScore->Text = "Score: " + IntToStr(successes);
	EditAnswer->Text = "";
    Timer1->Enabled = false;
	updateView();
}
//---------------------------------------------------------------------------

