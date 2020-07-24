#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
SHAPE_OBJ_NAME=Shape
# component name
SHAPE_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
SHAPE_OBJ_INCLUDE_PATH=$(SHAPE_OBJ_PATH)/include
SHAPE_OBJ_SRC_PATH=$(SHAPE_OBJ_PATH)/src

# used includes
SHAPE_INCLUDES_PATHS=$(sort	-I$(SHAPE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

SHAPE_INCLUDES=$(sort	$(SHAPE_OBJ_INCLUDE_PATH)/$(SHAPE_OBJ_NAME).h \
									$(SHAPE_OBJ_PATH)/$(SHAPE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
SHAPE_SRC=$(SHAPE_OBJ_SRC_PATH)/$(SHAPE_OBJ_NAME).c
SHAPE_OUTPUT_FOLDER=$(SHAPE_OBJ_PATH)/bin
SHAPE_OBJ=$(SHAPE_OUTPUT_FOLDER)/$(SHAPE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(SHAPE_OBJ): $(SHAPE_INCLUDES) $(SHAPE_SRC) 
	$(CC) $(CFLAGS) -o $(SHAPE_OBJ) $(SHAPE_INCLUDES_PATHS) $(SHAPE_SRC)
