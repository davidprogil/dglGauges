#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
BAR_OBJ_NAME=Bar
# component name
BAR_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS1_COMPONENT_NAME)
# include and source paths - no need to change
BAR_OBJ_INCLUDE_PATH=$(BAR_OBJ_PATH)/include
BAR_OBJ_SRC_PATH=$(BAR_OBJ_PATH)/src

# used includes
BAR_INCLUDES_PATHS=$(sort	-I$(BAR_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CANVAS_INCLUDES_PATHS))

BAR_INCLUDES=$(sort	$(BAR_OBJ_INCLUDE_PATH)/$(BAR_OBJ_NAME).h \
									$(BAR_OBJ_PATH)/$(BAR_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CANVAS_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
BAR_SRC=$(BAR_OBJ_SRC_PATH)/$(BAR_OBJ_NAME).c
BAR_OUTPUT_FOLDER=$(BAR_OBJ_PATH)/bin
BAR_OBJ=$(BAR_OUTPUT_FOLDER)/$(BAR_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(BAR_OBJ): $(BAR_INCLUDES) $(BAR_SRC) $(DGLGAUGESINSTRUMENTS1_COMPONENT_OUTPUT_FOLDER)
	$(CC) $(CFLAGS) -o $(BAR_OBJ) $(BAR_INCLUDES_PATHS) $(BAR_SRC)
