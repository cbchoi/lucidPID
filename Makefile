# lucidPID root Makefile v1.0
# This Makefile was made by referring to Peter Miller's paper. 
# Available at http://lcgapp.cern.ch/project/architecture/recursive_make.pdf

CXX := clang++

PROJ_DIR := .
PROJ_LIST := lucidPID lucidPlant example

all: 
	@for proj in $(PROJ_LIST) ; do \
		make -C $$proj ; \
	done

clean: 
	@for proj in $(PROJ_LIST) ; do \
		make -C $$proj clean; \
	done