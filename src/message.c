#define _GNU_SOURCE
#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/resource.h>
#include <linux/time.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/stat.h>
#include <linux/fcntl.h>


asmlinkage long sys_register_message(const char *pathname, const char *mensagem, int tamanho){

    
    int fd;
    long err;
    sys_open(pathname, O_CREAT | O_RDWR,S_IRWXU);
    fd = sys_open(pathname, O_RDWR,S_IRWXU);
    err = sys_write(fd, mensagem , tamanho);
    err = sys_close(fd);
	return err;
}

