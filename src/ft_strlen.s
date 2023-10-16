section .text
    global ft_strlen

;size_t strlen(const char *s);
ft_strlen:
    mov rax, 0      ;init counter

.loop:
    cmp byte [rdi], 0 ;dereference and compare if == '\0'
    je .end         ;if str ends, ZF == 0, returns
    inc rdi         ;increment str address
    inc rax         ;increment counter
    jmp .loop       ;loop until ends str

.end:
    ret             ;return the content in the rax
