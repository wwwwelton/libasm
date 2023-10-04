; Exemplo de um Hello World em Assembly
; ld -m elf_x86_64 -s -o hello hello.o
; nasm -f elf64 hello.s

; nasm hello.s -o hello.o -felf64
; ld -m elf_x86_64 -s -o hello hello.o

section .data
        msg     db  'Hello, world!', 0xa                 ;nossa string lindona
        len     equ $ - msg                             ;comprimento da lindona

section .text
        global _start

_start:
        mov     eax, 4                               ;número da system call
        mov     ebx, 1                               ;descritor de arquivo (stdout)
        mov     ecx, msg                             ;mensagem a ser escrita
        mov     edx, len                             ;comprimento da mensagem
        int     0x80                                ;call kernel

        mov     eax, 1                               ;numero da syscall
        int     0x80                                ;call kernel
