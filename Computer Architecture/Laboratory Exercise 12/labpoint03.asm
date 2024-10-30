;ILIAS STATHAKOS 2017
#start=led_display.exe#
TITLE LED_DISPLAY
DATA SEGMENT
    DEBUG dw 0
    digit DB 3 dup(0)
DATA ENDS

CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
        CALL get_three_decimal_digit
        CALL output_value_to_display
        
        MOV AH,4Ch
        INT 21h
        
        
        output_value_to_display PROC
            PUSH SI
            PUSH AX
            PUSH CX
            PUSH BX
            
            MOV SI,0
            MOV AL,digit[SI]
            MOV BL,100
            MUL BL
            
            ADD CL,AL
            
            INC SI
            MOV AL,digit[SI]
            MOV BL,10
            MUL BL
            
            ADD CL,AL
            
            INC SI
            MOV AL,digit[SI]
            ADD CL,AL
            
            MOV AX,CX
            
            OUT 199,AX
            
            POP BX
            POP CX
            POP AX
            POP SI
            RET
        output_value_to_display ENDP
        
        get_one_decimal_digit PROC
            PUSH AX
            PUSH BP
            
            
            MOV BP,SP
            
            AGAININPUT:
                MOV AH,07
                INT 21h
            
                CMP AL,'0'
                JB AGAININPUT
                
                CMP AL,'9'
                JA AGAININPUT
                
                SUB AL,30h
                MOV AH,0
                MOV [BP-2],AX
                
            POP BP
            POP AX           
            RET
        get_one_decimal_digit ENDP   
        
        get_three_decimal_digit PROC
            PUSH BP
            PUSH SI
            PUSH CX
            PUSH AX
            
            MOV CX,3
            MOV SI,0
            
            LOOP1:
                CALL get_one_decimal_digit
                MOV BP,SP
                MOV AX,[BP-8]
                MOV digit[SI],AL
                INC SI
            LOOP LOOP1
            
            POP AX
            POP SI
            POP CX
            POP AX
            RET
        get_three_decimal_digit ENDP
        
CODE ENDS
SOROS SEGMENT STACK
    DB 256 dup(0)
SOROS ENDS
END ARXH