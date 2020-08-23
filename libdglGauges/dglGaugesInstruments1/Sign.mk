#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
SIGN_OBJ_NAME=Sign
# component name
SIGN_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLGAUGESINSTRUMENTS1_COMPONENT_NAME)
# include and source paths - no need to change
SIGN_OBJ_INCLUDE_PATH=$(SIGN_OBJ_PATH)/include
SIGN_OBJ_SRC_PATH=$(SIGN_OBJ_PATH)/src

# used includes
SIGN_INCLUDES_PATHS=$(sort	-I$(SIGN_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(CANVAS_INCLUDES_PATHS))

SIGN_INCLUDES=$(sort	$(SIGN_OBJ_INCLUDE_PATH)/$(SIGN_OBJ_NAME).h \
									$(SIGN_OBJ_PATH)/$(SIGN_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(CANVAS_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
SIGN_SRC=$(SIGN_OBJ_SRC_PATH)/$(SIGN_OBJ_NAME).c
SIGN_OUTPUT_FOLDER=$(SIGN_OBJ_PATH)/bin
SIGN_OBJ=$(SIGN_OUTPUT_FOLDER)/$(SIGN_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(SIGN_OBJ): $(SIGN_INCLUDES) $(SIGN_SRC) 
	$(CC) $(CFLAGS) -o $(SIGN_OBJ) $(SIGN_INCLUDES_PATHS) $(SIGN_SRC)
