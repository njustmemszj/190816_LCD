/*******************************************************************************
* File Name: PinRS.h  
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

#if !defined(CY_PINS_PinRS_H) /* Pins PinRS_H */
#define CY_PINS_PinRS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinRS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinRS__PORT == 15 && ((PinRS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinRS_Write(uint8 value);
void    PinRS_SetDriveMode(uint8 mode);
uint8   PinRS_ReadDataReg(void);
uint8   PinRS_Read(void);
void    PinRS_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinRS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinRS_SetDriveMode() function.
     *  @{
     */
        #define PinRS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinRS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinRS_DM_RES_UP          PIN_DM_RES_UP
        #define PinRS_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinRS_DM_OD_LO           PIN_DM_OD_LO
        #define PinRS_DM_OD_HI           PIN_DM_OD_HI
        #define PinRS_DM_STRONG          PIN_DM_STRONG
        #define PinRS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinRS_MASK               PinRS__MASK
#define PinRS_SHIFT              PinRS__SHIFT
#define PinRS_WIDTH              1u

/* Interrupt constants */
#if defined(PinRS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinRS_SetInterruptMode() function.
     *  @{
     */
        #define PinRS_INTR_NONE      (uint16)(0x0000u)
        #define PinRS_INTR_RISING    (uint16)(0x0001u)
        #define PinRS_INTR_FALLING   (uint16)(0x0002u)
        #define PinRS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinRS_INTR_MASK      (0x01u) 
#endif /* (PinRS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinRS_PS                     (* (reg8 *) PinRS__PS)
/* Data Register */
#define PinRS_DR                     (* (reg8 *) PinRS__DR)
/* Port Number */
#define PinRS_PRT_NUM                (* (reg8 *) PinRS__PRT) 
/* Connect to Analog Globals */                                                  
#define PinRS_AG                     (* (reg8 *) PinRS__AG)                       
/* Analog MUX bux enable */
#define PinRS_AMUX                   (* (reg8 *) PinRS__AMUX) 
/* Bidirectional Enable */                                                        
#define PinRS_BIE                    (* (reg8 *) PinRS__BIE)
/* Bit-mask for Aliased Register Access */
#define PinRS_BIT_MASK               (* (reg8 *) PinRS__BIT_MASK)
/* Bypass Enable */
#define PinRS_BYP                    (* (reg8 *) PinRS__BYP)
/* Port wide control signals */                                                   
#define PinRS_CTL                    (* (reg8 *) PinRS__CTL)
/* Drive Modes */
#define PinRS_DM0                    (* (reg8 *) PinRS__DM0) 
#define PinRS_DM1                    (* (reg8 *) PinRS__DM1)
#define PinRS_DM2                    (* (reg8 *) PinRS__DM2) 
/* Input Buffer Disable Override */
#define PinRS_INP_DIS                (* (reg8 *) PinRS__INP_DIS)
/* LCD Common or Segment Drive */
#define PinRS_LCD_COM_SEG            (* (reg8 *) PinRS__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinRS_LCD_EN                 (* (reg8 *) PinRS__LCD_EN)
/* Slew Rate Control */
#define PinRS_SLW                    (* (reg8 *) PinRS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinRS_PRTDSI__CAPS_SEL       (* (reg8 *) PinRS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinRS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinRS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinRS_PRTDSI__OE_SEL0        (* (reg8 *) PinRS__PRTDSI__OE_SEL0) 
#define PinRS_PRTDSI__OE_SEL1        (* (reg8 *) PinRS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinRS_PRTDSI__OUT_SEL0       (* (reg8 *) PinRS__PRTDSI__OUT_SEL0) 
#define PinRS_PRTDSI__OUT_SEL1       (* (reg8 *) PinRS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinRS_PRTDSI__SYNC_OUT       (* (reg8 *) PinRS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinRS__SIO_CFG)
    #define PinRS_SIO_HYST_EN        (* (reg8 *) PinRS__SIO_HYST_EN)
    #define PinRS_SIO_REG_HIFREQ     (* (reg8 *) PinRS__SIO_REG_HIFREQ)
    #define PinRS_SIO_CFG            (* (reg8 *) PinRS__SIO_CFG)
    #define PinRS_SIO_DIFF           (* (reg8 *) PinRS__SIO_DIFF)
#endif /* (PinRS__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinRS__INTSTAT)
    #define PinRS_INTSTAT            (* (reg8 *) PinRS__INTSTAT)
    #define PinRS_SNAP               (* (reg8 *) PinRS__SNAP)
    
	#define PinRS_0_INTTYPE_REG 		(* (reg8 *) PinRS__0__INTTYPE)
#endif /* (PinRS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinRS_H */


/* [] END OF FILE */
