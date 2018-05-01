#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "sys_register_info.h"

int main( int argc, char *argv[ ] ){
	int err = syscall(357, argv[1], argv[2], strlen(argv[2]));
	if (!err){
		printf("Arquivo criado com sucesso :) \n");
	}
	else	perror("sys_info");
	return 0;
}
