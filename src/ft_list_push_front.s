section .text
    global ft_list_push_front
    extern ft_list_create_elem

;void ft_list_push_front(t_list **begin_list, void *data);
ft_list_push_front:
    push rdi        ;save rdi(**begin_list) to stack
    mov rdi, rsi    ;move *data to the first param
    call ft_list_create_elem ;call ft_list_create_elem(data)
    cmp rax, 0      ;if malloc failed == NULL go to .end
    je .end
    pop rdi         ;pop rdi(**begin_list) from stack
    mov r11, [rdi]  ;*begin_list
    mov QWORD [rax + 8], r11 ;element->next = *begin_list;
    mov [rdi], rax  ;*begin_list = element;

.end:
    ret             ;return the content in the rax
