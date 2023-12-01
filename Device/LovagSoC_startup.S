#	Copyright (C) 2023 Benedek Kocsis
#
#   File name:      LovagSoC_startup.S
#   Company:        University of Miskolc
#   Department:     Department of Automation and Infocommunication
#   Author:         Benedek Kocsis
#
#   Description:    LovagSoC startup file.

.global VectorTable
.global Default_Handler

     .section .text.Reset_Handler
     .weak Reset_Handler
     .type Reset_Handler, @function

Reset_Handler:
     li   sp,16384

# zero-init bss section:
     la a0, _sbss
     la a1, _ebss
     bge a0, a1, end_init_bss
loop_init_bss:
     sw zero, 0(a0)
     addi a0, a0, 4
     blt a0, a1, loop_init_bss
end_init_bss:

     call main
     ebreak

.size Reset_Handler, .-Reset_Handler

     .section .text.Default_Handler
Default_Handler:
error_loop:
     j error_loop

.size Default_Handler, .-Default_Handler

     .section .text.VectorTable
     .type VectorTable, @function


VectorTable:
     j Reset_Handler
     j 0                      #Supervisor Software Interrupt
     j 0
     j 0                      #Machine Software Interrupt
     j 0
     j 0                      #Supervisor Timer Interrupt
     j 0
     j CPU_TimTick_Handler    #Machine Timer Interrupt
     j 0
     j 0                      #Supervisor External Interrupt
     j 0
     j CPU_ExtI_Handler       #Machine External Interrupt
     j 0
     j 0
     j 0
     j 0
     j GPIO_IRQHandler        #GPIO Interrupt
     j MotVez_IRQHandler      #MotVez Interrupt
     j SPI_IRQHandler         #SPI_Master Interrupt
     j UART_IRQHandler        #UART Interrupt
     j GPT_IRQHandler         #GPT Interrupt

.weak    CPU_TimTick_Handler
.set     CPU_TimTick_Handler,Default_Handler

.weak    CPU_ExtI_Handler
.set     CPU_ExtI_Handler,Default_Handler

.weak    GPIO_IRQHandler
.set     GPIO_IRQHandler,Default_Handler

.weak    MotVez_IRQHandler
.set     MotVez_IRQHandler,Default_Handler

.weak    SPI_IRQHandler
.set     SPI_IRQHandler,Default_Handler

.weak    UART_IRQHandler
.set     UART_IRQHandler,Default_Handler

.weak    GPT_IRQHandler
.set     GPT_IRQHandler,Default_Handler
