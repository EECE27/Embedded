; ADC with Polling
; Assuming ADC is connected to Port 300H and its control latch to Port 302H

; Assuming 8 Bit ADC and 8 Bit CPU

** OUT     302H, AL    ; Start Conversion
 * IN      AL, 302H    ; Read Conversion Status
   AND     AL, 1       ; EOC is Active Low, check if it's still 1 or 0
   JNZ     *           ; Loop if it's still 1

   IN      AL, 300H    ; Read ADC Conversion Data
   STOSB               ; Store Converted Data
   Loop    **          ; Start Another Conversion

; Assuming 16 Bit CPU

** OUT     302H, AX    ; Start Conversion
 * IN      AX, 302H    ; Read Conversion Status
   AND     AX, 1       ; EOC is Active Low, check if it's still 1 or 0
   JNZ     *           ; Loop if it's still 1

   IN      AX, 300H    ; Read ADC Conversion Data
   STOSW               ; Store Converted Data
   Loop    **          ; Start Another Conversion

; Only Difference is AL -> AX       (for the 16 register)
;             and STOSB -> STOSW    (for Store Word)
