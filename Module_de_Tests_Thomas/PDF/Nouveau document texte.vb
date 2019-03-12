Sub NewCanvasPicture() 
 Dim shpCanvas As Shape 
 
 'Add a drawing canvas to the active document 
 Set shpCanvas = ActiveDocument.Shapes _ 
 .AddCanvas(Left:=100, Top:=75, _ 
 Width:=200, Height:=300) 
 
 'Add a graphic to the drawing canvas 
 shpCanvas.CanvasItems.AddPicture _ 
 FileName:="C:\Program Files\Microsoft Office\" & _ 
 "Office\Bitmaps\Styles\stone.bmp", _ 
 LinkToFile:=False, SaveWithDocument:=True 
End Sub