#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
CIRCLE_OBJ_NAME=Circle
# component name
CIRCLE_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
CIRCLE_OBJ_INCLUDE_PATH=$(CIRCLE_OBJ_PATH)/include
CIRCLE_OBJ_SRC_PATH=$(CIRCLE_OBJ_PATH)/src

# used includes
CIRCLE_INCLUDES_PATHS=$(sort	-I$(CIRCLE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

CIRCLE_INCLUDES=$(sort	$(CIRCLE_OBJ_INCLUDE_PATH)/$(CIRCLE_OBJ_NAME).h \
									$(CIRCLE_OBJ_PATH)/$(CIRCLE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
CIRCLE_SRC=$(CIRCLE_OBJ_SRC_PATH)/$(CIRCLE_OBJ_NAME).c
CIRCLE_OUTPUT_FOLDER=$(CIRCLE_OBJ_PATH)/bin
CIRCLE_OBJ=$(CIRCLE_OUTPUT_FOLDER)/$(CIRCLE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(CIRCLE_OBJ): $(CIRCLE_INCLUDES) $(CIRCLE_SRC) 
	$(CC) $(CFLAGS) -o $(CIRCLE_OBJ) $(CIRCLE_INCLUDES_PATHS) $(CIRCLE_SRC)
