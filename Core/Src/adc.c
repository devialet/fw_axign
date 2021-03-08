/**
  ******************************************************************************
  * File Name          : ADC.c
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
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

/* Includes ------------------------------------------------------------------*/
#include "adc.h"

/* USER CODE BEGIN 0 */
#include "usart.h"
/* USER CODE END 0 */

ADC_HandleTypeDef hadc;

/* ADC init function */
void MX_ADC_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = ENABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_2;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_3;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */
    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**ADC GPIO Configuration
    PA0     ------> ADC_IN0
    PA1     ------> ADC_IN1
    PA2     ------> ADC_IN2
    PA3     ------> ADC_IN3
    */
    GPIO_InitStruct.Pin = TEMP_TAS_Pin|TEMP_BRIDGE_Pin|PVDD_Pin|VAMP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();

    /**ADC GPIO Configuration
    PA0     ------> ADC_IN0
    PA1     ------> ADC_IN1
    PA2     ------> ADC_IN2
    PA3     ------> ADC_IN3
    */
    HAL_GPIO_DeInit(GPIOA, TEMP_TAS_Pin|TEMP_BRIDGE_Pin|PVDD_Pin|VAMP_Pin);

  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

#define ADC_VREF            3.3f
#define ADC_V_PER_COUNT     ADC_VREF/4095.0f
#define MCP9700_T_COEFF     100.0f      /*From MCP9700 Spec*/
#define MCP9700_OFFSET      0.5f    /*500mV offset*/

#define RESISTOR_DIV        13
#define VOLT_PER_COUNT      (ADC_VREF*RESISTOR_DIV/4095.0f)

void ADC_read(adc_t adc_index) {
	uint32_t tmp;
	uint8_t temp;
	uint8_t volt;
	static uint8_t previous_value[4] = {0};

	switch (adc_index) {
	case TEMP_TAS :
	    hadc.Instance->CHSELR = 1<<ADC_CHANNEL_0;
		break;
	case TEMP_BRIDGE :
        hadc.Instance->CHSELR = 1<<ADC_CHANNEL_1;
		break;
	case PVDD :
	    hadc.Instance->CHSELR = 1<<ADC_CHANNEL_2;
		break;
	case VAMP :
	    hadc.Instance->CHSELR = 1<<ADC_CHANNEL_3;
		break;
	default :
		break;
	}

	if (HAL_ADC_Start(&hadc) != HAL_OK)
	{
		Error_Handler();
	}
  	if (HAL_ADC_PollForConversion(&hadc, 100) != HAL_OK)
  	{
  		Error_Handler();
  	}

  	tmp = HAL_ADC_GetValue(&hadc);


	if (HAL_ADC_Stop(&hadc) != HAL_OK)
	{
		Error_Handler();
	}

    switch (adc_index) {
    case TEMP_TAS :
        temp = (uint8_t)((((float)(tmp) * ADC_V_PER_COUNT) - MCP9700_OFFSET) * MCP9700_T_COEFF + 0.5);
        if (temp > (previous_value[TEMP_TAS] + 2) || temp < (previous_value[TEMP_TAS] - 2)) {
            if (temp > 80)
            {
                color_console(RED_CONSOLE);
                console_printf("WARNING ");
                color_console(INIT_COLOR_CONSOLE);
            }
            console_printf("Temp TAS %d*C\r\n", temp);
            previous_value[TEMP_TAS] = temp;
        }
        break;
    case TEMP_BRIDGE :
        temp = (uint8_t)((((float)(tmp) * ADC_V_PER_COUNT) - MCP9700_OFFSET) * MCP9700_T_COEFF + 0.5);
        if (temp > (previous_value[TEMP_BRIDGE] + 2) || temp < (previous_value[TEMP_BRIDGE] - 2)) {
            if (temp > 80)
            {
                color_console(RED_CONSOLE);
                console_printf("WARNING ");
                color_console(INIT_COLOR_CONSOLE);
            }
            console_printf("Temp Bridge %d*C\r\n", temp);
            previous_value[TEMP_BRIDGE] = temp;
        }
        break;
    case PVDD :
        volt = (uint8_t)((float)(tmp) * VOLT_PER_COUNT + 0.5);
        if (previous_value[PVDD] != volt) {
            console_printf("PVDD %dV\r\n", (uint16_t)volt);
            previous_value[PVDD] = volt;
        }
        break;
    case VAMP :
        volt = (uint8_t)((float)(tmp) * VOLT_PER_COUNT + 0.5);
        if (previous_value[VAMP] != volt) {
            console_printf("VAMP %dV\r\n", (uint16_t)volt);
            previous_value[VAMP] = volt;
        }
        break;
    default :
        break;
    }
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
