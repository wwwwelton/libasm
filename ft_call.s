; Exemplo de um Hello World em Assembly
; ld -m elf_x86_64 -s -o hello hello.o
; nasm -f elf64 hello.s

; nasm ft_call.s -o ft_call.o -felf64
; ld -m elf_x86_64 -s -o hello hello.o

section .data
        msg db 'Hello, world!', 0xA
        len equ $ - msg

section .text
        global ft_call

ft_call:
        mov     rax, 1                               ;system call number
        mov     rdi, 1                               ;stdout fd
        ; mov     rsi, msg                           ;str to print
        lea     rsi, [rel msg]                       ;str to print
        mov     rdx, len                             ;str len
        syscall                                      ;call kernel

        ret
