/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  tm4creg.h
 *       Module:  common 
 *
 *  Description:  include the registers of tm4c123 microcontroller      
 *  
 *********************************************************************************************************************/
#ifndef tm4creg_H
#define tm4creg_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/*****************************************************************************
//
// NVIC registers  
//
*****************************************************************************/
#define IRQ_enable_base         ((volatile uint32_t *)0xE000E100)
#define IRQ_pri_base            ((volatile uint8_t *)0xE000E400)

#define NVIC_APINT_R            (*((volatile uint32_t*)0xE000ED0C))
	
#define NVIC_ST_CTRL_R          (*((volatile uint32_t*)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t*)0xE000E014))
	
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t*)0x400FE608))

	

/**********************************************************************************************************************
 *  GPIO registers/types 
 *********************************************************************************************************************/

typedef struct {                                                                                     
   uint32_t  RESERVED0[255];                    /*rserved for the bitmasking area 255 locations*/ 
   uint32_t  DATA;                              /* GPIO Data                                                             */
   uint32_t  DIR;                               /* GPIO Direction                                                        */
   uint32_t  IS;                                /* GPIO Interrupt Sense                                                  */
   uint32_t  IBE;                               /* GPIO Interrupt Both Edges                                             */
   uint32_t  IEV;                               /* GPIO Interrupt Event                                                  */
   uint32_t  IM;                                /* GPIO Interrupt Mask                                                   */
   uint32_t  RIS;                               /* GPIO Raw Interrupt Status                                             */
   uint32_t  MIS;                               /* GPIO Masked Interrupt Status                                          */
   uint32_t  ICR;                               /* GPIO Interrupt Clear                                                  */
   uint32_t  AFSEL;                             /* GPIO Alternate Function Select                                        */
   uint32_t  RESERVED1[55];
   uint32_t  DR2R;                              /* GPIO 2-mA Drive Select                                                */
   uint32_t  DR4R;                              /* GPIO 4-mA Drive Select                                                */
   uint32_t  DR8R;                              /* GPIO 8-mA Drive Select                                                */
   uint32_t  ODR;                               /* GPIO Open Drain Select                                                */
   uint32_t  PUR;                               /* GPIO Pull-Up Select                                                   */
   uint32_t  PDR;                               /* GPIO Pull-Down Select                                                 */
   uint32_t  SLR;                               /* GPIO Slew Rate Control Select                                         */
   uint32_t  DEN;                               /*GPIO Digital Enable                                                   */
   uint32_t  LOCK;                              /* GPIO Lock                                                             */
   uint32_t  CR;                                /* GPIO Commit                                                           */
   uint32_t  AMSEL;                             /* GPIO Analog Mode Select                                               */
   uint32_t  PCTL;                              /* GPIO Port Control                                                     */
   uint32_t  ADCCTL;                            /* GPIO ADC Control                                                      */
   uint32_t  DMACTL;                            /* GPIO DMA Control                                                      */
} GPIO_Type;

#define GPIOA_BASE                      0x40004000UL
#define GPIOB_BASE                      0x40005000UL
#define GPIOC_BASE                      0x40006000UL
#define GPIOD_BASE                      0x40007000UL
#define GPIOE_BASE                      0x40024000UL
#define GPIOF_BASE                      0x40025000UL

#define GPIOA_Access                    ((GPIO_Type              *) GPIOA_BASE)
#define GPIOB_Access                    ((GPIO_Type              *) GPIOB_BASE)
#define GPIOC_Access                    ((GPIO_Type              *) GPIOC_BASE)
#define GPIOD_Access                    ((GPIO_Type              *) GPIOD_BASE)
#define GPIOE_Access                    ((GPIO_Type              *) GPIOE_BASE)
#define GPIOF_Access                    ((GPIO_Type              *) GPIOF_BASE)
 
#endif  
 
/**********************************************************************************************************************
 *  END OF FILE: tm4creg.h
 *********************************************************************************************************************/
