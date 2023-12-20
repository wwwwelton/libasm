section .text
    global ft_list_create_elem
    extern malloc

;t_list *ft_list_create_elem(void *data);
ft_list_create_elem:
    push rdi        ;save rdi(*data) to stack
    mov rdi, 16     ;set rdi to 16 (sizeof(t_list))
    call malloc wrt ..plt ;call malloc
    cmp rax, 0      ;if malloc failed == NULL go to .end
    je .end
    pop rdi
    mov [rax], rdi  ;element->data = data;
    mov byte [rax + 8], 0 ;element->next = NULL;

.end:
    ret             ;return the content in the rax
