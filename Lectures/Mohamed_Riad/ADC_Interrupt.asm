; ADC with Interrupts
; Assuming ADC is connected to Port 300H and its control latch to Port 302H And interrupt signal connected on 304H

; Assuming 8 Bit ADC and 8 Bit CPU

ISR:
    OUT AL, 304H    ; Clear Interrupt Flag
    IN  AL, 300H    ; Read ADC Conversion Data
    STOSB           ; Store Converted Data
    OUT 302H, AL    ; Start a new Conversion
    IRET            ; Return from Interrupt Service Routine (Interrupt Return)

; Assuming 16 Bit CPU

ISR:
    OUT AX, 304H    ; Clear Interrupt Flag
    IN  AX, 300H    ; Read ADC Conversion Data
    STOSW           ; Store Converted Data
    OUT 302H, AX    ; Start a new Conversion
    IRET            ; Return from Interrupt Service Routine (Interrupt Return)

; Only Difference is AL -> AX       (for the 16 register)
;             and STOSB -> STOSW    (for Store Word)