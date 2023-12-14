#include <string.h>

#include "../src/header.h"
#include "ctest.h"

CTEST(ft_strdup, test1) {
  char *or = strdup("");
  char *ft = ft_strdup("");
  ASSERT_STR(or, ft);

  free(or);
  free(ft);
}

CTEST(ft_strdup, test2) {
  char *or = strdup("42");
  char *ft = ft_strdup("42");
  ASSERT_STR(or, ft);

  free(or);
  free(ft);
}

CTEST(ft_strdup, test3) {
  char *or = strdup("Mussum Ipsum, cacilds vidis litro abertis. Mauris nec dolor in eros commodo tempor!");
  char *ft = ft_strdup("Mussum Ipsum, cacilds vidis litro abertis. Mauris nec dolor in eros commodo tempor!");
  ASSERT_STR(or, ft);

  free(or);
  free(ft);
}
