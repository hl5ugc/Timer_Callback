/*
 * [ PROJECT   ]  stm32g030_fw_1_led
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  hwOutput.c
 * [ Version   ]  1.0
 * [ Created   ]  2024[10:39:57 AM ]
 * --------------------------------------------------------------------------
 * Revision History :
 * ------------------------------------------------------------------
 *
 *
 *  *.The use of this source code shall be deemed to have been 
 *    tacitly agreed by the user.
 *  *.This source code is freely available for personal learning 
 *    and research and development.
 *  *.In the case of secondary authoring or redistribution using this source, 
 *    it is essential The company name of SAMJIN ELECTRONICS must be specified.
 *  *.Do not sell or for-profit this source code.
 *	*.This clause and the original author mark are prohibited from being 
 *	  modified or deleted. 
 *  
 *------------------------------------------------------------------
 * --------------------------------------------------------------------------
 * Author         Date       Comments on this revision
 * --------------------------------------------------------------------------
 * Hagseong Kang  Jun 28, 2024    First release of this file
 * --------------------------------------------------------------------------
 * Additional Notes:
 * **************************************************************************
 */
 /**
 * @brief 
 * @param  
 * @return  
 */



/* Define Includes */
#include "hwOutput.h"
#ifdef _USE_HW_OUTPUT
// ---------------------------------------------------------------------------
//  Define Macros .
// ---------------------------------------------------------------------------
//
 
// ---------------------------------------------------------------------------
//  Define TypeDef & Constants.
// ---------------------------------------------------------------------------
//
typedef struct
{
  GPIO_TypeDef    *port;
  uint16_t        pin ;
  uint32_t        mode ;
  uint32_t        pull ;
  GPIO_PinState   onState ;
  GPIO_PinState   offState ;
} Hw_Output_t ;
// ---------------------------------------------------------------------------
//  Define Private variables.
// ---------------------------------------------------------------------------
//
static const Hw_Output_t hwOutput_tbl[OUTPUT_MAX_CH] = {
    {GPIOA, GPIO_PIN_4,GPIO_MODE_OUTPUT_OD,GPIO_NOPULL,GPIO_PIN_RESET,GPIO_PIN_SET}, // Active low
    {GPIOA, GPIO_PIN_3,GPIO_MODE_OUTPUT_PP,GPIO_PULLUP,GPIO_PIN_RESET,GPIO_PIN_SET},
    {GPIOA, GPIO_PIN_2,GPIO_MODE_OUTPUT_PP,GPIO_PULLUP,GPIO_PIN_RESET,GPIO_PIN_SET},
    {GPIOA, GPIO_PIN_1,GPIO_MODE_OUTPUT_PP,GPIO_PULLUP,GPIO_PIN_SET,GPIO_PIN_RESET},
};
 
// ---------------------------------------------------------------------------
// Define Private function prototype.
// ---------------------------------------------------------------------------
//

// ---------------------------------------------------------------------------
// Define Callback function prototype.
// ---------------------------------------------------------------------------
//

// ---------------------------------------------------------------------------
// Define Public function definitions. 
// ---------------------------------------------------------------------------
//
void hwOutputInit(void)
{
  uint8_t u8i = 0x00U ;
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  for (u8i=0U; u8i<OUTPUT_MAX_CH; u8i++)
  {
    HAL_GPIO_WritePin(hwOutput_tbl[u8i].port, hwOutput_tbl[u8i].pin, hwOutput_tbl[u8i].offState);
  }

  /*Configure GPIO pin   */
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  for (u8i=0U; u8i<OUTPUT_MAX_CH; u8i++)
  {
    GPIO_InitStruct.Pin  = hwOutput_tbl[u8i].pin ;
    GPIO_InitStruct.Mode = hwOutput_tbl[u8i].mode ;
    HAL_GPIO_Init(hwOutput_tbl[u8i].port, &GPIO_InitStruct);
  }

}
void hwOutputOn(uint8_t u8ch)
{
  if (u8ch < OUTPUT_MAX_CH)
  {
    HAL_GPIO_WritePin(hwOutput_tbl[u8ch].port, hwOutput_tbl[u8ch].pin, hwOutput_tbl[u8ch].onState);
  }
}
void hwOutputOff(uint8_t u8ch)
{
  if (u8ch < OUTPUT_MAX_CH)
  {
    HAL_GPIO_WritePin(hwOutput_tbl[u8ch].port, hwOutput_tbl[u8ch].pin, hwOutput_tbl[u8ch].offState);
  }
}
void hwOutputToggle(uint8_t u8ch)
{
  if (u8ch < OUTPUT_MAX_CH)
  {
    HAL_GPIO_TogglePin(hwOutput_tbl[u8ch].port, hwOutput_tbl[u8ch].pin);
  }
}
// ---------------------------------------------------------------------------
// Define private function definitions.  
// ---------------------------------------------------------------------------
//
 
// ---------------------------------------------------------------------------
//  Define Callbacks definitions.
// ---------------------------------------------------------------------------
//
 
// ---------------------------------------------------------------------------
//  Define CLI definitions.
// ---------------------------------------------------------------------------
//
#endif /* hwOutput.c End Of File !! Well Done */
