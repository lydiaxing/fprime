include $(BUILD_ROOT)/mk/configs/compiler/cygwin_gnu_common.mk
include $(BUILD_ROOT)/mk/configs/compiler/include_common.mk
include $(BUILD_ROOT)/mk/configs/compiler/ut_flags.mk

CFLAGS := 	$(DEBUG) \
			$(LINUX_GNU_CFLAGS) \
			$(LINUX_GNU_INCLUDES)

CXXFLAGS := $(DEBUG) \
			$(LINUX_GNU_CXXFLAGS) \
			$(LINUX_GNU_INCLUDES) \
			-fno-rtti

COMPILER := cygwin-x86-debug-gnu
