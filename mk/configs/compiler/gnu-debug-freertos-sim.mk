HOST = $(shell uname -s)
ifeq ("$(HOST)","Darwin")
include $(BUILD_ROOT)/mk/configs/compiler/darwin_llvm_common.mk
endif
ifeq ("$(HOST)","Linux")
include $(BUILD_ROOT)/mk/configs/compiler/linux_gnu_common.mk
endif
include $(BUILD_ROOT)/mk/configs/compiler/include_common.mk
include $(BUILD_ROOT)/mk/configs/compiler/freertos_sim_common.mk

ifeq ("$(HOST)","Darwin")
    CFLAGS :=   $(DEBUG) \
                $(DARWIN_LLVM_CFLAGS) \
                $(DARWIN_LLVM_INCLUDES) \
                $(FREERTOS_SIM_FLAGS_COMMON) \
                $(FREERTOS_SIM_INCLUDES_COMMON)

    CXXFLAGS := $(DEBUG) \
                $(DARWIN_LLVM_CXXFLAGS) \
                $(DARWIN_LLVM_INCLUDES) \
                $(FREERTOS_SIM_FLAGS_COMMON) \
                $(FREERTOS_SIM_INCLUDES_COMMON)
                -fno-rtti
endif

ifeq ("$(HOST)","Linux")
    CFLAGS :=   $(DEBUG) \
                $(LINUX_GNU_CFLAGS) \
                $(LINUX_GNU_INCLUDES) \
                $(FREERTOS_SIM_FLAGS_COMMON) \
                $(FREERTOS_SIM_INCLUDES_COMMON)

    CXXFLAGS := $(DEBUG) \
                $(LINUX_GNU_CXXFLAGS) \
                $(LINUX_GNU_INCLUDES) \
                $(FREERTOS_SIM_FLAGS_COMMON) \
                $(FREERTOS_SIM_INCLUDES_COMMON)
endif

COMPILER := freertos-sim-debug-gnu
