################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/1-modulos/10-lcd/Lcd.cpp 

CPP_DEPS += \
./src/1-modulos/10-lcd/Lcd.d 

OBJS += \
./src/1-modulos/10-lcd/Lcd.o 


# Each subdirectory must supply rules for building sources it contributes
src/1-modulos/10-lcd/%.o: ../src/1-modulos/10-lcd/%.cpp src/1-modulos/10-lcd/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\01-pin\in" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\01-pin\out" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\02-gpio" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\03-timer" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\04-EntradasDigitales" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\05-SalidasDigitales" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\06-PerifericosTemporizados" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\07-leds" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\2-aplicacion" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\3-firmware" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\3-firmware\systick" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\08-display_de_segmentos\09A-barrido\barrido-interfaz" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\08-display_de_segmentos\09A-barrido" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\08-display_de_segmentos\09B-segmentos\segmentos-interfaz" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\08-display_de_segmentos\09B-segmentos" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\08-display_de_segmentos\09C-display" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\09-teclado" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\10-lcd" -I"C:\Users\faust\Documents\MCUXpressoIDE_11.9.1_2170\workspace\uart.zip_expanded\UART\src\1-modulos\12-USART" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-1-2d-modulos-2f-10-2d-lcd

clean-src-2f-1-2d-modulos-2f-10-2d-lcd:
	-$(RM) ./src/1-modulos/10-lcd/Lcd.d ./src/1-modulos/10-lcd/Lcd.o

.PHONY: clean-src-2f-1-2d-modulos-2f-10-2d-lcd

