#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
INDICATOR_OBJ_NAME=Indicator
# component name
INDICATOR_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESBASE_COMPONENT_NAME)
# include and source paths - no need to change
INDICATOR_OBJ_INCLUDE_PATH=$(INDICATOR_OBJ_PATH)/include
INDICATOR_OBJ_SRC_PATH=$(INDICATOR_OBJ_PATH)/src

# used includes
INDICATOR_INCLUDES_PATHS=$(sort	-I$(INDICATOR_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

INDICATOR_INCLUDES=$(sort	$(INDICATOR_OBJ_INCLUDE_PATH)/$(INDICATOR_OBJ_NAME).h \
									$(INDICATOR_OBJ_PATH)/$(INDICATOR_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
INDICATOR_SRC=$(INDICATOR_OBJ_SRC_PATH)/$(INDICATOR_OBJ_NAME).c
INDICATOR_OUTPUT_FOLDER=$(INDICATOR_OBJ_PATH)/bin
INDICATOR_OBJ=$(INDICATOR_OUTPUT_FOLDER)/$(INDICATOR_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(INDICATOR_OBJ): $(INDICATOR_INCLUDES) $(INDICATOR_SRC)  
	$(CC) $(CFLAGS) -o $(INDICATOR_OBJ) $(INDICATOR_INCLUDES_PATHS) $(INDICATOR_SRC)
