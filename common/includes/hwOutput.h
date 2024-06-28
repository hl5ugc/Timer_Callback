/*
 * [ PROJECT   ]  stm32g030_fw_1_led
 * [ License   ]  SAMJIN ELECTRONICS.,Co.Ltd
 * [ Author    ]  Copyright 2024 By HAG-SEONG KANG
 * [ E-MAIL    ]  hl5ugc@nate.com (82)10- 3841-9706
 * [ C  P  U   ]
 * [ Compller  ]  
 * [ Filename  ]  hwOutput.h
 * [ Version   ]  1.0
 * [ Created   ]  2024[6:35:06 PM ]
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
#ifndef SRC_COMMON_INCLUDES_HWOUTPUT_H_
#define SRC_COMMON_INCLUDES_HWOUTPUT_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Includes */
#include "hw_def.h"
#ifdef _USE_HW_OUTPUT

 
// ---------------------------------------------------------------------------
// Define Global define
// --------------------------------------------------------------------------- 
// 
#define OUTPUT_MAX_CH    HW_OUTPUT_MAX_CH
// ---------------------------------------------------------------------------
// Define typedef
// --------------------------------------------------------------------------- 
// 
// ---------------------------------------------------------------------------
// Define  Global Function prototypes.
// --------------------------------------------------------------------------- 
//
void hwOutputInit(void);
void hwOutputOn(uint8_t u8ch);
void hwOutputOff(uint8_t u8ch);
void hwOutputToggle(uint8_t u8ch);

#endif 
#ifdef __cplusplus
}
#endif
#endif /* hwOutput.h End Of File !! Well Done */
