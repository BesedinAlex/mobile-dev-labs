object DataModuleSQLite: TDataModuleSQLite
  OldCreateOrder = False
  Height = 62
  Width = 197
  object FDConnection: TFDConnection
    Params.Strings = (
      'Database=Y:\alexey-besedin-171-333\IP2 - ToDoList\db.sqlite'
      'DriverID=SQLite')
    LoginPrompt = False
    BeforeConnect = FDConnectionBeforeConnect
    Left = 128
    Top = 8
  end
  object FDQueryTasks: TFDQuery
    Connection = FDConnection
    SQL.Strings = (
      '')
    Left = 32
    Top = 8
    object FDQueryTasksid: TFDAutoIncField
      FieldName = 'id'
      Origin = 'id'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object FDQueryTasksname: TWideMemoField
      FieldName = 'name'
      Origin = 'name'
      BlobType = ftWideMemo
    end
    object FDQueryTasksdone: TIntegerField
      FieldName = 'done'
      Origin = 'done'
      Required = True
    end
    object FDQueryTasksmainTaskId: TIntegerField
      FieldName = 'mainTaskId'
      Origin = 'mainTaskId'
    end
  end
end
