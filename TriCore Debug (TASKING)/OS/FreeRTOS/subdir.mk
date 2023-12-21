################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/FreeRTOS/croutine.c \
../OS/FreeRTOS/event_groups.c \
../OS/FreeRTOS/list.c \
../OS/FreeRTOS/queue.c \
../OS/FreeRTOS/stream_buffer.c \
../OS/FreeRTOS/tasks.c \
../OS/FreeRTOS/timers.c 

COMPILED_SRCS += \
./OS/FreeRTOS/croutine.src \
./OS/FreeRTOS/event_groups.src \
./OS/FreeRTOS/list.src \
./OS/FreeRTOS/queue.src \
./OS/FreeRTOS/stream_buffer.src \
./OS/FreeRTOS/tasks.src \
./OS/FreeRTOS/timers.src 

C_DEPS += \
./OS/FreeRTOS/croutine.d \
./OS/FreeRTOS/event_groups.d \
./OS/FreeRTOS/list.d \
./OS/FreeRTOS/queue.d \
./OS/FreeRTOS/stream_buffer.d \
./OS/FreeRTOS/tasks.d \
./OS/FreeRTOS/timers.d 

OBJS += \
./OS/FreeRTOS/croutine.o \
./OS/FreeRTOS/event_groups.o \
./OS/FreeRTOS/list.o \
./OS/FreeRTOS/queue.o \
./OS/FreeRTOS/stream_buffer.o \
./OS/FreeRTOS/tasks.o \
./OS/FreeRTOS/timers.o 


# Each subdirectory must supply rules for building sources it contributes
OS/FreeRTOS/%.src: ../OS/FreeRTOS/%.c OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/tiern/AURIX-v1.9.20-workspace/Deke_FreeRTOS/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/OS\/FreeRTOS\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/croutine.o: ./OS/FreeRTOS/croutine.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/event_groups.o: ./OS/FreeRTOS/event_groups.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/list.o: ./OS/FreeRTOS/list.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/queue.o: ./OS/FreeRTOS/queue.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/stream_buffer.o: ./OS/FreeRTOS/stream_buffer.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/tasks.o: ./OS/FreeRTOS/tasks.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/timers.o: ./OS/FreeRTOS/timers.src OS/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-OS-2f-FreeRTOS

clean-OS-2f-FreeRTOS:
	-$(RM) ./OS/FreeRTOS/croutine.d ./OS/FreeRTOS/croutine.o ./OS/FreeRTOS/croutine.src ./OS/FreeRTOS/event_groups.d ./OS/FreeRTOS/event_groups.o ./OS/FreeRTOS/event_groups.src ./OS/FreeRTOS/list.d ./OS/FreeRTOS/list.o ./OS/FreeRTOS/list.src ./OS/FreeRTOS/queue.d ./OS/FreeRTOS/queue.o ./OS/FreeRTOS/queue.src ./OS/FreeRTOS/stream_buffer.d ./OS/FreeRTOS/stream_buffer.o ./OS/FreeRTOS/stream_buffer.src ./OS/FreeRTOS/tasks.d ./OS/FreeRTOS/tasks.o ./OS/FreeRTOS/tasks.src ./OS/FreeRTOS/timers.d ./OS/FreeRTOS/timers.o ./OS/FreeRTOS/timers.src

.PHONY: clean-OS-2f-FreeRTOS

