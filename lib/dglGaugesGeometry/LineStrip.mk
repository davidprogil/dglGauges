#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
LINESTRIP_OBJ_NAME=LineStrip
# component name
LINESTRIP_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESGEOMETRY_COMPONENT_NAME)
# include and source paths - no need to change
LINESTRIP_OBJ_INCLUDE_PATH=$(LINESTRIP_OBJ_PATH)/include
LINESTRIP_OBJ_SRC_PATH=$(LINESTRIP_OBJ_PATH)/src

# used includes
LINESTRIP_INCLUDES_PATHS=$(sort	-I$(LINESTRIP_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

LINESTRIP_INCLUDES=$(sort	$(LINESTRIP_OBJ_INCLUDE_PATH)/$(LINESTRIP_OBJ_NAME).h \
									$(LINESTRIP_OBJ_PATH)/$(LINESTRIP_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
LINESTRIP_SRC=$(LINESTRIP_OBJ_SRC_PATH)/$(LINESTRIP_OBJ_NAME).c
LINESTRIP_OUTPUT_FOLDER=$(LINESTRIP_OBJ_PATH)/bin
LINESTRIP_OBJ=$(LINESTRIP_OUTPUT_FOLDER)/$(LINESTRIP_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(LINESTRIP_OBJ): $(LINESTRIP_INCLUDES) $(LINESTRIP_SRC) 
	$(CC) $(CFLAGS) -o $(LINESTRIP_OBJ) $(LINESTRIP_INCLUDES_PATHS) $(LINESTRIP_SRC)
