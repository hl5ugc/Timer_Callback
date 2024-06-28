/*
 * [ PROJECT   ]  stm32g030_fw_1_led
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  swTimer.c
 * [ Version   ]  1.0
 * [ Created   ]  2024[9:16:28 AM ]
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
#include "swTimer.h"
#ifdef _USE_HW_SW_TIMER
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
  bool is_set ;
  SwTimerMode_e mode ;
  uint32_t counter ;
  uint32_t reload ;
  void(*func)(void *arg);
  void *func_arg;
} SwTimer_t;
// ---------------------------------------------------------------------------
//  Define Private variables.
// ---------------------------------------------------------------------------
//
extern TIM_HandleTypeDef htim17;

static uint8_t swTimer_count = 0U ;
SwTimer_t swtimer_tbl[SWTIMER_MAX_CH] ;

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
void swTimerInit(void)
{
  uint8_t u8i = 0U ;

  for (u8i=0U; u8i<SWTIMER_MAX_CH; u8i++)
  {
    swtimer_tbl[u8i].enable   = false ;
    swtimer_tbl[u8i].is_set   = false ;
    swtimer_tbl[u8i].counter  = 0U ;
    swtimer_tbl[u8i].func     = NULL ;
    swtimer_tbl[u8i].func_arg = NULL ;
  }

  HAL_TIM_Base_Start_IT(&htim17);
}

bool swTimerGetCh(uint8_t *pCh)
{
  bool bRet = false ;

  if (swTimer_count < SWTIMER_MAX_CH)
  {
    pCh[0]  = swTimer_count ;
    swTimer_count++ ;
    bRet = true ;
  }

  return (bRet);
}
/**
 *
 */
void swTimerSet(uint8_t ch,
                void(*func)(void *arg),void *func_arg,
                SwTimerMode_e mode , uint32_t time_ms)
{
  if (ch < SWTIMER_MAX_CH)
  {
    swtimer_tbl[ch].func     = func ;
    swtimer_tbl[ch].func_arg = func_arg ;
    swtimer_tbl[ch].mode     = mode ;
    swtimer_tbl[ch].counter  = 0U ;
    swtimer_tbl[ch].reload   = time_ms ;
    swtimer_tbl[ch].enable   = false ;
    swtimer_tbl[ch].is_set   = true ;
  }
}
void swTimerStart(uint8_t ch)
{
  if (ch < SWTIMER_MAX_CH)
  {
    if (swtimer_tbl[ch].is_set  == true )
    {
      swtimer_tbl[ch].counter  = 0U ;
      swtimer_tbl[ch].enable   = true ;
    }
  }
}
void swTimerStop(uint8_t ch)
{
  if (ch < SWTIMER_MAX_CH)
  {
    if (swtimer_tbl[ch].is_set  == true )
    {
      swtimer_tbl[ch].enable   = false ;
    }
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

  for (u8i=0U; u8i<SWTIMER_MAX_CH; u8i++)
  {
    if (swtimer_tbl[u8i].enable == true)
    {
      swtimer_tbl[u8i].counter++ ;
      if (swtimer_tbl[u8i].counter >= swtimer_tbl[u8i].reload)
      {
        if (swtimer_tbl[u8i].func != NULL)
        {
          swtimer_tbl[u8i].func(swtimer_tbl[u8i].func_arg) ;
        }
        swtimer_tbl[u8i].counter = 0U ;
        if (swtimer_tbl[u8i].mode == SWTIMER_ONTIME)
        {
          swtimer_tbl[u8i].enable = false ;
        }
      }
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
#endif /* swTimer.c End Of File !! Well Done */
