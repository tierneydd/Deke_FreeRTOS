################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/FreeRTOS/portable/Tasking/TC3/port.c 

COMPILED_SRCS += \
./OS/FreeRTOS/portable/Tasking/TC3/port.src 

C_DEPS += \
./OS/FreeRTOS/portable/Tasking/TC3/port.d 

OBJS += \
./OS/FreeRTOS/portable/Tasking/TC3/port.o 


# Each subdirectory must supply rules for building sources it contributes
OS/FreeRTOS/portable/Tasking/TC3/%.src: ../OS/FreeRTOS/portable/Tasking/TC3/%.c OS/FreeRTOS/portable/Tasking/TC3/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/tiern/AURIX-v1.9.20-workspace/Deke_FreeRTOS/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/OS\/FreeRTOS\/portable\/Tasking\/TC3\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

OS/FreeRTOS/portable/Tasking/TC3/port.o: ./OS/FreeRTOS/portable/Tasking/TC3/port.src OS/FreeRTOS/portable/Tasking/TC3/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-OS-2f-FreeRTOS-2f-portable-2f-Tasking-2f-TC3

clean-OS-2f-FreeRTOS-2f-portable-2f-Tasking-2f-TC3:
	-$(RM) ./OS/FreeRTOS/portable/Tasking/TC3/port.d ./OS/FreeRTOS/portable/Tasking/TC3/port.o ./OS/FreeRTOS/portable/Tasking/TC3/port.src

.PHONY: clean-OS-2f-FreeRTOS-2f-portable-2f-Tasking-2f-TC3

