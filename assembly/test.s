	AREA    RESET, DATA, READONLY
    EXPORT  __Vectors
    EXPORT  __main

__Vectors
    DCD     0x20001000      ; Initial Stack Pointer
    DCD     __main          ; Reset Handler

    AREA    |.text|, CODE, READONLY
    ENTRY

__main
    MOV R0,#0x15
	MOV R1,#0x3
	MUL R2,R1,R0
stop
	B	stop
	ALIGN
END