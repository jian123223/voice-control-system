#ifndef __CONFIG_H
#define __CONFIG_H

#include "ch32v30x.h"
#include "hal_gpio.h"

/*============================================================================
 * Board Version Selection
 *============================================================================*/
#if !defined(BOARD_V1) && !defined(BOARD_V2)
#define BOARD_V1
#endif

/*============================================================================
 * I2S2 INMP441 麦克风A (板无关, V307 官方引脚)
 *   WS=PB12(AF5)  CK=PB13(AF5)  SD=PB15(AF5)
 *   SPI2_RX -> DMA1_Channel4
 *============================================================================*/
#define I2S2_WS_PIN_ENC        HAL_GPIO_PIN(1, 12)
#define I2S2_CK_PIN_ENC        HAL_GPIO_PIN(1, 13)
#define I2S2_SD_PIN_ENC        HAL_GPIO_PIN(1, 15)
#define I2S2_GPIO_AF           0
#define I2S2_SPI_INSTANCE      SPI2
#define I2S2_DMA_CHANNEL       DMA1_Channel4
#define I2S2_DMA_FLAG_TC       DMA1_FLAG_TC4
#define I2S2_DMA_FLAG_HT       DMA1_FLAG_HT4
#define I2S2_DMA_IRQn          DMA1_Channel4_IRQn

/*============================================================================
 * I2S3 INMP441 麦克风B (板无关, V307 官方引脚)
 *   WS=PA15(AF6)  CK=PB3(AF6)  SD=PB5(AF6)
 *   需禁用JTAG保留SWD, 释放PA15/PB3
 *   SPI3_RX -> DMA2_Channel1
 *============================================================================*/
#define I2S3_WS_PIN_ENC        HAL_GPIO_PIN(0, 15)
#define I2S3_CK_PIN_ENC        HAL_GPIO_PIN(1, 3)
#define I2S3_SD_PIN_ENC        HAL_GPIO_PIN(1, 5)
#define I2S3_GPIO_AF           0
#define I2S3_SPI_INSTANCE      SPI3
#define I2S3_DMA_CHANNEL       DMA2_Channel1
#define I2S3_DMA_FLAG_TC       DMA2_FLAG_TC1
#define I2S3_DMA_FLAG_HT       DMA2_FLAG_HT1
#define I2S3_DMA_IRQn          DMA2_Channel1_IRQn

/*============================================================================
 * OLED SSD1306 128x64 (硬件SPI1)
 *   CS=PB0  RES=PC4  DC=PC5  SCK=PA5(SPI1)  MOSI=PA7(SPI1)
 *============================================================================*/
#define OLED_CS_PIN_ENC    HAL_GPIO_PIN(1, 0)
#define OLED_RES_PIN_ENC   HAL_GPIO_PIN(2, 4)
#define OLED_DC_PIN_ENC    HAL_GPIO_PIN(2, 5)
#define OLED_SCK_PIN_ENC   HAL_GPIO_PIN(0, 5)
#define OLED_MOSI_PIN_ENC  HAL_GPIO_PIN(0, 7)

#define OLED_SPI_INSTANCE   SPI1

/*============================================================================
 * Common helper functions (board-independent)
 *============================================================================*/
void SPI_ClockEnable(SPI_TypeDef *SPIx);
void DMA_ClockEnable(DMA_TypeDef *DMAx);
void AFIO_ClockEnable(void);

#endif /* __CONFIG_H */