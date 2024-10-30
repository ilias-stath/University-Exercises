#start = thermometer.exe#
TITLE THERMOMETER
DATA SEGMENT
    MENU DB "Select Heater Mode:",10,13,"1-0N",10,13,"0-OFF $"
DATA ENDS

CODE SEGMENT
    START:
        MOV AX,DATA
        MOV DS,AX
        
        LEA DX,MENU
        MOV AH,09h
        INT 21h
        
        
        arxi:
        MOV AH,08h
        INT 21h
        
        CMP AL,'1'
        JE automation
        
        CMP AL,'0'
        JE EXIT
        
        JMP arxi
        
        automation:
            
            IN AL, 125
            CMP AL, 50
            JAE heaterOff
            
            CMP AL, 40
            JBE heaterOn
            
            JMP automation
            
        
        heaterOn:
            MOV AL,1
            OUT 127,AL
            JMP automation
            
            
        heaterOff:
            MOV AL,0
            OUT 127,AL
            JMP automation
            
        EXIT:
        MOV AL,0
        OUT 127,AL
        
        MOV AH,4Ch
        INT 21h
CODE ENDS
SOROS SEGMENT STACK
    DB 256 dup(0)
SOROS ENDS

END START