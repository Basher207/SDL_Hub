#Compiler to be used:
CC=clang

Library_C_Files =./Hub_C_Files/*.c
Output_Folder =./bin/
Add_Header_directory =-I ./SDL/SDL2.framework/Headers -I ./Headers

Build_hub:
	$(CC) $(Library_C_Files) $(Add_Header_directory) -c
	mv -f *.o $(Output_Folder)
