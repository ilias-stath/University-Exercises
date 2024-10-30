TITLE ASK1
;lsi.gr/snake

DATA SEGMENT
    SEED DW 56784
DATA ENDS

CODE SEGMENT
    START: 
        MOV AX,DATA
        MOV DS,AX
        MOV ES,AX
        
        CALL SETGRAPGICSMODE
        CALL CREATEBORDERS
        CALL INITIALIZE_DOTS
        
        MOV AH,4Ch
        INT 21h
        
        
    SETGRAPGICSMODE PROC
        PUSH AX
        
        MOV AH,0h
        MOV AL,13h
        INT 10h  
        
        POP AX
        RET
    SETGRAPGICSMODE ENDP
    
    CREATEBORDERS PROC
        PUSHA ;PUSH ALL
        
        MOV BX,0A000h
        MOV ES,BX
        
        MOV CX,320
        MOV DI,0
        
       
        
        horizontal:
            MOV ES:[DI],9
            INC DI
            MOV ES:[DI+63680],9
        loop horizontal
        
        MOV CX,200
        MOV DI,0
        
        vertical:
            MOV ES:[DI],9
            MOV ES:[DI+319],9
            ADD DI,320
        loop vertical
            
        
        POPA  ;POP ALL
        RET
    CREATEBORDERS ENDP
    
    INITIALIZE_DOTS PROC
        PUSHA
        
        MOV CX,30
        MOV AX,0A000h
        MOV ES,AX
        
        DOTS_LOOP:
            CALL RND16
            MOV DI,SEED
            MOV ES:[DI],45
        LOOP DOTS_LOOP
        
        POPA
        RET
    INITIALIZE_DOTS ENDP
    
    RND16 PROC
        PUSHA
        
        MOV AX,SEED
        MOV DX,8403h
        MUL DX
        INC AX
        MOV SEED,AX
        
        POPA
        RET
    RND16 ENDP
    
    CHECKKEYB_PROCESS PROC
        PUSHA
        
        MOV AH,01
        INT 16h
        JE _NOKEYPRESS  ; ZF=1 (JE) NO BUTTON PRESSED
        CALL PROCESSKEY
        
        _NOKEYPRESS:
        POPA
        RET
    CHECKKEYB_PROCESS ENDP
    
    PROCESSKEY PROC
        PUSHA
        
        MOV AH,0
        INT 16h ;AH,AL CARRIES THE KEY PRESSED
        CMP AL,0 ;IS IT NON ASCII KEY?
        JNE _PROCESS_KEY_END ;IGNORE ASCII KEYS
        
        ;CHECK ARROW KEYS
        CMP AH,4Bh ;LEFT ARROW
        JNE _PROCESS_KEY_RIGHT
        CALL LEFT_ARROW_PRESSED
        JMP _PROCESS_KEY_END
        
        _PROCESS_KEY_RIGHT:
            CMP AH,4Dh ; RIGHT ARROW
            JNE _PROCESS_KEY_END
            CALL RIGHT_ARROW_PRESSED
        
        _PROCESS_KEY_END:
        POPA
        RET
    PROCESSKEY ENDP
    
        
CODE ENDS

STACK SEGMENT
    DW 218 dup(0)
    
STACK ENDS
END START