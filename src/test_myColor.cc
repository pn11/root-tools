#include<iostream>
using namespace std;

#include "TCanvas.h"
#include "TApplication.h"
#include "TText.h"
#include "TBox.h"

#include "myColor.h"

int main(int argc, char* argv[]){
  
  TApplication *app = new TApplication("app", &argc, argv);
  
  TCanvas *ctest = new TCanvas("ctest", "ctest");
  ctest->Divide(2, 1);
  ctest->cd(1);
  ctest->DrawColorTable();
  ctest->cd(2);
  
  Int_t i, j;
  Int_t color;
  Double_t xlow, ylow, xup, yup, hs, ws;
  Double_t x1, y1, x2, y2;
  x1 = y1 = 0;
  x2 = y2 = 20;
  
  ctest->cd(2)->SetFillColor(0);
  ctest->cd(2)->Clear();
  ctest->cd(2)->Range(x1,y1,x2,y2);
  TText *text = new TText(0,0,"");
  text->SetTextFont(61);
  text->SetTextSize(0.07);
  text->SetTextAlign(22);
  
  TBox *box = new TBox();
  // Draw color table boxes.
  hs = (y2-y1)/Double_t(5);
  ws = (x2-x1)/Double_t(10);
  for (i=0;i<10;i++) {
    xlow = x1 + ws*(Double_t(i)+0.1);
    xup  = x1 + ws*(Double_t(i)+0.9);
    for (j=0;j<5;j++) {
      ylow = y1 + hs*(Double_t(j)+0.1);
      yup  = y1 + hs*(Double_t(j)+0.9);
      color = 10*j + i;
      box->SetFillStyle(1001);
      cout << color << " " << myColor(color) << endl;
      box->SetFillColor(myColor(color));
      box->DrawBox(xlow, ylow, xup, yup);
      box->SetFillStyle(0);
      box->SetLineColor(1);
      box->DrawBox(xlow, ylow, xup, yup);
      if (myColor(color) == 1) text->SetTextColor(0);
      else            text->SetTextColor(1);
      text->DrawText(0.5*(xlow+xup), 0.5*(ylow+yup), Form("%d",color));
    }

  }
  //  TText *text = new TText(.5, .5, "Hello world");
  //  text->SetTextColor();
  //  text->SetTextSize();
  //  text->Draw();
  
  ctest->Update();
  app->Run();
}

