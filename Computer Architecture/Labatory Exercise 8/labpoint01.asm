;ILIAS STATHAKOS 2017
TITLE 
DATA SEGMENT
    SEC DW 13222
    HOURS DB "hours= $"
    MINUTES DB "  minutes= $"
DATA ENDS
CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
                   
        
        MOV AX,SEC
        PUSH AX           
        CALL CONVERT
        
        MOV BP,SP
        MOV BL,[BP-12]
        MOV BH,[BP-14]
        
        LEA DX,HOURS
        MOV AH,09
        INT 21h
        MOV AL,BL
        CALL PRINT
        
        LEA DX,MINUTES
        MOV AH,09
        INT 21h
        MOV AL,BH
        CALL PRINT
        
        MOV AH, 4Ch
        INT 21h
        
        PRINT PROC
            ;PARAMETROS: AL(DOUBLE DIGIT)
            PUSH AX
            PUSH DX
            PUSH BX
            
            MOV AH,0
            MOV DL,10
            DIV DL
            
            MOV BH,AL
            MOV BL,AH
            
            ADD BH,30h
            ADD BL,30h
            
            MOV DL,BH
            MOV AH,02h
            INT 21h
            
            MOV DL,BL
            MOV AH,02h
            INT 21h
            
            POP BX
            POP DX
            POP AX
            RET
        PRINT ENDP
        
        CONVERT PROC
            PUSH BP
            PUSH BX
            PUSH DX
            PUSH AX
            
            MOV BP,SP
            MOV AX,[BP+10]
            MOV BX,3600
            DIV BX
            MOV [BP-2],AX
            
            MOV AX,DX
            MOV BX,60
            DIV BL
            
            MOV AH,0
            MOV [BP-4],AX
            
            POP AX
            POP DX
            POP BX
            POP BP
            RET
        CONVERT ENDP
    
CODE ENDS
STACK SEGMENT STACK
    DB 256 DUP(0)
STACK ENDS
EXIT:
END ARXH