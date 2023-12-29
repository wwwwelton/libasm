section .text
    global ft_atoi_base
    extern ft_strlen, printf, is_valid_base, trim_spaces, check_signal, char_to_value1, char_to_value2

; ;int isspace(int c)
; ft_isspace:
;     cmp rdi, ' '
;     je .isspace
;     mov rax, rdi
;     sub rax, '\t'
;     cmp rax, 5
;     jl .itsnotspace

; .itsnotspace:
;     mov rax, 0      ;isspace == FALSE
;     ret

; .isspace:
;     mov rax, 1      ;isspace == TRUE
;     ret

; ;int is_valid_base(char *base)
; is_valid_base:
;     push r12
;     call ft_strlen  ;count base len
;     cmp rax, 2      ;if (ft_strlen(base) < 2)
;     jl .is_invalid_base
;     mov r12, rax    ;r12(len)
;     mov rax, 0      ;rax(i) = 0

; .loop1:
;     cmp rax, r12    ;while(rax(i) < r12(len))
;     je .is_valid_base
;     cmp byte [rdi + rax], '+' ;if (base[i] == '+')
;     je .is_invalid_base
;     cmp byte [rdi + rax], '-' ;if (base[i] == '-')
;     je .is_invalid_base
;     push rax
;     push rdi
;     mov rdi, [rdi + rax] ;rdi = base[i]
;     call ft_isspace
;     cmp rax, 1      ;if (isspace(base[i]))
;     je .isspace_invalid_base
;     pop rdi
;     pop rax
;     inc rax         ;i++
;     push r13
;     push r14
;     mov r13, rax    ;r13(j) = rax(i + 1)
;     mov r14, [rdi + rax - 1] ;r14 = base[i]

; .loop2:
;     cmp r13, r12    ;while(r13(j) < r12(len))
;     je .reset
;     cmp r14, [rdi + r13] ;if (base[i] == base[j])
;     je .reset_is_invalid_base
;     inc r13
;     jmp .loop2

; .reset:
;     pop r14
;     pop r13
;     jmp .loop1

; .reset_is_invalid_base:
;     pop r14
;     pop r13
;     jmp .is_invalid_base

; .is_invalid_base:
;     pop r12
;     mov rax, 0      ;is_valid_base == FALSE
;     ret

; .isspace_invalid_base:
;     pop rdi
;     pop rax
;     pop r12
;     mov rax, 0      ;is_valid_base == FALSE
;     ret

; .is_valid_base:
;     pop r12
;     mov rax, 1      ;is_valid_base == TRUE
;     ret

; ;void trim_spaces(char **str)
; trim_spaces:
;     push r15
;     mov r15, [rdi]  ;r15 = (*str)

; .loop:
;     mov rdi, [r15]  ;rdi = (**str)
;     cmp rdi, 0      ;if (**str == '\0')
;     je .end
;     call ft_isspace
;     cmp rax, 0      ;if (!isspace(**str))
;     je .end
;     inc r15
;     jmp .loop

; .end:
;     pop r15
;     ret

;int check_signal(char **str)
; check_signal:
;     push r15
;     mov r15, [rdi]  ;r15 = (*str)
;     cmp byte [r15], '-' ;if (*str == '-')
;     je .end
;     cmp byte [r15], '+' ;if (*str == '+')
;     inc r15
;     pop r15
;     ret 1

; .end:
;     inc r15
;     pop r15
;     ret -1

; ;int char_to_value(char c, char *base)
; char_to_value:
;     push r15
;     call ft_strlen  ;count base len
;     mov r15, rax    ;r15 = len
;     mov rax, 0      ;i = 0

; .loop:
;     cmp rax, r15    ;while(i < len)
;     je .error
;     cmp [rsi + rax], rdi ;if (base[i] == c)
;     je .end
;     inc rax         ;i++
;     jmp .loop

; .error:
;     pop r15
;     mov rax, -1
;     ret

; .end:
;     pop r15
;     ret

;int ft_atoi_base(char *str, char *base);
;RDI, RSI, RDX, RCX, R8, R9
;R12, R13, R14, R15
ft_atoi_base:
    push r12
    push r13
    push r14
    push r15

    mov r12, 1      ;signal
    mov r13, 0      ;value
    mov r14, 0      ;result
    mov r15, 0      ;base_len

    cmp rdi, 0      ;str == NULL
    je .error_null
    cmp rsi, 0      ;base == NULL
    je .error_null

    push rdi
    push rsi
    mov rdi, rsi    ;rdi = rsi(base)
    call is_valid_base
    cmp rax, 0      ;if (!is_valid_base(base))
    je .reset_error_base
    pop rsi
    pop rdi

    push rdi
    lea rax, [rdi]  ;rdi = &rdi (&str)
    push rax
    mov rdi, rsp
    call trim_spaces
    call check_signal
    mov r12, rax    ;signal = check_signal()
    pop rax
    pop rdi

    push rdi
    mov rdi, rsi
    call ft_strlen
    mov r15, rax    ;r15 = base_len
    pop rdi

    push rdi
    mov rcx, [rdi]
    mov rdi, rcx
    call char_to_value1
    pop rdi
    mov r13, rax    ;r13(value) = char_to_value(str[0], base)

.loop:
    cmp byte [rdi], 0
    je .end
    cmp r13, -1     ;while (value != -1)
    je .end

    mov rax, r14    ;rax = result
    mul r15         ;rax = r14(result) * r15(base_len)
    mov r14, rax    ;r14(result) = rax
    add r14, r13    ;r14(result) = r14(result) + r13(value)

    inc rdi         ;str++

    push rdi
    mov rcx, [rdi]
    mov rdi, rcx
    call char_to_value2
    pop rdi
    mov r13, rax    ;r13(value) = char_to_value(str[0], base)

    jmp .loop

.error:
    pop r15
    pop r14
    pop r13
    pop r12

    mov rax, 0
    ret

.error_null:
    pop r15
    pop r14
    pop r13
    pop r12

    mov rax, 0
    ret

.reset_error:
    pop rsi
    pop rdi
    jmp .error

.reset_error_base:
    pop rsi
    pop rdi
    pop r15
    pop r14
    pop r13
    pop r12

    mov rax, 0
    ret

.end:
    mov rax, r14
    mul r12         ;result * sign;

    pop r15
    pop r14
    pop r13
    pop r12

    ret
