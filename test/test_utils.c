#include "test_header.h"

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
    free_fct(&begin_list->data);
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
