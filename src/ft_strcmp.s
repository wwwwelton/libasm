section .text
    global ft_strcmp

;int ft_strcmp(const char *s1, const char *s2);
ft_strcmp:
    mov r10, [rdi]  ;dereference s1 and copy to tmp register
    mov r11, [rsi]  ;dereference s2 and copy to tmp register

.loop:
    cmp r10b, r11b  ;compare if *s1 == *s2
    je .chars_equal ;if equal jump to .chars_equal
    jl .less
    jmp .above

.chars_equal:
    cmp r10b, 0     ;compare if *s1 == '\0'
    je .equal       ;if *s1 == '\0' jump to .equal
    inc rdi         ;increment s1 address
    inc rsi         ;increment s2 address
    mov r10, [rdi]  ;dereference s1 and copy to tmp register
    mov r11, [rsi]  ;dereference s2 and copy to tmp register
    jmp .loop       ;jump to .loop

.less:
    mov rax, -1     ;set rax (return register) to -1 (a < b)
    ret             ;return the content in the rax

.above:
    mov rax, 1      ;set rax (return register) to 1 (b > a)
    ret             ;return the content in the rax

.equal:
    mov rax, 0      ;set rax (return register) to 0 (a == a)
    ret             ;return the content in the rax
