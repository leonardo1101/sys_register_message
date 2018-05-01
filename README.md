## Introdução

## Instruções de instalação e execução

Apesar de não ter sido informado no enunciado do trabalho, é necessário compilar o kernel com o compilador **gcc-5** ou inferior, caso contrário não é possível compilar.

Para testar a implementação da syscall, realizamos os seguintes passos:

1. Descompactar o arquivo **Projeto_01.zip**, que contém o kernel e a imagem do sistema e colocar os arquivos **test_register_message.c** e **sys_register_message.h** na pasta gerada.

2. Modificar o arquivo *linux-3.17.2/arch/x86/syscalls/syscall_32.tlb*, adicionando a seguinte linha ao final do arquivo:  
    `357	i386	message	sys_register_message`

3. Adicionar a declaração da função *sys_register_message* no arquivo *linux-3.17.2/include/linux/syscalls.h*:  
    ```C
    asmlinkage long sys_register_message(const char *pathname, const char *mensagem, int tamanho);
    ```
4. Incluir o código **message.c** no diretório *linux-3.17.2/arch/x86/kernel/*.

5. Modificar o Makefile da pasta *linux-3.17.2/arch/x86/kernel/*, para que o nosso arquivo **info.c** seja compilado com o kernel, incluindo a linha:  
    `obj-y	+=	message.o`

6. Acessar a pasta *linux-3.17.2/* e compilar o kernel, com o comando:  
    `$ make -j 5 ARCH=i386`

7. Após isso, compile o código de teste **test_register_message.c** com o comando: 
    `gcc -m32  test_register_message.c -o test_register_message`


8. Executar a máquina virtual para testar a implementação da syscall no kernel alvo, utilizando o comando:  
    `$ qemu-system-i386 -hda DC_SO.img -kernel linux-3.17.2/arch/i386/boot/bzImage -append "ro root=/dev/hda" -hdb test_register_message`

9. Logar no sistema com as credenciais:  
    **user:root**  
    **password:root**

10. Executar os seguintes comandos para teste da syscall:  
    ```bash
    $ cat /dev/hdb > test_register_message 
    $ chmod +x test_register_message
    $ ./test_register_message /caminhoDoArquivo/arquivo mensagem
    ```
## Realizado pelos alunos:
* Leonardo de Oliveira Peralta - 726556
* Renata Sarmet Smiderle Mendes - 726586
* Rebeca Lima Rocha - 486060
