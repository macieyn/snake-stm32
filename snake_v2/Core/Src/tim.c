/**
  ******************************************************************************
  * File Name          : TIM.c
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
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

/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */
#include "snake.h"

uint8_t bit_kolumny = 0;
uint8_t bit_wiersza = 0;
uint8_t multi_wiersze2 = 0x01;
/* USER CODE END 0 */

TIM_HandleTypeDef htim14;

/* TIM14 init function */
void MX_TIM14_Init(void)
{

  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 499;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 1;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM14)
  {
  /* USER CODE BEGIN TIM14_MspInit 0 */

  /* USER CODE END TIM14_MspInit 0 */
    /* TIM14 clock enable */
    __HAL_RCC_TIM14_CLK_ENABLE();

    /* TIM14 interrupt Init */
    HAL_NVIC_SetPriority(TIM14_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM14_IRQn);
  /* USER CODE BEGIN TIM14_MspInit 1 */

  /* USER CODE END TIM14_MspInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM14)
  {
  /* USER CODE BEGIN TIM14_MspDeInit 0 */

  /* USER CODE END TIM14_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM14_CLK_DISABLE();

    /* TIM14 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM14_IRQn);
  /* USER CODE BEGIN TIM14_MspDeInit 1 */

  /* USER CODE END TIM14_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (bit_kolumny < 8) {

		if (bit_wiersza < 8) {
			uint16_t tab_to_2nd_byte = 0;
			uint8_t spr = 0;
			uint8_t przesuniecie = 0b10000000;

			przesuniecie = przesuniecie >> bit_wiersza;
			spr = virtual_screen[bit_kolumny] & przesuniecie;

			tab_to_2nd_byte = spr << 8;

			clear_screen();

			if(przesuniecie == 0b100000 && (spr>>bit_wiersza) > 0)
				HAL_GPIO_WritePin(KOLUMNA_2_GPIO_Port, KOLUMNA_2_Pin, KOLUMNA_ON);
			else if(przesuniecie == 0b01000000 && (spr>>bit_wiersza) > 0)
				HAL_GPIO_WritePin(KOLUMNA_1_GPIO_Port, KOLUMNA_1_Pin, KOLUMNA_ON);
			else if(przesuniecie == 0b10000000 && (spr>>bit_wiersza) > 0)
				HAL_GPIO_WritePin(KOLUMNA_0_GPIO_Port, KOLUMNA_0_Pin, KOLUMNA_ON);
			else
				HAL_GPIO_WritePin(GPIOA, tab_to_2nd_byte, KOLUMNA_ON);

			HAL_GPIO_WritePin(GPIOA, multi_wiersze, WIERSZ_ON);

			bit_wiersza++;
		} else
			bit_wiersza = 0;

		bit_kolumny++;
		multi_wiersze = multi_wiersze << 1;

	} else {
		bit_kolumny = 0;
		multi_wiersze = 0x01;
	}
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
