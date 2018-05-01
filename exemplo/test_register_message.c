#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "sys_register_message.h"

int main( int argc, char *argv[ ] ){
    int cont;
    char mensagem[360];
    
    bzero(mensagem, 360);
    for(cont=2; cont < argc; cont++){
        strcat(mensagem, argv[cont]);
        strcat(mensagem, " ");
    }
    strcat(mensagem, "\n");
	int err = syscall(357, argv[1], mensagem, strlen(mensagem));
	if (!err){
		printf("Arquivo criado com sucesso :) \n");
	}
	else	perror("sys_info");
	return 0;
}
