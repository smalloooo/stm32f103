#include "stm32f10x.h"

#define sFLASH_CS_GPIO_PORT   GPIOB
#define sFLASH_CS_PIN         GPIO_Pin_6

#define sFLASH_SPI_SCK_PIN    GPIO_Pin_5
#define sFLASH_SPI_MISO_PIN   GPIO_Pin_6
#define sFLASH_SPI_MOSI_PIN   GPIO_Pin_7

#define sFLASH_SPI   SPI1

#define sFLASH_CS_LOW()       GPIO_ResetBits(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN)
#define sFLASH_CS_HIGH()      GPIO_SetBits(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN)   

#define sFLASH_DUMMY_BYTE         0xA5

#define sFLASH_W25Q64_ID          0xEF4017

#define sFLASH_SPI_PAGESIZE       0x100

#define W25Q64_WriteEnable		  0x06 
#define W25Q64_WriteDisable		  0x04 
#define W25Q64_ReadStatusReg	  0x05 
#define W25Q64_ReadData				  0x03 
#define W25Q64_FastReadData		  0x0B 
#define W25Q64_PageProgram		  0x02 
#define W25Q64_BlockErase			  0xD8 
#define W25Q64_SectorErase		  0x20 
#define W25Q64_PowerDown			  0xB9 
#define W25Q64_ReleasePowerDown	0xAB 
#define W25Q64_ChipErase     	  0xC7 
#define W25Q64_JedecDeviceID		0x9F

#define W25Q64_WriteStatusReg   0x01




void Flash_Init(void);
uint32_t sFLASH_ReadID(void);
uint8_t sFLASH_SendByte(uint8_t byte);

void sFLASH_EraseBulk(void);
void sFLASH_EraseSector(uint32_t SectorAddr);
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);

void sFLASH_WriteEnable(void);
void sFLASH_WaitForWriteEnd(void);

