;Ilias Stathakos 2017
TITLE BINARY2HEX
DATA SEGMENT
    BINARY DB 8 DUP(0)
    SUM DB 0
    HEX DB 2 DUP(0)
    NL DB 10,13,"$"    
DATA ENDS
CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
        MOV CX,0
        
        
        INPUT:       
            MOV AH,07
            INT 21h
            
            CMP AL,'.'
            JE EXIT
            
            SUB AL,48
            CMP AL,0
            JE VALID
            CMP AL,1
            JE VALID
        
            JMP INPUT
        
        
        
        
        VALID:
            MOV SI,CX
            MOV BINARY[SI],AL
            
            MOV DL,AL
            ADD DL,48
            MOV AH,02h
            INT 21h
            
            INC CX
            
            CMP CX,8
            JB INPUT
            
                        
            CALL CONVERT
            
            LEA DX,NL
            MOV AH,9
            INT 21h
            
            CALL PRINT 
            
            LEA DX,NL
            MOV AH,9
            INT 21h
            
            
            JMP INPUT
            
        EXIT:
            MOV AH,4Ch
            INT 21h
            
        CONVERT PROC
            MOV SI,8
            MOV DI,1
            
            SEG_CONVERT:
                DEC SI
                MOV DL,BINARY[SI]
                MOV AL, 1
                MUL DL
                MOV SUM,AL
                
                DEC SI
                MOV DL,BINARY[SI]
                MOV AL,2
                MUL DL
                ADD SUM,AL
                
                DEC SI
                MOV DL,BINARY[SI]
                MOV AL,4
                MUL DL
                ADD SUM,AL
                
                
                DEC SI
                MOV DL,BINARY[SI]
                MOV AL,8
                MUL DL
                ADD SUM,AL
                MOV AL,SUM
                
                MOV HEX[DI], AL
                DEC DI
                
                CMP SI,3
                JAE SEG_CONVERT
            
            RET
        CONVERT ENDP
        
        PRINT PROC
            MOV SI,0
            MOV CX,2
            PRINT_LOOP:
                MOV DL,HEX[SI]
                
                CMP DL,9
                JBE DO_PRINT
                
                ADD DL,7
                
                
                DO_PRINT:
                    ADD DL,48
                    MOV AH,02h
                    INT 21h
                    
                INC SI
            LOOP PRINT_LOOP    
                
            RET
        PRINT ENDP
    
CODE ENDS
END ARXH