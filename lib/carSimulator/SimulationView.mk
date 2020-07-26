#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
SIMULATIONVIEW_OBJ_NAME=SimulationView
# component name
SIMULATIONVIEW_OBJ_PATH=$(PROJECT_PATH)/lib/$(CARSIMULATOR_COMPONENT_NAME)
# include and source paths - no need to change
SIMULATIONVIEW_OBJ_INCLUDE_PATH=$(SIMULATIONVIEW_OBJ_PATH)/include
SIMULATIONVIEW_OBJ_SRC_PATH=$(SIMULATIONVIEW_OBJ_PATH)/src

# used includes
SIMULATIONVIEW_INCLUDES_PATHS=$(sort	-I$(SIMULATIONVIEW_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(DGLRENDERWRAPPER_COMPONENT_INCLUDES_PATHS)\
									$(CARSIMULATION_INCLUDES_PATHS))

SIMULATIONVIEW_INCLUDES=$(sort	$(SIMULATIONVIEW_OBJ_INCLUDE_PATH)/$(SIMULATIONVIEW_OBJ_NAME).h \
									$(SIMULATIONVIEW_OBJ_PATH)/$(SIMULATIONVIEW_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(DGLRENDERWRAPPER_COMPONENT_INCLUDES)\
									$(CARSIMULATION_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
SIMULATIONVIEW_SRC=$(SIMULATIONVIEW_OBJ_SRC_PATH)/$(SIMULATIONVIEW_OBJ_NAME).c
SIMULATIONVIEW_OUTPUT_FOLDER=$(SIMULATIONVIEW_OBJ_PATH)/bin
SIMULATIONVIEW_OBJ=$(SIMULATIONVIEW_OUTPUT_FOLDER)/$(SIMULATIONVIEW_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(SIMULATIONVIEW_OBJ): $(SIMULATIONVIEW_INCLUDES) $(SIMULATIONVIEW_SRC) 
	$(CC) $(CFLAGS) -o $(SIMULATIONVIEW_OBJ) $(SIMULATIONVIEW_INCLUDES_PATHS) $(SIMULATIONVIEW_SRC)
