#ifndef TEST_HEADER
#define TEST_HEADER

#include <string.h>

#include "../src/header.h"
#include "ctest.h"

int *intdup(int number);
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

#endif
