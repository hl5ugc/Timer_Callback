/*
 * [ PROJECT   ]  stm32g030_fw
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  ap.c
 * [ Version   ]  1.0
 * [ Created   ]  2024[5:22:28 PM ]
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
 * Hagseong Kang  Jun 27, 2024    First release of this file
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
#include "ap.h"

// ---------------------------------------------------------------------------
//  Define Macros .
// ---------------------------------------------------------------------------
//
 
// ---------------------------------------------------------------------------
//  Define TypeDef & Constants.
// ---------------------------------------------------------------------------
//
 
// ---------------------------------------------------------------------------
//  Define Private variables.
// ---------------------------------------------------------------------------
//
static volatile uint8_t index = 0U ;
// ---------------------------------------------------------------------------
// Define Private function prototype.
// ---------------------------------------------------------------------------
//

// ---------------------------------------------------------------------------
// Define Callback function prototype.
// ---------------------------------------------------------------------------
//
static void cbTImerTest(void);
static void cbTImer1mSecTest(void);
static void cbTImer1mSecTest2(void);
// ---------------------------------------------------------------------------
// Define Public function definitions. 
// ---------------------------------------------------------------------------
//
void apInit(void)
{
  sjTimerSet(0x02U,cbTImerTest);
  sjTimer1mSecSet(0x02U,cbTImer1mSecTest);
  sjTimer1mSecSet(0x04U,cbTImer1mSecTest2);
}
void apMain(void)
{

  uint32_t preTime = 0UL;
  preTime = millis();

  sjTimerStart(0x02U);
  sjTimer1mSecStart(0x02U);
  sjTimer1mSecStart(0x04U);
  while(1)
  {
    if ((millis() - preTime) > 2000U)
    {
      preTime = millis();

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
// ---------------------------------------------------------------------------
//  Define CLI definitions.
// ---------------------------------------------------------------------------
//
 /* ap.c End Of File !! Well Done */
