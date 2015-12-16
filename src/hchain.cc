#include<iostream>
using namespace std;

#include "getopt.h"

#include<TFile.h>
#include<TChain.h>

int main(int argc, char* argv[]){

  // get options
  int result = 0;
  bool overwrite = false;
  
  while ( (result = getopt(argc, argv, "f")) != -1){
    switch (result){
    case 'f':
      overwrite = true;
    }
  }


  // get arguments

  if (argc - optind < 3){
    cerr << "Usage: hchain treename chain.root input1.root input2.root" << endl;
    return -1;
  }

  char *treename = argv[optind];
  char *fchainname = argv[optind+1];
  
  TFile *fchain;
  if (overwrite){
    fchain = new TFile(fchainname, "recreate");
  }
  else if (!overwrite){
    fchain = new TFile(fchainname, "create");
    if (!fchain){
      cerr << "Error! " << argv[2] << "exists. Please run with \"-f\" if you want to overwrite." << endl;
      return -1;
    }
  }
  
  TChain *inchain = new TChain(treename);
  for (int ifile = optind+2; ifile < argc; ifile++){
    inchain->Add(argv[ifile]);
  }

  fchain->cd();
  inchain->Write();
  fchain->Close();

}

