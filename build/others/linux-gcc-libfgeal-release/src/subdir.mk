################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/actor.cpp \
../src/animation.cpp \
../src/block.cpp \
../src/entity.cpp \
../src/ingame_state.cpp \
../src/inventory.cpp \
../src/loading_state.cpp \
../src/main.cpp \
../src/main_menu_state.cpp \
../src/map.cpp \
../src/map_io.cpp \
../src/options_menu_state.cpp \
../src/physics.cpp \
../src/physics_box2d.cpp \
../src/physics_chipmunk.cpp \
../src/terrarium_game.cpp \
../src/terrarium_game_logic.cpp 

OBJS += \
./src/actor.o \
./src/animation.o \
./src/block.o \
./src/entity.o \
./src/ingame_state.o \
./src/inventory.o \
./src/loading_state.o \
./src/main.o \
./src/main_menu_state.o \
./src/map.o \
./src/map_io.o \
./src/options_menu_state.o \
./src/physics.o \
./src/physics_box2d.o \
./src/physics_chipmunk.o \
./src/terrarium_game.o \
./src/terrarium_game_logic.o 

CPP_DEPS += \
./src/actor.d \
./src/animation.d \
./src/block.d \
./src/entity.d \
./src/ingame_state.d \
./src/inventory.d \
./src/loading_state.d \
./src/main.d \
./src/main_menu_state.d \
./src/map.d \
./src/map_io.d \
./src/options_menu_state.d \
./src/physics.d \
./src/physics_box2d.d \
./src/physics_chipmunk.d \
./src/terrarium_game.d \
./src/terrarium_game_logic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"BUILD_PATH/src" -I"BUILD_PATH/src_libs" -I"FGEAL_INCLUDE_PATH" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


