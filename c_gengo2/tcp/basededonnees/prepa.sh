 #!.usr/bin/sh

 gcc mysqlfirst.c -c 
 gcc login.c -c 
 gcc enregistrer.c -c 
 gcc insert.c -c 
 gcc select1.c -c 
 gcc mysqlfirst.o login.o enregistrer.o insert.o select1.o  -o GO
