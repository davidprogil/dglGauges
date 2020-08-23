#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
SQUARESTRIP_OBJ_NAME=SquareStrip
# component name
SQUARESTRIP_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
SQUARESTRIP_OBJ_INCLUDE_PATH=$(SQUARESTRIP_OBJ_PATH)/include
SQUARESTRIP_OBJ_SRC_PATH=$(SQUARESTRIP_OBJ_PATH)/src

# used includes
SQUARESTRIP_INCLUDES_PATHS=$(sort	-I$(SQUARESTRIP_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

SQUARESTRIP_INCLUDES=$(sort	$(SQUARESTRIP_OBJ_INCLUDE_PATH)/$(SQUARESTRIP_OBJ_NAME).h \
									$(SQUARESTRIP_OBJ_PATH)/$(SQUARESTRIP_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
SQUARESTRIP_SRC=$(SQUARESTRIP_OBJ_SRC_PATH)/$(SQUARESTRIP_OBJ_NAME).c
SQUARESTRIP_OUTPUT_FOLDER=$(SQUARESTRIP_OBJ_PATH)/bin
SQUARESTRIP_OBJ=$(SQUARESTRIP_OUTPUT_FOLDER)/$(SQUARESTRIP_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(SQUARESTRIP_OBJ): $(SQUARESTRIP_INCLUDES) $(SQUARESTRIP_SRC) 
	$(CC) $(CFLAGS) -o $(SQUARESTRIP_OBJ) $(SQUARESTRIP_INCLUDES_PATHS) $(SQUARESTRIP_SRC)
