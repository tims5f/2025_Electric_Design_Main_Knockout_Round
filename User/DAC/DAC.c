#include "DAC.h"
#include "math.h"
#include "main.h"



#define WAVE_TABLE_SIZE 256


uint8_t sine_wave[WAVE_TABLE_SIZE];
uint8_t triangle_wave[WAVE_TABLE_SIZE];
uint8_t square_wave[WAVE_TABLE_SIZE];
uint8_t wave_diagram[4][WAVE_TABLE_SIZE];
uint8_t dc;


void Generate_WaveTables(void)
{
  for(int j=0;j<4;j++){
     if(j==0){
       for(int i = 0; i < WAVE_TABLE_SIZE; i++){
            double angle = 2 * 3.14159 * i / (WAVE_TABLE_SIZE - 1);
            double sine_value = sin(angle);
            wave_diagram[j][i] = (uint8_t)((sine_value + 1.0) * 127.5*0.91); // Ó³Éäµ½0-255
          }
     }

  
     if(j==1){
       for(int i = 0; i < WAVE_TABLE_SIZE; i++){
           uint8_t value;
           if(i < WAVE_TABLE_SIZE / 2) {
                value = (uint8_t)((2.0 * i / (WAVE_TABLE_SIZE / 2.0)) * 127.5*0.91);
           }else{
                value = (uint8_t)((2.0 * (WAVE_TABLE_SIZE - 1 - i) / (WAVE_TABLE_SIZE / 2.0)) * 127.5*0.91); 
            }
           wave_diagram[j][i] = value;
          }
      }
     
     
     if(j==2){
       for (int i = 0; i < WAVE_TABLE_SIZE; i++){
          wave_diagram[j][i] = (i < WAVE_TABLE_SIZE / 2) ? 0xFF : 0x00;
          wave_diagram[j][i] = (uint8_t)(wave_diagram[j][i]*0.91);
       }
     }
     
     
     if(j==3){
       for(int i=0 ;i<WAVE_TABLE_SIZE;i++){
         wave_diagram[j][i] = (uint8_t)(255*0.91);
       }
     }
  }
//  //Èý½Ç²¨
//
//  for (int i = 0; i < WAVE_TABLE_SIZE; i++)
//  {
//     double angle = 2 * 3.14159 * i / (WAVE_TABLE_SIZE - 1);
//        double sine_value = sin(angle);
//        sine_wave[i] = (uint8_t)((sine_value + 1.0) * 127.5); // Ó³Éäµ½0-255
//  }

//  // Èý½Ç
//  for (int i = 0; i < WAVE_TABLE_SIZE; i++)
//  {
//    uint8_t value;
//        if (i < WAVE_TABLE_SIZE / 2) {
//            value = (uint8_t)((2.0 * i / (WAVE_TABLE_SIZE / 2.0)) * 127.5);
//        } else {
//            value = (uint8_t)((2.0 * (WAVE_TABLE_SIZE - 1 - i) / (WAVE_TABLE_SIZE / 2.0)) * 127.5); 
//        }
//        triangle_wave[i] = value;
//  }
//
//  // ·½²¨
//  for (int i = 0; i < WAVE_TABLE_SIZE; i++)
//  {
//    square_wave[i] = (i < WAVE_TABLE_SIZE / 2) ? 0xFF : 0x00;
//  }
}



void Set_DAC_Value(uint8_t value)
{
    if (value & 0x80)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
    }
    else 
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
    }
    
    if (value & 0x40)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
    }
    else 
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
    }
    
    if (value & 0x20)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
    }
    else 
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
    }
    
    if (value & 0x10)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
    }
    else 
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
    }
    
    if (value & 0x08)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
    }
    else 
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
    }
    
    if (value & 0x04)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    }
    else 
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    }
    
    if (value & 0x02)
    {
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
    }
    else 
    {
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
    }

    if (value & 0x01)
    {
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
    }
    else 
    {
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
    }
}