CC = g++

# for ROOT
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs)
ROOTGLIBS := $(shell root-config --glibs)

TARGETS = print_tree 

# Suffix
.SUFFIXES: .o .cc
.cc.o:
	$(CC) $(ROOTCFLAGS) -fPIC -c $< -o $@

all: $(TARGETS)

print_tree: src/print_tree.o
	$(CC) -Wall -O2 $(ROOTCFLAGS) $(ROOTLIBS) -o bin/$@ $^

.PHONY: clean check-syntax

clean:
	rm *~ src/*.o bin/*

check-syntax: # for flymake for emacs
	$(CC) -Wall -Wextra -pedantic -fsyntax-only $(ROOTCFLAGS) $(ROOTLIBS) $(CHK_SOURCES)

