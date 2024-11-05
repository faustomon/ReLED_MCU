################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/3-firmware/systick/subdir.mk
-include src/3-firmware/subdir.mk
-include src/2-aplicacion/subdir.mk
-include src/1-modulos/12-USART/subdir.mk
-include src/1-modulos/10-lcd/subdir.mk
-include src/1-modulos/09-teclado/subdir.mk
-include src/1-modulos/08-display_de_segmentos/09C-display/subdir.mk
-include src/1-modulos/08-display_de_segmentos/09B-segmentos/subdir.mk
-include src/1-modulos/08-display_de_segmentos/09A-barrido/subdir.mk
-include src/1-modulos/07-leds/subdir.mk
-include src/1-modulos/06-PerifericosTemporizados/subdir.mk
-include src/1-modulos/05-SalidasDigitales/subdir.mk
-include src/1-modulos/04-EntradasDigitales/subdir.mk
-include src/1-modulos/03-timer/subdir.mk
-include src/1-modulos/02-gpio/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := UART
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: UART.axf

# Tool invocations
UART.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -Xlinker -Map="UART.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T UART_Debug.ld -o "UART.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) UART.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "UART.axf"; # arm-none-eabi-objcopy -v -O binary "UART.axf" "UART.bin" ; # checksum -p LPC845 -d "UART.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
