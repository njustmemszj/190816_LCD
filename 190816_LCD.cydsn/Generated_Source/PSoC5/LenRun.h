/*******************************************************************************
* File Name: LenRun.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LenRun_H) /* Pins LenRun_H */
#define CY_PINS_LenRun_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LenRun_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LenRun__PORT == 15 && ((LenRun__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LenRun_Write(uint8 value);
void    LenRun_SetDriveMode(uint8 mode);
uint8   LenRun_ReadDataReg(void);
uint8   LenRun_Read(void);
void    LenRun_SetInterruptMode(uint16 position, uint16 mode);
uint8   LenRun_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LenRun_SetDriveMode() function.
     *  @{
     */
        #define LenRun_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LenRun_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LenRun_DM_RES_UP          PIN_DM_RES_UP
        #define LenRun_DM_RES_DWN         PIN_DM_RES_DWN
        #define LenRun_DM_OD_LO           PIN_DM_OD_LO
        #define LenRun_DM_OD_HI           PIN_DM_OD_HI
        #define LenRun_DM_STRONG          PIN_DM_STRONG
        #define LenRun_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LenRun_MASK               LenRun__MASK
#define LenRun_SHIFT              LenRun__SHIFT
#define LenRun_WIDTH              1u

/* Interrupt constants */
#if defined(LenRun__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LenRun_SetInterruptMode() function.
     *  @{
     */
        #define LenRun_INTR_NONE      (uint16)(0x0000u)
        #define LenRun_INTR_RISING    (uint16)(0x0001u)
        #define LenRun_INTR_FALLING   (uint16)(0x0002u)
        #define LenRun_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LenRun_INTR_MASK      (0x01u) 
#endif /* (LenRun__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LenRun_PS                     (* (reg8 *) LenRun__PS)
/* Data Register */
#define LenRun_DR                     (* (reg8 *) LenRun__DR)
/* Port Number */
#define LenRun_PRT_NUM                (* (reg8 *) LenRun__PRT) 
/* Connect to Analog Globals */                                                  
#define LenRun_AG                     (* (reg8 *) LenRun__AG)                       
/* Analog MUX bux enable */
#define LenRun_AMUX                   (* (reg8 *) LenRun__AMUX) 
/* Bidirectional Enable */                                                        
#define LenRun_BIE                    (* (reg8 *) LenRun__BIE)
/* Bit-mask for Aliased Register Access */
#define LenRun_BIT_MASK               (* (reg8 *) LenRun__BIT_MASK)
/* Bypass Enable */
#define LenRun_BYP                    (* (reg8 *) LenRun__BYP)
/* Port wide control signals */                                                   
#define LenRun_CTL                    (* (reg8 *) LenRun__CTL)
/* Drive Modes */
#define LenRun_DM0                    (* (reg8 *) LenRun__DM0) 
#define LenRun_DM1                    (* (reg8 *) LenRun__DM1)
#define LenRun_DM2                    (* (reg8 *) LenRun__DM2) 
/* Input Buffer Disable Override */
#define LenRun_INP_DIS                (* (reg8 *) LenRun__INP_DIS)
/* LCD Common or Segment Drive */
#define LenRun_LCD_COM_SEG            (* (reg8 *) LenRun__LCD_COM_SEG)
/* Enable Segment LCD */
#define LenRun_LCD_EN                 (* (reg8 *) LenRun__LCD_EN)
/* Slew Rate Control */
#define LenRun_SLW                    (* (reg8 *) LenRun__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LenRun_PRTDSI__CAPS_SEL       (* (reg8 *) LenRun__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LenRun_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LenRun__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LenRun_PRTDSI__OE_SEL0        (* (reg8 *) LenRun__PRTDSI__OE_SEL0) 
#define LenRun_PRTDSI__OE_SEL1        (* (reg8 *) LenRun__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LenRun_PRTDSI__OUT_SEL0       (* (reg8 *) LenRun__PRTDSI__OUT_SEL0) 
#define LenRun_PRTDSI__OUT_SEL1       (* (reg8 *) LenRun__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LenRun_PRTDSI__SYNC_OUT       (* (reg8 *) LenRun__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LenRun__SIO_CFG)
    #define LenRun_SIO_HYST_EN        (* (reg8 *) LenRun__SIO_HYST_EN)
    #define LenRun_SIO_REG_HIFREQ     (* (reg8 *) LenRun__SIO_REG_HIFREQ)
    #define LenRun_SIO_CFG            (* (reg8 *) LenRun__SIO_CFG)
    #define LenRun_SIO_DIFF           (* (reg8 *) LenRun__SIO_DIFF)
#endif /* (LenRun__SIO_CFG) */

/* Interrupt Registers */
#if defined(LenRun__INTSTAT)
    #define LenRun_INTSTAT            (* (reg8 *) LenRun__INTSTAT)
    #define LenRun_SNAP               (* (reg8 *) LenRun__SNAP)
    
	#define LenRun_0_INTTYPE_REG 		(* (reg8 *) LenRun__0__INTTYPE)
#endif /* (LenRun__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LenRun_H */


/* [] END OF FILE */
