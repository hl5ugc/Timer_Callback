/*
 * [ PROJECT   ]  stm32g030_fw
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  hw.c
 * [ Version   ]  1.0
 * [ Created   ]  2024[5:23:32 PM ]
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
#include "hw.h"

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
void hwInit(void)
{
  bspInit();
  hwOutputInit();
  hwTimerInit();
  sjTimerInit();
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
 /* hw.c End Of File !! Well Done */
