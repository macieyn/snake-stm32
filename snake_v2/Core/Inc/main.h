/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t testowa[8];
extern int8_t game_over;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void clear_screen();

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WIERSZ_0_Pin GPIO_PIN_0
#define WIERSZ_0_GPIO_Port GPIOA
#define WIERSZ_1_Pin GPIO_PIN_1
#define WIERSZ_1_GPIO_Port GPIOA
#define WIERSZ_2_Pin GPIO_PIN_2
#define WIERSZ_2_GPIO_Port GPIOA
#define WIERSZ_3_Pin GPIO_PIN_3
#define WIERSZ_3_GPIO_Port GPIOA
#define WIERSZ_4_Pin GPIO_PIN_4
#define WIERSZ_4_GPIO_Port GPIOA
#define WIERSZ_5_Pin GPIO_PIN_5
#define WIERSZ_5_GPIO_Port GPIOA
#define WIERSZ_6_Pin GPIO_PIN_6
#define WIERSZ_6_GPIO_Port GPIOA
#define WIERSZ_7_Pin GPIO_PIN_7
#define WIERSZ_7_GPIO_Port GPIOA
#define KOLUMNA_7_Pin GPIO_PIN_8
#define KOLUMNA_7_GPIO_Port GPIOA
#define KOLUMNA_6_Pin GPIO_PIN_9
#define KOLUMNA_6_GPIO_Port GPIOA
#define KOLUMNA_5_Pin GPIO_PIN_10
#define KOLUMNA_5_GPIO_Port GPIOA
#define KOLUMNA_4_Pin GPIO_PIN_11
#define KOLUMNA_4_GPIO_Port GPIOA
#define KOLUMNA_3_Pin GPIO_PIN_12
#define KOLUMNA_3_GPIO_Port GPIOA
#define KOLUMNA_2_Pin GPIO_PIN_15
#define KOLUMNA_2_GPIO_Port GPIOA
#define KOLUMNA_1_Pin GPIO_PIN_3
#define KOLUMNA_1_GPIO_Port GPIOB
#define KOLUMNA_0_Pin GPIO_PIN_4
#define KOLUMNA_0_GPIO_Port GPIOB
#define SW_RIGHT_Pin GPIO_PIN_5
#define SW_RIGHT_GPIO_Port GPIOB
#define SW_RIGHT_EXTI_IRQn EXTI4_15_IRQn
#define SW_DOWN_Pin GPIO_PIN_6
#define SW_DOWN_GPIO_Port GPIOB
#define SW_DOWN_EXTI_IRQn EXTI4_15_IRQn
#define SW_LEFT_Pin GPIO_PIN_7
#define SW_LEFT_GPIO_Port GPIOB
#define SW_LEFT_EXTI_IRQn EXTI4_15_IRQn
#define SW_UP_Pin GPIO_PIN_8
#define SW_UP_GPIO_Port GPIOB
#define SW_UP_EXTI_IRQn EXTI4_15_IRQn


/* USER CODE BEGIN Private defines */

#define KOLUMNA_OFF 1
#define KOLUMNA_ON 0

#define WIERSZ_OFF 0
#define WIERSZ_ON 1

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
