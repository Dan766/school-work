Assignment 2: Procedures 
==========
a) (20 points) Write a procedure called DisplayHexDigit that takes as input a number between 0 and 15 stored in BX register and prints it in hexadecimal.    

b) (20 points) Write a procedure called DisplayHexByte that takes as input a number between 0 and 255 stored in BX register and prints it in hexadecimal. Procedure DisplayHexByte should call DisplayHexDigit to print the number.    

c) (20 points) Write a procedure called DisplayHexWord that takes as input a number between 0 and 65535 stored in BX register and prints it in hexadecimal. Procedure DisplayHexWord should call DisplayHexByte to print the number.    

d) (40 points) To test these procedures your main program should read a number from the input between 0 and 65535 and depending on the range that the input number falls call one of the above procedure.    

Here are some sample execution scenarios:

          C:\ASM>ass_2-2  
          0  
          0    

          C:\ASM>ass_2-2  
          15  
          F 

          C:\ASM>ass_2-2  
          16  
          10 

          C:\ASM>ass_2-2  
          255  
          FF    

          C:\ASM>ass_2-2  
          256  
          0100    

          C:\ASM>ass_2-2  
          1000  
          03E8    
