//---------------------------------------------------------------------------

#ifndef donemH
#define donemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfrmDonem : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TDBNavigator *DBNavigator1;
    TDBGrid *DBGrid1;
    TDataSource *dsrcDONEM;
    TTable *tblDONEM;
    TStringField *tblDONEMDONEM_ADI;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmDonem(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDonem *frmDonem;
//---------------------------------------------------------------------------
#endif
