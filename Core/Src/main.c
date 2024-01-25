/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint32_t buf[100] = {0};
char msg[30];
char cmd[50];
char *webdata;
/* USER CODE END PTD */

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
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  sprintf(cmd,"AT\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),1000);//Sends AT command with time(Command for Achknowledgement)
  HAL_UART_Receive (&huart3,(uint8_t *)buf,sizeof(buf),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),1000);
  memset(buf,0,sizeof(buf));

  sprintf(cmd,"AT+CWMODE=3\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),1000);//Sends AT command with time (For setting mode of Wifi)
  HAL_UART_Receive (&huart3,(uint8_t *)buf,sizeof(buf),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),1000);
  memset(buf,0,sizeof(buf));

  sprintf(cmd,"AT+CWQAP\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),1000);           //Sends AT command with time (for Quit AP)
  HAL_UART_Receive (&huart3,(uint8_t *)buf,sizeof(buf),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),1000);
  memset(buf,0,sizeof(buf));

  sprintf(cmd,"AT+RST\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),10000);//Sends AT command with time (For RESETTING WIFI)
  HAL_UART_Receive (&huart3,(uint8_t *)buf,sizeof(buf),10000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),5000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),5000);
  memset(buf,0,sizeof(buf));

  sprintf(cmd,"AT+CWJAP=\"Fedha Electrics Limited\",\"Fedha@2023\"\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),10000);//provide your WiFi username and password here
  HAL_UART_Receive (&huart3,(uint8_t *)buf,sizeof(buf),10000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),5000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),5000);
  memset(buf,0,sizeof(buf));

  sprintf(cmd,"AT+CIPMUX=0\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),200);           //Sends AT command with time (for Quit AP)
  HAL_UART_Receive (&huart3,(uint8_t *)buf, sizeof(buf),200);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),1000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),1000);
  memset(buf,0,sizeof(buf));

//  sprintf(cmd,"AT+CIPSTART=\"TCP\",\"172.105.56.254\",7075\r\n"); //Data to send
  sprintf(cmd,"AT+CIPSTART=\"TCP\",\"192.168.1.5\",7075\r\n");
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),15000);           //Sends AT command with time (for Quit AP)
  HAL_UART_Receive (&huart3,(uint8_t *)buf, sizeof(buf),15000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),5000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),5000);
  memset(buf,0,sizeof(buf));

  webdata = "LEMONbsee141jAndycoding123456" ;

  sprintf(cmd,"AT+CIPSEND=29\r\n"); //Data to send
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),5000);           //Sends AT command with time (for Quit AP)
  HAL_UART_Receive (&huart3,(uint8_t *)buf, sizeof(buf),5000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),3000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),3000);
  memset(buf,0,sizeof(buf));

  sprintf(cmd,"%s\r\n", webdata);
  HAL_UART_Transmit(&huart3,(uint8_t *)cmd,sizeof(cmd),10000);//Sends AT command with time (For RESETTING WIFI)
  HAL_UART_Receive (&huart3,(uint8_t *)buf, sizeof(buf),10000);
  HAL_UART_Transmit(&huart1,(uint8_t *)cmd,sizeof(cmd),5000);
  HAL_UART_Transmit(&huart1,(uint8_t *)buf,sizeof(buf),5000);
  memset(buf,0,sizeof(buf));

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }
  LL_SetSystemCoreClock(8000000);

   /* Update the time base */
  if (HAL_InitTick (TICK_INT_PRIORITY) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
