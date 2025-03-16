/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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
#define D6_Pin GPIO_PIN_14
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_15
#define D7_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_8
#define D5_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_9
#define D4_GPIO_Port GPIOA
#define D3_Pin GPIO_PIN_10
#define D3_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_11
#define D2_GPIO_Port GPIOA
#define D1_Pin GPIO_PIN_12
#define D1_GPIO_Port GPIOA
#define D0_Pin GPIO_PIN_15
#define D0_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define WAVE_TABLE_SIZE 256
extern uint8_t sine_wave[WAVE_TABLE_SIZE];
extern uint8_t triangle_wave[WAVE_TABLE_SIZE];
extern uint8_t square_wave[WAVE_TABLE_SIZE];
extern uint8_t wave_diagram[4][WAVE_TABLE_SIZE];
extern uint8_t dc;
extern int index;
extern int jndex;


extern uint8_t cnt_frequency;
extern uint8_t cnt_voltage;
extern uint8_t wave;
extern uint8_t arry[6];
extern float amplitude;
extern uint16_t adc_buff[500];
extern uint16_t adc_show_data;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
