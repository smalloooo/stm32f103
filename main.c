/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "LED.h"
#include "Flash.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define  FLASH_WriteAddress     0x700000
#define  FLASH_ReadAddress      FLASH_WriteAddress
#define  FLASH_SectorToErase    FLASH_WriteAddress

#define  BufferSize (countof(Tx_Buffer)-1)

/* Private macro -------------------------------------------------------------*/
#define countof(a) (sizeof(a) / sizeof(*(a)))

/* Private variables ---------------------------------------------------------*/
__IO uint32_t FlashID = 0;
uint8_t Tx_Buffer[] = "STM32F10x SPI Firmware Library Example: communication with an W25Q64 SPI FLASH";
uint8_t Rx_Buffer[BufferSize];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	LED_Init();
	Flash_Init();
	FlashID = sFLASH_ReadID();
	
	if(FlashID == sFLASH_W25Q64_ID)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		//sFLASH_EraseSector(FLASH_SectorToErase);
		sFLASH_EraseBulk();
		
		sFLASH_WriteBuffer(Tx_Buffer, FLASH_WriteAddress, BufferSize);
		
		sFLASH_ReadBuffer(Rx_Buffer, FLASH_ReadAddress, BufferSize);
		
		sFLASH_EraseSector(FLASH_SectorToErase);
		
		sFLASH_ReadBuffer(Rx_Buffer, FLASH_ReadAddress, BufferSize);
		
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	}
	
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
