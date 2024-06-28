/*
 * [ PROJECT   ]  stm32g030_fw_1_led
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  swTimer.h
 * [ Version   ]  1.0
 * [ Created   ]  2024[9:16:12 AM ]
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


/* Mutiple includes protection */
#ifndef SRC_HW_CSU_SWTIMER_H_
#define SRC_HW_CSU_SWTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes */
#include "hw_def.h"
#ifdef _USE_HW_SW_TIMER

/*
  1. static uint8_t  timer_ch = 0U;

  2.
  if (swTimerGetCh(&timer_ch) == true)
  {
    swTimerSet(timer_ch, cbLedSwTimer, NULL, SWTIMER_LOOP, 100U);
  }
  3.
  swTimerStart(timer_ch);
  swTimerStop(timer_ch);
  4.
  static void cbLedSwTimer(void *arg)
  {
    hwOutputToggle(_DEF_CH1);
  }
*/
// ---------------------------------------------------------------------------
// Define Global define
// --------------------------------------------------------------------------- 
// 
#define SWTIMER_MAX_CH    HW_SJ_TIMER_MAX_CH
// ---------------------------------------------------------------------------
// Define typedef
// --------------------------------------------------------------------------- 
//
typedef enum
{
  SWTIMER_LOOP  = 0U,
  SWTIMER_ONTIME ,
} SwTimerMode_e ;
// ---------------------------------------------------------------------------
// Define  Global Function prototypes.
// --------------------------------------------------------------------------- 
//
void swTimerInit(void);
bool swTimerGetCh(uint8_t *pCh);
void swTimerSet(uint8_t ch,
                void(*func)(void *arg),
                void *func_arg,
                SwTimerMode_e mode , uint32_t time_ms);
void swTimerStart(uint8_t ch);
void swTimerStop(uint8_t ch);

#endif 
#ifdef __cplusplus
}
#endif
#endif /* swTimer.h End Of File !! Well Done */
