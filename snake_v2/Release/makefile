################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32G0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
snake_v2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
snake_v2.list \

OBJCOPY_BIN += \
snake_v2.bin \


# All Target
all: snake_v2.elf secondary-outputs

# Tool invocations
snake_v2.elf: $(OBJS) $(USER_OBJS) C:\workspace_STM32CubeIDE\snake_v2\STM32G030K6TX_FLASH.ld
	arm-none-eabi-gcc -o "snake_v2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"C:\workspace_STM32CubeIDE\snake_v2\STM32G030K6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="snake_v2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

snake_v2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "snake_v2.list"
	@echo 'Finished building: $@'
	@echo ' '

snake_v2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "snake_v2.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
