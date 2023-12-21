section .text
    global ft_list_sort

;void ft_list_sort(t_list **begin_list, int (*cmp)());
;(*cmp)(list_ptr->data, list_other_ptr->data);
ft_list_sort:
    mov r8, rdi     ;r8 = **begin_list
    mov r9, rsi     ;r9 = int (*cmp)() (ft_strcmp)
    mov r12, 1      ;swapped = 1;
    mov r13, [r8]   ;node = *begin_list;

.loop1:
    cmp r12, 0      ;if swapped == 0
    je .end
    mov r12, 0      ;swapped = 0
    mov r13, [r8]   ;node = *begin_list;

.loop2:
    cmp QWORD [r13 + 8], 0 ;if node->next == NULL
    je .loop1
    mov rdi, [r13]  ;ft_strcmp(node->data, X)
    mov rsi, [r13 + 8] ;rsi = node->next
    mov rsi, [rsi]  ;ft_strcmp(X, node->next->data)
    call r9         ;call cmp(ft_strcmp) function
    cmp rax, 1      ;if cmp > 0 (A > B)
    je .swap
    mov r13, [r13 + 8] ;node = node->next
    jmp .loop2

.swap:
    mov r12, 1      ;swapped = 1
    mov [r13], rsi  ;node = node->next->data
    mov r14, [r13 + 8] ;r14 = node->next
    mov [r14], rdi  ;node->next->data = node->data
    mov r13, [r13 + 8] ;node = node->next
    jmp .loop2

.end:
    mov rdi, r8     ;restore **begin_list
    mov rsi, r9     ;restore int (*cmp)() (ft_strcmp)
    ret             ;return the content in the rax
