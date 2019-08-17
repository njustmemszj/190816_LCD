/*******************************************************************************
* File Name: PinRW.h  
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

#if !defined(CY_PINS_PinRW_H) /* Pins PinRW_H */
#define CY_PINS_PinRW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinRW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinRW__PORT == 15 && ((PinRW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinRW_Write(uint8 value);
void    PinRW_SetDriveMode(uint8 mode);
uint8   PinRW_ReadDataReg(void);
uint8   PinRW_Read(void);
void    PinRW_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinRW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinRW_SetDriveMode() function.
     *  @{
     */
        #define PinRW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinRW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinRW_DM_RES_UP          PIN_DM_RES_UP
        #define PinRW_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinRW_DM_OD_LO           PIN_DM_OD_LO
        #define PinRW_DM_OD_HI           PIN_DM_OD_HI
        #define PinRW_DM_STRONG          PIN_DM_STRONG
        #define PinRW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinRW_MASK               PinRW__MASK
#define PinRW_SHIFT              PinRW__SHIFT
#define PinRW_WIDTH              1u

/* Interrupt constants */
#if defined(PinRW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinRW_SetInterruptMode() function.
     *  @{
     */
        #define PinRW_INTR_NONE      (uint16)(0x0000u)
        #define PinRW_INTR_RISING    (uint16)(0x0001u)
        #define PinRW_INTR_FALLING   (uint16)(0x0002u)
        #define PinRW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinRW_INTR_MASK      (0x01u) 
#endif /* (PinRW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinRW_PS                     (* (reg8 *) PinRW__PS)
/* Data Register */
#define PinRW_DR                     (* (reg8 *) PinRW__DR)
/* Port Number */
#define PinRW_PRT_NUM                (* (reg8 *) PinRW__PRT) 
/* Connect to Analog Globals */                                                  
#define PinRW_AG                     (* (reg8 *) PinRW__AG)                       
/* Analog MUX bux enable */
#define PinRW_AMUX                   (* (reg8 *) PinRW__AMUX) 
/* Bidirectional Enable */                                                        
#define PinRW_BIE                    (* (reg8 *) PinRW__BIE)
/* Bit-mask for Aliased Register Access */
#define PinRW_BIT_MASK               (* (reg8 *) PinRW__BIT_MASK)
/* Bypass Enable */
#define PinRW_BYP                    (* (reg8 *) PinRW__BYP)
/* Port wide control signals */                                                   
#define PinRW_CTL                    (* (reg8 *) PinRW__CTL)
/* Drive Modes */
#define PinRW_DM0                    (* (reg8 *) PinRW__DM0) 
#define PinRW_DM1                    (* (reg8 *) PinRW__DM1)
#define PinRW_DM2                    (* (reg8 *) PinRW__DM2) 
/* Input Buffer Disable Override */
#define PinRW_INP_DIS                (* (reg8 *) PinRW__INP_DIS)
/* LCD Common or Segment Drive */
#define PinRW_LCD_COM_SEG            (* (reg8 *) PinRW__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinRW_LCD_EN                 (* (reg8 *) PinRW__LCD_EN)
/* Slew Rate Control */
#define PinRW_SLW                    (* (reg8 *) PinRW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinRW_PRTDSI__CAPS_SEL       (* (reg8 *) PinRW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinRW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinRW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinRW_PRTDSI__OE_SEL0        (* (reg8 *) PinRW__PRTDSI__OE_SEL0) 
#define PinRW_PRTDSI__OE_SEL1        (* (reg8 *) PinRW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinRW_PRTDSI__OUT_SEL0       (* (reg8 *) PinRW__PRTDSI__OUT_SEL0) 
#define PinRW_PRTDSI__OUT_SEL1       (* (reg8 *) PinRW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinRW_PRTDSI__SYNC_OUT       (* (reg8 *) PinRW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinRW__SIO_CFG)
    #define PinRW_SIO_HYST_EN        (* (reg8 *) PinRW__SIO_HYST_EN)
    #define PinRW_SIO_REG_HIFREQ     (* (reg8 *) PinRW__SIO_REG_HIFREQ)
    #define PinRW_SIO_CFG            (* (reg8 *) PinRW__SIO_CFG)
    #define PinRW_SIO_DIFF           (* (reg8 *) PinRW__SIO_DIFF)
#endif /* (PinRW__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinRW__INTSTAT)
    #define PinRW_INTSTAT            (* (reg8 *) PinRW__INTSTAT)
    #define PinRW_SNAP               (* (reg8 *) PinRW__SNAP)
    
	#define PinRW_0_INTTYPE_REG 		(* (reg8 *) PinRW__0__INTTYPE)
#endif /* (PinRW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinRW_H */


/* [] END OF FILE */
