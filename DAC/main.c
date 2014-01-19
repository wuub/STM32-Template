#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_dac.h"

void init(void) {

  GPIO_InitTypeDef GPIO_InitStructure;
  DAC_InitTypeDef DAC_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // DAC channel1 Configuration
  DAC_StructInit(&DAC_InitStructure);
  DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;
  DAC_Init(DAC_Channel_1, &DAC_InitStructure);

  // Enable DAC
  DAC_Cmd(DAC_Channel_1, ENABLE);

  DAC_SetChannel1Data(DAC_Align_12b_R, 0);
  // DAC_WaveGenerationCmd(DAC_Channel_1, DAC_WaveGeneration_Triangle, ENABLE);

}

uint16_t dacvalue = 0;

void loop(void) {

  if (dacvalue != 0)  {
      dacvalue = 0;
    }
    else {
      dacvalue = 255;

    }
  DAC_SetChannel1Data(DAC_Align_8b_R, dacvalue);

  for (int i = 0; i < 1000000; ++i)
  {
      __NOP;
  }

}

int main(void)
{
  init();
  while (1)
  {
    loop();
  }
}



#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
  while (1)
  {
  }
}

#endif

