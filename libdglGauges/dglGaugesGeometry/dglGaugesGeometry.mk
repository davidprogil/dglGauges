#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

DGLGAUGESGEOMETRY_COMPONENT_NAME=dglGaugesGeometry
DGLGAUGESGEOMETRY_COMPONENT_FOLDER=$(PROJECT_PATH)/libdglGauges/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
DGLGAUGESGEOMETRY_COMPONENT_OUTPUT_FOLDER=$(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/bin

$(DGLGAUGESGEOMETRY_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/Point.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/Window.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/LineStrip.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/SquareStrip.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/Text.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/Shape.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/Circle.mk
include $(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/Colour.mk

DGLGAUGESGEOMETRY_COMPONENT_INCLUDES_PATHS= \
						$(POINT_INCLUDES_PATHS) \
						$(WINDOW_INCLUDES_PATHS) \
						$(LINESTRIP_INCLUDES_PATHS) \
						$(SQUARESTRIP_INCLUDES_PATHS) \
						$(TEXT_INCLUDES_PATHS) \
						$(SHAPE_INCLUDES_PATHS) \
						$(CIRCLE_INCLUDES_PATHS) \
						$(COLOUR_INCLUDES_PATHS) \


DGLGAUGESGEOMETRY_COMPONENT_INCLUDES=	$(DGLGAUGESGEOMETRY_COMPONENT_FOLDER)/$(DGLGAUGESGEOMETRY_COMPONENT_NAME).mk \
						$(POINT_INCLUDES) \
						$(WINDOW_INCLUDES) \
						$(LINESTRIP_INCLUDES) \
						$(SQUARESTRIP_INCLUDES) \
						$(TEXT_INCLUDES) \
						$(SHAPE_INCLUDES) \
						$(CIRCLE_INCLUDES) \
						$(COLOUR_INCLUDES) \


DGLGAUGESGEOMETRY_COMPONENT_OBJ= \
						$(POINT_OBJ) \
						$(WINDOW_OBJ) \
						$(LINESTRIP_OBJ) \
						$(SQUARESTRIP_OBJ) \
						$(TEXT_OBJ) \
						$(SHAPE_OBJ) \
						$(CIRCLE_OBJ) \
						$(COLOUR_OBJ) \

