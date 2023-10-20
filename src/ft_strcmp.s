section .text
    global ft_strcmp

;int ft_strcmp(const char *s1, const char *s2);
ft_strcmp:
    mov r10, [rdi]
    mov r11, [rsi]

.loop:
    cmp r10b, r11b
    je .chars_equal
    jl .less
    jmp .above

.chars_equal:
    cmp r10b, 0
    je .equal
    inc rdi
    inc rsi
    mov r10, [rdi]
    mov r11, [rsi]
    jmp .loop

.less:
    mov rax, -1
    ret

.above:
    mov rax, 1
    ret

.equal:
    mov rax, 0
    ret
