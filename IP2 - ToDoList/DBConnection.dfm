object DataModuleSQLite: TDataModuleSQLite
  OldCreateOrder = False
  Height = 134
  Width = 197
  object FDConnection: TFDConnection
    Params.Strings = (
      'Database=Y:\alexey-besedin-171-333\IP2 - ToDoList\db.sqlite'
      'DriverID=SQLite')
    LoginPrompt = False
    AfterConnect = FDConnectionAfterConnect
    BeforeConnect = FDConnectionBeforeConnect
    Left = 128
    Top = 8
  end
  object FDTableTasks: TFDTable
    IndexFieldNames = 'id'
    Connection = FDConnection
    UpdateOptions.UpdateTableName = 'Tasks'
    TableName = 'Tasks'
    Left = 40
    Top = 8
    object FDTableTasksid: TFDAutoIncField
      FieldName = 'id'
      Origin = 'id'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object FDTableTasksname: TWideMemoField
      FieldName = 'name'
      Origin = 'name'
      BlobType = ftWideMemo
    end
    object FDTableTasksdone: TIntegerField
      FieldName = 'done'
      Origin = 'done'
      Required = True
    end
  end
  object FDTableSubTasks: TFDTable
    IndexFieldNames = 'id'
    Connection = FDConnection
    UpdateOptions.UpdateTableName = 'SubTasks'
    TableName = 'SubTasks'
    Left = 40
    Top = 64
    object FDTableSubTasksid: TFDAutoIncField
      FieldName = 'id'
      Origin = 'id'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object FDTableSubTasksname: TWideMemoField
      FieldName = 'name'
      Origin = 'name'
      BlobType = ftWideMemo
    end
    object FDTableSubTasksdone: TIntegerField
      FieldName = 'done'
      Origin = 'done'
      Required = True
    end
    object FDTableSubTasksmainId: TIntegerField
      FieldName = 'mainId'
      Origin = 'mainId'
      Required = True
    end
  end
end
