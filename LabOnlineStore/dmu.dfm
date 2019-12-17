object dm: Tdm
  OldCreateOrder = False
  Height = 466
  Width = 669
  object FDConnection1: TFDConnection
    Params.Strings = (
      
        'Database=C:\Users\VD\Desktop\'#1053#1086#1074#1072#1103' '#1087#1072#1087#1082#1072'\labOnlineStore\ONLINEST' +
        'ORE.FDB'
      'User_Name=SYSDBA'
      'Password=masterkey'
      'CharacterSet=UTF8'
      'DriverID=FB')
    Connected = True
    LoginPrompt = False
    Left = 552
    Top = 128
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'FMX'
    Left = 552
    Top = 256
  end
  object FDPhysFBDriverLink1: TFDPhysFBDriverLink
    Left = 552
    Top = 192
  end
  object spFeedbackIns: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'FEEDBACK_INS'
    Left = 264
    Top = 344
    ParamData = <
      item
        Position = 1
        Name = 'FIO'
        DataType = ftWideString
        ParamType = ptInput
        Size = 70
      end
      item
        Position = 2
        Name = 'PHONE'
        DataType = ftWideString
        ParamType = ptInput
        Size = 15
      end
      item
        Position = 3
        Name = 'EMAIL'
        DataType = ftWideString
        ParamType = ptInput
        Size = 70
      end
      item
        Position = 4
        Name = 'NOTE'
        DataType = ftWideString
        ParamType = ptInput
        Size = 4000
      end>
  end
  object quCategory: TFDQuery
    Active = True
    AfterScroll = quCategoryAfterScroll
    Connection = FDConnection1
    SQL.Strings = (
      'select '
      '    category.id,'
      '    category.name,'
      '    category.image'
      'from category'
      'order by category.id, category.name')
    Left = 320
    Top = 216
    object quCategoryID: TIntegerField
      FieldName = 'ID'
      Origin = 'ID'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object quCategoryNAME: TWideStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Required = True
      Size = 70
    end
    object quCategoryIMAGE: TBlobField
      FieldName = 'IMAGE'
      Origin = 'IMAGE'
    end
  end
  object quProduct: TFDQuery
    Active = True
    Filtered = True
    Connection = FDConnection1
    SQL.Strings = (
      'select '
      '    p.id,'
      '    p.category_id,'
      '    p.name,'
      '    p.price,'
      '    p.note,'
      '    p.image'
      'from product p'
      'order by p.name')
    Left = 192
    Top = 224
    object quProductID: TIntegerField
      FieldName = 'ID'
      Origin = 'ID'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object quProductCATEGORY_ID: TIntegerField
      FieldName = 'CATEGORY_ID'
      Origin = 'CATEGORY_ID'
      Required = True
    end
    object quProductNAME: TWideStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Required = True
      Size = 70
    end
    object quProductPRICE: TFloatField
      FieldName = 'PRICE'
      Origin = 'PRICE'
      Required = True
    end
    object quProductNOTE: TWideStringField
      FieldName = 'NOTE'
      Origin = 'NOTE'
      Size = 4000
    end
    object quProductIMAGE: TBlobField
      FieldName = 'IMAGE'
      Origin = 'IMAGE'
    end
  end
end
