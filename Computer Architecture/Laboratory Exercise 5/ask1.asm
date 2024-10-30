;METATROPH 8BIT DIADIKOU SE DEKAEKSADIKO ARITHMO
;EISODOS KAI EKSODOS ME SYNARTISEIS
;TO PROGRAMMA NA EKTELEITE MEXRI O XRISTIS NA PATISEI "."
;OI XARAKTIRES POU EISAGWNTE APO TO PLIKTROLOGIO NA EMFANIZONTAI META APO ELEGXO
;ALLIWS NA AGNOOUNTAI(SIOPILA).

TITLE BIN2HEX
DATA SEGMENT
    FLAG DW ?
    BIN_MSG DB 10,13, "DWSE ENAN 8 BIT DIADIKO ARITHMO: $"
    HEX_MSG DB 10,13, "O DEKAEKSADIKOS ARITHMOS EINIA 0: $"    
DATA ENDS
CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
    BIN_TO_HEX:    
        CALL DISPLAY_MSG
        CALL INPUT_BIN 
        
    OUTPUT_HEX:
        CALL DISPLAYHEXMSG
        CALL BINARYTOHEX
        
        JMP BIN_TO_HEX
           
    EXIT:    
        MOV AH,4CH
        INT 21H
        
DISPLAY_MSG PROC
    MOV AH,9
    LEA DX,BIN_MSG
    INT 21H
    RET    
DISPLAY_MSG ENDP

INPUT_BIN PROC
    MOV AX,0
    MOV BX,0
    MOV CX,0
    MOV DX,0


    
    INPUT_BIN2:
        CMP CX,8
        JE  OUTPUT_HEX
     
        MOV AH,08h
        INT 21h
    
        CMP AL,"."
        JE EXIT1
    
        CMP AL,"0"
        JNE BINARY_CHECK
    
        MOV DL,AL
        MOV AH,02h
        INT 21h
    
        INC CX
    
    
    BINARY_CONTINUE:
        SUB AL,48
        SHL BX,1
        OR BL,AL
        JMP INPUT_BIN2    
        
    
    BINARY_CHECK:
        CMP AL,"1"   
        JNE INPUT_BIN2        
    
        MOV DL,AL
        MOV AH,02h
        INT 21h
    
        INC CX
    
        JMP BINARY_CONTINUE
    
    EXIT1:
        RET        
    
INPUT_BIN ENDP    

DISPLAYHEXMSG PROC
    MOV AH,9
    LEA DX, HEX_MSG
    INT 21h
    RET
           
DISPLAYHEXMSG ENDP
           
BINARYTOHEX PROC
    MOV DX,0
    MOV CL,1
    MOV CH,0
    
    OUTPUT_HEX2:
        CMP CH,4
        JE BIN_TO_HEX
        INC CH
        
        MOV DL, BH
        SHR DL,4
        
        CMP DL, 0Ah
        JL HEXA_DIGIT
        
        ADD DL,37h
        MOV AH,2
        INT 21H
        ROL BX,4
        
        JMP OUTPUT_HEX2
        
    HEXA_DIGIT:
        ADD DL, 30h
        MOV AH,2
        INT 21h
        
        JMP OUTPUT_HEX2
    
        
BINARYTOHEX ENDP


CODE ENDS
END ARXH