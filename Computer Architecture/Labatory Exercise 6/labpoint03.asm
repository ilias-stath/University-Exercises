;Ilias Stathakos 2017
TITLE HEX2BIN
DATA SEGMENT
    MSG1 DB 10,13,"DWSE 1 HEX PSIFIO: $"
    MSG2 DB 10,13,"O BIN EINAI: $"
    HEX DB 0
    BIN DB 4 DUP(0)
DATA ENDS
CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
        MOV CX,1
        MAIN_LOOP:
            LEA DX,MSG1
            MOV AH,9
            INT 21h
            
            INPUT:
                MOV AH,07
                INT 21h
                
                CMP AL,'.'
                JE EXIT
                
                CMP AL,48
                JB INPUT
                CMP AL,57
                JBE VALID1
                CMP AL,65
                JB INPUT
                CMP AL,70
                JA INPUT
                
                VALID2:
                    MOV HEX,AL
                    MOV DL,AL
                    MOV AH,02h
                    INT 21h
                    
                    SUB HEX,55
                    
                    JMP NEXT
                    
                VALID1:
                    MOV HEX,AL
                    MOV DL,AL
                    MOV AH,02h
                    INT 21h
                    
                    SUB HEX,48
                
                NEXT:
                    CALL CONVERT
            
            MOV CX,2
        LOOP MAIN_LOOP
        
        EXIT:
            MOV AH,4CH
            INT 21H
            
        CONVERT PROC
            MOV SI,3
            
            SEG_CONVERT:
                MOV AH,0
                MOV AL,HEX
                MOV DL,2
                DIV DL
                MOV BIN[SI],AH
                MOV HEX,AL
                
                DEC SI
                CMP SI,0
                JNE SEG_CONVERT
                MOV BIN[SI],AL
                CALL PRINT
            RET
        CONVERT ENDP
        
        PRINT PROC
            LEA DX,MSG1
            MOV AH,9
            INT 21h
            
            MOV SI,0
            PRINT_SEG:
                MOV DL,BIN[SI]
                ADD DL,48
                MOV AH,02h
                INT 21h
                
                INC SI
                CMP SI,4
                JB PRINT_SEG
            
            RET
        PRINT ENDP
CODE ENDS
END ARXH