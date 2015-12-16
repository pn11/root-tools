#ifndef MYCOLOR_H
#define MYCOLOR_H

int myColor(int icolor){
  const int ncolor = 10;
  if (icolor < ncolor){
    return 0;
  }
  
  int myColor[ncolor] = {
    0, // 0
    1, // 1
  };
  


  return myColor[icolor];
}

#endif
