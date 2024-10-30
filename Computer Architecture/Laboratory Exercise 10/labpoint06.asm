;ILIAS STATHAKOS 2017
#start=led_display.exe#
TITLE LED_DISPLAY2
DATA SEGMENT
    NL DB 10,13,"$"
DATA ENDS

CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
        CALL get_two_hex_digits
        CALL output_value_to_display
        CALL print
        
        MOV AH,4Ch
        INT 21h
        
        print PROC
            PUSH AX
            PUSH BP
            PUSH CX
            PUSH BX
            PUSH DX
            
            LEA DX,NL
            MOV AH,09h
            INT 21h
            
            MOV BP,SP
            MOV BX,[BP-20] 
            MOV CX,8
            
            printLoop:
                MOV DX,0
                SHL BL,1
                RCL DL,1
                ADD DL,30h
                
                MOV AH,02h
                INT 21h
            LOOP printLoop
            
            POP DX
            POP BX
            POP CX
            POP BP
            POP AX
            RET
        print ENDP 
        
        
        output_value_to_display PROC
            PUSH BP
            PUSH AX
            PUSH CX
            PUSH BX
            
            MOV CX,0
            MOV BP,SP
            
            
            MOV AX,[BP-18]
            MOV BL,16
            MUL BL
            
            ADD CL,AL
            
            MOV AX,[BP-20]
            ADD CL,AL
            
            MOV AX,CX
            MOV [BP-22],AX
            
            OUT 199,AX
            
            
            POP BX
            POP CX
            POP AX
            POP BP
            RET
        output_value_to_display ENDP
        
        get_one_hex_digit PROC
            PUSH AX
            PUSH BP
            PUSH DX
            
            
            MOV BP,SP
            
            AGAININPUT:
                MOV AH,07
                INT 21h
                
                CMP AL,'0'
                JB AGAININPUT
                
                CMP AL,'9'
                JBE CONTINUE_BIN
                
                CMP AL,'A'
                JB AGAININPUT
                
                CMP AL,'F'
                JA AGAININPUT
                
                CONTINUE_HEX:
                    MOV DL,AL
                    MOV AH,02h
                    INT 21h 
                    SUB DL,55
                    MOV DH,0
                    MOV [BP-2],DX
                    JMP CONTINUE
                    
                CONTINUE_BIN:
                    MOV DL,AL
                    MOV AH,02h
                    INT 21h 
                    SUB DL,30h
                    MOV DH,0
                    MOV [BP-2],DX
            
            CONTINUE:
                
                                
                POP DX    
                POP BP
                POP AX           
                RET
        get_one_hex_digit ENDP   
        
        get_two_hex_digits PROC
            PUSH BP
            PUSH SI
            PUSH CX
            PUSH AX
            PUSH DX
            
            MOV CX,2
            MOV SI,1
            
            LOOP1:
                CALL get_one_hex_digit
                MOV BP,SP 
                MOV AL,2
                MUL SI
                MOV DX,0 
                MOV DL,AL 
                
                MOV AX,[BP-10]
                SUB BP,DX
                MOV [BP-14],AX
                INC SI
            LOOP LOOP1
            
            POP DX
            POP AX
            POP CX
            POP SI
            POP BP
            RET
        get_two_hex_digits ENDP
        
CODE ENDS
SOROS SEGMENT STACK
    DB 256 dup(0)
SOROS ENDS
END ARXH