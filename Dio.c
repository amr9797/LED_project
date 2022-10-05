/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Dio driver 
 *
 *      \details  contains all the functions of Dio module 
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
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
* \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType channelid)         
* \Description     : read the requred channel and returned its state                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : channelid   the channel number wanted to be read                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType  channel state                                 
*******************************************************************************/
 Dio_LevelType Dio_ReadChannel (Dio_ChannelType channelid) 
 {
	 unsigned char  pin , port ,read ; 
	 GPIO_Type * GPIO_Base ; 
	 
	 port = channelid /8 ; /*get the port*/
	 pin = channelid % 8 ; /*get the pin*/
	 
	 switch (port) /*choose the target port base address*/
	 {
		 case portA : 
			 GPIO_Base = GPIOA_Access ; 
			break ;
		 case portB :
			 GPIO_Base = GPIOB_Access ;
			break ;
		 case portC : 
			  GPIO_Base = GPIOC_Access ;
			break ;
		 case portD : 
			  GPIO_Base = GPIOD_Access ;
			break ;
		 case portE :
        GPIO_Base = GPIOE_Access ;			 
			break ;
		 case portF :
        GPIO_Base = GPIOF_Access ;			 
			break ;
		 default : 
			 /*do nothing*/
			 break ; 
	 }
	 read = (unsigned char)Bit_Band_read_bit(GPIO_Base->DATA,pin) ; /*bit-banding read the channel*/
	 
	 return read ; 
		 
 }
 
 /******************************************************************************
* \Syntax          : void Dio_WriteChannel (Dio_ChannelType channelid , Dio_LevelType level)        
* \Description     : write the level to the channelid                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : channelid    the required DIO channel 
                     level   the required level high or low  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
 
void Dio_WriteChannel (Dio_ChannelType channelid , Dio_LevelType level) 
{
	unsigned char  pin , port  ; 
	 GPIO_Type * GPIO_Base ; 
	 
	 port = channelid /8 ; /*get the target port*/
	 pin = channelid % 8 ; /*get the pin */ 
	 
	 switch (port) /*choose the requird port base address*/
	 {
		 case portA : 
			 GPIO_Base = GPIOA_Access ; 
			break ;
		 case portB :
			 GPIO_Base = GPIOB_Access ;
			break ;
		 case portC : 
			  GPIO_Base = GPIOC_Access ;
			break ;
		 case portD : 
			  GPIO_Base = GPIOD_Access ;
			break ;
		 case portE :
        GPIO_Base = GPIOE_Access ;			 
			break ;
		 case portF :
        GPIO_Base = GPIOF_Access ;			 
			break ;
		 default : 
			 /*do nothing*/
			 break ; 
	 }
	 if(level == high) /*perform wrtte operation to the target pin*/ 
	 {
		 Bit_Band_set_bit(GPIO_Base->DATA,pin); 
	 }		
   else	 
	 {
		    if(level == low)
	      {
		       Bit_Band_reset_bit(GPIO_Base->DATA,pin); 
	      }
				else
				{
					/*do nothing wrong parameters */
				}
   	 
		}
}
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType portid )         
* \Description     : read the requred port and returned its state                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : port  : the port num wanted to be read                      
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType   read value

*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType portid ) 
{
		GPIO_Type * GPIO_Base ;
    Dio_PortLevelType read ; 	
	
	switch (portid) /*choose the target port base address*/ 
	 {
		 case portA : 
			 GPIO_Base = GPIOA_Access ; 
			break ;
		 case portB :
			 GPIO_Base = GPIOB_Access ;
			break ;
		 case portC : 
			  GPIO_Base = GPIOC_Access ;
			break ;
		 case portD : 
			  GPIO_Base = GPIOD_Access ;
			break ;
		 case portE :
        GPIO_Base = GPIOE_Access ;			 
			break ;
		 case portF :
        GPIO_Base = GPIOF_Access ;			 
			break ;
		 default : 
			 /*do nothing*/
			 break ; 
	 }
	 read = (Dio_PortLevelType)GPIO_Base->DATA ; /*read the port*/ 
	return read   ;
}

/******************************************************************************
* \Syntax          : void Dio_WritePort (Dio_PortType portid  , Dio_PortLevelType level)        
* \Description     : write level to portid                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : portid   port wanted to be written 
                     level    the write level 
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Dio_WritePort (Dio_PortType portid  , Dio_PortLevelType level) 
{
	GPIO_Type * GPIO_Base ; 
	
	switch (portid)  /*choose the required port base address*/ 
	 {
		 case portA : 
			 GPIO_Base = GPIOA_Access ; 
			break ;
		 case portB :
			 GPIO_Base = GPIOB_Access ;
			break ;
		 case portC : 
			  GPIO_Base = GPIOC_Access ;
			break ;
		 case portD : 
			  GPIO_Base = GPIOD_Access ;
			break ;
		 case portE :
        GPIO_Base = GPIOE_Access ;			 
			break ;
		 case portF :
        GPIO_Base = GPIOF_Access ;			 
			break ;
		 default : 
			 /*do nothing*/
			 break ; 
	 }
	 GPIO_Base->DATA = level ; /*perform the write*/
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/