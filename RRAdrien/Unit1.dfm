object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 16
    Top = 8
    Width = 65
    Height = 49
    Shape = stCircle
  end
  object Label1: TLabel
    Left = 256
    Top = 91
    Width = 153
    Height = 13
    Caption = 'Modifier la recette '#224' votre guise'
    Visible = False
  end
  object Button1: TButton
    Left = 48
    Top = 115
    Width = 121
    Height = 33
    Caption = 'R'#233'cup'#233'rer la recette'
    TabOrder = 0
    Visible = False
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 48
    Top = 88
    Width = 145
    Height = 21
    TabOrder = 1
    Visible = False
  end
  object Tableau: TStringGrid
    Left = 160
    Top = 200
    Width = 467
    Height = 57
    ColCount = 6
    FixedCols = 0
    RowCount = 2
    ScrollBars = ssNone
    TabOrder = 2
    Visible = False
    ColWidths = (
      64
      64
      64
      64
      64
      108)
  end
  object Button2: TButton
    Left = 87
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Se Connecter'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 175
    Top = 115
    Width = 122
    Height = 33
    Caption = 'Supprimer la Recette'
    TabOrder = 4
    Visible = False
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 111
    Top = 154
    Width = 138
    Height = 33
    Caption = 'Mettre '#224' Jour la Recette'
    TabOrder = 5
    Visible = False
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 175
    Top = 127
    Width = 57
    Height = 21
    TabOrder = 6
    Visible = False
  end
  object Edit2: TEdit
    Left = 240
    Top = 127
    Width = 57
    Height = 21
    TabOrder = 7
    Visible = False
  end
  object Edit3: TEdit
    Left = 303
    Top = 127
    Width = 57
    Height = 21
    NumbersOnly = True
    TabOrder = 8
    Visible = False
  end
  object Edit4: TEdit
    Left = 375
    Top = 127
    Width = 57
    Height = 21
    NumbersOnly = True
    TabOrder = 9
    Visible = False
  end
  object Edit5: TEdit
    Left = 438
    Top = 127
    Width = 57
    Height = 21
    NumbersOnly = True
    TabOrder = 10
    Visible = False
  end
  object Button5: TButton
    Left = 312
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Mettre '#224' jour'
    TabOrder = 11
    Visible = False
    OnClick = Button5Click
  end
  object Edit6: TEdit
    Left = 528
    Top = 128
    Width = 121
    Height = 21
    TabOrder = 12
    Text = 'Edit6'
    Visible = False
  end
  object Edit7: TEdit
    Left = 528
    Top = 127
    Width = 121
    Height = 21
    TabOrder = 13
    Text = 'Edit7'
    Visible = False
  end
end