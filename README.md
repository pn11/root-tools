# root-tools

Tools using ROOT libraries.

## How to install

Run `make` here to build. Binary file will created in `bin`. Add this `bin` directory in your `$PATH`.

### How to uninstall

Run `make uninstall` will remove all binary files, object files and *~ files.  `make clean` will remove all objects and  *~ files, without removing binaries.

## Programs

### hchain

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

### print_tree

Just print the branches of TTree in the ROOT file.

```
./print_tree example.root
```

### canvas2pdf

Covert all `TCanvas`es in a ROOT file into a PDF file.

```
./canvas2pdf example.root [example.pdf]
```

By default, output PDF name will be like `example.root.pdf`.

#### To do

Should be consider duplication by `cycle`. (See [this](https://root.cern.ch/root/htmldoc/guides/users-guide/InputOutput.html#the-histogram-records).)

### test_myColor

Check program for `myColor.h`. Under developping.

## Headers

Headers are located in `include` directory.

### myColor.h

Define custom color numbering because ROOT's default numbering sucks (How can I see number 5 (yellow)? How can I distinguish number 3 and 8?). Numbering was set Gnuplot-like.  
`int myColor(int icolor)` returns Gnuplot-like-ordered number (up to seven at present).

#### Reference

- [Gnuplot Examples](http://www2.yukawa.kyoto-u.ac.jp/~akira.ohnishi/Lib/gnuplot.html)
	- Color numbering in Gnuplot.
- [ROOT: TColor Class Reference](https://root.cern.ch/doc/master/classTColor.html)
	- Color in ROOT.
