extern __errno_location

section .text
    global ft_write

ft_write:
    mov rax, 1
    syscall
    cmp rax, -1
    js .error
    ret

.error:
    neg rax
    mov r11, rax
    call __errno_location wrt ..plt
    mov [rax], r11
    mov rax, -1
    ret
