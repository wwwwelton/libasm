section .text
    global ft_strlen

ft_strlen:
                                ;size_t strlen(const char *s);
    mov rax, 0                  ;init counter

len:
    cmp byte [rdi], 0x0         ;dereference and compare if == '\0'
    je end                      ;if str ends return

    inc rdi                     ;increment str address
    inc rax                     ;increment counter

    jmp len                     ;loop until ends str

end:
    ret
