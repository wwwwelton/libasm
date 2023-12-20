section .text
    global ft_list_size

;int ft_list_size(t_list *begin_list);
ft_list_size:
    mov rax, 0      ;int size = 0;
    mov r11, rdi    ;node = begin_list;

.loop:
    cmp r11, 0      ;check if node is null
    je .end         ;return the rax(size)
    inc rax         ;size++
    mov r11, [r11 + 8] ;node = node->next
    jmp .loop       ;back to loop (while...)

.end:
    ret             ;return the content in the rax
