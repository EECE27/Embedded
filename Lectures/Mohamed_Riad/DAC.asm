; DAC Code

; Count is a variable containing required number of covnersions
; DX is a register holding the address of where the DAC is connected

; Assuming 8 bit data

    MOV CX, Count    ; Move value of Count to CX register
 *  OUT DX, AL       ; Start Conversion signal

    MOV AL, [SI]     ; SI is a pointer, move the data its poiting at to register AL
    INC SI           ; Increment SI to point at the next number in the array

;   Add Delay here for "Ts" sampling Time

    DEC CX           ; Decrement Loop Iterator
    JNZ *            ; Loop if the counter hasn't finished yet

; Alternative Versions:

;-----------------

MOV AL, [SI]
INC SI
; Can be replaced with
LODSB

;-----------------

DEC CX
JNZ *
; Can be replaced with
LOOP *

;-----------------
; Delay can be implemented with an empty loop like this

    MOV BL, M   ; Where M contains the number of loops required for delay
**  DEC BL
    JNZ **


; Final Altered Code:

*   OUT DX, AL
    LODSB

    MOV BL, M
**  DEC BL
    JNZ **

    LOOP *




