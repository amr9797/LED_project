#include "app_inc.h"
 

static unsigned long  count = 1 ; /*count variable */ 
static unsigned long  on_time = 0 ; /*on time delay*/
static unsigned long  off_time = 0 ; /*off time delay*/ 
  
int main(void)
{  
	set_on_off (1,1) ; /*set required in/off delays*/ 
	app_init() ;  /*initialize the modules*/
	
	  while (1)
		{ 	
		 app_endless() ; /*app starts here*/ 
		}
		
}

/*to init all the used modules*/ 
static void app_init (void) 
{  
  Port_Init(Pins); /*init the port module */ 
	systick_init() ; /*init systick module  */ 
	callback_reg(led_delay_toggle) ; /*register the ISR*/
	systick_start() ; /*start the timer*/ 
	
}

/*the call back systick ISR */ 
static void led_delay_toggle (void) 
{  
   count-- ; /*count down*/ 
	
}

/*app endless */
static void app_endless (void)
{
	if (count == 0 ) /*check if the desired delay time ended*/ 
	  {
	    if(LED_State() == off )  /*toggle the led and set the new state delay time*/ 
	    {
	    	Turn_LED_On() ; 
		    count=on_time;
	    }
	    else
	    { 
	    	Turn_LED_Off() ; 
	    	count = off_time ;
	    }
	
    }
  else
    {
				/*do nothing*/
    }
	
}
/*to set on/off timings in seconds*/ 
static void set_on_off (unsigned long on ,unsigned long off )
{
	on_time = on ;
	off_time =off ;
}

