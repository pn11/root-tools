CC = g++

# for ROOT
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs)
ROOTGLIBS := $(shell root-config --glibs)

INCLUDE := -Iinclude

TARGETS = print_tree hchain test_myColor

# Suffix
.SUFFIXES: .o .cc
.cc.o:
	$(CC) $(ROOTCFLAGS) $(INCLUDE) -fPIC -c $< -o $@

all: $(TARGETS)

hchain: src/hchain.o
	$(CC) -Wall -O2 $(ROOTCFLAGS) $(ROOTLIBS) -o bin/$@ $^

print_tree: src/print_tree.o
	$(CC) -Wall -O2 $(ROOTCFLAGS) $(ROOTLIBS) -o bin/$@ $^

test_myColor: src/test_myColor.o
	$(CC) -Wall -O2 $(ROOTCFLAGS) $(ROOTLIBS) -o bin/$@ $<

.PHONY: clean check-syntax uninstall

clean:
	rm *~ src/*.o src/*~ include/*~

uninstall:
	rm *~ src/*.o bin/*

check-syntax: # for flymake for emacs
	$(CC) -Wall -Wextra -pedantic -fsyntax-only $(ROOTCFLAGS) $(ROOTLIBS) $(CHK_SOURCES)

