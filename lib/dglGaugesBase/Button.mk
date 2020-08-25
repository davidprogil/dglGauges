#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
BUTTON_OBJ_NAME=Button
# component name
BUTTON_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESBASE_COMPONENT_NAME)
# include and source paths - no need to change
BUTTON_OBJ_INCLUDE_PATH=$(BUTTON_OBJ_PATH)/include
BUTTON_OBJ_SRC_PATH=$(BUTTON_OBJ_PATH)/src

# used includes
BUTTON_INCLUDES_PATHS=$(sort	-I$(BUTTON_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CANVAS_INCLUDES_PATHS))

BUTTON_INCLUDES=$(sort	$(BUTTON_OBJ_INCLUDE_PATH)/$(BUTTON_OBJ_NAME).h \
									$(BUTTON_OBJ_PATH)/$(BUTTON_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CANVAS_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
BUTTON_SRC=$(BUTTON_OBJ_SRC_PATH)/$(BUTTON_OBJ_NAME).c
BUTTON_OUTPUT_FOLDER=$(BUTTON_OBJ_PATH)/bin
BUTTON_OBJ=$(BUTTON_OUTPUT_FOLDER)/$(BUTTON_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object $(BUTTON_INCLUDES) $(BUTTON_SRC)  $(BUTTON_OUTPUT_FOLDER)
$(BUTTON_OBJ):  $(BUTTON_SRC)  $(BUTTON_INCLUDES) 
	$(CC) $(CFLAGS) -o $(BUTTON_OBJ) $(BUTTON_INCLUDES_PATHS) $(BUTTON_SRC)
