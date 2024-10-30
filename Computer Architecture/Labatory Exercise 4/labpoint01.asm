;ILIAS STATHAKOS 2017

TITLE labpoint01

DATA SEGMENT
     
     MSG DB 10,13, "DWSE KEFALAIOUS LATINIKOUS XARAKTIRES: $"
     C1 DB 0
     C2 DB 0

DATA ENDS

CODE SEGMENT
    ARXH:
         MOV AX,DATA
         MOV DS,AX
     
    START:     
         LEA DX,MSG
         MOV AH,09h
         INT 21h 
    
    INPUT:     
         MOV AH,08h
         INT 21h
         
         MOV C1,AL
         
         CMP C1,65
         JB  INPUT
         CMP C1,90
         JA  INPUT
         
         MOV DL,C1
         MOV AH,02h
         INT 21h    
         
         MOV C2,DL 
         ADD C2, 32
         
         MOV DL,C2
         MOV AH,02h
         INT 21h
         
         
         JMP START
    
CODE ENDS
END ARXH