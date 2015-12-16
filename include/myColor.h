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
    
  };
  
  return myColor[icolor];
}

#endif
