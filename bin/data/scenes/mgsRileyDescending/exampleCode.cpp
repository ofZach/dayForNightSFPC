setSpeed([[Speed]]);
setFillColor(255); // 255 is for white
setBackground(0); // 0 is for black
setDepth([[Depth Amount]]);
setColumnWidth([[Column Width]]);
setRowHeight([[Row Height]]);

void drawKinkedLines(){
  // Loop through the width and height of the grid
  for(int column = 0; i < numOfColumns; column += [[Column Width]]){
      for(int row = 0; i < numOfRows; row += [[Row Height]]){
        drawKinkedRileyLine(column,
                            row,
                            x*[[Column Width]]*[[Columns]],
                            y*[[Rows]]*[[Row Height]]);
      }
  }
}