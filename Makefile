#------------------------------------------------------------------------------#
# Copyright David Gil 1998-TODO                                                #
# 								                                               #
# davidgil@dgadv.com 			                                               #
#------------------------------------------------------------------------------#

#--------------------------------------------------------------------------------
# project set-up
PROJECT_PATH=$(CWD)
COMMON_INCLUDES_PATHS=-I/usr/local/include/dgl -I$(PROJECT_PATH)/../dglWrapperOpenGl/lib/dglRenderWrapper/include
COMMON_INCLUDES=
CC=gcc
CFLAGS=-Wall -c 
LDFLAGS=-Wall 

#--------------------------------------------------------------------------------
# project components
include ./lib/dglGauges.mk
include ./application/carSimulator/carSimulator.mk

#--------------------------------------------------------------------------------
# includes and objects 
MAIN_INCLUDES_PATHS=$(sort 	$(COMMON_INCLUDES_PATHS) \
							$(CARSIMULATOR_COMPONENT_INCLUDES_PATHS))
							
MAIN_INCLUDES=		$(sort 	$(COMMON_INCLUDES) \
							Makefile \
							$(CARSIMULATOR_COMPONENT_INCLUDES))

MAIN_OBJECTS=		$(DGLGAUGES_OBJECTS) \
					$(CARSIMULATOR_COMPONENT_OBJ) \

MAIN_OUTPUT_FOLDERS =  	$(DGLGAUGES_OUTPUT_FOLDERS) \
						$(CARSIMULATOR_COMPONENT_OUTPUT_FOLDER) \

#--------------------------------------------------------------------------------
# no need to change anything below this line

#--------------------------------------------------------------------------------
# main component
MAIN_OBJ_NAME=main
MAIN_OBJ_PATH=$(PROJECT_PATH)

#------------------------------------------------------------------------------#	
# no need to change anything below this line
MAIN_SRC=$(MAIN_OBJ_PATH)/$(MAIN_OBJ_NAME).c
MAIN_OUTPUT_FOLDER=$(MAIN_OBJ_PATH)/bin
MAIN_OBJ=$(MAIN_OUTPUT_FOLDER)/$(MAIN_OBJ_NAME).o
MAIN_EXE=$(MAIN_OUTPUT_FOLDER)/$(MAIN_OBJ_NAME).exe
MAIN_LIBS=-lrt -lpthread -lm -L/usr/local/lib/dgl -ldglRenderWrapper -lGL -lglut -lGLU  

#------------------------------------------------------------------------------#							
# may need to delete this
$(MAIN_OUTPUT_FOLDER):
	mkdir $@

#------------------------------------------------------------------------------#							
# compile object
$(MAIN_OBJ): $(MAIN_INCLUDES) $(MAIN_SRC) | $(MAIN_OUTPUT_FOLDER) $(MAIN_OUTPUT_FOLDERS)
	$(CC) $(CFLAGS) -o $(MAIN_OBJ) $(MAIN_INCLUDES_PATHS) $(MAIN_SRC)
	
$(MAIN_EXE):  $(MAIN_OBJECTS) $(MAIN_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(MAIN_OBJ) $(MAIN_OBJECTS) $(MAIN_LIBS)

compile: dglGaugesCompile $(MAIN_EXE)

all: compile
	
run: compile
	export LD_LIBRARY_PATH=/usr/local/lib/dgl; $(MAIN_EXE)
	
clean: dglGaugesClean
	rm -rf $(MAIN_EXE) $(MAIN_OBJ) $(MAIN_OBJECTS)
	rm -rf $(MAIN_OUTPUT_FOLDER) \
	$(CARSIMULATOR_COMPONENT_OUTPUT_FOLDER)
	
	