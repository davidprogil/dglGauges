#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
MULTICHART_OBJ_NAME=MultiChart
# component name
MULTICHART_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME)
# include and source paths - no need to change
MULTICHART_OBJ_INCLUDE_PATH=$(MULTICHART_OBJ_PATH)/include
MULTICHART_OBJ_SRC_PATH=$(MULTICHART_OBJ_PATH)/src

# used includes
MULTICHART_INCLUDES_PATHS=$(sort	-I$(MULTICHART_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(LABEL_INCLUDES_PATHS))

MULTICHART_INCLUDES=$(sort	$(MULTICHART_OBJ_INCLUDE_PATH)/GGI2_$(MULTICHART_OBJ_NAME).h \
									$(MULTICHART_OBJ_PATH)/$(MULTICHART_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(LABEL_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
MULTICHART_SRC=$(MULTICHART_OBJ_SRC_PATH)/$(MULTICHART_OBJ_NAME).c
MULTICHART_OUTPUT_FOLDER=$(MULTICHART_OBJ_PATH)/bin
MULTICHART_OBJ=$(MULTICHART_OUTPUT_FOLDER)/$(MULTICHART_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(MULTICHART_OBJ): $(MULTICHART_INCLUDES) $(MULTICHART_SRC) $(DGLGAUGESINSTRUMENTS2_COMPONENT_OUTPUT_FOLDER)
	$(CC) $(CFLAGS) -o $(MULTICHART_OBJ) $(MULTICHART_INCLUDES_PATHS) $(MULTICHART_SRC)
