MEMORY
{
   ps7_ram : ORIGIN = 0x00000000, LENGTH = 0x0003FFFF
}

SECTIONS
{
   .text : { ... } > ps7_ram
   .rodata : { ... } > ps7_ram
   .data : { ... } > ps7_ram

   .bss (NOLOAD) : {
      __bss_start__ = .;
      *(.bss)
      *(.bss.*)
      *(COMMON)
      __bss_end__ = .;
   } > ps7_ram

   .stack (NOLOAD) : {
      _stack_end = .;
      . += 0x4000;
      _stack_start = .;
   } > ps7_ram

   /* Add ARM exception mode stacks */
   .undef_stack (NOLOAD) : {
     __undef_stack = .;
     . += 0x400;
   } > ps7_ram
   .abt_stack (NOLOAD) : {
     __abt_stack = .;
     . += 0x400;
   } > ps7_ram
   .fiq_stack (NOLOAD) : {
     __fiq_stack = .;
     . += 0x400;
   } > ps7_ram
   .irq_stack (NOLOAD) : {
     __irq_stack = .;
     . += 0x400;
   } > ps7_ram
   .svc_stack (NOLOAD) : {
     __svc_stack = .;
     . += 0x400;
   } > ps7_ram

   /* ...etc... */
}
