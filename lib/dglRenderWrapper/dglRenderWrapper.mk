#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

DGLRENDERWRAPPER_COMPONENT_NAME=dglRenderWrapper
DGLRENDERWRAPPER_COMPONENT_FOLDER=$(PROJECT_PATH)/lib/$(DGLRENDERWRAPPER_COMPONENT_NAME)
DGLRENDERWRAPPER_COMPONENT_OUTPUT_FOLDER=$(DGLRENDERWRAPPER_COMPONENT_FOLDER)/bin

$(DGLRENDERWRAPPER_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(DGLRENDERWRAPPER_COMPONENT_FOLDER)/Wrapper2D.mk
include $(DGLRENDERWRAPPER_COMPONENT_FOLDER)/Wrapper3D.mk
include $(DGLRENDERWRAPPER_COMPONENT_FOLDER)/WrapperRayTrace.mk

DGLRENDERWRAPPER_COMPONENT_INCLUDES_PATHS= \
						$(WRAPPER2D_INCLUDES_PATHS) \
						$(WRAPPER3D_INCLUDES_PATHS) \
						$(WRAPPERRAYTRACE_INCLUDES_PATHS) \


DGLRENDERWRAPPER_COMPONENT_INCLUDES=	$(DGLRENDERWRAPPER_COMPONENT_FOLDER)/$(DGLRENDERWRAPPER_COMPONENT_NAME).mk \
						$(WRAPPER2D_INCLUDES) \
						$(WRAPPER3D_INCLUDES) \
						$(WRAPPERRAYTRACE_INCLUDES) \


DGLRENDERWRAPPER_COMPONENT_OBJ= \
						$(WRAPPER2D_OBJ) \
						$(WRAPPER3D_OBJ) \
						$(WRAPPERRAYTRACE_OBJ) \

