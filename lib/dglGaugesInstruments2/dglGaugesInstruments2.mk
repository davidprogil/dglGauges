#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

DGLGAUGESINSTRUMENTS2_COMPONENT_NAME=dglGaugesInstruments2
DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME)
DGLGAUGESINSTRUMENTS2_COMPONENT_OUTPUT_FOLDER=$(DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER)/bin

$(DGLGAUGESINSTRUMENTS2_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER)/MultiChart.mk
include $(DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER)/MultiGauge.mk
include $(DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER)/Dial.mk
include $(DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER)/Spread.mk

DGLGAUGESINSTRUMENTS2_COMPONENT_INCLUDES_PATHS= \
						$(MULTICHART_INCLUDES_PATHS) \
						$(MULTIGAUGE_INCLUDES_PATHS) \
						$(DIAL_INCLUDES_PATHS) \
						$(SPREAD_INCLUDES_PATHS) \


DGLGAUGESINSTRUMENTS2_COMPONENT_INCLUDES=	$(DGLGAUGESINSTRUMENTS2_COMPONENT_FOLDER)/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME).mk \
						$(MULTICHART_INCLUDES) \
						$(MULTIGAUGE_INCLUDES) \
						$(DIAL_INCLUDES) \
						$(SPREAD_INCLUDES) \


DGLGAUGESINSTRUMENTS2_COMPONENT_OBJ= \
						$(MULTICHART_OBJ) \
						$(MULTIGAUGE_OBJ) \
						$(DIAL_OBJ) \
						$(SPREAD_OBJ) \

