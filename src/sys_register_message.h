#include <unistd.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>


long sys_register_message(const char *pathname, const char *mensagem, int tamanho){

    int fd;
    long err;
    open(pathname, O_CREAT | O_RDWR,S_IRWXU);
    fd = open(pathname, O_RDWR,S_IRWXU);
    err = write(fd, mensagem , tamanho);
    err = write(fd, '\n' , 1);
    err = close(fd);
	return err;
}

