TITLE ILIAS
DEDOMENA SEGMENT
    MSG DB "LAB07 Starting",10,13,"$"
    MSG2 DB "GOGOGO",10,13,"$"
    MSG3 DB "KEEP UP....",10,13,"$"
    MSG4 DB "MAY THE STACK FORCE BE WITH YOU",10,13,"$"
    
    PARAM1 DW 0 ;DW->2BYTE DB->1BYTE
DEDOMENA ENDS
 
;Me tin xrisi tou stack kanw tis synartiseis diafaneis(PUSH,POP) 
 
CODE SEGMENT
    ARXH:
        MOV AX,DEDOMENA
        MOV DS,AX
        
        CALL PRINTMSG   ;synartisi xwris parametrous
        
        LEA DX,MSG2
        CALL PRINTMSGREGISTER  ;perasma parametrou me kataxoriti
        
        
        LEA DX,MSG3
        MOV PARAM1,DX
        CALL PRINTMSGDATASEGMENT ;perasma parametrou me data segment
        
        LEA DI,MSG4
        PUSH DI
        CALL PRINTMSGSTACK  ;Perasma parametrou me soro
        
        MOV AX,1
        PUSH AX
        MOV AX,3
        PUSH AX
        CALL ADDNUMBERSTACK ;Perasma parametron me soro
        
        MOV BP,SP
        MOV DL,[BP-10]
        ADD DL,30h
        MOV AH,02
        INT 21h
        
        MOV AH,4CH
        INT 21h
        
        ADDNUMBERSTACK PROC   ;Function with parameters at stack
            PUSH BP
            PUSH DI
            PUSH SI
            
            MOV BP,SP
            MOV DI,[BP+8]
            MOV SI,[BP+10]
            ADD DI,SI
            MOV [BP-2],DI
            
            POP SI
            POP DI
            POP BP
            
            RET
        ADDNUMBERSTACK ENDP
        
        PRINTMSGSTACK PROC  ;Function with parameter at stack
            PUSH BP
            PUSH DX
            PUSH AX
            
            MOV BP,SP
            MOV DX,[BP+8]
            MOV AH,09
            INT 21h
            
            POP AX
            POP DX
            POP BP
            RET
        PRINTMSGSTACK ENDP
        
        PRINTMSG PROC ;Function without parameters
            PUSH AX
            PUSH DX
            LEA DX,MSG
            MOV AH,09
            INT 21h
            
            POP DX
            POP AX
            RET
        PRINTMSG ENDP   
        
        PRINTMSGREGISTER PROC  ;Function with parameter at register dx
            PUSH AX
            MOV AH,09
            INT 21h
            POP AX
            RET            
        PRINTMSGREGISTER ENDP
        
        PRINTMSGDATASEGMENT PROC
            PUSH DX
            PUSH AX
            MOV DX,PARAM1
            MOV AH,09
            INT 21h
            POP AX
            POP DX
            RET
        PRINTMSGDATASEGMENT ENDP
        
CODE ENDS

SOROS SEGMENT STACK
    DB 256 dup(0)
    SOROS ENDS
END ARXH