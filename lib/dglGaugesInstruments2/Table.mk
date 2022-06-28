#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
TABLE_OBJ_NAME=Table
# component name
TABLE_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME)
# include and source paths - no need to change
TABLE_OBJ_INCLUDE_PATH=$(TABLE_OBJ_PATH)/include
TABLE_OBJ_SRC_PATH=$(TABLE_OBJ_PATH)/src

# used includes
TABLE_INCLUDES_PATHS=$(sort	-I$(TABLE_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(LABEL_INCLUDES_PATHS))

TABLE_INCLUDES=$(sort	$(TABLE_OBJ_INCLUDE_PATH)/GGI2_$(TABLE_OBJ_NAME).h \
									$(TABLE_OBJ_PATH)/$(TABLE_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(LABEL_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
TABLE_SRC=$(TABLE_OBJ_SRC_PATH)/$(TABLE_OBJ_NAME).c
TABLE_OUTPUT_FOLDER=$(TABLE_OBJ_PATH)/bin
TABLE_OBJ=$(TABLE_OUTPUT_FOLDER)/$(TABLE_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(TABLE_OBJ): $(TABLE_INCLUDES) $(TABLE_SRC) 
	$(CC) $(CFLAGS) -o $(TABLE_OBJ) $(TABLE_INCLUDES_PATHS) $(TABLE_SRC)
