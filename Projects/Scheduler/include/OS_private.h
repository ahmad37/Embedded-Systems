/*************************************/
/* Authour : Ahmad Abdulrahem        */
/* VER     : V01                     */
/*************************************/

#ifndef OS_PRIVATE_H 
#define OS_PRIVATE_H


typedef enum {
	DORMANT=0,
	READY,
	RUNNING,
	SUSPENDED,
}Task_State;


typedef struct {
	u16 Periodicity;    /* Periodicity of the Task*/ 
    void (*Fptr)(void);	/*Pointer to the fucntion related to the task*/ 
	u16 FirstDelay; 
	Task_State state;
}Task_TCB; 

#endif 
