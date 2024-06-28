/*
 * [ PROJECT   ]  stm32g030_fw_1_led
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  sjTimer.h
 * [ Version   ]  1.0
 * [ Created   ]  2024[11:53:47 AM ]
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
#ifndef SRC_HW_CSU_SJTIMER_H_
#define SRC_HW_CSU_SJTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes */
#include "hw_def.h"
#ifdef _USE_HW_SJ_TIMER
/*
1.
  static void cbTImerTest(void);
  static void cbTImer1mSecTest(void);
  static void cbTImer1mSecTest2(void);
2.
  sjTimerSet(0x02U,cbTImerTest);
  sjTimer1mSecSet(0x02U,cbTImer1mSecTest);
  sjTimer1mSecSet(0x04U,cbTImer1mSecTest2);
3.
  sjTimerStart(0x02U);
  sjTimer1mSecStart(0x02U);
  sjTimer1mSecStart(0x04U);
4.
  static void cbTImerTest(void)
  {
    hwOutputToggle(_DEF_CH2);
  }
  static void cbTImer1mSecTest(void)
  {
    hwOutputToggle(_DEF_CH3);
  }
  static void cbTImer1mSecTest2(void)
  {
    hwOutputToggle(_DEF_CH4);
    index = (index + 1U ) % 100 ;
    if(index == 50)
    {
      hwOutputToggle(_DEF_CH1);
    }
  }
*/
// ---------------------------------------------------------------------------
// Define Global define
// --------------------------------------------------------------------------- 
// 
#define SJTIMER_MAX_CH      HW_SJ_TIMER_MAX_CH
#define SJTIMER_1M_MAX_CH   HW_SJ_TIMER_1M_MAX_CH
// ---------------------------------------------------------------------------
// Define typedef
// --------------------------------------------------------------------------- 
// 
// ---------------------------------------------------------------------------
// Define  Global Function prototypes.
// --------------------------------------------------------------------------- 
//
void sjTimerInit(void);
void sjTimerSet(uint8_t ch,void(*func)(void));
void sjTimerStart(uint8_t ch);
void sjTimerStop(uint8_t ch);

void sjTimer1mSecSet(uint8_t ch,void(*func)(void));
void sjTimer1mSecStart(uint8_t ch);
void sjTimer1mSecStop(uint8_t ch);

#endif 
#ifdef __cplusplus
}
#endif
#endif /* sjTimer.h End Of File !! Well Done */
