#include <string.h>

#include "../src/header.h"
#include "ctest.h"

CTEST(ft_strlen, test1) {
  int or = strlen("");
  int ft = ft_strlen("");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strlen, test2) {
  int or = strlen("42");
  int ft = ft_strlen("42");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strlen, test3) {
  int or = strlen("42 is awesome");
  int ft = ft_strlen("42 is awesome");
  ASSERT_EQUAL(or, ft);
}

CTEST(ft_strlen, test4) {
  char str[] =
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor.";

  int or = strlen(str);
  int ft = ft_strlen(str);
  ASSERT_EQUAL(or, ft);
}
