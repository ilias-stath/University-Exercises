;Ilias Stathakos 2017
#start=thermometer.exe#
TITLE HEATER 
DATA SEGMENT
    MENU DB "Heater Mode: ",10,13,"0-Off",10,13,"1-On",10,13,"2-Auto",10,13,"$"
    MSG_OFF DB "max temp reached, turning off heater",10,13,"$"
    MSG_ON DB "min temp reached, turning on heater",10,13,"$"
DATA ENDS

CODE SEGMENT
    ARXH:
        MOV AX,DATA
        MOV DS,AX
        
        MOV AH,09h
        LEA DX,MENU
        INT 21h
        
        
        MOV AH,08
        INT 21h
        
        CMP AL,'2'
        JE AUTO
        
        CMP AL,'0'
        JE EXIT
        
        CMP AL,'1'
        JE EXIT_ON
        
        AUTO:
            IN AL,125
            CMP AL,50
            JAE HEATER_OFF
            
            CMP AL,0
            JBE HEATER_ON
            
            JMP AUTO
            
        HEATER_OFF:
            IN AX,127
            CMP AL,0
            JE AUTO
            
            LEA DX,MSG_OFF
            MOV AH,09h
            INT 21h
            
            MOV AX,0
            OUT 127,AX
            JMP AUTO
            
        
        HEATER_ON:
            IN AX,127
            CMP AL,1
            JE AUTO
            
            
            LEA DX,MSG_ON
            MOV AH,09h
            INT 21h
            
            MOV AX,1
            OUT 127,AX
            JMP AUTO
            
            
    EXIT:
        MOV AX,0
        OUT 127,AX
        
        MOV AH,4Ch
        INT 21h
        
    EXIT_ON:
        MOV AX,1
        OUT 127,AX
        
        MOV AH,4Ch
        INT 21h 
        
CODE ENDS

SOROS SEGMENT STACK
    DB 256 dup(0)
SOROS ENDS 

END ARXH