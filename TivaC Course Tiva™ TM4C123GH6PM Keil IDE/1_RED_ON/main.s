; 1. Activate clock of the port in RCGCGPIO(RCC) REGISTERS PAGE 340
;  - Wait for status bit to be in PRGPIO    --> SKIPED 
; 2. Unlock Pin - only needed for PD7  --> SKIPED 
; 3. Set direction of pin in DIR register page(663)
; 4. Enable pin in DEN register (page 682)

;     Write/Read data : GPIODATA register (page 654)

SYSCTL_RCGCGPIO_R EQU 0x400FE608
GPIO_PORTF_DIR_R  EQU 0x40025400
GPIO_PORTF_DATA_R EQU 0x400253FC
GPIO_PORTF_DEN_R  EQU 0x4002551C
 
				AREA 	|.text|,CODE,READONLY,ALIGN=2
				THUMB
				EXPORT  main

main
		BL 		GPIOF_Init
		
Loop    BL      LIGHT_ON
	    B       Loop 	


GPIOF_Init 
	    LDR      R1,=SYSCTL_RCGCGPIO_R ;load the address of RCC register
		LDR      R0,[R1]               ; load the pointed value by R1 in R0                                  
		ORR      R0,R0,#0x20           ; ORing with 0x20 to Enable bit 5 to enable clock of PORTF 
		STR      R0,[R1]               ; Store back the value in the clock register
        ;SET PIN1 of PORTF As Output
		LDR R1,=GPIO_PORTF_DIR_R
		MOV R0,#0x02
		STR R0,[R1]
		;SET PIN1 of PORTF high
		LDR R1,=GPIO_PORTF_DEN_R
		MOV R0,#0x02
	    STR R0,[R1]
		
		BX  LR    ;branch to Main 


LIGHT_ON
        LDR R1,=GPIO_PORTF_DATA_R
		MOV R0,#0x02
		STR R0,[R1]
		BX  LR 
		
		ALIGN
		END	
		







