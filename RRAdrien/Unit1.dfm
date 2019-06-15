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
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 16
    Top = 8
    Width = 65
    Height = 49
    Shape = stCircle
  end
  object Button1: TButton
    Left = 144
    Top = 56
    Width = 121
    Height = 33
    Caption = 'R'#233'cup'#233'rer la recette'
    TabOrder = 0
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 136
    Top = 16
    Width = 145
    Height = 21
    TabOrder = 1
    Text = 'ComboBox1'
  end
end
