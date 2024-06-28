/*
 * [ PROJECT   ]  stm32g030_fw_1_led
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  sjTimer.c
 * [ Version   ]  1.0
 * [ Created   ]  2024[11:53:56 AM ]
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
#include "sjTimer.h"
#ifdef _USE_HW_SJ_TIMER
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
  bool enable ;
  void(*func)(void);
} SjTimer_t;
// ---------------------------------------------------------------------------
//  Define Private variables.
// ---------------------------------------------------------------------------
//
extern TIM_HandleTypeDef htim17;

static volatile uint8_t sjTimer_count = 0U ;
static volatile SjTimer_t sjtimer_tbl[SJTIMER_MAX_CH] ;
static volatile SjTimer_t sjtimer_1msec_tbl[SJTIMER_1M_MAX_CH] ;
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
void sjTimerInit(void)
{
  uint8_t u8i = 0U ;

  for (u8i=0U; u8i<SJTIMER_MAX_CH; u8i++)
  {
    sjtimer_tbl[u8i].enable   = false ;
    sjtimer_tbl[u8i].func     = NULL ;
  }

  HAL_TIM_Base_Start_IT(&htim17);
}

void sjTimerSet(uint8_t ch,void(*func)(void))
{
  if (ch < SJTIMER_MAX_CH)
  {
    sjtimer_tbl[ch].func     = func ;
    sjtimer_tbl[ch].enable   = false ;
  }
}

void sjTimerStart(uint8_t ch)
{
  if (ch < SJTIMER_MAX_CH)
  {
    sjtimer_tbl[ch].enable   = true ;
  }
}
void sjTimerStop(uint8_t ch)
{
  if (ch < SJTIMER_MAX_CH)
  {
    sjtimer_tbl[ch].enable   = false ;
  }
}
/**
 *
 */
void sjTimer1mSecSet(uint8_t ch,void(*func)(void))
{
  if (ch < SJTIMER_1M_MAX_CH)
  {
    sjtimer_1msec_tbl[ch].func     = func ;
    sjtimer_1msec_tbl[ch].enable   = false ;
  }
}
void sjTimer1mSecStart(uint8_t ch)
{
  if (ch < SJTIMER_1M_MAX_CH)
  {
    sjtimer_1msec_tbl[ch].enable   = true ;
  }
}
void sjTimer1mSecStop(uint8_t ch)
{
  if (ch < SJTIMER_1M_MAX_CH)
  {
    sjtimer_1msec_tbl[ch].enable   = false ;
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
void swTimerISR(void)
{
  uint8_t u8i = 0U ;

  if (sjtimer_tbl[sjTimer_count].enable == true)
  {
    if (sjtimer_tbl[sjTimer_count].func != NULL)
    {
      sjtimer_tbl[sjTimer_count].func() ;
    }
  }
  //
  sjTimer_count = (sjTimer_count + 1U) % SJTIMER_MAX_CH ;
  // 1msec callabck
  for (u8i=0U; u8i < SJTIMER_1M_MAX_CH ; u8i++)
  {
    if (sjtimer_1msec_tbl[u8i].enable  == true)
    {
      sjtimer_1msec_tbl[u8i].func() ;
    }
  }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim17)
  {
    swTimerISR();
  }
}
// ---------------------------------------------------------------------------
//  Define CLI definitions.
// ---------------------------------------------------------------------------
//
#endif /* sjTimer.c End Of File !! Well Done */
