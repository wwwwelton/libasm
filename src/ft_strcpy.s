section .text
    global ft_strcpy

;char *strcpy(char *dest, const char *src);
ft_strcpy:
    mov rax, rdi    ;stores the dest original address

.loop:
    mov r11, [rsi]  ;copy 1 byte from src to temp register
    mov [rdi], r11b ;copy 1 byte from r11 to dest
    cmp byte [rdi], 0 ;dereference and compare if == '\0'
    je .end         ;if src ends, ZF == 0, returns
    inc rdi         ;increment dest address
    inc rsi         ;increment src  address
    jmp .loop       ;loop until ends str

.end:
    ret             ;return the content in the rax
