#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
POINT_OBJ_NAME=Point
# component name
POINT_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
POINT_OBJ_INCLUDE_PATH=$(POINT_OBJ_PATH)/include
POINT_OBJ_SRC_PATH=$(POINT_OBJ_PATH)/src

# used includes
POINT_INCLUDES_PATHS=$(sort	-I$(POINT_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(WRAPPER2D_INCLUDES_PATHS))

POINT_INCLUDES=$(sort	$(POINT_OBJ_INCLUDE_PATH)/$(POINT_OBJ_NAME).h \
									$(POINT_OBJ_PATH)/$(POINT_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(WRAPPER2D_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
POINT_SRC=$(POINT_OBJ_SRC_PATH)/$(POINT_OBJ_NAME).c
POINT_OUTPUT_FOLDER=$(POINT_OBJ_PATH)/bin
POINT_OBJ=$(POINT_OUTPUT_FOLDER)/$(POINT_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(POINT_OBJ): $(POINT_INCLUDES) $(POINT_SRC)  $(DGLGAUGESGEOMETRY_COMPONENT_OUTPUT_FOLDER)
	$(CC) $(CFLAGS) -o $(POINT_OBJ) $(POINT_INCLUDES_PATHS) $(POINT_SRC)
