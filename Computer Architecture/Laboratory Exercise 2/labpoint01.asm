#ece02017---Ilias stathakos

TITLE ILIAS
DEDOMENA SEGMENT
    myname db 49H,"l",105,"a",01110011B," Sta",74H,104,01100001B,"kos","$"    
DEDOMENA ENDS

CODE SEGMENT
    ARXH: MOV AX,DEDOMENA
          MOV DS,AX
          
          LEA DX,myname
          MOV AH,09
          INT 21H
          
          MOV AH,4CH
          INT 21H
          
CODE ENDS

END ARXH