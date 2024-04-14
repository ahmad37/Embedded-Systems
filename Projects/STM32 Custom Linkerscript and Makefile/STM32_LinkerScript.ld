Entry(Reset_Handler)

MEMORY
{
  FLASH(rx):ORIGIN =0x08000000,LENGTH =1024K
  SRAM(rwx):ORIGIN =0x20000000,LENGTH =96K
}


SECTIONS
{

 .text :
 {
   /*To Tell Linker to include all .section data i used a wild card 
     and This acceptable due to I use GNU GCC Compiler , it's acceptable in linux 
	 but be carefule it's a compiler dependent also :D
	*/

   /*Merge All .isr_vetor in all object files */
   *(.isr_vector)
   
   /*Merge All .text in all object files */
   *(.text)
   
   /*Merge All .rodata in all object files */
   *(.rodata)
   
   _end_of_text_section=.; /*store the last address of .text section*/
 
 }>FLASH
  
  /* ALL OF THESE SYNTAX ARE TRUE : I want to store the .text into flash 
     in this case : VMA = LMA 
   >vma AT> lma            -- virtual address = load address 
   >FLASH AT> FLASH        -- save vma as equal to lma -> this mean store in flash also 
   >FLASH                  -- store in flash 
  */
 
 .data :
 {_start_of_data_section=.; 
   *(.data)
   _end_of_data_section=.;
 }> SRAM AT> FLASH 
 
 .bss :
 {
  _start_of_bss_section=.; 
   *(.bss)
   _end_of_bss_section=.; 
 }> SRAM
 
}



