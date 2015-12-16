#ifndef MYCOLOR_H
#define MYCOLOR_H

int myColor(int icolor){
  const int ncolor = 10;
  if (icolor > ncolor){
    return icolor;
  }
  
  int myColor[ncolor] = {
    1, // 0 for black
    2, // 1 for red
    3, // 2 for green 
    4, // 3 for blue
    6, // 4 for magenta
    7, // 5 for lightblue
    800, // 6 for orange
    420, // 7 for dark green
  };
  
  return myColor[icolor];
}

#endif
