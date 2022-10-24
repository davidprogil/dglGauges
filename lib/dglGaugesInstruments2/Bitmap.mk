#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
BITMAP_OBJ_NAME=Bitmap
# component name
BITMAP_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGLGAUGESINSTRUMENTS2_COMPONENT_NAME)
# include and source paths - no need to change
BITMAP_OBJ_INCLUDE_PATH=$(BITMAP_OBJ_PATH)/include
BITMAP_OBJ_SRC_PATH=$(BITMAP_OBJ_PATH)/src

# used includes
BITMAP_INCLUDES_PATHS=$(sort	-I$(BITMAP_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(LABEL_INCLUDES_PATHS))

BITMAP_INCLUDES=$(sort	$(BITMAP_OBJ_INCLUDE_PATH)/GGI2_$(BITMAP_OBJ_NAME).h \
									$(BITMAP_OBJ_PATH)/$(BITMAP_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(LABEL_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
BITMAP_SRC=$(BITMAP_OBJ_SRC_PATH)/$(BITMAP_OBJ_NAME).c
BITMAP_OUTPUT_FOLDER=$(BITMAP_OBJ_PATH)/bin
BITMAP_OBJ=$(BITMAP_OUTPUT_FOLDER)/$(BITMAP_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(BITMAP_OBJ): $(BITMAP_INCLUDES) $(BITMAP_SRC) 
	$(CC) $(CFLAGS) -o $(BITMAP_OBJ) $(BITMAP_INCLUDES_PATHS) $(BITMAP_SRC)
