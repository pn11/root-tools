# root-tools
Tools using ROOT libraries.

##How to install
Run `make` here to build. Binary file will created in `bin`. Add this `bin` directory in your `$PATH`.

###How to uninstall
Run `make clean` will remove all the binary files.

##Programs
###hchain
Make TChain of TTree in multiple ROOT files just like `hadd`.

```
./hchain treename out.root in1.root in2.root...
```

If you have TTree named "tree" in ROOT files with name of input*.root and your output name is output.root, you will run like this:

```
./hchain tree output.root input*.root
```

If option `-f` applied, `output.root` will be overwritten.

```
./hchain -f tree output.root input*.root
```

Input file names shoud be specified with absolute path so that output file can be used in any directory.

###print_tree
Just print the branches of TTree in the ROOT file.

```
./print_tree example.root
```

