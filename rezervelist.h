//---------------------------------------------------------------------------

#ifndef rezervelistH
#define rezervelistH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TfrmRezerveList : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *RadioGroup1;
    TEdit *editSORGU;
    TDBGrid *DBGrid1;
    TQuery *queryREZERVELIST;
    TDataSource *dsrcREZERVELIST;
    TStringField *queryREZERVELISTDONEM;
    TFloatField *queryREZERVELISTSIRA_NO;
    TStringField *queryREZERVELISTEMEKLILIK;
    TStringField *queryREZERVELISTKUVVETI;
    TStringField *queryREZERVELISTRUTBESI;
    TStringField *queryREZERVELISTPBIK_NO;
    TStringField *queryREZERVELISTSICIL_NO;
    TStringField *queryREZERVELISTADI;
    TStringField *queryREZERVELISTSOYADI;
    TStringField *queryREZERVELISTPLAKA;
    TDateField *queryREZERVELISTDOGUM_TARIHI;
    TMemoField *queryREZERVELISTADRES;
    TStringField *queryREZERVELISTTAHSIS_CESIDI;
    TStringField *queryREZERVELISTMOTEL;
    TStringField *queryREZERVELISTBLOK;
    TFloatField *queryREZERVELISTODA_NO;
    TDateField *queryREZERVELISTGIRIS_TARIHI;
    TDateField *queryREZERVELISTCIKIS_TARIHI;
    TFloatField *queryREZERVELISTMOTEL_UCRETI;
    TFloatField *queryREZERVELISTILAVE_YATAK;
    TFloatField *queryREZERVELISTIDREZERVE;
    void __fastcall editSORGUChange(TObject *Sender);
    void __fastcall RadioGroup1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall DBGrid1CellClick(TColumn *Column);
    void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmRezerveList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRezerveList *frmRezerveList;
//---------------------------------------------------------------------------
#endif
