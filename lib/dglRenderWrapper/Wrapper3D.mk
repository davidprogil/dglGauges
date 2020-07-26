#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
WRAPPER3D_OBJ_NAME=Wrapper3D
# component name
WRAPPER3D_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLRENDERWRAPPER_COMPONENT_NAME)
# include and source paths - no need to change
WRAPPER3D_OBJ_INCLUDE_PATH=$(WRAPPER3D_OBJ_PATH)/include
WRAPPER3D_OBJ_SRC_PATH=$(WRAPPER3D_OBJ_PATH)/src

# used includes
WRAPPER3D_INCLUDES_PATHS=$(sort	-I$(WRAPPER3D_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

WRAPPER3D_INCLUDES=$(sort	$(WRAPPER3D_OBJ_INCLUDE_PATH)/$(WRAPPER3D_OBJ_NAME).h \
									$(WRAPPER3D_OBJ_PATH)/$(WRAPPER3D_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
WRAPPER3D_SRC=$(WRAPPER3D_OBJ_SRC_PATH)/$(WRAPPER3D_OBJ_NAME).c
WRAPPER3D_OUTPUT_FOLDER=$(WRAPPER3D_OBJ_PATH)/bin
WRAPPER3D_OBJ=$(WRAPPER3D_OUTPUT_FOLDER)/$(WRAPPER3D_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(WRAPPER3D_OBJ): $(WRAPPER3D_INCLUDES) $(WRAPPER3D_SRC) 
	$(CC) $(CFLAGS) -o $(WRAPPER3D_OBJ) $(WRAPPER3D_INCLUDES_PATHS) $(WRAPPER3D_SRC)
