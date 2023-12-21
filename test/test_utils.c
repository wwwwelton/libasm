#include <stdio.h>
#include <stdlib.h>

#include "test_header.h"

int *intdup(int number) {
  int *dup = (int *)malloc(sizeof(int));

  if (dup == NULL)
    return NULL;
  *dup = number;

  return dup;
}

// t_list *ft_list_create_elem(void *data) {
//   t_list *element;

//   element = (t_list *)malloc(sizeof(t_list));
//   if (!element)
//     return (NULL);
//   element->data = data;
//   element->next = NULL;
//   return (element);
// }

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *)) {
  t_list *tmp_element;

  if (!begin_list || !free_fct)
    return;
  while (begin_list) {
    tmp_element = begin_list->next;
    free(begin_list->data);
    free(begin_list);
    begin_list = tmp_element;
  }
}

// void ft_list_push_front(t_list **begin_list, void *data) {
//   t_list *element;

//   if (!begin_list || !data)
//     return;
//   element = ft_list_create_elem(data);
//   element->next = *begin_list;
//   *begin_list = element;
// }

// int ft_list_size(t_list *begin_list) {
//   int size = 0;

//   t_list *node = begin_list;
//   while (node) {
//     size++;
//     node = node->next;
//   }

//   return size;
// }

// (*cmp)(list_ptr->data, list_other_ptr->data);
// void ft_list_sort(t_list **begin_list, int (*cmp)()) {
//   int swapped = 1;

//   while (swapped) {
//     swapped = 0;
//     t_list *node = *begin_list;

//     while (node->next) {
//       if (cmp((char *)node->data, (char *)node->next->data) > 0) {
//         swapped = 1;
//         void *tmp_data = node->data;
//         node->data = node->next->data;
//         node->next->data = tmp_data;
//       }
//       node = node->next;
//     }
//   }
// }
