#include<iostream>
using namespace std;

#include<TList.h>
#include<TFile.h>
#include<TCanvas.h>
#include<TString.h>


int main(int argc, char* argv[]){
  string finname = "", foutname = "";
  
  if (argc < 2){
    cerr << "No input ROOT file specified." << endl;
    return -1;
  }
  if (argc > 1){
    finname = argv[1];
    if (argc > 2){
      foutname = argv[2];
    }
    else {
      foutname = finname + ".pdf";
    }
  }
  TFile *f1 = new TFile(finname.c_str());
  if (f1->IsZombie()){
    cerr << finname << " is a zombie." << endl;
    return -1;
  }
  
  TList *l1 = f1->GetListOfKeys();
  const Int_t nentry = l1->GetEntries();
  TObject *obj;
  TCanvas *ctmp;
  TCanvas *cdummy = new TCanvas();
  cdummy->Print(Form("%s[", foutname.c_str()));
  
  for (Int_t ientry = 0; ientry < nentry; ientry++){
    cout << l1->At(ientry)->GetName() << endl;
    //    cout << l1->At(ientry)->GetCycle() << endl;
    obj = (TObject*)f1->Get(l1->At(ientry)->GetName());
    
    string clstr = obj->ClassName();
    //    cout << clstr << endl;
    
    if (clstr == "TCanvas"){
      ctmp = (TCanvas*)obj;
      ctmp->Print(foutname.c_str());
    }
  }

  cdummy->Print(Form("%s]", foutname.c_str()));
  
}

