#start=led_display.exe#
TITLE LED _DISPLAY
DATA SEGMENT
DATA ENDS

CODE SEGMENT
    START:
        MOV AX,DATA
        MOV DS,AX
        
        CALL GET8BITS
        MOV AX,0
        MOV AL,BL
        
        PUSH AX
        CALL PRINT
        
        MOV AH,4Ch
        INT 21h
        
        
        PRINT PROC
            PUSH BP
            PUSH AX
            
            
            MOV BP,SP
            MOV AX,[BP+6]
            OUT 199,AX
            
            POP AX
            POP BP
            RET
        PRINT ENDP
        
        GET8BITS PROC
            PUSH CX
            PUSH AX
            PUSH DX
            
            MOV CX,8
            
            AGAININPUT:
                
                
                MOV AH,07
                INT 21h 
                
                CMP AL,'.'
                JE EXIT
                
                CMP AL,'0'
                JB AGAININPUT
                
                CMP AL,'1'
                JA AGAININPUT
                
                MOV DL,AL
                MOV AH,02
                INT 21h
                
                SUB DL,30h
                
                ;01010101
                ;00101010   1 => sto CF
                
                SHR DL,1
                RCL BL,1
                 
                
                
            LOOP AGAININPUT
            
            EXIT:
            POP DX
            POP AX
            POP CX
            
            RET
        GET8BITS ENDP
        
CODE ENDS
SOROS SEGMENT STACK
    DB 256 dup(0)
SOROS ENDS
END START