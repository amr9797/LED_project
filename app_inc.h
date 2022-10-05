/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  app_inc.h
 *       Module:  APP 
 *
 *  Description:  contains include of the required modules headers and app functions prototypes       
 *  
 *********************************************************************************************************************/
 
#include "port.h"
#include "LED.h"
#include "systick.h"
static void led_delay_toggle (void) ; 
static void app_init (void) ; 
static void app_endless (void) ; 	
static void set_on_off (unsigned long on ,unsigned long off );
