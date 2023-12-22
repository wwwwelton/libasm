section .text
    global ft_list_remove_if
    extern free

;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
;(*cmp)(list_ptr->data, data_ref);
;(*free_fct)(list_ptr->data);
ft_list_remove_if:
    push r8
    push r9
    push r12
    push r13
    push r14
    push r15

    mov r8, rdi     ;r8 = **begin_list
    mov r9, rsi     ;r9 = void *data_ref
    mov r12, rdx    ;r12 = int (*cmp)()
    mov r13, rcx    ;r13 = void (*free_fct)(void *)
    mov r14, 0      ;prev = NULL
    mov r15, 0      ;root = NULL
    mov rax, 1      ;removed = 1;

.loop:
    cmp rax, 0      ;while (removed)
    je .end
    mov rax, 0      ;removed = 0
    mov r15, [r8]   ;root = *begin_list

.check_root:
    cmp r15, 0      ;if root == NULL
    je .end
    mov rdi, [r15]  ;ft_strcmp(root->data, X)
    mov rsi, r9     ;ft_strcmp(X, data_ref)
    call r12        ;call cmp(ft_strcmp) function
    cmp rax, 0
    je .remove_root_node

.check_node:
    cmp r15, 0      ;while (root)
    je .end
    mov rdi, [r15]  ;ft_strcmp(root->data, X)
    mov rsi, r9     ;ft_strcmp(X, data_ref)
    call r12        ;call cmp(ft_strcmp) function
    cmp rax, 0
    je .remove_node ;if cmp() == 0
    mov r14, r15    ;prev = root
    mov r15, [r15 + 8] ;root = root->next
    jmp .check_node

.remove_node:
    mov rax, [r15 + 8] ;rax = root->next
    mov [r14 + 8], rax ;prev->next = root->next
    mov rdi, [r15]  ;free_fct(root->data)
    call r13        ;call free_fct
    mov rdi, r15    ;free(root)
    call free wrt ..plt ;call free
    mov rax, 1      ;removed = 1
    jmp .loop

.remove_root_node:
    mov rax, [r15 + 8] ;rax = root->next
    mov [r8], rax   ;*begin_list = root->next;
    mov rdi, [r15]  ;free_fct(root->data)
    call r13
    mov rdi, r15    ;free(root)
    call free wrt ..plt ;call free
    mov rax, 1      ;removed = 1;
    jmp .loop

.end:
    pop r15
    pop r14
    pop r13
    pop r12
    pop r9
    pop r8

    ret             ;return the content in the rax
