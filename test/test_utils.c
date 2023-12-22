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
    free_fct(begin_list->data);
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

// (*cmp)(list_ptr->data, data_ref);
// (*free_fct)(list_ptr->data);
// ft_list_remove_if(&root1, "U", ft_strcmp, free);
// void ft_list_remove_if(t_list **begin_list,
//                        void *data_ref,
//                        int (*cmp)(),
//                        void (*free_fct)(void *)) {
//   t_list *prev = NULL;
//   t_list *root = *begin_list;
//   int removed = 1;

//   if (!begin_list || !*begin_list || !data_ref || !cmp || !free_fct)
//     return;

//   while (removed) {
//     root = *begin_list;
//     removed = 0;

//     if (root && cmp(root->data, data_ref) == 0) {
//       *begin_list = root->next;
//       free_fct(root->data);
//       free(root);
//       removed = 1;
//       continue;
//     }

//     while (root && cmp(root->data, data_ref) != 0) {
//       prev = root;
//       root = root->next;
//     }

//     if (root) {
//       prev->next = root->next;
//       free_fct(root->data);
//       free(root);
//       removed = 1;
//     }
//   }
// }
