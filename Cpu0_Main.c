/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * Solstar Space
 * 
 * Purpose:
 *
 * CPU 0 is used to host the MQTT - Message Que Telemetry Transpport Broker
 *
 * Task Naming:
 *  vTaskPrioritySet() returns a void
 *  xQueueReceive() returns a variable
 *  pvTimerGetTimerID() returns a pointer to void
 *  prvPrivateFunction()private functions are prefixed with ‘prv’.
 *
 * Version 1.0 - December 17, 2023
 *      - Author: Daniel Tierney
 *      - Baseline Version
 * 
 * Platform: AURIX TC375 lite Kit, KIT_A2G_TC375_LITE, TC37xTP_A-Step
 *********************************************************************************************************************/
#include "IfxCpu.h"
#include "IfxScuWdt.h"

#include "App_Config.h"
#include "FreeRTOS.h"
#include "task.h"

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

    //IfxScuWdt_enableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    //IfxScuWdt_enableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    /********************* Create Deke Tasks Here **********************************/
    /*xTaskCreate( vTask1, * Pointer to the function that implements the task
     *     "Task 1",       * Text name for the task. This is to facilitate debugging only
     *      stack size,    * Stack depth - small microcontrollers will use much less stack than this
     *      parameter,     * task parameter
     *      priority,      * This task will run at priority 1
     *      task handle)   * Task Handle
     *******************************************************************************/

    /* Create LED1 app task */
    xTaskCreate(task_app_led1, "APP LED1", configMINIMAL_STACK_SIZE, NULL, 0, NULL);

    /* Create LED2 app task */
    xTaskCreate(task_app_led2, "APP LED2", configMINIMAL_STACK_SIZE, NULL, 0, NULL);

    /********************** End of Deke Tasks **************************************/

    /* Start the scheduler */
    vTaskStartScheduler();
    
    /* Required for FreeRTOS infinite loop */
    while (1)
    {
    }
}

/* Required FreeRTOS callback, called in case of a stack overflow.
 * For the sake of simplicity, this function will loop indefinitely
 * and the root cause can be confirmed by using a debugger
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    while (1)
    {
        __nop();
    }
}
