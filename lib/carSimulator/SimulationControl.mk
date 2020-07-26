#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
SIMULATIONCONTROL_OBJ_NAME=SimulationControl
# component name
SIMULATIONCONTROL_OBJ_PATH=$(PROJECT_PATH)/lib/$(CARSIMULATOR_COMPONENT_NAME)
# include and source paths - no need to change
SIMULATIONCONTROL_OBJ_INCLUDE_PATH=$(SIMULATIONCONTROL_OBJ_PATH)/include
SIMULATIONCONTROL_OBJ_SRC_PATH=$(SIMULATIONCONTROL_OBJ_PATH)/src

# used includes
SIMULATIONCONTROL_INCLUDES_PATHS=$(sort	-I$(SIMULATIONCONTROL_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SIMULATIONVIEW_INCLUDES_PATHS))

SIMULATIONCONTROL_INCLUDES=$(sort	$(SIMULATIONCONTROL_OBJ_INCLUDE_PATH)/$(SIMULATIONCONTROL_OBJ_NAME).h \
									$(SIMULATIONCONTROL_OBJ_PATH)/$(SIMULATIONCONTROL_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SIMULATIONVIEW_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
SIMULATIONCONTROL_SRC=$(SIMULATIONCONTROL_OBJ_SRC_PATH)/$(SIMULATIONCONTROL_OBJ_NAME).c
SIMULATIONCONTROL_OUTPUT_FOLDER=$(SIMULATIONCONTROL_OBJ_PATH)/bin
SIMULATIONCONTROL_OBJ=$(SIMULATIONCONTROL_OUTPUT_FOLDER)/$(SIMULATIONCONTROL_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(SIMULATIONCONTROL_OBJ): $(SIMULATIONCONTROL_INCLUDES) $(SIMULATIONCONTROL_SRC) 
	$(CC) $(CFLAGS) -o $(SIMULATIONCONTROL_OBJ) $(SIMULATIONCONTROL_INCLUDES_PATHS) $(SIMULATIONCONTROL_SRC)
