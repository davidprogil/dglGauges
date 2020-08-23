#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
PANEL_OBJ_NAME=Panel
# component name
PANEL_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESBASE_COMPONENT_NAME)
# include and source paths - no need to change
PANEL_OBJ_INCLUDE_PATH=$(PANEL_OBJ_PATH)/include
PANEL_OBJ_SRC_PATH=$(PANEL_OBJ_PATH)/src

# used includes
PANEL_INCLUDES_PATHS=$(sort	-I$(PANEL_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CANVAS_INCLUDES_PATHS))

PANEL_INCLUDES=$(sort	$(PANEL_OBJ_INCLUDE_PATH)/$(PANEL_OBJ_NAME).h \
									$(PANEL_OBJ_PATH)/$(PANEL_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CANVAS_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
PANEL_SRC=$(PANEL_OBJ_SRC_PATH)/$(PANEL_OBJ_NAME).c
PANEL_OUTPUT_FOLDER=$(PANEL_OBJ_PATH)/bin
PANEL_OBJ=$(PANEL_OUTPUT_FOLDER)/$(PANEL_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(PANEL_OBJ): $(PANEL_INCLUDES) $(PANEL_SRC) 
	$(CC) $(CFLAGS) -o $(PANEL_OBJ) $(PANEL_INCLUDES_PATHS) $(PANEL_SRC)
