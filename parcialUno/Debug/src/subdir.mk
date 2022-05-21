################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Main.c \
../src/Menu.c \
../src/Operaciones.c \
../src/Producto.c \
../src/Tracking.c \
../src/Usuario.c \
../src/input.c 

C_DEPS += \
./src/Main.d \
./src/Menu.d \
./src/Operaciones.d \
./src/Producto.d \
./src/Tracking.d \
./src/Usuario.d \
./src/input.d 

OBJS += \
./src/Main.o \
./src/Menu.o \
./src/Operaciones.o \
./src/Producto.o \
./src/Tracking.o \
./src/Usuario.o \
./src/input.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Main.d ./src/Main.o ./src/Menu.d ./src/Menu.o ./src/Operaciones.d ./src/Operaciones.o ./src/Producto.d ./src/Producto.o ./src/Tracking.d ./src/Tracking.o ./src/Usuario.d ./src/Usuario.o ./src/input.d ./src/input.o

.PHONY: clean-src

