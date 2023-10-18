#include <string.h>

#include "../src/header.h"
#include "ctest.h"

CTEST(ft_strcpy, test1) {
  char or_dest[10];
  char ft_dest[10];

  char * or = strcpy(or_dest, "");
  char *ft = ft_strcpy(ft_dest, "");
  ASSERT_STR(or, ft);
}

CTEST(ft_strcpy, test2) {
  char or_dest[15];
  char ft_dest[15];

  char * or = strcpy(or_dest, "42 is awesome");
  char *ft = ft_strcpy(ft_dest, "42 is awesome");
  ASSERT_STR(or, ft);
}

CTEST(ft_strcpy, test4) {
  char str[] =
      "Mussum Ipsum, cacilds vidis litro abertis.\
       Mauris nec dolor in eros commodo tempor.";
  char or_dest[90];
  char ft_dest[90];

  char * or = strcpy(or_dest, str);
  char *ft = ft_strcpy(ft_dest, str);
  ASSERT_STR(or, ft);
}
