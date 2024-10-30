;ILIAS STATHAKOS 2017
TITLE LABPOINT03

DATA SEGMENT
    
    promtMsg DB 10,13, "Dwse enan dipsifio 16adiko arithmo (0-9 A-F):$" 
    promtResult DB 10,13, "To apotelesma einai: $"
    HEX_INP_1 DB 0
    HEX_INP_2 DB 0    
    RESULT DB 0 
    MONADES DB 0
    DEKADES DB 0
    EKATONTADES DB 0
    
DATA ENDS

CODE SEGMENT
    ARXH:
    
        MOV AX,DATA
        MOV DS,AX
        
        MOV CX,5
    
    START:    
        LEA DX,promtMsg
        MOV AH,09h
        INT 21H
             
             
    INPUT1:
        MOV AH,08h
        INT 21h
        MOV HEX_INP_1,AL
        
        CMP HEX_INP_1, 48   ; '0'
        JB INPUT1
        CMP HEX_INP_1, 57   ; '9'
        JBE IS_DEC_HEX1         
        CMP HEX_INP_1, 65   ; 'A'
        JB INPUT1
        CMP HEX_INP_1, 70   ; 'F'
        JA INPUT1
        JMP IS_HEX1

    IS_DEC_HEX1:
        MOV DL,HEX_INP_1
        MOV AH,02h
        INT 21h
        
        MOV AL,HEX_INP_1
        SUB AL,48
        MOV HEX_INP_1,AL
        
        JMP INPUT2
        
    IS_HEX1:
        MOV DL, HEX_INP_1
        MOV AH,02h
        INT 21h
        
        MOV AL,HEX_INP_1
        SUB AL,55
        MOV HEX_INP_1,AL

       
       
    INPUT2:
        MOV AH,08h
        INT 21h
        MOV HEX_INP_2,AL
        
        CMP HEX_INP_2, 48   ; '0'
        JB INPUT2
        CMP HEX_INP_2, 57   ; '9'
        JBE IS_DEC_HEX2         
        CMP HEX_INP_2, 65   ; 'A'
        JB INPUT2
        CMP HEX_INP_2, 70   ; 'F'
        JA INPUT2
        JMP IS_HEX2
   
    IS_DEC_HEX2:
        MOV DL,HEX_INP_2
        MOV AH,02h
        INT 21h
        
        MOV AL,HEX_INP_2
        SUB AL,48
        MOV HEX_INP_2,AL
        
        JMP AFTER_HEX2
        
    IS_HEX2:
        MOV DL,HEX_INP_2
        MOV AH,02h
        INT 21h
        
        MOV AL,HEX_INP_2
        SUB AL,55
        MOV HEX_INP_2,AL
        
        
    
    AFTER_HEX2:
        ;A3 = 10*16+3
        MOV AH,0
        MOV AL,HEX_INP_1
        MOV BL,16
        MUL BL     ; AL*16
        
        ADD AL,HEX_INP_2
        MOV RESULT,AL
        
        MOV AH,0
        MOV AL,RESULT
        MOV BL,100
        DIV BL
        MOV EKATONTADES, AL
        
        MOV RESULT,AH
        
        MOV AH,0
        MOV AL,RESULT
        MOV BL,10
        DIV BL
        MOV DEKADES,AL
        
        MOV MONADES,AH
        
        LEA DX,promtResult
        MOV AH,09h
        INT 21H
        
        MOV DL,EKATONTADES
        ADD DL,48
        MOV AH,02h
        INT 21h    
        
        MOV DL,DEKADES
        ADD DL,48
        MOV AH,02h
        INT 21h  
        
        MOV DL,MONADES
        ADD DL,48
        MOV AH,02h
        INT 21h
        
        SUB CX,1
        CMP CX,0
        JA START

             
        MOV AH,4CH
        INT 21h
        
CODE ENDS
END ARXH