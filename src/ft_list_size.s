section .text
    global ft_list_size

;int ft_list_size(t_list *begin_list);
ft_list_size:
    push r15

    mov rax, 0      ;int size = 0;
    mov r15, rdi    ;node = begin_list;

.loop:
    cmp r15, 0      ;check if node is null
    je .end         ;return the rax(size)
    inc rax         ;size++
    mov r15, [r15 + 8] ;node = node->next
    jmp .loop       ;back to loop (while...)

.end:
    pop r15

    ret             ;return the content in the rax
