;indicates that the function is defined in another file
extern __errno_location

section .text
    global ft_read

;ssize_t read(int fd, void *buf, size_t count);
ft_read:
    mov rax, 0      ;sys_read
    syscall         ;perform a system call
    cmp rax, 0      ;check if read returned < 0 (error)
    jl .error       ;jump to .error if rax < 0. SF == 1
    ret             ;return the content in the rax

.error:
    neg rax         ;invert the sign -9 => 9
    mov r11, rax    ;save rax value in a tmp register
    call __errno_location wrt ..plt ;set errno value
    mov [rax], r11  ;dereference the rax pointer and restore value
    mov rax, -1     ;set rax to -1 to indicate an error
    ret             ;return the content in the rax (-1)
