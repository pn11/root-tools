#include<iostream>
using namespace std;

#include "TCanvas.h"
#include "TApplication.h"
#include "TText.h"

#include "myColor.h"

int main(int argc, char* argv[]){

  TApplication *app = new TApplication("app", &argc, argv);
  
  TCanvas *ctest = new TCanvas("ctest", "ctest");
  ctest->Divide(2, 1);
  ctest->cd(1);
  ctest->DrawColorTable();
  ctest->cd(2);

  TText *text = new TText(.5, .5, "Hello world");
  text->SetTextColor();
  text->SetTextSize();
  text->Draw();
  
  app->Run();
}

