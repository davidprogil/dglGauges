#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
GAUGE_OBJ_NAME=Gauge
# component name
GAUGE_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLGAUGESINSTRUMENTS1_COMPONENT_NAME)
# include and source paths - no need to change
GAUGE_OBJ_INCLUDE_PATH=$(GAUGE_OBJ_PATH)/include
GAUGE_OBJ_SRC_PATH=$(GAUGE_OBJ_PATH)/src

# used includes
GAUGE_INCLUDES_PATHS=$(sort	-I$(GAUGE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(LABEL_INCLUDES_PATHS))

GAUGE_INCLUDES=$(sort	$(GAUGE_OBJ_INCLUDE_PATH)/$(GAUGE_OBJ_NAME).h \
									$(GAUGE_OBJ_PATH)/$(GAUGE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(LABEL_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
GAUGE_SRC=$(GAUGE_OBJ_SRC_PATH)/$(GAUGE_OBJ_NAME).c
GAUGE_OUTPUT_FOLDER=$(GAUGE_OBJ_PATH)/bin
GAUGE_OBJ=$(GAUGE_OUTPUT_FOLDER)/$(GAUGE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(GAUGE_OBJ): $(GAUGE_INCLUDES) $(GAUGE_SRC) 
	$(CC) $(CFLAGS) -o $(GAUGE_OBJ) $(GAUGE_INCLUDES_PATHS) $(GAUGE_SRC)
