#include "stm32f4xx_it.h"
#include <stdio.h>

#define ERR_INFO "\r\nEnter HardFault_Handler, System Halt.\r\n"

/*
*********************************************************************************************************
*	Cortex-M3 内核异常中断服务程序
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*	函 数 名: NMI_Handler
*	功能说明: 不可屏蔽中断服务程序。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void NMI_Handler(void)
{
}


__asm void wait()
{
      BX lr
}

/*
*********************************************************************************************************
*	函 数 名: HardFault_Handler
*	功能说明: 硬件故障中断服务程序。其他异常处理被关闭，而又发生了异常，则触发。
*			  执行异常处理时，发生了异常，则触发。复位时默认使能。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void HardFault_Handler(void)
{
	wait();
#if 0
  const char *pError = ERR_INFO;
  uint8_t i;

  for (i = 0; i < sizeof(ERR_INFO); i++)
  {
     USART1->DR = pError[i];
     /* 等待发送结束 */
     while ((USART1->SR & USART_FLAG_TC) == (uint16_t)RESET);
  }
	
	bsp_SetPWMDutyCycle(0,1);
	bsp_SetPWMDutyCycle(0,2);
	bsp_SetPWMDutyCycle(0,3);
	bsp_SetPWMDutyCycle(0,4);
	
	//__asm out dx, al
#endif

  /* 当硬件失效异常发生时进入死循环 */
  while (1)
  {
  }
}

/*
*********************************************************************************************************
*	函 数 名: MemManage_Handler
*	功能说明: 内存管理异常中断服务程序。违反MPU设定的存储器访问规则时触发。 复位时默认未使能
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void MemManage_Handler(void)
{
  /* 当内存管理异常发生时进入死循环 */
  while (1)
  {
  }
}

/*
*********************************************************************************************************
*	函 数 名: BusFault_Handler
*	功能说明: 总线访问异常中断服务程序。取指令、数据读写、堆栈操作出现异常。 复位时默认未使能
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void BusFault_Handler(void)
{
  /* 当总线异常时进入死循环 */
  while (1)
  {
  }
}

/*
*********************************************************************************************************
*	函 数 名: UsageFault_Handler
*	功能说明: 用法错误中断服务程序。执行未定义指令、非对齐操作、除零时触发。 复位时默认未使能
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void UsageFault_Handler(void)
{
  /* 当用法异常时进入死循环 */
  while (1)
  {
  }
}

/*
*********************************************************************************************************
*	函 数 名: SVC_Handler
*	功能说明: 通过SWI指令的系统服务调用中断服务程序。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void SVC_Handler(void)
{
}

/*
*********************************************************************************************************
*	函 数 名: DebugMon_Handler
*	功能说明: 调试监视器中断服务程序。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void DebugMon_Handler(void)
{
}

/*
*********************************************************************************************************
*	函 数 名: PendSV_Handler
*	功能说明: 可挂起的系统服务调用中断服务程序。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void PendSV_Handler(void)
{
}

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
