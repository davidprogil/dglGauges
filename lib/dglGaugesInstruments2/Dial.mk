#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
DIAL_OBJ_NAME=Dial
# component name
DIAL_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME)
# include and source paths - no need to change
DIAL_OBJ_INCLUDE_PATH=$(DIAL_OBJ_PATH)/include
DIAL_OBJ_SRC_PATH=$(DIAL_OBJ_PATH)/src

# used includes
DIAL_INCLUDES_PATHS=$(sort	-I$(DIAL_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

DIAL_INCLUDES=$(sort	$(DIAL_OBJ_INCLUDE_PATH)/GGI2_$(DIAL_OBJ_NAME).h \
									$(DIAL_OBJ_PATH)/$(DIAL_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
DIAL_SRC=$(DIAL_OBJ_SRC_PATH)/$(DIAL_OBJ_NAME).c
DIAL_OUTPUT_FOLDER=$(DIAL_OBJ_PATH)/bin
DIAL_OBJ=$(DIAL_OUTPUT_FOLDER)/$(DIAL_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(DIAL_OBJ): $(DIAL_INCLUDES) $(DIAL_SRC) 
	$(CC) $(CFLAGS) -o $(DIAL_OBJ) $(DIAL_INCLUDES_PATHS) $(DIAL_SRC)
