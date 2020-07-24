#------------------------------------------------------------------------------#
# Copyright David Gil 1998-TODO                                                #
# 								                                               #
# davidgil@dgadv.com 			                                               #
#------------------------------------------------------------------------------#

#--------------------------------------------------------------------------------
# project set-up
PROJECT_PATH=$(CWD)
COMMON_INCLUDES_PATHS=-I$(PROJECT_PATH)include
COMMON_INCLUDES=$(PROJECT_PATH)include/myTypes.h
CC=gcc
CFLAGS=-Wall -c
LDFLAGS=-Wall

#--------------------------------------------------------------------------------
# project components
include ./lib/dglGaugesGeometry/dglGaugesGeometry.mk
include ./lib/dglGaugesBase/dglGaugesBase.mk


#--------------------------------------------------------------------------------
# includes and objects 
MAIN_INCLUDES_PATHS=$(sort 	$(COMMON_INCLUDES_PATHS) \
							$(DGLGAUGESBASE_COMPONENT_INCLUDES_PATHS))
							
MAIN_INCLUDES=		$(sort 	$(COMMON_INCLUDES) \
							Makefile \
							$(DGLGAUGESBASE_COMPONENT_INCLUDES))

MAIN_OBJECTS=		$(DGLGAUGESBASE_COMPONENT_OBJ) \
					$(DGLGAUGESGEOMETRY_COMPONENT_OBJ)

MAIN_OUTPUT_FOLDERS =  $(DGLGAUGESBASE_COMPONENT_OUTPUT_FOLDER) \
					$(DGLGAUGESGEOMETRY_COMPONENT_OUTPUT_FOLDER)

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
MAIN_LIBS=

#------------------------------------------------------------------------------#							
# may need to delete this
$(MAIN_OUTPUT_FOLDER):
	mkdir $@

#------------------------------------------------------------------------------#							
# compile object
$(MAIN_OBJ): $(MAIN_INCLUDES) $(MAIN_SRC) | $(MAIN_OUTPUT_FOLDER) $(MAIN_OUTPUT_FOLDERS)
	$(CC) $(CFLAGS) -o $(MAIN_OBJ) $(MAIN_INCLUDES_PATHS) $(MAIN_SRC)
	
$(MAIN_EXE): $(MAIN_OBJ) $(MAIN_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(MAIN_OBJ) $(MAIN_OBJECTS) $(MAIN_LIBS)

compile: $(MAIN_EXE)

all: compile
	
run: compile
	$(MAIN_EXE)
	
clean:
	rm -rf $(MAIN_EXE) $(MAIN_OBJ) $(MAIN_OBJECTS)
	rm -rf $(MAIN_OUTPUT_FOLDER) $(TEMPLATE_COMPONENT_OUTPUT_FOLDER)
	