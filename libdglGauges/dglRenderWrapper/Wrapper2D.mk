#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
WRAPPER2D_OBJ_NAME=Wrapper2D
# component name
WRAPPER2D_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLRENDERWRAPPER_COMPONENT_NAME)
# include and source paths - no need to change
WRAPPER2D_OBJ_INCLUDE_PATH=$(WRAPPER2D_OBJ_PATH)/include
WRAPPER2D_OBJ_SRC_PATH=$(WRAPPER2D_OBJ_PATH)/src

# used includes
WRAPPER2D_INCLUDES_PATHS=$(sort	-I$(WRAPPER2D_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

WRAPPER2D_INCLUDES=$(sort	$(WRAPPER2D_OBJ_INCLUDE_PATH)/$(WRAPPER2D_OBJ_NAME).h \
									$(WRAPPER2D_OBJ_PATH)/$(WRAPPER2D_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
WRAPPER2D_SRC=$(WRAPPER2D_OBJ_SRC_PATH)/$(WRAPPER2D_OBJ_NAME).c
WRAPPER2D_OUTPUT_FOLDER=$(WRAPPER2D_OBJ_PATH)/bin
WRAPPER2D_OBJ=$(WRAPPER2D_OUTPUT_FOLDER)/$(WRAPPER2D_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(WRAPPER2D_OBJ): $(WRAPPER2D_INCLUDES) $(WRAPPER2D_SRC) $(DGLRENDERWRAPPER_COMPONENT_OUTPUT_FOLDER)
	$(CC) $(CFLAGS) -o $(WRAPPER2D_OBJ) $(WRAPPER2D_INCLUDES_PATHS) $(WRAPPER2D_SRC)
