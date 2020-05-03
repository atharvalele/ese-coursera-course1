#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

CSTD = c99
CFLAGS = -Wall -Werror -g -O0 -std=$(CSTD)

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
CC = gcc
LD = ld
OBJDUMP = objdump
PLATFORM_FLAGS := -DHOST
else
ifeq ($(PLATFORM), MSP432)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump
LINKER_FILE = ../msp432p401r.lds
LDFLAGS  = -Wl,-T $(LINKER_FILE)
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
PLATFORM_FLAGS := -m$(ARCH) \
				  -march=armv7e-m \
				  -mcpu=$(CPU) \
				  -mfloat-abi=hard \
				  -mfpu=fpv4-sp-d16 \
				  --specs=$(SPECS) \
				  -DMSP432
endif
endif

OBJS := $(SOURCES:.c=.o)

# Compile all object files
%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) $(PLATFORM_FLAGS) -o $@

# Compile preprocessed files
%.i : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) $(PLATFORM_FLAGS) -E -o $@

# Compile assembly
%.asm : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) $(PLATFORM_FLAGS) -S -o $@

c1m2.out: $(OBJS)
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) $(PLATFORM_FLAGS) -o $@ $(OBJS)

c1m2.asm: c1m2.out
	$(OBJDUMP) -d c1m2.out > c1m2.asm

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) -c $< $(CFLAGS) $(PLATFORM_FLAGS) -o $@

.PHONY: build
build: c1m2.out

.PHONY: clean
clean:
	rm -f *.asm *.i *.o c1m2.out