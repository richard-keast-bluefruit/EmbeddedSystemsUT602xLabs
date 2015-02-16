#This file is generated by VisualGDB.
#It contains GCC settings automatically derived from the board support package (BSP).
#DO NOT EDIT MANUALLY. THE FILE WILL BE OVERWRITTEN. 
#Use VisualGDB Project Properties dialog or modify Makefile or per-configuration .mak files instead.

#VisualGDB provides BSP_ROOT and TOOLCHAIN_ROOT via environment when running Make. The line below will only be active if GNU Make is started manually.
BSP_ROOT ?= C:/ti/GNUarm4.9
TOOLCHAIN_ROOT ?= C:/ti/GNUarm4.9

#Embedded toolchain
CC := $(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc.exe
CXX := $(TOOLCHAIN_ROOT)/bin/arm-none-eabi-g++.exe
LD := $(CXX)
AR := $(TOOLCHAIN_ROOT)/bin/arm-none-eabi-ar.exe
OBJCOPY := $(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objcopy.exe

#Additional flags
PREPROCESSOR_MACROS += 
INCLUDE_DIRS += C:/ti/EdXEmbeddedSystems/Source C:/ti/EdXEmbeddedSystems/Lab4_IO
LIBRARY_DIRS += 
LIBRARY_NAMES += 
ADDITIONAL_LINKER_INPUTS += 
MACOS_FRAMEWORKS += 
LINUX_PACKAGES += 

CFLAGS += -g -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16  -std=c++11 -specs=nosys.specs
CXXFLAGS += -g -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16  -std=c++11 -specs=nosys.specs
ASFLAGS += -g -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16  -std=c++11 -specs=nosys.specs
LDFLAGS += -g -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c++11 -specs=nosys.specs -TC:/ti/EdXEmbeddedSystems/EdXEmbeddedSystems/blinky.ld
COMMONFLAGS += 

