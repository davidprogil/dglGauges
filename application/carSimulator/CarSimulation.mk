#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
CARSIMULATION_OBJ_NAME=CarSimulation
# component name
CARSIMULATION_OBJ_PATH=$(PROJECT_PATH)/application/$(CARSIMULATOR_COMPONENT_NAME)
# include and source paths - no need to change
CARSIMULATION_OBJ_INCLUDE_PATH=$(CARSIMULATION_OBJ_PATH)/include
CARSIMULATION_OBJ_SRC_PATH=$(CARSIMULATION_OBJ_PATH)/src

# used includes
CARSIMULATION_INCLUDES_PATHS=$(sort	-I$(CARSIMULATION_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CARMFD_INCLUDES_PATHS))

CARSIMULATION_INCLUDES=$(sort	$(CARSIMULATION_OBJ_INCLUDE_PATH)/$(CARSIMULATION_OBJ_NAME).h \
									$(CARSIMULATION_OBJ_PATH)/$(CARSIMULATION_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CARMFD_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
CARSIMULATION_SRC=$(CARSIMULATION_OBJ_SRC_PATH)/$(CARSIMULATION_OBJ_NAME).c
CARSIMULATION_OUTPUT_FOLDER=$(CARSIMULATION_OBJ_PATH)/bin
CARSIMULATION_OBJ=$(CARSIMULATION_OUTPUT_FOLDER)/$(CARSIMULATION_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(CARSIMULATION_OBJ): $(CARSIMULATION_INCLUDES) $(CARSIMULATION_SRC) 
	$(CC) $(CFLAGS) -o $(CARSIMULATION_OBJ) $(CARSIMULATION_INCLUDES_PATHS) $(CARSIMULATION_SRC)
