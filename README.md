## Introdução
O objetivo desse trabalho é implementar uma chamada de sistema que receba ao menos um parâmetro e que trabalhe com pelo menos um elemento do sistema operacional. Para isso, o grupo implementou uma syscall que recebe como parâmetro um caminho, uma mensagem e o tamanho de caracteres e cria um arquivo no caminho com a mensagem recebida.

Para implementação do trabalho, foi utilizado o Kernel Linux versão 3.17.2, e a imagem de sistema DC_SO.img fornecida em aula.

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

5. Modificar o Makefile da pasta *linux-3.17.2/arch/x86/kernel/*, para que o nosso arquivo **message.c** seja compilado com o kernel, incluindo a linha:  
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
    $ ./test_register_message /root/arquivoComMensagem Posso escrever uma mensagem!
    ```
   A parte "/root/arquivoComMensagem" pode ser substituída por qualquer caminho desejado e "Posso escrever uma mensagem!" pode ser subtituída por qualquer mensagem desejada de até 350 caracteres.
   
## Realizado pelos alunos:
* Leonardo de Oliveira Peralta - 726556
* Renata Sarmet Smiderle Mendes - 726586
* Rebeca Lima Rocha - 486060

Disciplina: Sistemas Operacionais 01 - Profª Kellen Vivaldini
