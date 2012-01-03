//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "donem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDonem *frmDonem;
//---------------------------------------------------------------------------
__fastcall TfrmDonem::TfrmDonem(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDonem::FormShow(TObject *Sender)
{
    tblDONEM->Open();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDonem::FormClose(TObject *Sender, TCloseAction &Action)
{
    tblDONEM->Close();    
}
//---------------------------------------------------------------------------
