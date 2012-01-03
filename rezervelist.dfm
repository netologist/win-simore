object frmRezerveList: TfrmRezerveList
  Left = 266
  Top = 105
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Rezervasyon Listesi'
  ClientHeight = 216
  ClientWidth = 483
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 0
    Top = -3
    Width = 481
    Height = 31
    Columns = 3
    ItemIndex = 0
    Items.Strings = (
      'Ada Göre'
      'Soyada Göre'
      'Sicil Nosuna Göre')
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object editSORGU: TEdit
    Left = 2
    Top = 30
    Width = 479
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 1
    OnChange = editSORGUChange
  end
  object DBGrid1: TDBGrid
    Left = 2
    Top = 54
    Width = 479
    Height = 160
    DataSource = dsrcREZERVELIST
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    OnKeyPress = DBGrid1KeyPress
    Columns = <
      item
        Expanded = False
        FieldName = 'DONEM'
        Title.Alignment = taCenter
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SICIL_NO'
        Title.Alignment = taCenter
        Title.Caption = 'SÝCÝL NO'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ADI'
        Title.Alignment = taCenter
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SOYADI'
        Title.Alignment = taCenter
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'RUTBESI'
        Title.Alignment = taCenter
        Width = 90
        Visible = True
      end>
  end
  object queryREZERVELIST: TQuery
    DatabaseName = 'SIMORE'
    SQL.Strings = (
      'select * from rezerve')
    Left = 30
    Top = 174
    object queryREZERVELISTDONEM: TStringField
      FieldName = 'DONEM'
      Origin = 'SIMORE."rezerve.DB".DONEM'
      Size = 30
    end
    object queryREZERVELISTSIRA_NO: TFloatField
      FieldName = 'SIRA_NO'
      Origin = 'SIMORE."rezerve.DB".SIRA_NO'
    end
    object queryREZERVELISTEMEKLILIK: TStringField
      FieldName = 'EMEKLILIK'
      Origin = 'SIMORE."rezerve.DB".EMEKLILIK'
    end
    object queryREZERVELISTKUVVETI: TStringField
      FieldName = 'KUVVETI'
      Origin = 'SIMORE."rezerve.DB".KUVVETI'
      Size = 30
    end
    object queryREZERVELISTRUTBESI: TStringField
      FieldName = 'RUTBESI'
      Origin = 'SIMORE."rezerve.DB".RUTBESI'
      Size = 30
    end
    object queryREZERVELISTPBIK_NO: TStringField
      FieldName = 'PBIK_NO'
      Origin = 'SIMORE."rezerve.DB".PBIK_NO'
      Size = 30
    end
    object queryREZERVELISTSICIL_NO: TStringField
      FieldName = 'SICIL_NO'
      Origin = 'SIMORE."rezerve.DB".SICIL_NO'
      Size = 30
    end
    object queryREZERVELISTADI: TStringField
      FieldName = 'ADI'
      Origin = 'SIMORE."rezerve.DB".ADI'
      Size = 30
    end
    object queryREZERVELISTSOYADI: TStringField
      FieldName = 'SOYADI'
      Origin = 'SIMORE."rezerve.DB".SOYADI'
      Size = 30
    end
    object queryREZERVELISTPLAKA: TStringField
      FieldName = 'PLAKA'
      Origin = 'SIMORE."rezerve.DB".PLAKA'
    end
    object queryREZERVELISTDOGUM_TARIHI: TDateField
      FieldName = 'DOGUM_TARIHI'
      Origin = 'SIMORE."rezerve.DB".DOGUM_TARIHI'
    end
    object queryREZERVELISTADRES: TMemoField
      FieldName = 'ADRES'
      Origin = 'SIMORE."rezerve.DB".ADRES'
      BlobType = ftMemo
      Size = 1
    end
    object queryREZERVELISTTAHSIS_CESIDI: TStringField
      FieldName = 'TAHSIS_CESIDI'
      Origin = 'SIMORE."rezerve.DB".TAHSIS_CESIDI'
      Size = 30
    end
    object queryREZERVELISTMOTEL: TStringField
      FieldName = 'MOTEL'
      Origin = 'SIMORE."rezerve.DB".MOTEL'
      Size = 5
    end
    object queryREZERVELISTBLOK: TStringField
      FieldName = 'BLOK'
      Origin = 'SIMORE."rezerve.DB".BLOK'
      Size = 5
    end
    object queryREZERVELISTODA_NO: TFloatField
      FieldName = 'ODA_NO'
      Origin = 'SIMORE."rezerve.DB".ODA_NO'
    end
    object queryREZERVELISTGIRIS_TARIHI: TDateField
      FieldName = 'GIRIS_TARIHI'
      Origin = 'SIMORE."rezerve.DB".GIRIS_TARIHI'
    end
    object queryREZERVELISTCIKIS_TARIHI: TDateField
      FieldName = 'CIKIS_TARIHI'
      Origin = 'SIMORE."rezerve.DB".CIKIS_TARIHI'
    end
    object queryREZERVELISTMOTEL_UCRETI: TFloatField
      FieldName = 'MOTEL_UCRETI'
      Origin = 'SIMORE."rezerve.DB".MOTEL_UCRETI'
    end
    object queryREZERVELISTILAVE_YATAK: TFloatField
      FieldName = 'ILAVE_YATAK'
      Origin = 'SIMORE."rezerve.DB".ILAVE_YATAK'
    end
    object queryREZERVELISTIDREZERVE: TFloatField
      FieldName = 'IDREZERVE'
      Origin = 'SIMORE."rezerve.DB".IDREZERVE'
    end
  end
  object dsrcREZERVELIST: TDataSource
    DataSet = queryREZERVELIST
    Left = 27
    Top = 135
  end
end
