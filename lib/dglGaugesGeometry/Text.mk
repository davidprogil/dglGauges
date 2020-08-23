#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
TEXT_OBJ_NAME=Text
# component name
TEXT_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
TEXT_OBJ_INCLUDE_PATH=$(TEXT_OBJ_PATH)/include
TEXT_OBJ_SRC_PATH=$(TEXT_OBJ_PATH)/src

# used includes
TEXT_INCLUDES_PATHS=$(sort	-I$(TEXT_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

TEXT_INCLUDES=$(sort	$(TEXT_OBJ_INCLUDE_PATH)/$(TEXT_OBJ_NAME).h \
									$(TEXT_OBJ_PATH)/$(TEXT_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
TEXT_SRC=$(TEXT_OBJ_SRC_PATH)/$(TEXT_OBJ_NAME).c
TEXT_OUTPUT_FOLDER=$(TEXT_OBJ_PATH)/bin
TEXT_OBJ=$(TEXT_OUTPUT_FOLDER)/$(TEXT_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(TEXT_OBJ): $(TEXT_INCLUDES) $(TEXT_SRC) 
	$(CC) $(CFLAGS) -o $(TEXT_OBJ) $(TEXT_INCLUDES_PATHS) $(TEXT_SRC)
