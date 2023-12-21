/**
 * \file Ifx_Ssw.h
 * \brief Startup Software configuration. Can configure which core to be enabled.
 *
 * \version iLLD_1_0_1_16_0_1
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef IFX_SSW_H_
#define IFX_SSW_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Compilers.h"
#include "Ifx_Ssw_LegacySwCfg.h"

/******************************************************************************/
/*                          Macros                                            */
/******************************************************************************/

#ifndef IFX_CFG_SSW_ENABLE_TRICORE0
#define IFX_CFG_SSW_ENABLE_TRICORE0 (1U)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE1
#define IFX_CFG_SSW_ENABLE_TRICORE1 (1U)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE2
#define IFX_CFG_SSW_ENABLE_TRICORE2 (1U)
#endif

#ifndef IFX_CFG_SSW_PSW_DEFAULT
#define IFX_CFG_SSW_PSW_DEFAULT     (0x00000980u)
#endif

#ifndef IFX_CFG_SSW_ENABLE_INDIVIDUAL_C_INIT
#define IFX_CFG_SSW_ENABLE_INDIVIDUAL_C_INIT (0U)
#endif

/******************************************************************************/
/*                          Typedefs                                          */
/******************************************************************************/
/** \brief Structure definition for the BMHD
 * Based on BMI and start address respective CRC and Inverted CRC values has to be calculated and updated.
 * CRC-32 polynomial as defined in the IEEE 802.3 standard is used to generate the CRC value. The CRC algorithm
 * treats input data as a stream of bits.
 *
 * Eg. To calculate the CRC data has to given in big-endian order.
 * for the below values:
 *    bmi    = 0x00FE
 *    bmhdid = 0xB359
 *    stad   = 0xA00A0000
 * CRC calculation:
 *    Input        = 0xB35900FEA00A0000
 *    CRC value    = 0x3CEED0A6
 *    CRC Inverted = 0xC3112F59
 */
typedef struct
{
    unsigned short bmi;             /**< \brief 0x000: Boot Mode Index (BMI)*/
    unsigned short bmhdid;          /**< \brief 0x002: Boot Mode Header ID (CODE) = B359H*/
    unsigned int   stad;            /**< \brief 0x004: User Code start address*/
    unsigned int   crc;             /**< \brief 0x008: Check Result for the BMI Header (offset 000H - 007H)*/
    unsigned int   crcInv;          /**< \brief 0x00C: Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    unsigned int   reserved0[60];   /**< \brief 0x010: Reserved area (60 words) till the offset 0x100*/
    unsigned int   pw[8];           /**< \brief 0x100: Password protection (8 words) till the offset 0x120 */
    unsigned int   reserved1[52];   /**< \brief 0x120: Reserved area (52 words) till the offset 0x1F0*/
    unsigned int   confirmation;    /**< \brief 0x1F0: 32-bit CODE, (always same)*/
} Ifx_Ssw_Bmhd;

/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/
void __Core1_start(void);
void __Core2_start(void);

#endif /* IFX_SSW_H_ */
