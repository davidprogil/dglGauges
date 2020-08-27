#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
MULTIGAUGE_OBJ_NAME=MultiGauge
# component name
MULTIGAUGE_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME)
# include and source paths - no need to change
MULTIGAUGE_OBJ_INCLUDE_PATH=$(MULTIGAUGE_OBJ_PATH)/include
MULTIGAUGE_OBJ_SRC_PATH=$(MULTIGAUGE_OBJ_PATH)/src

# used includes
MULTIGAUGE_INCLUDES_PATHS=$(sort	-I$(MULTIGAUGE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

MULTIGAUGE_INCLUDES=$(sort	$(MULTIGAUGE_OBJ_INCLUDE_PATH)/GGI2_$(MULTIGAUGE_OBJ_NAME).h \
									$(MULTIGAUGE_OBJ_PATH)/$(MULTIGAUGE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
MULTIGAUGE_SRC=$(MULTIGAUGE_OBJ_SRC_PATH)/$(MULTIGAUGE_OBJ_NAME).c
MULTIGAUGE_OUTPUT_FOLDER=$(MULTIGAUGE_OBJ_PATH)/bin
MULTIGAUGE_OBJ=$(MULTIGAUGE_OUTPUT_FOLDER)/$(MULTIGAUGE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(MULTIGAUGE_OBJ): $(MULTIGAUGE_INCLUDES) $(MULTIGAUGE_SRC) 
	$(CC) $(CFLAGS) -o $(MULTIGAUGE_OBJ) $(MULTIGAUGE_INCLUDES_PATHS) $(MULTIGAUGE_SRC)
