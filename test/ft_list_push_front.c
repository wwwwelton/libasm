#include <string.h>

#include "../src/header.h"
#include "ctest.h"
#include "test_header.h"

CTEST(ft_list_push_front, test1) {
  t_list *root = NULL;
  int elem1 = 42;
  int elem2 = 24;
  int elem3 = 13;

  ft_list_push_front(&root, intdup(elem1));
  ASSERT_EQUAL(*(int *)root->data, elem1);

  ft_list_push_front(&root, intdup(elem2));
  ASSERT_EQUAL(*(int *)root->data, elem2);

  ft_list_push_front(&root, intdup(elem3));
  ASSERT_EQUAL(*(int *)root->data, elem3);

  ft_list_clear(root, free);
}

CTEST(ft_list_push_front, test2) {
  t_list *root = NULL;
  char elem1[] = "42";
  char elem2[] = "24";
  char elem3[] = "13";

  ft_list_push_front(&root, strdup(elem1));
  ASSERT_STR((char *)root->data, elem1);

  ft_list_push_front(&root, strdup(elem2));
  ASSERT_STR((char *)root->data, elem2);

  ft_list_push_front(&root, strdup(elem3));
  ASSERT_STR((char *)root->data, elem3);

  ft_list_clear(root, free);
}

CTEST(ft_list_push_front, test3) {
  t_list *root = NULL;
  char elem1 = 'A';
  char elem2 = 'B';
  char elem3 = 'C';

  ft_list_push_front(&root, intdup(elem1));
  ASSERT_EQUAL(*(char *)root->data, elem1);

  ft_list_push_front(&root, intdup(elem2));
  ASSERT_EQUAL(*(char *)root->data, elem2);

  ft_list_push_front(&root, intdup(elem3));
  ASSERT_EQUAL(*(char *)root->data, elem3);

  ft_list_clear(root, free);
}
