section .text
    global ft_strcmp

;int ft_strcmp(const char *s1, const char *s2);
ft_strcmp:
    dec rdi         ;s1--
    dec rsi         ;s2--

.loop:
    inc rdi         ;s1++
    inc rsi         ;s2++
    cmp byte [rdi], 0 ;if *s1 == '\0'
    je .check_value
    cmp byte [rsi], 0 ;if *s2 == '\0'
    je .check_value
    mov al, [rdi]   ;al = *s1
    cmp al, [rsi]   ;if *s1 == *s2
    je .loop

.check_value:
    mov al, [rdi]   ;al = *s1
    sub al, [rsi]   ;*s1 - *s2
    je .equal       ;if *s1 == *s2
    jl .less        ;if *s1 < *s2
    jmp .above      ;if *s1 > *s2

.less:
    mov rax, -1     ;set rax (return register) to -1 (a < b)
    jmp .end

.above:
    mov rax, 1      ;set rax (return register) to  1 (a > b)
    jmp .end

.equal:
    mov rax, 0      ;set rax (return register) to 0 (a == a)
    jmp .end

.end:

    ret
