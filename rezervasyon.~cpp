//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "rezervasyon.h"
#include "hakkinda.h"
#include "rezervelist.h"
#include "donem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmResepsiyon *frmResepsiyon;
//---------------------------------------------------------------------------
__fastcall TfrmResepsiyon::TfrmResepsiyon(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmResepsiyon::Yeni1Click(TObject *Sender)
{
    datetimeGIRIS->DateTime = datetimeGIRIS->DateTime.CurrentDate();
    datetimeCIKIS->DateTime = datetimeCIKIS->DateTime.CurrentDate();

    tblREZERVE->Open();
    tblREZERVE->Filtered = false;
    tblREZERVE->Insert();

    dbcomboEMKLILIK->ItemIndex = 0;
    dbcomboKUVVET->ItemIndex = 0;
    dbcomboTAHSIS->ItemIndex = 0;

    tblREZERVE->Edit();
    tblREZERVEEMEKLILIK->Value = dbcomboEMKLILIK->Text;
    tblREZERVE->Edit();
    tblREZERVEKUVVETI->Value = dbcomboKUVVET->Text;
    tblREZERVE->Edit();
    tblREZERVETAHSIS_CESIDI->Value = dbcomboTAHSIS->Text;
    tblREZERVE->Edit();
    tblREZERVEDONEM->Value = comboDONEM->Text;

    tblREZERVE->Edit();
    tblREZERVEGIRIS_TARIHI->Value = datetimeGIRIS->DateTime;
    tblREZERVE->Edit();
    tblREZERVECIKIS_TARIHI->Value = datetimeCIKIS->DateTime;
    tblREZERVE->Edit();
    tblREZERVEDOGUM_TARIHI->Value = datetimeDOGUMTARIHI->DateTime;

    queryKAYIT_NO->Close();
    queryKAYIT_NO->Open();
    tblREZERVE->Edit();
    tblREZERVEIDREZERVE->Value = queryKAYIT_NOIDREZERVE->Value + 1;
    queryKAYIT_NO->Close();

    tblAKRABA->Filtered = true;
    tblAKRABA->Filter = "[IDREZERVE]="+AnsiString(tblREZERVEIDREZERVE->Value);
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::Kaydet1Click(TObject *Sender)
{
    if (dbeditSICILNO->Text.Length() <= 0)
        Application->MessageBoxA("Sicil Numarasýný girilmeden kayýt yapýlamaz", "Uyarý", MB_OK | MB_ICONEXCLAMATION);
    else if (dbeditADI->Text.Length() <= 0)
        Application->MessageBoxA("Kamp sakinin ADI girilmeden kayýt yapýlamaz", "Uyarý", MB_OK | MB_ICONEXCLAMATION);
    else if (dbeditSOYADI->Text.Length() <= 0)
        Application->MessageBoxA("Kamp sakinin SOYADI girilmeden kayýt yapýlamaz", "Uyarý", MB_OK | MB_ICONEXCLAMATION);
    else
    {
        tblREZERVE->Edit();
        tblREZERVE->Post();

        if (tblAKRABA->Modified == true)
        {
            tblAKRABA->Edit();
            tblAKRABA->Post();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::FormShow(TObject *Sender)
{
    comboDONEM->Clear();

    frmDonem->tblDONEM->Open();
    frmDonem->tblDONEM->First();
    while (!frmDonem->tblDONEM->Eof)
    {
        comboDONEM->Items->Add(frmDonem->tblDONEMDONEM_ADI->Value);
        frmDonem->tblDONEM->Next();
    }
    comboDONEM->ItemIndex = 0;
    frmDonem->tblDONEM->Close();

    datetimeDOGUMTARIHI->DateTime = datetimeDOGUMTARIHI->DateTime.CurrentDate();
    datetimeGIRIS->DateTime = datetimeGIRIS->DateTime.CurrentDate();
    datetimeCIKIS->DateTime = datetimeCIKIS->DateTime.CurrentDate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::datetimeDOGUMTARIHIChange(TObject *Sender)
{
    tblREZERVE->Edit();
    tblREZERVEDOGUM_TARIHI->Value = datetimeDOGUMTARIHI->DateTime;
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::datetimeGIRISChange(TObject *Sender)
{
    tblREZERVE->Edit();
    tblREZERVEGIRIS_TARIHI->Value = datetimeGIRIS->DateTime;
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::datetimeCIKISChange(TObject *Sender)
{
    if (tblREZERVE->Active == true)
    {
        tblREZERVE->Edit();
        tblREZERVECIKIS_TARIHI->Value = datetimeCIKIS->DateTime;

        if (datetimeCIKIS->DateTime != datetimeGIRIS->DateTime)
        {
            tblAKRABA->First();
            while (!tblAKRABA->Eof)
            {
                tblAKRABA->Edit();
                tblAKRABAKAMP_CIKISI->Value = false;
                tblAKRABA->Post();
                tblAKRABA->Next();
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::Timer1Timer(TObject *Sender)
{
    tblAKRABA->Active = tblREZERVE->Active;

    dbeditSIRANO->Enabled = tblREZERVE->Active;
    dbcomboEMKLILIK->Enabled = tblREZERVE->Active;
    dbcomboKUVVET->Enabled = tblREZERVE->Active;
    dbeditRUTBE->Enabled = tblREZERVE->Active;
    dbeditPBIKNO->Enabled = tblREZERVE->Active;
    dbeditSICILNO->Enabled = tblREZERVE->Active;
    dbeditADI->Enabled = tblREZERVE->Active;
    dbeditSOYADI->Enabled = tblREZERVE->Active;
    dbeditPLAKA->Enabled = tblREZERVE->Active;
    datetimeDOGUMTARIHI->Enabled = tblREZERVE->Active;
    dbmemoADRES->Enabled = tblREZERVE->Active;
    dbcomboTAHSIS->Enabled = tblREZERVE->Active;
    dbcomboMOTEL->Enabled = tblREZERVE->Active;
    dbcomboBLOK->Enabled = tblREZERVE->Active;
    dbeditODANO->Enabled = tblREZERVE->Active;
    datetimeGIRIS->Enabled = tblREZERVE->Active;
    datetimeCIKIS->Enabled = tblREZERVE->Active;
    dbeditMOTELUCRETI->Enabled = tblREZERVE->Active;
    dbeditILAVEYATAK->Enabled = tblREZERVE->Active;
    dbmemoADRES->Enabled = tblREZERVE->Active;

    queryKAMPICI_ODA->Close();
    queryKAMPICI_ODA->ParamByName("DONEM")->AsString = comboDONEM->Text;
    queryKAMPICI_ODA->Open();
    queryKAMPICI_PERSONEL->Close();
    queryKAMPICI_PERSONEL->ParamByName("DONEM")->AsString = comboDONEM->Text;
    queryKAMPICI_PERSONEL->Open();
    StatusBar1->Panels->Items[1]->Text = AnsiString(queryKAMPICI_ODATOPLAM->Value) + " / " + AnsiString(queryKAMPICI_PERSONELTOPLAM->Value+queryKAMPICI_ODATOPLAM->Value);

    queryKAMPDISI_ODA->Close();
    queryKAMPDISI_ODA->ParamByName("DONEM")->AsString = comboDONEM->Text;
    queryKAMPDISI_ODA->Open();
    queryKAMPDISI_PERSONEL->Close();
    queryKAMPDISI_PERSONEL->ParamByName("DONEM")->AsString = comboDONEM->Text;
    queryKAMPDISI_PERSONEL->Open();
    StatusBar1->Panels->Items[3]->Text = AnsiString(queryKAMPDISI_ODATOPLAM->Value) + " / " + AnsiString(queryKAMPDISI_PERSONELTOPLAM->Value+queryKAMPDISI_ODATOPLAM->Value);
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    tblREZERVE->Close();
    
    queryKAMPICI_ODA->Close();
    queryKAMPICI_PERSONEL->Close();
    queryKAMPDISI_ODA->Close();
    queryKAMPDISI_PERSONEL->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::ToolButton8Click(TObject *Sender)
{
    Timer1->Enabled = false;
    frmDonem->Show();
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::A1Click(TObject *Sender)
{
    frmRezerveList->Show();
}
//---------------------------------------------------------------------------



void __fastcall TfrmResepsiyon::tblAKRABAAfterInsert(TDataSet *DataSet)
{
    tblAKRABA->Edit();
    tblAKRABADONEM->Value = comboDONEM->Text;

    tblAKRABA->Edit();
    tblAKRABAIDREZERVE->Value = tblREZERVEIDREZERVE->Value;

    if (datetimeCIKIS->DateTime != datetimeGIRIS->DateTime) {
        tblAKRABA->Edit();
        tblAKRABAKAMP_CIKISI->Value = false;
    }
    else {
        tblAKRABA->Edit();
        tblAKRABAKAMP_CIKISI->Value = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboEMKLILIKChange(TObject *Sender)
{
    tblREZERVE->Edit();
    tblREZERVEEMEKLILIK->Value = dbcomboEMKLILIK->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboKUVVETChange(TObject *Sender)
{
    tblREZERVE->Edit();
    tblREZERVEKUVVETI->Value = dbcomboKUVVET->Text;
}
//---------------------------------------------------------------------------


void __fastcall TfrmResepsiyon::comboDONEMChange(TObject *Sender)
{
    tblREZERVE->Cancel();
    tblREZERVE->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditSIRANOKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboEMKLILIKKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboKUVVETKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditRUTBEKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditPBIKNOKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditSICILNOKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditADIKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditSOYADIKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditPLAKAKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::datetimeDOGUMTARIHIKeyPress(
      TObject *Sender, char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboTAHSISKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboMOTELKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbcomboBLOKKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditODANOKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::datetimeGIRISKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::datetimeCIKISKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditMOTELUCRETIKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::dbeditILAVEYATAKKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;
        PostMessage(Handle, WM_NEXTDLGCTL, 0, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::Sil1Click(TObject *Sender)
{
    int nDeger;

    nDeger = Application->MessageBox("Kaydý silmek istediðinize emin misiniz?", "Silme onayý",
        MB_YESNO + MB_ICONQUESTION);

    if (nDeger == IDYES) {
        tblAKRABA->First();
        while (!tblAKRABA->Eof)
            tblAKRABA->Delete();

        tblREZERVE->Delete();
    }
}
//---------------------------------------------------------------------------



void __fastcall TfrmResepsiyon::erik1Click(TObject *Sender)
{
    frmHakkinda->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmResepsiyon::DBGrid1KeyPress(TObject *Sender, char &Key)
{
    if (Key == Char(VK_RETURN)) {
        Key = 0;

        if (DBGrid1->SelectedIndex < DBGrid1->FieldCount-1)
            ++DBGrid1->SelectedIndex;
        else {
            DBGrid1->SelectedIndex = 0;
            // Kayýt ediliyor....
            Kaydet1Click(Sender);
        }
    }
}
//---------------------------------------------------------------------------

