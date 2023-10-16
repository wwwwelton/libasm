;indicates that the function is defined in another file
extern __errno_location

section .text
    global ft_write

;ssize_t write(int fd, const void *buf, size_t count);
ft_write:
    mov rax, 1      ;sys_write
    syscall         ;perform a system call
    cmp rax, 0      ;check if write returned < 0 (error)
    jl .error       ;jump to .error if rax < 0. SF == 1
    ret             ;return the content in the rax

.error:
    neg rax         ;invert the sign -9 => 9
    mov r11, rax    ;save rax value in a tmp register
    call __errno_location wrt ..plt ;set errno value
    mov [rax], r11  ;dereference the rax pointer and restore value
    mov rax, -1     ;set rax to -1 to indicate an error
    ret             ;return the content in the rax (-1)
