a.out: Client_File.o Server_Sujith.o Server_Vivek.o Server_Pavan.o
	gcc Client_File.o Server_Sujith.o Server_Vivek.o Server_Pavan.o
Client_File.o: Client_File.c Header_File.h
	gcc -c Client_File.c
Server_Sujith.o: Server_Sujith.c Header_File.h
	gcc -c Server_Sujith.c
Server_Vivek.o: Server_Vivek.c Header_File.h
	gcc -c Server_Vivek.c
Server_Pavan.o: Server_Pavan.c Header_File.h
	gcc -c Server_Pavan.c
