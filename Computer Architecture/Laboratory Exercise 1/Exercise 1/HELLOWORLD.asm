TITLE HELLOWORLD       

DEDOM SEGMENT
    MSG1 DB "Ilias Stathakos",01,10,13,"$"
    MSG2 DB "6/10/23$"
DEDOM ENDS

CODE SEGMENT
ARXH: MOV AX,DEDOM
      MOV DS,AX
      
        LEA DX,MSG1
        MOV AH,9
        INT 21H 
        
        LEA DX,MSG2
        MOV AH,9
        INT 21H
        
      MOV AH,4CH
      INT 21H
      
CODE ENDS
END ARXH    