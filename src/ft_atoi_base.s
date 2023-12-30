%macro align_stack 0
    mov rax, rsp
    and rax, 15     ; Check the lower 4 bits to determine alignment
    jz .aligned     ; If zero, already aligned
    sub rsp, 8      ; Otherwise, subtract 8 to align
    .aligned:
%endmacro

section .text
    global ft_atoi_base
    extern ft_strlen, ft_isspace, ft_sstrlen, print_str, printf, not1, check_signal, is_valid_base, char_to_value1, char_to_value2

; ;int isspace(int c)
; ft_isspace:
;     cmp rdi, ' '
;     je .isspace
;     mov rax, rdi
;     sub rax, '\t'
;     cmp rax, 5
;     jl .itsnotspace

; .itsnotspace:
    ; mov rax, 0      ;isspace == FALSE
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
    push r9
    push r12
    push r13
    push r14
    push r15
    push rsi

    mov r9, 0       ;tmp rdi
    mov r12, 1      ;signal
    mov r13, 0      ;value
    mov r14, 0      ;result
    mov r15, 0      ;base_len
    mov r13, rsi    ;tmp rsi

.check_null:
    cmp rdi, 0      ;str == NULL
    je .error_null
    cmp rsi, 0      ;base == NULL
    je .error_null

.check_base:
    push rdi
    mov rdi, rsi
    call is_valid_base
    cmp rax, 0
    je .error_invalid_base
    pop rdi

    push rdi
    call print_str
    pop rdi

    mov r14, 0
    mov r15, rdi

.trim_spaces:
    mov rdi, [r15 + r14]
    sub rsp, 8
    call ft_isspace
    add rsp, 8
    cmp rax, 1
    je .trim_space

    lea rdi, [r15 + r14]
    push rdi
    call print_str
    pop rdi

.check_signal:
    cmp byte [rdi], '+'
    je .set_signal_pos
    cmp byte [rdi], '-'
    je .set_signal_neg

    push rdi
    call print_str
    pop rdi

    mov r14, 0
    mov r15, 0
    pop rsi         ;use .endd2 here
    mov rsi, r13

.get_base_len:
    push rdi
    push rsi
    mov rdi, rsi
    call ft_sstrlen
    mov r15, rax
    pop rsi
    pop rdi

.atoi_base:
    mov rax, 0
    push rdi
    push rsi
    mov rdi, [rdi + rax]
    mov rsi, rsi
    call char_to_value2
    pop rsi
    pop rdi
    mov r13, rax
    cmp r13b, -1
    je .end
    mov r14, r13
    mov rax, 0

; mov r9, 0       ;tmp
; mov r12, 0      ;signal
; mov r13, 0      ;value
; mov r14, 0      ;result
; mov r15, 0      ;base_len
.atoi_base_loop:
    inc rax
    push rdi
    push rsi
    push rax
    mov rdi, [rdi + rax]
    mov rsi, rsi
    sub rsp, 8
    call char_to_value2
    add rsp, 8
    mov r13, rax
    pop rax
    pop rdi
    pop rsi
    cmp r13b, -1
    je .end
    push rax
    mov rax, r14
    mul r15
    add rax, r13
    mov r14, rax
    pop rax
    jmp .atoi_base_loop

    ; push rdi
    ; push rsi
    ; mov rdi, rsi
    ; call print_str
    ; pop rsi
    ; pop rdi

    ; jmp .end

.set_signal_neg:
    mov r12, -1
    inc rdi
    jmp .check_signal

.set_signal_pos:
    mov r12, 1
    inc rdi
    jmp .check_signal

.trim_space:
    inc r14
    jmp .trim_spaces

.error_null:
    pop rsi
    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    mov rax, 0
    ret

.error_invalid_base:
    pop rdi
    pop rsi
    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    mov rax, 0
    ret

; mov r12, 0      ;signal
; mov r13, 0      ;value
; mov r14, 0      ;result
; mov r15, 0      ;base_len
.end:
    mov rax, r14
    mul r12         ;result * sign;

    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    ret

.endd:
    pop rsi
    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    mov rax, 21
    ret

.endd2:
    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    mov rax, 22
    ret

.endd3:
    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    ret
