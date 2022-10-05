/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  port.c
 *        \brief  port Driver
 *
 *      \details  The Driver Configure All gpio channels of the mcu 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "port.h"
#include "port_config.h"
#include "tm4creg.h" 
#include "reg_access.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          :  void Port_Init (const Port_ConfigType * configptr )                                      
* \Description     : initialize port Module by parsing the Configuration 
*                    into gpio registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : configptr  array of the configured pins                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 void Port_Init (const Port_ConfigType * configptr ) 
 {
	 unsigned char i , pin , port ; 
	 GPIO_Type * GPIO_Base  ; 
	 for(i=0 ; i< pins_num ; i++)
	 {
		 port = (configptr[i]).pinid / 8 ; /*get port*/
		 pin = (configptr[i]).pinid % 8 ; /*get pin*/
		 set_bit(SYSCTL_RCGCGPIO_R ,port) ;  /*enable lock */ 
		 
		 switch (port)  /*choose the correct port base */ 
		 {
			 case 0 :
				 GPIO_Base = GPIOA_Access ; 
				 break ;
			 case 1 :
				 GPIO_Base = GPIOB_Access ; 
				 break ;
			 case 2 : 
				 GPIO_Base = GPIOC_Access ; 
				 break ; 
			 case 3 : 
				 GPIO_Base = GPIOD_Access ; 
			   break ; 
			 case 4 :
				 GPIO_Base = GPIOE_Access ; 
			   break ; 
			 case 5 :
				 GPIO_Base = GPIOF_Access ; 
			 default :
				 break ; 
			 
		 }
		 /*set the Diection of portn pin_x *********************************/
				 if((configptr[i]).dir == input) 
				 {
					 reset_bit(GPIO_Base->DIR,pin) ; 
				 }
				 else
				 {
					 if((configptr[i]).dir == output)
					 {
					 set_bit(GPIO_Base->DIR,pin) ; 
					 }
					 else
					 {
						 /*do nothing // wrong config*/ 
					 }
				 }
				 /*set the Mode of portn pin_x *********************************/
				 if((configptr[i]).mode == analog) 
				 {
					 set_bit(GPIO_Base->AMSEL,pin) ; 
				 }
				 else
				 {
					 if((configptr[i]).mode == digital)
					 {
					 set_bit(GPIO_Base->DEN,pin) ; 
					 }
					 else
					 {
						 /*do nothing // wrong config*/ 
					 }
				 }
				 
				 
				 
				  /*set the level of portn pin_x if ouput ******************************************/
				 if((configptr[i]).dir == output) 
				 {
					  if((configptr[i]).level == LOW )
						{
							reset_bit(GPIO_Base->DATA , pin) ; 
						}
						else
						{ 
							 if((configptr[i]).level == HIGH )
							 {
								 
								 set_bit(GPIO_Base->DATA , pin) ;
							 }
							 else
							 {
								/*do nothing // wrong config*/  
							 }
						 }
				 }
				 else
				 {
					 /*do nothing pin is input*/ 
				 }
				 
				 /*set the attach of portn pin_x if ouput ******************************************/
				 
				 switch ((configptr[i]).attach)
				 {
					 case open_drain :
						 set_bit(GPIO_Base->ODR , pin) ;
					 break ; 
					 case pull_up : 
						 set_bit(GPIO_Base->PUR , pin) ;
					 break ;
					 
					 case pull_down : 
						 set_bit(GPIO_Base->PDR , pin) ;
					 break ; 
					 
					 
				 }
				 
				 /*set the current of portn pin_x if ouput ******************************************/
				 
				 switch ((configptr[i]).current)
				 {
					 case DRV2 :
						 set_bit(GPIO_Base->DR2R  , pin) ;
					 break ; 
					 case DRV4 : 
						 set_bit(GPIO_Base->DR4R , pin) ;
					 break ;
					 
					 case DRV8 : 
						 set_bit(GPIO_Base->DR8R , pin) ;
					 break ; 
					 
					 
						 
				 }
	 }
	 
 }

/**********************************************************************************************************************
 *  END OF FILE: port.c
 *********************************************************************************************************************/
