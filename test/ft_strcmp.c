#include <string.h>

#include "../src/header.h"
#include "ctest.h"

CTEST(ft_strcmp, test1) {
  int or = strcmp("", "42");
  int ft = ft_strcmp("", "42");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test2) {
  int or = strcmp("42", "");
  int ft = ft_strcmp("42", "");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test3) {
  int or = strcmp("42", "42");
  int ft = ft_strcmp("42", "42");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test4) {
  int or = strcmp("abc", "def");
  int ft = ft_strcmp("abc", "def");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test5) {
  int or = strcmp("def", "abc");
  int ft = ft_strcmp("def", "abc");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test6) {
  int or = strcmp("42 is awesome", "42 is zaweso");
  int ft = ft_strcmp("42 is awesome", "42 is zaweso");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test7) {
  int or = strcmp("42 is zaweso", "42 is awesome");
  int ft = ft_strcmp("42 is zaweso", "42 is awesome");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test8) {
  int or = strcmp(
             "Mussum Ipsum, cacilds vidis litro abertis.\
              Mauris nec dolor in eros commodo tempor.",
             "Mussum Ipsum, cacilds vidis litro abertis.\
              Mauris nec dolor in eros commodo tempor.");

  int ft = ft_strcmp(
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor.",
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor.");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test9) {
  int or = strcmp(
             "Mussum Ipsum, cacilds vidis litro abertis.\
              Mauris nec dolor in eros commodo tempor!",
             "Mussum Ipsum, cacilds vidis litro abertis.\
              Mauris nec dolor in eros commodo tempor.");

  int ft = ft_strcmp(
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor!",
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor.");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strcmp, test10) {
  int or = strcmp(
             "Mussum Ipsum, cacilds vidis litro abertis.\
              Mauris nec dolor in eros commodo tempor.",
             "Mussum Ipsum, cacilds vidis litro abertis.\
              Mauris nec dolor in eros commodo tempor!");

  int ft = ft_strcmp(
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor.",
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor!");
  ASSERT_EQUAL(or, ft);
}
