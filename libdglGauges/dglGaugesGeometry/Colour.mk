#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
COLOUR_OBJ_NAME=Colour
# component name
COLOUR_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
COLOUR_OBJ_INCLUDE_PATH=$(COLOUR_OBJ_PATH)/include
COLOUR_OBJ_SRC_PATH=$(COLOUR_OBJ_PATH)/src

# used includes
COLOUR_INCLUDES_PATHS=$(sort	-I$(COLOUR_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(WRAPPER2D_INCLUDES_PATHS))

COLOUR_INCLUDES=$(sort	$(COLOUR_OBJ_INCLUDE_PATH)/$(COLOUR_OBJ_NAME).h \
									$(COLOUR_OBJ_PATH)/$(COLOUR_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(WRAPPER2D_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
COLOUR_SRC=$(COLOUR_OBJ_SRC_PATH)/$(COLOUR_OBJ_NAME).c
COLOUR_OUTPUT_FOLDER=$(COLOUR_OBJ_PATH)/bin
COLOUR_OBJ=$(COLOUR_OUTPUT_FOLDER)/$(COLOUR_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(COLOUR_OBJ): $(COLOUR_INCLUDES) $(COLOUR_SRC) 
	$(CC) $(CFLAGS) -o $(COLOUR_OBJ) $(COLOUR_INCLUDES_PATHS) $(COLOUR_SRC)
