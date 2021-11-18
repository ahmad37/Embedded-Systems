/*************************************/
/* Authour : Ahmad Abdulrahem        */
/* VER     : V01                     */
/*************************************/

#include "STD_TYPES.h" 
#include "BIT_MATH.h"
 
#include "STK_interface.h"  
 
#include "OS_interface.h" 

#include "OS_config.h" 
#include "OS_private.h"

#define NULL (void*)0

/*Array of Tasks */ 
static Task_TCB OS_Tasks[NUMBER_OF_TASKS]= {{NULL}};

void SOS_voidCreatTask(u8 copy_u8PriorityID, u16 copy_u16Periodicity,u16 copy_u16FirstDelay, void(*ptr)(void))
{

	OS_Tasks[copy_u8PriorityID].Periodicity = copy_u16Periodicity;
	OS_Tasks[copy_u8PriorityID].FirstDelay= copy_u16FirstDelay;
	OS_Tasks[copy_u8PriorityID].Fptr = ptr;
	OS_Tasks[copy_u8PriorityID].state = READY;

}
void SOS_voidStartScheduler(void)
{
	/*Initializations */ 
	MSTK_voidInit(); 
	/* 1MS ticks-HSE 8MHZ */ 
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);//1000us=1MS  

}

void Scheduler(void)
{
#if NUMBER_OF_TASKS <= 0
	NUMBER_OF_TASKS=1;  /*for idle Task -run CPU in lower power consumption mode - sleep mode */
#endif

	/*check periodicity for all functions */
	for (u8 i=0; i<NUMBER_OF_TASKS;i++)
	  {
/* Check size of task, check state of tasks, check if there is a valid function assigned to the task*/
	    if ((OS_Tasks[i].state == READY) && (OS_Tasks[i].Fptr != NULL) )
	    {
	    	if(OS_Tasks[i].FirstDelay==0)
			{  /*reload first delay with periodicity and decrement a copy of it's value till reach 0 */
				OS_Tasks[i].FirstDelay= OS_Tasks[i].Periodicity-1;
				/*change task state to running state*/
				//OS_Tasks[i].state=RUNNING;
				/*call(run) the function*/
				OS_Tasks[i].Fptr();
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}
	    }//end of if()
	}//end of for loop
}//end of function

void SOS_voidDeleteTask(u8 copy_u8PriorityID)
{
	OS_Tasks[copy_u8PriorityID].Periodicity = 0;
    OS_Tasks[copy_u8PriorityID].FirstDelay  = 0;
    OS_Tasks[copy_u8PriorityID].Fptr        = NULL;
    OS_Tasks[copy_u8PriorityID].state       = DORMANT;
/*update in an location /array/ of that the task number x deleted-to use it's space if needed*/
} 
void SOS_voidSuspendTask(u8 copy_u8PriorityID)
{
	OS_Tasks[copy_u8PriorityID].state       = SUSPENDED;
}


u8   SOS_u8GetTaskState(u8 copy_u8PriorityID)
{
  u8 Local_u8State=100;
  Local_u8State= OS_Tasks[copy_u8PriorityID].state;
  return Local_u8State;
}

void SOSvoidGoReadyState()
{

}















