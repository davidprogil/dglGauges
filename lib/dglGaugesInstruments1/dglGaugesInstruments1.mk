#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

DGLGAUGESINSTRUMENTS1_COMPONENT_NAME=dglGaugesInstruments1
DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS1_COMPONENT_NAME)
DGLGAUGESINSTRUMENTS1_COMPONENT_OUTPUT_FOLDER=$(DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER)/bin

$(DGLGAUGESINSTRUMENTS1_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER)/Bar.mk
include $(DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER)/Gauge.mk
include $(DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER)/Sign.mk
include $(DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER)/Chart.mk

DGLGAUGESINSTRUMENTS1_COMPONENT_INCLUDES_PATHS= \
						$(BAR_INCLUDES_PATHS) \
						$(GAUGE_INCLUDES_PATHS) \
						$(SIGN_INCLUDES_PATHS) \
						$(CHART_INCLUDES_PATHS) \


DGLGAUGESINSTRUMENTS1_COMPONENT_INCLUDES=	$(DGLGAUGESINSTRUMENTS1_COMPONENT_FOLDER)/$(DGLGAUGESINSTRUMENTS1_COMPONENT_NAME).mk \
						$(BAR_INCLUDES) \
						$(GAUGE_INCLUDES) \
						$(SIGN_INCLUDES) \
						$(CHART_INCLUDES) \


DGLGAUGESINSTRUMENTS1_COMPONENT_OBJ= \
						$(BAR_OBJ) \
						$(GAUGE_OBJ) \
						$(SIGN_OBJ) \
						$(CHART_OBJ) \

