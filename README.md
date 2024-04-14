
# STM32 ARM Deice Drivers
 This reposoitry containing devic drivers for STM32 Arm Based Microcontrollers but you can use different ARM-Based microcontrollers with minimumm changes. 

## Layed Architecture 
  The codes are written based on layed Architecture concept. 
As each layer is responsible to make a specific type of work. 
#### Usuall any upper layer can call the down layer and not vice versa. 
![Layered Arch](https://github.com/ahmad37/Embedded-Systems/assets/31402712/a995d8d9-4cd1-49ff-b5c9-f1ab758d1a2c)


#### ----------------------------------------------------------------------------

####   Microcontrollers Abstraction Layer (MCAL): 
  It's responsible to interact with the  bare-metal microcontrollers and it's core peripherals. 

  

####  Hardware Abstraction Layer (HAL): 
It's responsible to interact with different hardware componets such as sensors  and input/outout devices like Keypads, LCDs, 7-Segments and others.

#### Service Layer 
 containing services modules such as OS services and Schedulers.

 #### Application Layer (APP): 
Contain the applcation code that you want to build. 

#### Library Layer (LIB): 
 it is a Shared layered between all layers it can  be used in any layer which is shared with it. 


## Note 
   This Design it vary based on your design and your application you want to build. 


## Modules

## Every Module is dividedded into 4 files. 
#### 1- Modname_Private.h <br />       
        This file contains hidded data such as registers definitions and data types definitions. 
#### 2- Modname_interface.h  <br />
        This file contains functions prototypes.<br />
#### 3- Modname_config.h <br />
        This file contains module configuration parameters and this cand be edited by the user. 
#### 4- Modname_prog.c<br />
         This file containd the functions definitions and importing imporntant libraries. 
         

![Modules](https://github.com/ahmad37/Embedded-Systems/assets/31402712/1607f672-fd22-49ab-a24d-8b41b754fa9a)




  ## Author. 
     Ahmad Abdulrahem 
     Ahmad.abdulrahem1@gmail.com

    

