//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "rezervelist.h"
#include "rezervasyon.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRezerveList *frmRezerveList;
//---------------------------------------------------------------------------
__fastcall TfrmRezerveList::TfrmRezerveList(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmRezerveList::editSORGUChange(TObject *Sender)
{
    queryREZERVELIST->Close();
    queryREZERVELIST->SQL->Clear();
    queryREZERVELIST->SQL->Add("SELECT * FROM REZERVE");

    switch (RadioGroup1->ItemIndex)
    {
        case 0:
            queryREZERVELIST->SQL->Add("WHERE ADI LIKE '%"+editSORGU->Text+"%'");
            queryREZERVELIST->SQL->Add("ORDER BY ADI");
        break;
        case 1:
            queryREZERVELIST->SQL->Add("WHERE SOYADI LIKE '%"+editSORGU->Text+"%'");
            queryREZERVELIST->SQL->Add("ORDER BY SOYADI");
        break;
        case 2:
            queryREZERVELIST->SQL->Add("WHERE SICIL_NO LIKE '%"+editSORGU->Text+"%'");
            queryREZERVELIST->SQL->Add("ORDER BY SICIL_NO");
        break;
    }

    queryREZERVELIST->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfrmRezerveList::RadioGroup1Click(TObject *Sender)
{
    editSORGU->Clear();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmRezerveList::FormShow(TObject *Sender)
{
    queryREZERVELIST->Close();
    queryREZERVELIST->SQL->Clear();
    queryREZERVELIST->SQL->Add("SELECT * FROM REZERVE");

    switch (RadioGroup1->ItemIndex)
    {
        case 0:
            queryREZERVELIST->SQL->Add("WHERE ADI LIKE '%"+editSORGU->Text+"%'");
            queryREZERVELIST->SQL->Add("ORDER BY ADI");
        break;
        case 1:
            queryREZERVELIST->SQL->Add("WHERE SOYADI LIKE '%"+editSORGU->Text+"%'");
            queryREZERVELIST->SQL->Add("ORDER BY SOYADI");
        break;
        case 2:
            queryREZERVELIST->SQL->Add("WHERE SICIL_NO LIKE '%"+editSORGU->Text+"%'");
            queryREZERVELIST->SQL->Add("ORDER BY SICIL_NO");
        break;
    }

    queryREZERVELIST->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRezerveList::DBGrid1CellClick(TColumn *Column)
{
    if (queryREZERVELISTIDREZERVE->Value > 0)
    {
        if (frmResepsiyon->tblREZERVE->Active == true)
            frmResepsiyon->tblREZERVE->Cancel();
        else
            frmResepsiyon->tblREZERVE->Open();

        frmResepsiyon->tblREZERVE->Filtered = true;
        frmResepsiyon->tblREZERVE->Filter = "[IDREZERVE]="+AnsiString(queryREZERVELISTIDREZERVE->Value);

        frmResepsiyon->tblAKRABA->Filtered = true;
        frmResepsiyon->tblAKRABA->Filter = "[IDREZERVE]="+AnsiString(frmResepsiyon->tblREZERVEIDREZERVE->Value);

        frmResepsiyon->datetimeGIRIS->DateTime = queryREZERVELISTGIRIS_TARIHI->Value;
        frmResepsiyon->datetimeDOGUMTARIHI->DateTime = queryREZERVELISTDOGUM_TARIHI->Value;
        frmResepsiyon->datetimeCIKIS->DateTime = queryREZERVELISTCIKIS_TARIHI->Value;

        frmRezerveList->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmRezerveList::DBGrid1KeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;

        if (queryREZERVELISTIDREZERVE->Value > 0)
        {
            if (frmResepsiyon->tblREZERVE->Active == true)
                frmResepsiyon->tblREZERVE->Cancel();
            else
                frmResepsiyon->tblREZERVE->Open();

            frmResepsiyon->tblREZERVE->Filtered = true;
            frmResepsiyon->tblREZERVE->Filter = "[IDREZERVE]="+AnsiString(queryREZERVELISTIDREZERVE->Value);

            frmResepsiyon->tblAKRABA->Filtered = true;
            frmResepsiyon->tblAKRABA->Filter = "[IDREZERVE]="+AnsiString(frmResepsiyon->tblREZERVEIDREZERVE->Value);

            frmResepsiyon->datetimeGIRIS->DateTime = queryREZERVELISTGIRIS_TARIHI->Value;
            frmResepsiyon->datetimeDOGUMTARIHI->DateTime = queryREZERVELISTDOGUM_TARIHI->Value;
            frmResepsiyon->datetimeCIKIS->DateTime = queryREZERVELISTCIKIS_TARIHI->Value;

            frmRezerveList->Close();
        }
    }
}
//---------------------------------------------------------------------------

