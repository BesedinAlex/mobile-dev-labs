//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *tbMenu;
	TGridPanelLayout *GridPanelLayout1;
	TLayout *lyMenu;
	TTabControl *tc;
	TTabItem *tiMenu;
	TTabItem *tiCategory;
	TTabItem *tiFeedback;
	TGridLayout *glCategory;
	TToolBar *tbCategory;
	TLabel *Label1;
	TLabel *Label2;
	TButton *buBack;
	TButton *buStore;
	TButton *buBasket;
	TButton *buFeedback;
	TButton *buAbout;
	TToolBar *ToolBar1;
	TScrollBox *ScrollBox1;
	TLabel *Label3;
	TEdit *edFeedbackFIO;
	TLabel *Label4;
	TEdit *edFeedbackPhone;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *edFeedbackEmail;
	TMemo *meFeedbackNote;
	TButton *buSendFeedback;
	TLabel *Label7;
	TButton *Button4;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TScrollBox *ScrollBox2;
	TTabItem *tiProductList;
	TToolBar *ToolBar2;
	TLabel *Label8;
	TButton *Button1;
	TListView *lvProduct;
	TBindSourceDB *BindSourceDB2;
	TLinkListControlToField *LinkListControlToField1;
	TTabItem *tiProduct;
	TToolBar *ToolBar3;
	TLabel *Label9;
	TButton *Button2;
	TImage *imProductImage;
	TLabel *laProductName;
	TLabel *laProductPrice;
	TBindSourceDB *BindSourceDB3;
	TLayout *Layout1;
	TGridPanelLayout *GridPanelLayout2;
	TButton *Button3;
	TButton *Button5;
	TLinkPropertyToField *LinkPropertyToFieldBitmap;
	TLinkPropertyToField *LinkPropertyToFieldText3;
	TMemo *meProductNote;
	TLinkControlToField *LinkControlToField1;
	TLinkPropertyToField *LinkPropertyToFieldText;
	void __fastcall buFeedbackClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buBackAllClick(TObject *Sender);
	void __fastcall buStoreClick(TObject *Sender);
	void __fastcall buSendFeedbackClick(TObject *Sender);
	void __fastcall CategoryCellOnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall glCategoryResize(TObject *Sender);
	void __fastcall buBackToCategoryClick(TObject *Sender);
	void __fastcall lvProductItemClick(TObject * const Sender, TListViewItem * const AItem);
	void __fastcall buProdClick(TObject *Sender);
	void __fastcall buBackTOProductListClick(TObject *Sender);

private:	// User declarations
	void ReloadCategoryList();
    int x;
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
