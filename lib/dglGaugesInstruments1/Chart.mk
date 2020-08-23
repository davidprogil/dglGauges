#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
CHART_OBJ_NAME=Chart
# component name
CHART_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS1_COMPONENT_NAME)
# include and source paths - no need to change
CHART_OBJ_INCLUDE_PATH=$(CHART_OBJ_PATH)/include
CHART_OBJ_SRC_PATH=$(CHART_OBJ_PATH)/src

# used includes
CHART_INCLUDES_PATHS=$(sort	-I$(CHART_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(LABEL_INCLUDES_PATHS))

CHART_INCLUDES=$(sort	$(CHART_OBJ_INCLUDE_PATH)/$(CHART_OBJ_NAME).h \
									$(CHART_OBJ_PATH)/$(CHART_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(LABEL_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
CHART_SRC=$(CHART_OBJ_SRC_PATH)/$(CHART_OBJ_NAME).c
CHART_OUTPUT_FOLDER=$(CHART_OBJ_PATH)/bin
CHART_OBJ=$(CHART_OUTPUT_FOLDER)/$(CHART_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(CHART_OBJ): $(CHART_INCLUDES) $(CHART_SRC) 
	$(CC) $(CFLAGS) -o $(CHART_OBJ) $(CHART_INCLUDES_PATHS) $(CHART_SRC)
