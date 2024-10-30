TITLE LAB 3
DATA SEGMENT  
    
    c1 DB 0
    c2 DB 0
    c1msg DB 10,13, "Enter the first char:","$"
    c2msg DB 10,13, "Enter the second char:","$"
    
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
        
        MOV c1,AL
        
        LEA DX,c2msg
        MOV AH,09
        INT 21h
        
        MOV AH,01
        INT 21h
        
        MOV c2,AL
        
        CMP c1,'a'
        JL SCRN1 
        CMP c1, 'z'
        JG SCRN1
        SUB c1, 32  
        
         
    SCRN1: 
        
        CMP c2,'a'
        JL SCRN2 
        CMP c2, 'z'
        JG SCRN2
        SUB c2, 32
        
        
    SCRN2:
        ;Display result
        MOV DL,c1
        MOV AH,02
        INT 21h 
        
        MOV DL,c2
        MOV AH,02
        INT 21h
    
        MOV AH,4CH
        INT 21h
CODE ENDS
END ARXH