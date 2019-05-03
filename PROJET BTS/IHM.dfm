object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 401
  ClientWidth = 779
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
    Left = 648
    Top = 24
    Width = 96
    Height = 49
    Brush.Color = clRed
    Shape = stCircle
  end
  object Connect_Automate: TButton
    Left = 615
    Top = 79
    Width = 156
    Height = 42
    Caption = 'Se connecter avec l'#39'automate'
    TabOrder = 0
    OnClick = Connect_AutomateClick
  end
  object Sender: TGroupBox
    Left = 48
    Top = 24
    Width = 273
    Height = 153
    Caption = 'Sender'
    TabOrder = 1
    object Launch: TButton
      Left = 40
      Top = 32
      Width = 75
      Height = 25
      Caption = 'Launch'
      TabOrder = 0
      OnClick = LaunchClick
    end
    object Close: TButton
      Left = 176
      Top = 32
      Width = 75
      Height = 25
      Caption = 'Close'
      TabOrder = 1
      OnClick = CloseClick
    end
    object Send_Recette: TButton
      Left = 40
      Top = 104
      Width = 75
      Height = 25
      Caption = 'SendRecette'
      TabOrder = 2
      OnClick = Send_RecetteClick
    end
    object Raz_Bt: TButton
      Left = 176
      Top = 104
      Width = 75
      Height = 25
      Caption = 'R'#233'initialisation'
      TabOrder = 3
      OnClick = Raz_BtClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 48
    Top = 253
    Width = 369
    Height = 132
    Caption = 'Display'
    TabOrder = 2
    object Shape_Etat1: TShape
      Left = 16
      Top = 48
      Width = 65
      Height = 57
      Brush.Color = clRed
      Shape = stCircle
    end
    object Shape_Etat2: TShape
      Left = 112
      Top = 48
      Width = 57
      Height = 57
      Brush.Color = clRed
      Shape = stCircle
    end
    object Shape_Etat3: TShape
      Left = 203
      Top = 48
      Width = 62
      Height = 57
      Brush.Color = clRed
      Shape = stCircle
    end
    object Shape_Etat5: TShape
      Left = 296
      Top = 48
      Width = 57
      Height = 57
      Brush.Color = clRed
      Shape = stCircle
    end
  end
  object InfosClient: TMemo
    Left = 474
    Top = 256
    Width = 289
    Height = 129
    Lines.Strings = (
      'InfosClient')
    TabOrder = 3
  end
  object AcquisitionTmp_Bt: TButton
    Left = 568
    Top = 208
    Width = 115
    Height = 34
    Caption = 'Acquisition Recette'
    TabOrder = 4
    OnClick = AcquisitionTmp_BtClick
  end
end
