/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio driver
 *
 *  Description:  contain the main Dio types and function prototypes     
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 
typedef enum
{
	channel0 = 0 ,
	channel1  ,
	channel2  ,
	channel3  ,
	channel4  ,
	channel5  ,
	channel6  ,
	channel7  ,
	channel8  ,
	channel9  ,
	channel10  ,
	channel11  ,
	channel12  ,
	channel13  ,
	channel14  ,
	channel15  ,
	channel16  ,
	channel17  ,
	channel18  ,
	channel19  ,
	channel20  ,
	channel21  ,
	channel22  ,
	channel23  ,
	channel24  ,
	channel25  ,
	channel26  ,
	channel27  ,
	channel28  ,
	channel29  ,
	channel30  ,
	channel31  ,
	channel32  ,
	channel33  ,
	channel34  ,
	channel35  ,
	channel36  ,
	channel37  ,
	channel38  ,
	channel39  ,
	channel40  ,
	channel41  ,
	channel42  ,
	channel43  ,
	channel44  ,	
	channel45  ,
	channel46  ,	
	channel47  	 		
}Dio_ChannelType;


typedef enum
{
	portA = 0 ,
	portB     ,
	portC			,
	portD			,
	portE			,
	portF			
}Dio_PortType ;

typedef enum
{
	low = 0 ,
	high		
}Dio_LevelType ;

typedef unsigned char Dio_PortLevelType ; /*from 0 to 255*/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType channelid) ;
void Dio_WriteChannel (Dio_ChannelType channelid , Dio_LevelType level) ; 
Dio_PortLevelType Dio_ReadPort (Dio_PortType portid ) ; 
void Dio_WritePort (Dio_PortType portid  , Dio_PortLevelType level) ; 
 
#endif  

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/ 
 