TITLE LAB3_2
DATA SEGMENT
    c1 DB ?
    c2 DB ?
    result DW ?
    c1msg DB 10,13, "Enter a number [0-9]: $"
    c2msg DB 10,13, "Enter a number [0-9]: $"
    c3msg DB 10,13, "The result is: $"
    
DATA ENDS
CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
        LEA DX,c1msg
        MOV AH,09
        INT 21h
        
        MOV AH,01
        INT 21h
        SUB AL,'0'
        MOV c1,AL
        
        LEA DX,c1msg
        MOV AH,09
        INT 21h
        
        MOV AH,01
        INT 21h
        SUB AL,'0'
        MOV c2,AL
        
        MOV AL,c1
        MUL c2
        MOV result,AX
        
        MOV AX,result
        MOV CX,2
        MOV BX,10
        MOV SI,0
        MOV DI,0
        MOV DX,0
        
        
    PRINT_DIGIT:
        DIV BX
        ADD DL,'0'
        MOV [c3msg + DI],DL
        INC DI
        DEC SI
        CMP SI,0
        JNZ PRINT_DIGIT 
        
        
        LEA DX,c3msg
        MOV AH,09
        INT 21h
        
        
        MOV AH,4CH
        INT 21h
CODE ENDS
END ARXH