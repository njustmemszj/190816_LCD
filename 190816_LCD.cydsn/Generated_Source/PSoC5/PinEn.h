/*******************************************************************************
* File Name: PinEn.h  
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

#if !defined(CY_PINS_PinEn_H) /* Pins PinEn_H */
#define CY_PINS_PinEn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinEn_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinEn__PORT == 15 && ((PinEn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinEn_Write(uint8 value);
void    PinEn_SetDriveMode(uint8 mode);
uint8   PinEn_ReadDataReg(void);
uint8   PinEn_Read(void);
void    PinEn_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinEn_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinEn_SetDriveMode() function.
     *  @{
     */
        #define PinEn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinEn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinEn_DM_RES_UP          PIN_DM_RES_UP
        #define PinEn_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinEn_DM_OD_LO           PIN_DM_OD_LO
        #define PinEn_DM_OD_HI           PIN_DM_OD_HI
        #define PinEn_DM_STRONG          PIN_DM_STRONG
        #define PinEn_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinEn_MASK               PinEn__MASK
#define PinEn_SHIFT              PinEn__SHIFT
#define PinEn_WIDTH              1u

/* Interrupt constants */
#if defined(PinEn__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinEn_SetInterruptMode() function.
     *  @{
     */
        #define PinEn_INTR_NONE      (uint16)(0x0000u)
        #define PinEn_INTR_RISING    (uint16)(0x0001u)
        #define PinEn_INTR_FALLING   (uint16)(0x0002u)
        #define PinEn_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinEn_INTR_MASK      (0x01u) 
#endif /* (PinEn__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinEn_PS                     (* (reg8 *) PinEn__PS)
/* Data Register */
#define PinEn_DR                     (* (reg8 *) PinEn__DR)
/* Port Number */
#define PinEn_PRT_NUM                (* (reg8 *) PinEn__PRT) 
/* Connect to Analog Globals */                                                  
#define PinEn_AG                     (* (reg8 *) PinEn__AG)                       
/* Analog MUX bux enable */
#define PinEn_AMUX                   (* (reg8 *) PinEn__AMUX) 
/* Bidirectional Enable */                                                        
#define PinEn_BIE                    (* (reg8 *) PinEn__BIE)
/* Bit-mask for Aliased Register Access */
#define PinEn_BIT_MASK               (* (reg8 *) PinEn__BIT_MASK)
/* Bypass Enable */
#define PinEn_BYP                    (* (reg8 *) PinEn__BYP)
/* Port wide control signals */                                                   
#define PinEn_CTL                    (* (reg8 *) PinEn__CTL)
/* Drive Modes */
#define PinEn_DM0                    (* (reg8 *) PinEn__DM0) 
#define PinEn_DM1                    (* (reg8 *) PinEn__DM1)
#define PinEn_DM2                    (* (reg8 *) PinEn__DM2) 
/* Input Buffer Disable Override */
#define PinEn_INP_DIS                (* (reg8 *) PinEn__INP_DIS)
/* LCD Common or Segment Drive */
#define PinEn_LCD_COM_SEG            (* (reg8 *) PinEn__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinEn_LCD_EN                 (* (reg8 *) PinEn__LCD_EN)
/* Slew Rate Control */
#define PinEn_SLW                    (* (reg8 *) PinEn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinEn_PRTDSI__CAPS_SEL       (* (reg8 *) PinEn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinEn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinEn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinEn_PRTDSI__OE_SEL0        (* (reg8 *) PinEn__PRTDSI__OE_SEL0) 
#define PinEn_PRTDSI__OE_SEL1        (* (reg8 *) PinEn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinEn_PRTDSI__OUT_SEL0       (* (reg8 *) PinEn__PRTDSI__OUT_SEL0) 
#define PinEn_PRTDSI__OUT_SEL1       (* (reg8 *) PinEn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinEn_PRTDSI__SYNC_OUT       (* (reg8 *) PinEn__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinEn__SIO_CFG)
    #define PinEn_SIO_HYST_EN        (* (reg8 *) PinEn__SIO_HYST_EN)
    #define PinEn_SIO_REG_HIFREQ     (* (reg8 *) PinEn__SIO_REG_HIFREQ)
    #define PinEn_SIO_CFG            (* (reg8 *) PinEn__SIO_CFG)
    #define PinEn_SIO_DIFF           (* (reg8 *) PinEn__SIO_DIFF)
#endif /* (PinEn__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinEn__INTSTAT)
    #define PinEn_INTSTAT            (* (reg8 *) PinEn__INTSTAT)
    #define PinEn_SNAP               (* (reg8 *) PinEn__SNAP)
    
	#define PinEn_0_INTTYPE_REG 		(* (reg8 *) PinEn__0__INTTYPE)
#endif /* (PinEn__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinEn_H */


/* [] END OF FILE */
