#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
LABEL_OBJ_NAME=Label
# component name
LABEL_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESBASE_COMPONENT_NAME)
# include and source paths - no need to change
LABEL_OBJ_INCLUDE_PATH=$(LABEL_OBJ_PATH)/include
LABEL_OBJ_SRC_PATH=$(LABEL_OBJ_PATH)/src

# used includes
LABEL_INCLUDES_PATHS=$(sort	-I$(LABEL_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CANVAS_INCLUDES_PATHS))

LABEL_INCLUDES=$(sort	$(LABEL_OBJ_INCLUDE_PATH)/$(LABEL_OBJ_NAME).h \
									$(LABEL_OBJ_PATH)/$(LABEL_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CANVAS_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
LABEL_SRC=$(LABEL_OBJ_SRC_PATH)/$(LABEL_OBJ_NAME).c
LABEL_OUTPUT_FOLDER=$(LABEL_OBJ_PATH)/bin
LABEL_OBJ=$(LABEL_OUTPUT_FOLDER)/$(LABEL_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(LABEL_OBJ): $(LABEL_INCLUDES) $(LABEL_SRC)  $(LABEL_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(LABEL_OBJ) $(LABEL_INCLUDES_PATHS) $(LABEL_SRC)
