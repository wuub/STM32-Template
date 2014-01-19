#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "uart.h"

GPIO_InitTypeDef GPIO_InitStruct;
USART_InitTypeDef USART_InitStructure;


void init(void) {
  uart_open(USART1, 1382400, 0);
}

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)

#pragma message(VAR_NAME_VALUE(SYSCLK_FREQ_24MHz))

void loop(void) {

  for (char c = 'a'; c < 'z'; ++c)
  {
    uart_putc(c, USART1);
  }
  uart_putc('\n', USART1);

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

