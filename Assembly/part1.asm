global _start
_start:
    MOV eax, 1
    MOV ebx, 42
    SUB ebx, 29
    INT 0x80