//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("simorev1.res");
USEFORM("rezervasyon.cpp", frmResepsiyon);
USEFORM("donem.cpp", frmDonem);
USEFORM("rezervelist.cpp", frmRezerveList);
USEFORM("hakkinda.cpp", frmHakkinda);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TfrmResepsiyon), &frmResepsiyon);
         Application->CreateForm(__classid(TfrmDonem), &frmDonem);
         Application->CreateForm(__classid(TfrmRezerveList), &frmRezerveList);
         Application->CreateForm(__classid(TfrmHakkinda), &frmHakkinda);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
