/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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
#include "gpio.h"
/* USER CODE BEGIN 0 */
int8_t game_over = 1;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, WIERSZ_0_Pin|WIERSZ_1_Pin|WIERSZ_2_Pin|WIERSZ_3_Pin 
                          |WIERSZ_4_Pin|WIERSZ_5_Pin|WIERSZ_6_Pin|WIERSZ_7_Pin 
                          |KOLUMNA_7_Pin|KOLUMNA_6_Pin|KOLUMNA_5_Pin|KOLUMNA_4_Pin 
                          |KOLUMNA_3_Pin|KOLUMNA_2_Pin|KOLUMNA_1_Pin|KOLUMNA_0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB9 PB0 PB1 PB2 
                           PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2 
                          |GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PC14 PC15 PC6 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin 
                           PAPin PAPin PAPin PAPin 
                           PAPin PAPin PAPin PAPin 
                           PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = WIERSZ_0_Pin|WIERSZ_1_Pin|WIERSZ_2_Pin|WIERSZ_3_Pin 
                          |WIERSZ_4_Pin|WIERSZ_5_Pin|WIERSZ_6_Pin|WIERSZ_7_Pin 
                          |KOLUMNA_7_Pin|KOLUMNA_6_Pin|KOLUMNA_5_Pin|KOLUMNA_4_Pin 
                          |KOLUMNA_3_Pin|KOLUMNA_2_Pin|KOLUMNA_1_Pin|KOLUMNA_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin */
  GPIO_InitStruct.Pin = SW_START_Pin|SW_RIGHT_Pin|SW_DOWN_Pin|SW_LEFT_Pin 
                          |SW_UP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin) {
	switch (GPIO_Pin) {
	case SW_UP_Pin:
		game_over = 0;
		which_sw = 'w';
		break;
	case SW_DOWN_Pin:
		which_sw = 's';
		break;
	case SW_LEFT_Pin:
		which_sw = 'a';
		break;
	case SW_RIGHT_Pin:
		which_sw = 'd';
		break;
	case SW_START_Pin:
		break;
	}
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
