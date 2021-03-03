/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TAS5342_OTW_Pin GPIO_PIN_13
#define TAS5342_OTW_GPIO_Port GPIOC
#define TAS5342_SD_Pin GPIO_PIN_14
#define TAS5342_SD_GPIO_Port GPIOC
#define TAS5342_RST_AB_Pin GPIO_PIN_15
#define TAS5342_RST_AB_GPIO_Port GPIOC
#define TAS5342_RST_CD_Pin GPIO_PIN_0
#define TAS5342_RST_CD_GPIO_Port GPIOF
#define OE_CLK_MULT_Pin GPIO_PIN_1
#define OE_CLK_MULT_GPIO_Port GPIOF
#define TEMP_TAS_Pin GPIO_PIN_0
#define TEMP_TAS_GPIO_Port GPIOA
#define TEMP_BRIDGE_Pin GPIO_PIN_1
#define TEMP_BRIDGE_GPIO_Port GPIOA
#define PVDD_Pin GPIO_PIN_2
#define PVDD_GPIO_Port GPIOA
#define VAMP_Pin GPIO_PIN_3
#define VAMP_GPIO_Port GPIOA
#define EN_BRIDGE_Pin GPIO_PIN_1
#define EN_BRIDGE_GPIO_Port GPIOB
#define AX5689_RST_Pin GPIO_PIN_12
#define AX5689_RST_GPIO_Port GPIOB
#define AX5689_MUTE_Pin GPIO_PIN_13
#define AX5689_MUTE_GPIO_Port GPIOB
#define AX5689_PWRDN_Pin GPIO_PIN_14
#define AX5689_PWRDN_GPIO_Port GPIOB
#define AX5689_STATUS_Pin GPIO_PIN_15
#define AX5689_STATUS_GPIO_Port GPIOB
#define DEBUG_0_Pin GPIO_PIN_11
#define DEBUG_0_GPIO_Port GPIOA
#define DEBUG_1_Pin GPIO_PIN_12
#define DEBUG_1_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
