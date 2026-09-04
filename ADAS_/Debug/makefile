################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/timer1/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Ultrasonic/subdir.mk
-include HAL/Motor/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Buzzer/subdir.mk
-include HAL/Button/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ADAS_.lss \

FLASH_IMAGE += \
ADAS_.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADAS_.elf secondary-outputs

# Tool invocations
ADAS_.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADAS_.map -mmcu=atmega32 -o "ADAS_.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADAS_.lss: ADAS_.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADAS_.elf  >"ADAS_.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADAS_.hex: ADAS_.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ADAS_.elf  "ADAS_.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADAS_.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ADAS_.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ADAS_.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
