/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DAC.h"
#include "tim.h"
#include "dma.h"
#include "adc.h"
#include "oled.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;
/* USER CODE BEGIN EV */
int index = 0;
uint8_t cnt_frequency = 0;
uint8_t cnt_voltage = 0;
float amplitude = 1.0;
int jndex = 0;
uint16_t adc_buff[500];

int adc_cnt = 0;

uint8_t adc_cnt_frequency = 0;
uint8_t adc_cnt_voltage = 0;
uint32_t max;
float v;
int low = 0;
int high = 0;
uint16_t last_adc;
int key = 0;
uint16_t adc_show_data = 3723;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line1 interrupt.
  */
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */
  //PA1ÇÐ»»²¨ÐÎ
  if (jndex == 3)
        {
         jndex = 0;
        }
        else
        {
          jndex++;
        }

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line2 interrupt.
  */
void EXTI2_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI2_IRQn 0 */

  /* USER CODE END EXTI2_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_IRQn 1 */
  if (cnt_frequency == 30)
      {
        cnt_frequency = 0;
      }
      else
      {
        cnt_frequency++;
      }
  
  
  switch (cnt_frequency)
    {
    case 0:
      TIM2_RESET(39,9);
      break;
    case 1:
      TIM2_RESET(49,9);
      break;
    case 2:
      TIM2_RESET(79,9);
      break;
    case 3:
      TIM2_RESET(99,9);
      break;
    case 4:
      TIM2_RESET(129,9);
      break;
    case 5:
      TIM2_RESET(159,9);
      break;
    case 6:
      TIM2_RESET(199,9);
      break;
    case 7:
      TIM2_RESET(249,9);
      break;
    case 8:
      TIM2_RESET(299,9);
      break;
      
      
      
    case 9:
      TIM2_RESET(349,9);
      break;
    case 10:
      TIM2_RESET(399,9);
      break;
    case 11:
      TIM2_RESET(499,9);
      break;
    case 12:
      TIM2_RESET(699,9);
      break;
    case 13:
      TIM2_RESET(899,9);
      break;
    case 14:
      TIM2_RESET(999,9);
      break;
    case 15:
      TIM2_RESET(999,19);
      break;
    case 16:
      TIM2_RESET(999,29);
      break;
    case 17:
      TIM2_RESET(999,39);
      break;
    case 18:
      TIM2_RESET(1399,39);
      break;
    case 19:
      TIM2_RESET(1799,39);
      break;
    case 20:
      TIM2_RESET(2799,39);
      break;
    case 21:
      TIM2_RESET(3999,39);
      break;
    case 22:
      TIM2_RESET(5999,39);
      break;
    case 23:
      TIM2_RESET(7999,39);
      break;
    case 24:
      TIM2_RESET(9999,39);
      break;
    case 25:
      TIM2_RESET(9999,49);
      break;
    case 26:
      TIM2_RESET(9999,69);
      break;
    case 27:
      TIM2_RESET(9999,99);
      break;
    case 28:
      TIM2_RESET(9999,299);
      break;
    case 29:
      TIM2_RESET(9999,499);
      break;
    case 30:
      TIM2_RESET(9999,999);
      break;
    }

  /* USER CODE END EXTI2_IRQn 1 */
}

/**
  * @brief This function handles EXTI line3 interrupt.
  */
void EXTI3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI3_IRQn 0 */

  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
  /* USER CODE BEGIN EXTI3_IRQn 1 */
  if (cnt_voltage == 3)
      {
        cnt_voltage = 0;
      }
      else
      {
        cnt_voltage++;
      }
  switch (cnt_voltage)
    {
    case 0:
      amplitude=1;
      break;
    case 1:
      amplitude=0.7;
      break;
    case 2:
      amplitude=0.5;
      break;
    case 3:
      amplitude=0.3;
      break;
    }

  /* USER CODE END EXTI3_IRQn 1 */
}

/**
  * @brief This function handles EXTI line4 interrupt.
  */
void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_IRQn 0 */

  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI4_IRQn 1 */
  if (adc_cnt_frequency == 24)
      {
        adc_cnt_frequency = 0;
      }
      else
      {
        adc_cnt_frequency++;
      }
  
  
  switch (adc_cnt_frequency)
    {
    case 0:
      TIM4_RESET(1,9);
      break;
    case 1:
      TIM4_RESET(59,9);
      break;
    case 2:
      TIM4_RESET(79,9);
      break;
    case 3:
      TIM4_RESET(99,9);
      break;
    case 4:
      TIM4_RESET(129,9);
      break;
    case 5:
      TIM4_RESET(179,9);
      break;
    case 6:
      TIM4_RESET(239,9);
      break;
    case 7:
      TIM4_RESET(269,9);
      break;
    case 8:
      TIM4_RESET(299,9);
      break;
    case 9:
      TIM4_RESET(379,9);
      break;
    case 10:
      TIM4_RESET(469,9);
      break;
      
      
      
      
    case 11:
      TIM4_RESET(599,9);
      break;
    case 12:
      TIM4_RESET(599,19);
      break;
    case 13:
      TIM4_RESET(599,29);
      break;
    case 14:
      TIM4_RESET(599,39);
      break;
    case 15:
      TIM4_RESET(699,49);
      break;
    case 16:
      TIM4_RESET(999,49);
      break;
    case 17:
      TIM4_RESET(999,59);
      break;
    case 18:
      TIM4_RESET(999,79);
      break;
    case 19:
      TIM4_RESET(999,99);
      break;
    case 20:
      TIM4_RESET(2999,99);
      break;
    case 21:
      TIM4_RESET(4999,99);
      break;
      
      
      
    case 22:
      TIM4_RESET(9999,99);
      break;
    case 23:
      TIM4_RESET(9999,399);
      break;
    case 24:
      TIM4_RESET(9999,599);
      break;
    
    }
  

  /* USER CODE END EXTI4_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */
  if(key==2){
    key=0;
  }else{
    key++;
  }
  show_data(key);

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */
  if(jndex==3){
        Set_DAC_Value((uint8_t)(255*amplitude));
      }else{
        if(index<255){
          index++;
        }else{
          index=0;
        }
        Set_DAC_Value((uint8_t)(wave_diagram[jndex][index]*amplitude));
      }
   
  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */
  
  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */
  
     //OLED_Clear();
  //HAL_ADC_Stop_DMA(&hadc1);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buff, 500);
  

  if(adc_cnt == 499){
    //OLED_Clear();
    OLED_Clear_area();
    Oled_Base_Show();
  //OLED_ShowChar(16,13,51,12,1);
  //OLED_ShowChar(16,29,50,12,1);
  //OLED_ShowChar(16,45,49,12,1);
    
    for(int l=0;l<500;l++){
      if(adc_buff[l] > adc_show_data){
        adc_buff[l] = adc_show_data;
      }
      
      if(l==0){
        max = adc_buff[0];
        last_adc = adc_buff[0];
      }
      if(max<adc_buff[l]){
        max = (uint16_t)adc_buff[l];
      }
      
      if(jndex==2){

         if(abs(adc_buff[l]-last_adc) > 50||last_adc-adc_buff[l]>50){
           for(int i=(63-48*adc_buff[l]/adc_show_data);i<(63-48*adc_buff[l-1]/adc_show_data);i++){
            OLED_DrawPoint((unsigned char)(171-0.286*l),i,1);
          }
        }
        last_adc = adc_buff[l];
      }
      
      OLED_DrawPoint((unsigned char)(171-0.286*l),(63-48*adc_buff[l]/adc_show_data),1);
    
    
    
    
    }
    
    
    v = (float)(max*3.3/4095);
    show_one_decimal(0,0,v,12);
    OLED_ShowChar(19,0,86,12,1);
    
    OLED_Refresh_Gram();
  }
  
  
  
  if(adc_cnt<500){
    adc_cnt++;
  }else{
    adc_cnt=0;
  }

  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream0 global interrupt.
  */
void DMA2_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream0_IRQn 0 */

  /* USER CODE END DMA2_Stream0_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA2_Stream0_IRQn 1 */

  /* USER CODE END DMA2_Stream0_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
