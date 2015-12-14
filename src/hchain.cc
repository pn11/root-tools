#include<iostream>
using namespace std;

#include<TFile.h>
#include<TChain.h>

int main(int argc, char* argv[]){


  if (argc < 4){
    cerr << "Usage: hchain treename chain.root input1.root input2.root" << endl;
    return -1;
  }

  //  string treename = argv[1];
  
  TFile *fchain = new TFile(argv[2], "create");
  if (!fchain){
    cerr << "Error! " << argv[2] << "exists." << endl;
    return -1;
  }

  TChain *inchain = new TChain(argv[1]);
  for (int ifile = 3; ifile < argc; ifile++){
    inchain->Add(argv[ifile]);
  }

  fchain->cd();
  inchain->Write();
  fchain->Close();

}

