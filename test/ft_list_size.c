#include <string.h>

#include "../src/header.h"
#include "ctest.h"
#include "test_header.h"

CTEST(ft_list_size, test1) {
  t_list *root = NULL;
  int elems[] = {42, 3, 10, 8, 67, 88, 22, 1};

  for (int i = 0; i < 8; i++) {
    ft_list_push_front(&root, intdup(elems[i]));
  }

  ASSERT_EQUAL(ft_list_size(root), 8);

  ft_list_clear(root, free);
}

CTEST(ft_list_size, test2) {
  t_list *root = NULL;
  int elems[] = {42, 3, 10, 8, 67, 88, 22, 1};

  for (int i = 0; i < 7; i++) {
    ft_list_push_front(&root, intdup(elems[i]));
  }

  ASSERT_EQUAL(ft_list_size(root), 7);

  ft_list_clear(root, free);
}

CTEST(ft_list_size, test3) {
  t_list *root = NULL;
  int elems[] = {42, 3, 10, 8, 67, 88, 22, 1};

  for (int i = 0; i < 1; i++) {
    ft_list_push_front(&root, intdup(elems[i]));
  }

  ASSERT_EQUAL(ft_list_size(root), 1);

  ft_list_clear(root, free);
}

CTEST(ft_list_size, test4) {
  t_list *root = NULL;

  ASSERT_EQUAL(ft_list_size(root), 0);

  ft_list_clear(root, free);
}
