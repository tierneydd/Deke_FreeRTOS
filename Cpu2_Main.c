/**********************************************************************************************************************
 * \file Cpu2_Main.c
 * Solstar Space
 * 
 * CPU 2 is used to host the Ethernet connection to the Skylink to the Iridium satelliet
 * 
 * Version 1.0 - December 17, 2023
 *      - Author: Daniel Tierney
 *      - Baseline Version
 * 
 * Platform: AURIX TC375 lite Kit, KIT_A2G_TC375_LITE, TC37xTP_A-Step
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

extern IfxCpu_syncEvent g_cpuSyncEvent;

void core2_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG2 IS DISABLED HERE!!
     * Enable the watchdog and service it periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    while(1)
    {
    }
}
