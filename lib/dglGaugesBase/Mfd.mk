#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
MFD_OBJ_NAME=Mfd
# component name
MFD_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESBASE_COMPONENT_NAME)
# include and source paths - no need to change
MFD_OBJ_INCLUDE_PATH=$(MFD_OBJ_PATH)/include
MFD_OBJ_SRC_PATH=$(MFD_OBJ_PATH)/src

# used includes
MFD_INCLUDES_PATHS=$(sort	-I$(MFD_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(PANEL_INCLUDES_PATHS))

MFD_INCLUDES=$(sort	$(MFD_OBJ_INCLUDE_PATH)/$(MFD_OBJ_NAME).h \
									$(MFD_OBJ_PATH)/$(MFD_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(PANEL_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
MFD_SRC=$(MFD_OBJ_SRC_PATH)/$(MFD_OBJ_NAME).c
MFD_OUTPUT_FOLDER=$(MFD_OBJ_PATH)/bin
MFD_OBJ=$(MFD_OUTPUT_FOLDER)/$(MFD_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(MFD_OBJ): $(MFD_INCLUDES) $(MFD_SRC)   
	$(CC) $(CFLAGS) -o $(MFD_OBJ) $(MFD_INCLUDES_PATHS) $(MFD_SRC)
