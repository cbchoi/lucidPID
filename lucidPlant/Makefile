# lucidPID root Makefile v1.0
# This Makefile was made by referring to Peter Miller's paper. 
# Available at http://lcgapp.cern.ch/project/architecture/recursive_make.pdf

CXX := clang++

PROJ_DIR := ..
BIN_DIR := bin
INC_DIR := include
MODULES := lucidPlant
# look for include files in each of the modules
CPPFLAGS += $(patsubst %,-I%, $(MODULES))
CPPFLAGS += -I$(PROJ_DIR)/include -std=c++11 -D_GLIBCXX_USE_NANOSLEEP

# extra libraries if required
LIBS :=
# each module will add to this
SRC := 
# include the description for each module
include $(patsubst %, %/module.mk,$(MODULES))

# determine the object files
OBJ := $(patsubst %.cpp,%.o, $(filter %.cpp,$(SRC))) 

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

libLucidPlant.a: $(OBJ)
	ar -r $@ $(OBJ) 
	mv $@ $(PROJ_DIR)/bin
clean: 
	rm -f $(PROJ_DIR)/$(BIN_DIR)/libLucidPlant.a
	rm $(OBJ)

