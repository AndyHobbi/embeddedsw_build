/* Modified lscript.ld for Zynq FSBL (single LOAD segment) */
MEMORY
{
   ps7_ram : ORIGIN = 0x00000000, LENGTH = 0x0003FFFF /* 256 KB */
}

/* Stack size and heap size are not strictly needed for FSBL */
__stack_size = 0x4000;
__heap_size = 0x4000;

SECTIONS
{
   .text : {
      *(.vectors)
      *(.init)
      *(.text)
      *(.text.*)
      *(.gnu.linkonce.t.*)
      *(.rodata)
      *(.rodata.*)
      *(.gnu.linkonce.r.*)
      *(.data)
      *(.data.*)
      *(.gnu.linkonce.d.*)
   } > ps7_ram

   .bss (NOLOAD) : {
      *(.bss)
      *(.bss.*)
      *(COMMON)
   } > ps7_ram

   .ARM.exidx : {
      *(.ARM.exidx*)
   } > ps7_ram

   /* Optional: If needed for FSBL tables (mmu_tbl etc) */
   .mmu_tbl (NOLOAD) : {
      *(.mmu_tbl)
   } > ps7_ram

   /* Optional: Small stack/heap region for startup, also in ps7_ram */
   .heap (NOLOAD) : {
      _heap_start = .;
      . += __heap_size;
      _heap_end = .;
   } > ps7_ram

   .stack (NOLOAD) : {
      _stack_end = .;
      . += __stack_size;
      _stack_start = .;
   } > ps7_ram

   /* End of RAM region */
   _end = .;
}
