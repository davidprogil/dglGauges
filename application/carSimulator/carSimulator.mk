#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

CARSIMULATOR_COMPONENT_NAME=carSimulator
CARSIMULATOR_COMPONENT_FOLDER=$(PROJECT_PATH)/application/$(CARSIMULATOR_COMPONENT_NAME)
CARSIMULATOR_COMPONENT_OUTPUT_FOLDER=$(CARSIMULATOR_COMPONENT_FOLDER)/bin

$(CARSIMULATOR_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(CARSIMULATOR_COMPONENT_FOLDER)/SimulationControl.mk
include $(CARSIMULATOR_COMPONENT_FOLDER)/CarSimulation.mk
include $(CARSIMULATOR_COMPONENT_FOLDER)/CarMfd.mk
include $(CARSIMULATOR_COMPONENT_FOLDER)/SimulationView.mk
include $(CARSIMULATOR_COMPONENT_FOLDER)/KeyboardAndMouse.mk

CARSIMULATOR_COMPONENT_INCLUDES_PATHS= \
						$(SIMULATIONCONTROL_INCLUDES_PATHS) \
						$(CARSIMULATION_INCLUDES_PATHS) \
						$(CARMFD_INCLUDES_PATHS) \
						$(SIMULATIONVIEW_INCLUDES_PATHS) \
						$(KEYBOARDANDMOUSE_INCLUDES_PATHS) \


CARSIMULATOR_COMPONENT_INCLUDES=	$(CARSIMULATOR_COMPONENT_FOLDER)/$(CARSIMULATOR_COMPONENT_NAME).mk \
						$(SIMULATIONCONTROL_INCLUDES) \
						$(CARSIMULATION_INCLUDES) \
						$(CARMFD_INCLUDES) \
						$(SIMULATIONVIEW_INCLUDES) \
						$(KEYBOARDANDMOUSE_INCLUDES) \


CARSIMULATOR_COMPONENT_OBJ= \
						$(SIMULATIONCONTROL_OBJ) \
						$(CARSIMULATION_OBJ) \
						$(CARMFD_OBJ) \
						$(SIMULATIONVIEW_OBJ) \
						$(KEYBOARDANDMOUSE_OBJ) \

