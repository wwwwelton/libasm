#include <stdio.h>
#include <string.h>

#include "test_header.h"

static int compare_int(int *a, int *b) {
  return (*a > *b) - (*a < *b);
}

static int compare_char(char *a, char *b) {
  return (*a > *b) - (*a < *b);
}

CTEST(ft_list_remove_if, test1) {
  t_list *root1 = NULL;
  t_list *root2 = NULL;
  t_list *tmp_root1 = NULL;
  t_list *tmp_root2 = NULL;
  char *elems1[] = {"PIZZA", "BURGER", "PIZZA", "PASTA", "TACOS", "CURRY", "SALAD", "STEAK", "CURRY", "TOAST"};
  char *elems2[] = {"PASTA", "TACOS", "SALAD", "STEAK", "TOAST"};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, strdup(elems1[i]));
  }

  for (int i = 0; i < 5; i++) {
    ft_list_push_front(&root2, strdup(elems2[i]));
  }

  ft_list_remove_if(&root1, "PIZZA", strcmp, free);
  ft_list_remove_if(&root1, "BURGER", strcmp, free);
  ft_list_remove_if(&root1, "CURRY", strcmp, free);

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

CTEST(ft_list_remove_if, test2) {
  t_list *root1 = NULL;
  t_list *root2 = NULL;
  t_list *tmp_root1 = NULL;
  t_list *tmp_root2 = NULL;
  char elems1[] = {'B', 'S', 'B', 'T', 'R', 'V', 'R', 'Y', 'H', 'W'};
  char elems2[] = {'S', 'T', 'V', 'Y', 'H'};
  char remove[] = {'B', 'R', 'W'};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, intdup(elems1[i]));
  }

  for (int i = 0; i < 5; i++) {
    ft_list_push_front(&root2, intdup(elems2[i]));
  }

  ft_list_remove_if(&root1, &remove[0], compare_char, free);
  ft_list_remove_if(&root1, &remove[1], compare_char, free);
  ft_list_remove_if(&root1, &remove[2], compare_char, free);

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

CTEST(ft_list_remove_if, test3) {
  t_list *root1 = NULL;
  t_list *root2 = NULL;
  t_list *tmp_root1 = NULL;
  t_list *tmp_root2 = NULL;
  int elems1[] = {15, 49, 15, 35, 70, 76, 54, 69, 80, 70};
  int elems2[] = {49, 35, 76, 54, 80};
  int remove[] = {15, 69, 70};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, intdup(elems1[i]));
  }

  for (int i = 0; i < 5; i++) {
    ft_list_push_front(&root2, intdup(elems2[i]));
  }

  ft_list_remove_if(&root1, &remove[0], compare_int, free);
  ft_list_remove_if(&root1, &remove[1], compare_int, free);
  ft_list_remove_if(&root1, &remove[2], compare_int, free);

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

CTEST(ft_list_remove_if, test4) {
  t_list *root1 = NULL;
  int elems1[] = {15, 49, 15, 35, 70, 76, 54, 69, 80, 70};
  int remove[] = {70, 80, 69, 54, 76, 70, 35, 15, 49, 15};

  for (int i = 0; i < 10; i++) {
    ft_list_push_front(&root1, intdup(elems1[i]));
  }

  for (int i = 0; i < 10; i++) {
    ft_list_remove_if(&root1, &remove[i], compare_int, free);
  }
}
