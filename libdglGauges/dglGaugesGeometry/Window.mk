#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
WINDOW_OBJ_NAME=Window
# component name
WINDOW_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
WINDOW_OBJ_INCLUDE_PATH=$(WINDOW_OBJ_PATH)/include
WINDOW_OBJ_SRC_PATH=$(WINDOW_OBJ_PATH)/src

# used includes
WINDOW_INCLUDES_PATHS=$(sort	-I$(WINDOW_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

WINDOW_INCLUDES=$(sort	$(WINDOW_OBJ_INCLUDE_PATH)/$(WINDOW_OBJ_NAME).h \
									$(WINDOW_OBJ_PATH)/$(WINDOW_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
WINDOW_SRC=$(WINDOW_OBJ_SRC_PATH)/$(WINDOW_OBJ_NAME).c
WINDOW_OUTPUT_FOLDER=$(WINDOW_OBJ_PATH)/bin
WINDOW_OBJ=$(WINDOW_OUTPUT_FOLDER)/$(WINDOW_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(WINDOW_OBJ): $(WINDOW_INCLUDES) $(WINDOW_SRC) 
	$(CC) $(CFLAGS) -o $(WINDOW_OBJ) $(WINDOW_INCLUDES_PATHS) $(WINDOW_SRC)
