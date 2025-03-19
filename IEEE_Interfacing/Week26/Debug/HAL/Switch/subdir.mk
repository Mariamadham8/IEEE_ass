################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Switch/switch_config.c \
../HAL/Switch/switch_prog.c 

OBJS += \
./HAL/Switch/switch_config.o \
./HAL/Switch/switch_prog.o 

C_DEPS += \
./HAL/Switch/switch_config.d \
./HAL/Switch/switch_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Switch/%.o: ../HAL/Switch/%.c HAL/Switch/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


