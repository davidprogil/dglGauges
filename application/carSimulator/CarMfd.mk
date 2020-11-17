#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
CARMFD_OBJ_NAME=CarMfd
# component name
CARMFD_OBJ_PATH=$(PROJECT_PATH)/application/$(CARSIMULATOR_COMPONENT_NAME)
# include and source paths - no need to change
CARMFD_OBJ_INCLUDE_PATH=$(CARMFD_OBJ_PATH)/include
CARMFD_OBJ_SRC_PATH=$(CARMFD_OBJ_PATH)/src

# used includes
CARMFD_INCLUDES_PATHS=$(sort	-I$(CARMFD_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(MFD_INCLUDES_PATHS)\
									$(DGLGAUGESINSTRUMENTS1_COMPONENT_INCLUDES_PATHS)\
									$(DGLGAUGESINSTRUMENTS2_COMPONENT_INCLUDES_PATHS))

CARMFD_INCLUDES=$(sort	$(CARMFD_OBJ_INCLUDE_PATH)/$(CARMFD_OBJ_NAME).h \
									$(CARMFD_OBJ_PATH)/$(CARMFD_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(MFD_INCLUDES)\
									$(DGLGAUGESINSTRUMENTS1_COMPONENT_INCLUDES)\
									$(DGLGAUGESINSTRUMENTS2_COMPONENT_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
CARMFD_SRC=$(CARMFD_OBJ_SRC_PATH)/$(CARMFD_OBJ_NAME).c
CARMFD_OUTPUT_FOLDER=$(CARMFD_OBJ_PATH)/bin
CARMFD_OBJ=$(CARMFD_OUTPUT_FOLDER)/$(CARMFD_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(CARMFD_OBJ): $(CARMFD_INCLUDES) $(CARMFD_SRC) 
	$(CC) $(CFLAGS) -o $(CARMFD_OBJ) $(CARMFD_INCLUDES_PATHS) $(CARMFD_SRC)
