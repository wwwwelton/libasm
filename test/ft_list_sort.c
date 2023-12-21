#include <stdio.h>
#include <string.h>

#include "../src/header.h"
#include "ctest.h"
#include "test_header.h"

static int compare_int(int *a, int *b) {
  return (*a > *b) - (*a < *b);
}

static int compare_char(char *a, char *b) {
  return (*a > *b) - (*a < *b);
}

CTEST(ft_list_sort, test1) {
  t_list *root1 = NULL;
  t_list *root2 = NULL;
  t_list *tmp_root1 = NULL;
  t_list *tmp_root2 = NULL;
  char *elems1[] = {"U", "I", "W", "R", "B", "S", "T", "V", "Y", "H"};
  char *elems2[] = {"Y", "W", "V", "U", "T", "S", "R", "I", "H", "B"};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, strdup(elems1[i]));
    ft_list_push_front(&root2, strdup(elems2[i]));
  }

  ft_list_sort(&root1, ft_strcmp);

  // while (root1 && root2) {
  //   printf("%s", (char *)root1->data);
  //   printf(" ");
  //   printf("%s", (char *)root2->data);
  //   printf("\n");
  //   root1 = root1->next;
  //   root2 = root2->next;
  // }

  tmp_root1 = root1;
  tmp_root2 = root2;
  while (tmp_root1 && tmp_root2) {
    ASSERT_STR((char *)tmp_root1->data, (char *)tmp_root2->data);
    tmp_root1 = tmp_root1->next;
    tmp_root2 = tmp_root2->next;
  }

  ft_list_clear(root1, free);
  ft_list_clear(root2, free);
}

CTEST(ft_list_sort, test2) {
  t_list *root1 = NULL;
  t_list *root2 = NULL;
  t_list *tmp_root1 = NULL;
  t_list *tmp_root2 = NULL;
  int elems1[] = {93, 91, 70, 69, 15, 49, 35, 76, 54, 80};
  int elems2[] = {93, 91, 80, 76, 70, 69, 54, 49, 35, 15};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, intdup(elems1[i]));
    ft_list_push_front(&root2, intdup(elems2[i]));
  }

  ft_list_sort(&root1, compare_int);

  // while (root1 && root2) {
  //   printf("%d", *(int *)root1->data);
  //   printf(" ");
  //   printf("%d", *(int *)root2->data);
  //   printf("\n");
  //   root1 = root1->next;
  //   root2 = root2->next;
  // }

  tmp_root1 = root1;
  tmp_root2 = root2;
  while (tmp_root1 && tmp_root2) {
    ASSERT_EQUAL(*(int *)tmp_root1->data, *(int *)tmp_root2->data);
    tmp_root1 = tmp_root1->next;
    tmp_root2 = tmp_root2->next;
  }

  ft_list_clear(root1, free);
  ft_list_clear(root2, free);
}

CTEST(ft_list_sort, test3) {
  t_list *root1 = NULL;
  t_list *root2 = NULL;
  t_list *tmp_root1 = NULL;
  t_list *tmp_root2 = NULL;
  char elems1[] = {'Z', 'X', 'E', 'D', 'M', 'Y', 'L', 'J', 'H', 'S'};
  char elems2[] = {'Z', 'Y', 'X', 'S', 'M', 'L', 'J', 'H', 'E', 'D'};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, intdup(elems1[i]));
    ft_list_push_front(&root2, intdup(elems2[i]));
  }

  ft_list_sort(&root1, compare_char);

  // while (root1 && root2) {
  //   printf("%c", *(char *)root1->data);
  //   printf(" ");
  //   printf("%c", *(char *)root2->data);
  //   printf("\n");
  //   root1 = root1->next;
  //   root2 = root2->next;
  // }

  tmp_root1 = root1;
  tmp_root2 = root2;
  while (tmp_root1 && tmp_root2) {
    ASSERT_EQUAL(*(char *)tmp_root1->data, *(char *)tmp_root2->data);
    tmp_root1 = tmp_root1->next;
    tmp_root2 = tmp_root2->next;
  }

  ft_list_clear(root1, free);
  ft_list_clear(root2, free);
}
