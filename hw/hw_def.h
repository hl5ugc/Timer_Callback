/*
 * [ PROJECT   ]  stm32g030_fw
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  hw_def.h
 * [ Version   ]  1.0
 * [ Created   ]  2024[5:23:14 PM ]
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


/* Mutiple includes protection */
#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes */
#include "def.h"
#include "bsp.h"

 
// ---------------------------------------------------------------------------
// Define Global define
// --------------------------------------------------------------------------- 
// 
#define _USE_HW_OUTPUT                1U
#define      HW_OUTPUT_MAX_CH         4U

#define _USE_HW_TIMER                 1U
#define _USE_HW_SJ_TIMER              1U
#define      HW_SJ_TIMER_MAX_CH       10U
#define      HW_SJ_TIMER_1M_MAX_CH    5U
//
//#define _USE_HW_SW_TIMER          1U
//#define      HW_SW_TIMER_MAX_CH   5U
//
// ---------------------------------------------------------------------------
// Define typedef
// --------------------------------------------------------------------------- 
// 
// ---------------------------------------------------------------------------
// Define  Global Function prototypes.
// --------------------------------------------------------------------------- 
//



#ifdef __cplusplus
}
#endif
#endif /* hw_def.h End Of File !! Well Done */
