#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
CANVAS_OBJ_NAME=Canvas
# component name
CANVAS_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESBASE_COMPONENT_NAME)
# include and source paths - no need to change
CANVAS_OBJ_INCLUDE_PATH=$(CANVAS_OBJ_PATH)/include
CANVAS_OBJ_SRC_PATH=$(CANVAS_OBJ_PATH)/src

# used includes
CANVAS_INCLUDES_PATHS=$(sort	-I$(CANVAS_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(WINDOW_INCLUDES_PATHS))

CANVAS_INCLUDES=$(sort	$(CANVAS_OBJ_INCLUDE_PATH)/$(CANVAS_OBJ_NAME).h \
									$(CANVAS_OBJ_PATH)/$(CANVAS_OBJ_NAME).mk \
									$(COMMON_INCLUDES)\
									$(WINDOW_INCLUDES)\
									$(COLOUR_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
CANVAS_SRC=$(CANVAS_OBJ_SRC_PATH)/$(CANVAS_OBJ_NAME).c
CANVAS_OUTPUT_FOLDER=$(CANVAS_OBJ_PATH)/bin
CANVAS_OBJ=$(CANVAS_OUTPUT_FOLDER)/$(CANVAS_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(CANVAS_OBJ): $(CANVAS_INCLUDES) $(CANVAS_SRC)  
	$(CC) $(CFLAGS) -o $(CANVAS_OBJ) $(CANVAS_INCLUDES_PATHS) $(CANVAS_SRC)
