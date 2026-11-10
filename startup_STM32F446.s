.syntax unified
.cpu cortex-m4
.thumb

.global stack
.global reset_handler
.global main

.section .vector_table,"a",%progbits
.word stack
.word reset_handler + 1

.section .text.reset_handler
reset_handler :
    bl main
1:
    b 1b
    