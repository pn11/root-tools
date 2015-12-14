#include<iostream>
#include<TList.h>
#include<TFile.h>


int main(int argc, char* argv[]){
  using namespace std;
  
  TFile *f1 = new TFile(argv[1]);
  TList *l1 = f1->GetListOfKeys();
  const Int_t nentry = l1->GetEntries();
  TObject *obj[nentry];
  
  for (int ientry = 0; ientry < nentry; ientry++){
    obj[ientry] = f1->Get(l1->At(ientry)->GetName());
    
    string clstr = obj[ientry]->ClassName();
    //    cout << clstr << endl;
    
    if (clstr == "TTree"){
      //      cout << "TTree: " << obj[ientry]->GetName() <<endl;
      obj[ientry]->Print();
    }
  }
}

