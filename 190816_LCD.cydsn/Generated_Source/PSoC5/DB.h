/*******************************************************************************
* File Name: DB.h  
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

#if !defined(CY_PINS_DB_H) /* Pins DB_H */
#define CY_PINS_DB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DB__PORT == 15 && ((DB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DB_Write(uint8 value);
void    DB_SetDriveMode(uint8 mode);
uint8   DB_ReadDataReg(void);
uint8   DB_Read(void);
void    DB_SetInterruptMode(uint16 position, uint16 mode);
uint8   DB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DB_SetDriveMode() function.
     *  @{
     */
        #define DB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DB_DM_RES_UP          PIN_DM_RES_UP
        #define DB_DM_RES_DWN         PIN_DM_RES_DWN
        #define DB_DM_OD_LO           PIN_DM_OD_LO
        #define DB_DM_OD_HI           PIN_DM_OD_HI
        #define DB_DM_STRONG          PIN_DM_STRONG
        #define DB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DB_MASK               DB__MASK
#define DB_SHIFT              DB__SHIFT
#define DB_WIDTH              8u

/* Interrupt constants */
#if defined(DB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DB_SetInterruptMode() function.
     *  @{
     */
        #define DB_INTR_NONE      (uint16)(0x0000u)
        #define DB_INTR_RISING    (uint16)(0x0001u)
        #define DB_INTR_FALLING   (uint16)(0x0002u)
        #define DB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DB_INTR_MASK      (0x01u) 
#endif /* (DB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DB_PS                     (* (reg8 *) DB__PS)
/* Data Register */
#define DB_DR                     (* (reg8 *) DB__DR)
/* Port Number */
#define DB_PRT_NUM                (* (reg8 *) DB__PRT) 
/* Connect to Analog Globals */                                                  
#define DB_AG                     (* (reg8 *) DB__AG)                       
/* Analog MUX bux enable */
#define DB_AMUX                   (* (reg8 *) DB__AMUX) 
/* Bidirectional Enable */                                                        
#define DB_BIE                    (* (reg8 *) DB__BIE)
/* Bit-mask for Aliased Register Access */
#define DB_BIT_MASK               (* (reg8 *) DB__BIT_MASK)
/* Bypass Enable */
#define DB_BYP                    (* (reg8 *) DB__BYP)
/* Port wide control signals */                                                   
#define DB_CTL                    (* (reg8 *) DB__CTL)
/* Drive Modes */
#define DB_DM0                    (* (reg8 *) DB__DM0) 
#define DB_DM1                    (* (reg8 *) DB__DM1)
#define DB_DM2                    (* (reg8 *) DB__DM2) 
/* Input Buffer Disable Override */
#define DB_INP_DIS                (* (reg8 *) DB__INP_DIS)
/* LCD Common or Segment Drive */
#define DB_LCD_COM_SEG            (* (reg8 *) DB__LCD_COM_SEG)
/* Enable Segment LCD */
#define DB_LCD_EN                 (* (reg8 *) DB__LCD_EN)
/* Slew Rate Control */
#define DB_SLW                    (* (reg8 *) DB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DB_PRTDSI__CAPS_SEL       (* (reg8 *) DB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DB_PRTDSI__OE_SEL0        (* (reg8 *) DB__PRTDSI__OE_SEL0) 
#define DB_PRTDSI__OE_SEL1        (* (reg8 *) DB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DB_PRTDSI__OUT_SEL0       (* (reg8 *) DB__PRTDSI__OUT_SEL0) 
#define DB_PRTDSI__OUT_SEL1       (* (reg8 *) DB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DB_PRTDSI__SYNC_OUT       (* (reg8 *) DB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DB__SIO_CFG)
    #define DB_SIO_HYST_EN        (* (reg8 *) DB__SIO_HYST_EN)
    #define DB_SIO_REG_HIFREQ     (* (reg8 *) DB__SIO_REG_HIFREQ)
    #define DB_SIO_CFG            (* (reg8 *) DB__SIO_CFG)
    #define DB_SIO_DIFF           (* (reg8 *) DB__SIO_DIFF)
#endif /* (DB__SIO_CFG) */

/* Interrupt Registers */
#if defined(DB__INTSTAT)
    #define DB_INTSTAT            (* (reg8 *) DB__INTSTAT)
    #define DB_SNAP               (* (reg8 *) DB__SNAP)
    
	#define DB_0_INTTYPE_REG 		(* (reg8 *) DB__0__INTTYPE)
	#define DB_1_INTTYPE_REG 		(* (reg8 *) DB__1__INTTYPE)
	#define DB_2_INTTYPE_REG 		(* (reg8 *) DB__2__INTTYPE)
	#define DB_3_INTTYPE_REG 		(* (reg8 *) DB__3__INTTYPE)
	#define DB_4_INTTYPE_REG 		(* (reg8 *) DB__4__INTTYPE)
	#define DB_5_INTTYPE_REG 		(* (reg8 *) DB__5__INTTYPE)
	#define DB_6_INTTYPE_REG 		(* (reg8 *) DB__6__INTTYPE)
	#define DB_7_INTTYPE_REG 		(* (reg8 *) DB__7__INTTYPE)
#endif /* (DB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DB_H */


/* [] END OF FILE */
