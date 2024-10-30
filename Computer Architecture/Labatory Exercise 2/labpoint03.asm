#ece02017-------Ilias stathakos 2017     
TITLE ILIAS
DATA SEGMENT
    NUM1 DB 3
    NUM2 DB 4
    MSG1 DB "TO NUM1 EINAI: ","$"
    MSG2 DB 10,13,"TO NUM2 EINAI: ","$"
    MSG3 DB 10,13,"TO APOTELESMA PROSTHESIS EINAI: ","$"
DATA ENDS

CODE SEGMENT
    ARXH: MOV AX,DATA
          MOV DS,AX
          
          LEA DX,MSG1
          MOV AH,9
          INT 21H
          
          MOV DL,NUM1
          ADD DL,30H
          MOV AH,02
          INT 21H
          
          LEA DX,MSG2
          MOV AH,9
          INT 21H
          
          MOV DL,NUM2
          ADD DL,30H
          MOV AH,02
          INT 21H
          
          LEA DX,MSG3
          MOV AH,9
          INT 21H
          
          MOV AH,NUM1
          MOV AL,NUM2
          ADD AH,AL
          
          MOV DL,AH
          ADD DL,30H
          MOV AH,02
          INT 21H
          
          MOV AH,4CH
          INT 21H
          
CODE ENDS
END ARXH