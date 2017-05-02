# lucidPID root Makefile v1.0
# This Makefile was made by referring to Peter Miller's paper. 
# Available at http://lcgapp.cern.ch/project/architecture/recursive_make.pdf

CXX := clang++

PROJ_DIR := ..
INC_DIR := $(PROJ_DIR)/include
MODULES := PIDTest
# look for include files in each of the modules
CPPFLAGS += $(patsubst %,-I%, $(MODULES))
CPPFLAGS += -I$(INC_DIR) -std=c++11 -D_GLIBCXX_USE_NANOSLEEP

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

$(MODULES): $(OBJ)
	clang++ -L$(PROJ_DIR)/bin -o lucidTest $(OBJ) -lLucidPID
	mv lucidTest $(PROJ_DIR)/bin/lucidTest
clean:
	rm -r $(OBJ)
# include the C include dependencies
#include $(OBJ:.o=.d)
# calculate C include dependencies
#%.d: %.c
#  depend.sh $(CFLAGS) $< > $@