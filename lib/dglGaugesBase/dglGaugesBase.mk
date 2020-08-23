#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

DGLGAUGESBASE_COMPONENT_NAME=dglGaugesBase
DGLGAUGESBASE_COMPONENT_FOLDER=$(PROJECT_PATH)lib/$(DGLGAUGESBASE_COMPONENT_NAME)
DGLGAUGESBASE_COMPONENT_OUTPUT_FOLDER=$(DGLGAUGESBASE_COMPONENT_FOLDER)/bin

$(DGLGAUGESBASE_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(DGLGAUGESBASE_COMPONENT_FOLDER)/Canvas.mk
include $(DGLGAUGESBASE_COMPONENT_FOLDER)/Mfd.mk
include $(DGLGAUGESBASE_COMPONENT_FOLDER)/Panel.mk
include $(DGLGAUGESBASE_COMPONENT_FOLDER)/Button.mk
include $(DGLGAUGESBASE_COMPONENT_FOLDER)/Indicator.mk
include $(DGLGAUGESBASE_COMPONENT_FOLDER)/Label.mk

DGLGAUGESBASE_COMPONENT_INCLUDES_PATHS= \
						$(CANVAS_INCLUDES_PATHS) \
						$(MFD_INCLUDES_PATHS) \
						$(PANEL_INCLUDES_PATHS) \
						$(BUTTON_INCLUDES_PATHS) \
						$(INDICATOR_INCLUDES_PATHS) \
						$(LABEL_INCLUDES_PATHS) \


DGLGAUGESBASE_COMPONENT_INCLUDES=	$(DGLGAUGESBASE_COMPONENT_FOLDER)/$(DGLGAUGESBASE_COMPONENT_NAME).mk \
						$(CANVAS_INCLUDES) \
						$(MFD_INCLUDES) \
						$(PANEL_INCLUDES) \
						$(BUTTON_INCLUDES) \
						$(INDICATOR_INCLUDES) \
						$(LABEL_INCLUDES) \


DGLGAUGESBASE_COMPONENT_OBJ= \
						$(CANVAS_OBJ) \
						$(MFD_OBJ) \
						$(PANEL_OBJ) \
						$(BUTTON_OBJ) \
						$(INDICATOR_OBJ) \
						$(LABEL_OBJ) \

