#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
KEYBOARDANDMOUSE_OBJ_NAME=KeyboardAndMouse
# component name
KEYBOARDANDMOUSE_OBJ_PATH=$(PROJECT_PATH)/lib/$(CARSIMULATOR_COMPONENT_NAME)
# include and source paths - no need to change
KEYBOARDANDMOUSE_OBJ_INCLUDE_PATH=$(KEYBOARDANDMOUSE_OBJ_PATH)/include
KEYBOARDANDMOUSE_OBJ_SRC_PATH=$(KEYBOARDANDMOUSE_OBJ_PATH)/src

# used includes
KEYBOARDANDMOUSE_INCLUDES_PATHS=$(sort	-I$(KEYBOARDANDMOUSE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CARSIMULATION_INCLUDES_PATHS)\
									$(DGLRENDERWRAPPER_COMPONENT_INCLUDES_PATHS))

KEYBOARDANDMOUSE_INCLUDES=$(sort	$(KEYBOARDANDMOUSE_OBJ_INCLUDE_PATH)/$(KEYBOARDANDMOUSE_OBJ_NAME).h \
									$(KEYBOARDANDMOUSE_OBJ_PATH)/$(KEYBOARDANDMOUSE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CARSIMULATION_INCLUDES)\
									$(DGLRENDERWRAPPER_COMPONENT_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
KEYBOARDANDMOUSE_SRC=$(KEYBOARDANDMOUSE_OBJ_SRC_PATH)/$(KEYBOARDANDMOUSE_OBJ_NAME).c
KEYBOARDANDMOUSE_OUTPUT_FOLDER=$(KEYBOARDANDMOUSE_OBJ_PATH)/bin
KEYBOARDANDMOUSE_OBJ=$(KEYBOARDANDMOUSE_OUTPUT_FOLDER)/$(KEYBOARDANDMOUSE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(KEYBOARDANDMOUSE_OBJ): $(KEYBOARDANDMOUSE_INCLUDES) $(KEYBOARDANDMOUSE_SRC) 
	$(CC) $(CFLAGS) -o $(KEYBOARDANDMOUSE_OBJ) $(KEYBOARDANDMOUSE_INCLUDES_PATHS) $(KEYBOARDANDMOUSE_SRC)
