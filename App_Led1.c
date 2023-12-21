/**********************************************************************************************************************
 * \file App_Led1.c
 *
 * Solstar Space
 *
 * Purpose:
 *
 * Blink LED 1
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Port/Io/IfxPort_Io.h"

#include "App_Config.h"
#include "FreeRTOS.h"
#include "task.h"

/*********************************************************************************************************************/
/*-----------------------------------------------------Macros--------------------------------------------------------*/
/*********************************************************************************************************************/
#define LED1_BLINKY_PERIOD_MS (125)                         /* The period (in milliseconds) at which LED1 will blink */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Initialization function for LED1 app */
static void app_init(void)
{
    /* Setup the port/pin connected to LED1 to general output mode push-pull. This function can be
     * used to initialize any port pin by specifying the port number, pin number and port pin mode.
     */
    IfxPort_setPinMode(LED_1.port, LED_1.pinIndex, IfxPort_Mode_outputPushPullGeneral);
    IfxPort_setPinMode(LED_2.port, LED_2.pinIndex, IfxPort_Mode_outputPushPullGeneral);
}

/* Task which runs the LED1 app */
void task_app_led1(void *arg)
{
    app_init();

    while (1)
    {
        /* Toggle LED1 state */
        IfxPort_setPinState(LED_1.port, LED_1.pinIndex, IfxPort_State_toggled);

        /* Delay 250ms */
        vTaskDelay(pdMS_TO_TICKS(LED1_BLINKY_PERIOD_MS));

        IfxPort_setPinState(LED_2.port, LED_2.pinIndex, IfxPort_State_toggled);

        /* Delay 250ms */
        vTaskDelay(pdMS_TO_TICKS(LED1_BLINKY_PERIOD_MS));
    }
}
