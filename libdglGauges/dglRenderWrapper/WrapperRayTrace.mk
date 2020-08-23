#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
WRAPPERRAYTRACE_OBJ_NAME=WrapperRayTrace
# component name
WRAPPERRAYTRACE_OBJ_PATH=$(PROJECT_PATH)/libdglGauges/$(DGLRENDERWRAPPER_COMPONENT_NAME)
# include and source paths - no need to change
WRAPPERRAYTRACE_OBJ_INCLUDE_PATH=$(WRAPPERRAYTRACE_OBJ_PATH)/include
WRAPPERRAYTRACE_OBJ_SRC_PATH=$(WRAPPERRAYTRACE_OBJ_PATH)/src

# used includes
WRAPPERRAYTRACE_INCLUDES_PATHS=$(sort	-I$(WRAPPERRAYTRACE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

WRAPPERRAYTRACE_INCLUDES=$(sort	$(WRAPPERRAYTRACE_OBJ_INCLUDE_PATH)/$(WRAPPERRAYTRACE_OBJ_NAME).h \
									$(WRAPPERRAYTRACE_OBJ_PATH)/$(WRAPPERRAYTRACE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
WRAPPERRAYTRACE_SRC=$(WRAPPERRAYTRACE_OBJ_SRC_PATH)/$(WRAPPERRAYTRACE_OBJ_NAME).c
WRAPPERRAYTRACE_OUTPUT_FOLDER=$(WRAPPERRAYTRACE_OBJ_PATH)/bin
WRAPPERRAYTRACE_OBJ=$(WRAPPERRAYTRACE_OUTPUT_FOLDER)/$(WRAPPERRAYTRACE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(WRAPPERRAYTRACE_OBJ): $(WRAPPERRAYTRACE_INCLUDES) $(WRAPPERRAYTRACE_SRC) 
	$(CC) $(CFLAGS) -o $(WRAPPERRAYTRACE_OBJ) $(WRAPPERRAYTRACE_INCLUDES_PATHS) $(WRAPPERRAYTRACE_SRC)
