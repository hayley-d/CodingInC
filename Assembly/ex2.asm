global _start ; makes the _start label available to the linker

section .data
    msg db "Hello world!", 0x0a ; Defines a null-terminated string followed by a newline char (0x0a)
    len equ $-msg ;Calculates the length of the string by subtracting the address of msg from the current address ($).

section .text
_start:
    MOV eax, 4 ; sys_write system call
    MOV ebx, 1 ; file descriptor
    MOV ecx, msg ; bytes to write
    MOV edx, len ; number of bytes to write
    int 0x80 ; preform a system call
    MOV eax, 1 ; sys_exit system call
    MOV ebx, 0 ; exit status is 0
    int 0x80