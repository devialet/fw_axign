/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */
#define color_console(param) console_printf("\033[%sm",param)
/*   param devant �tre un const char *, vide (identique � "0") ou form�
     d'une o� plusieurs valeurs s�par�es par des ; parmi
         0  r�initialisation         1  haute intensit� (des caract�res)
         5  clignotement             7  video invers�
         30, 31, 32, 33, 34, 35, 36, 37 couleur des caract�res
         40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
        les couleurs, suivant la logique RGB, �tant respectivement
        noir, rouge, vert, jaune, bleu, magenta, cyan et blanc */

#define INIT_COLOR_CONSOLE      "0"
#define RED_CONSOLE             "31"
#define GREEN_CONSOLE           "32"
#define YELLOW_CONSOLE          "33"
#define BLUE_CONSOLE            "34"
#define MAGENTA_CONSOLE         "35"
#define CYAN_CONSOLE            "36"
void console_printf(const char *format, ...);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
