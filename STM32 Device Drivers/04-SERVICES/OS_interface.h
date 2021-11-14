/*************************************/
/* Authour : Ahmad Abdulrahem        */
/* VER     : V01                     */
/*************************************/

#ifndef OS_INTERFACE_H 
#define OS_INTERFACE_H

void SOS_voidCreatTask(u8 copy_u8IDpriority, u16 copy_u16Periodicity,u16 copy_u16FirstDelay, void(*Fptr)(void));
void SOS_voidStartScheduler(void); 
void SOS_voidDeleteTask(u8 copy_u8PriorityID);
void SOS_voidSuspendTask(u8 copy_u8PriorityID);
void Scheduler(void);
u8   SOS_u8GetTaskState(u8 copy_u8PriorityID);
void SOS_voidIdleTask(void);
void SOS_voidYieldTask(void); //
#endif 
