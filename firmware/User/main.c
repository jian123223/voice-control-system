/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Description        : CH32V307 双麦克风 + USB AOA 手机控制
*******************************************************************************/

#include "debug.h"
#include "phone_control.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(2000000);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID());
    Delay_Ms(500);

    Phone_Control_Init();

    while(1) {
        Phone_Control_Poll();
    }
}
