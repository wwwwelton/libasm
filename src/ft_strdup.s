section .text
    global ft_strdup
    extern ft_strlen, malloc, ft_strcpy

;char *strdup(const char *s);
ft_strdup:
    mov r15, rdi    ;copy s address to tmp register
    call ft_strlen  ;count s len
    add rax, 1      ;add +1 for '\0'
    mov rdi, rax    ;save s len to first param
    call malloc wrt ..plt ;call malloc
    cmp rax, 0      ;if malloc failed == NULL go to .end
    je .end
    mov rdi, rax    ;if malloc success put address in first param (dest)
    mov rsi, r15    ;put s address in second param (src)
    call ft_strcpy  ;copy s to dest

.end:

    ret             ;return the content in the rax
