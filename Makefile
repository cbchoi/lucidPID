# lucidPID root Makefile v1.0
# This Makefile was made by referring to Peter Miller's paper. 
# Available at http://lcgapp.cern.ch/project/architecture/recursive_make.pdf

CXX := clang++

PROJ_DIR := .
BIN_DIR := bin
INC_DIR := include
MODULES := libLucidPID
# look for include files in each of the modules
CPPFLAGS += $(patsubst %,-I%, $(MODULES))
CPPFLAGS += -Iinclude -std=c++11 -D_GLIBCXX_USE_NANOSLEEP

# extra libraries if required
LIBS :=
# each module will add to this
SRC := 
# include the description for
#   each module
include $(patsubst %, %/module.mk,$(MODULES))

# determine the object files
OBJ := $(patsubst %.cpp,%.o, $(filter %.cpp,$(SRC))) 
#  $(patsubst %.y,%.o,     \
#    $(filter %.y,$(SRC)))
# link the program

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

libLucidPID.a: $(OBJ)
	ar -r $@ $(OBJ) 
	mv $@ ./bin
	make -C example

clean: 
	rm $(PROJ_DIR)/$(BIN_DIR)/libLucidPID.a
	rm $(OBJ)
	make -C example clean
# include the C include dependencies
#include $(OBJ:.o=.d)
# calculate C include dependencies
#%.d: %.c
#  depend.sh $(CFLAGS) $< > $@