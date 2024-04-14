/*
 * main.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Ahmad
 */

/*lib includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* RCC INCLUDES*/
#include "RCC_interface.h"

/*GPIO INCLUDES */
#include "GPIO_interface.h"

#include "NVIC_interface.h"

/*Systick timer */
#include "STK_interface.h"

/*LED MATRIX*/
#include"LEDMRX_interface.h"



u8 DataArrayA0[]={0, 254, 18, 18, 18, 254, 0, 254  };
u8 DataArrayA1[]={16, 16, 254, 0, 254, 2, 4, 2  };
u8 DataArrayA2[]={254, 0, 254, 18, 18, 254, 0, 254  };
u8 DataArrayA3[]={254, 130, 130, 124 };
//u8 DataArrayA4[]={254, 50, 50, 254, 0, 254, 130, 124, 0, 0, 0, 0, 0, 0 };
u8 DataArrayA5[]={0  ,0  ,0  ,0  ,0  ,126,0  ,0  };
u8 DataArrayA6[]={0  ,0  ,0  ,0  ,0  ,0  ,126,0  };
u8 DataArrayA7[]={0  ,0  ,0  ,0  ,0  ,0  ,0  ,126};
u8 * ArrayPtr[]={
		DataArrayA0,
		DataArrayA1,
		DataArrayA2,
		DataArrayA3,
		//DataArrayA4,
		DataArrayA5,
		DataArrayA6,
		DataArrayA7
};
/*********************************************************/
u8 DataArrayA[]={124, 20, 20, 124, 0, 0, 0, 0  };
u8 DataArrayH[]={0, 124, 16, 16, 124, 0, 0, 0  };
u8 DataArrayM[]={0, 0, 124, 8, 16, 8, 124, 0  };
u8 DataArrayA_2[]={0, 0, 0, 0, 124, 20, 20, 124  };
u8 DataArrayD[]={0, 0, 0, 0, 0, 124, 68, 56  };

u8 * ArrayPtr_AHMAD[]={
		DataArrayA,
		DataArrayH,
		DataArrayM,
		DataArrayA_2,
		DataArrayD
};

u8 Array0[]={255, 168, 170, 170, 136, 170, 170, 170  };
u8 Array1[]={255, 84, 85, 85, 68, 85, 85, 85         };
u8 Array2[]={255, 42, 170, 170, 162, 170, 170, 170   };
u8 Array3[]={255, 149, 85, 213, 209, 213, 213, 213   };
u8 Array4[]={255, 202, 42, 234, 232, 234, 234, 234   };
u8 Array5[]={255, 37, 85, 117, 116, 117, 117, 117    };
u8 Array6[]={255, 73, 85, 93, 93, 93, 93, 93         };
u8 Array7[]={255, 36, 170, 174, 174, 174, 174, 174   };
u8 Array8[]={255, 9, 106, 107, 11, 107, 107, 107     };
u8 Array9[]={255, 66, 90, 90, 66, 90, 90, 90         };
u8 Array10[]={255, 144, 86, 86, 80, 86, 86, 150       };
u8 *TdArray[] ={
		Array0 ,
		Array1 ,
		Array2 ,
		Array3 ,
		Array4 ,
		Array5 ,
		Array6 ,
		Array7 ,
		Array8 ,
		Array9 ,
		Array10

};
/*********************************************************/
void main(void){

	    /* Enable HSE Crystal As Clock Source */
		 RCC_voidInitSysClock();
		 /*Enable GPIOA Clock */
		 RCC_voidEnableClock(RCC_APB2, 2);
		 /*Enable GPIOB Clock */
		 RCC_voidEnableClock(RCC_APB2, 3);
		 /*Enable GPIOC Clock */
		 RCC_voidEnableClock(RCC_APB2, 4);

		 /*init systick*/
		 MSTK_voidInit();
		 /*init led matrix*/
		 HLEDMRX_voidInit();

  while (1)
  {
	/*  HLEDMRX_voidDisplay(ArrayPtr_AHMAD[0]);
	  HLEDMRX_voidDisplay(ArrayPtr_AHMAD[1]);
	  HLEDMRX_voidDisplay(ArrayPtr_AHMAD[2]);
	  HLEDMRX_voidDisplay(ArrayPtr_AHMAD[3]);
	  HLEDMRX_voidDisplay(ArrayPtr_AHMAD[4]);
*/
/*	  HLEDMRX_voidDisplay(ArrayPtr[0]);
	  HLEDMRX_voidDisplay(ArrayPtr[1]);
	  HLEDMRX_voidDisplay(ArrayPtr[2]);
	  HLEDMRX_voidDisplay(ArrayPtr[3]);
	 // HLEDMRX_voidDisplay(ArrayPtr[4]);
	*/

	  HLEDMRX_voidDisplay(TdArray[0 ]);
	  HLEDMRX_voidDisplay(TdArray[1 ]);
	  HLEDMRX_voidDisplay(TdArray[2 ]);
	  HLEDMRX_voidDisplay(TdArray[3 ]);
	  HLEDMRX_voidDisplay(TdArray[4 ]);
	  HLEDMRX_voidDisplay(TdArray[5 ]);
	  HLEDMRX_voidDisplay(TdArray[6 ]);
	  HLEDMRX_voidDisplay(TdArray[7 ]);
	  HLEDMRX_voidDisplay(TdArray[8 ]);
	  HLEDMRX_voidDisplay(TdArray[9 ]);
	  HLEDMRX_voidDisplay(TdArray[10]);


  }

}
