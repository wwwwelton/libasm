#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../src/header.h"
#include "ctest.h"

CTEST(ft_write, test1) {
  char str[] = "42";

  errno = 0;
  int or = write(-1, str, strlen(str));
  int or_errno = errno;

  errno = 0;
  int ft = ft_write(-1, str, strlen(str));
  int ft_errno = errno;

  ASSERT_EQUAL(or, ft);
  ASSERT_EQUAL(or_errno, ft_errno);
}

CTEST(ft_write, test2) {
  char str[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry\n";
  int fd;
  char *filename = "output.txt";
  FILE *file;
  char line1[100];
  char line2[100];

  fd = open(filename, O_RDONLY | O_WRONLY | O_CREAT, 0644);

  errno = 0;
  int or = write(fd, str, strlen(str));
  int or_errno = errno;

  errno = 0;
  int ft = ft_write(fd, str, strlen(str));
  int ft_errno = errno;

  close(fd);

  file = fopen(filename, "r");
  fgets(line1, sizeof(line1), file);
  fgets(line2, sizeof(line1), file);
  fclose(file);

  ASSERT_EQUAL(or, ft);
  ASSERT_EQUAL(or_errno, ft_errno);
  ASSERT_STR(line1, line2);
}

CTEST(ft_write, test3) {
  char str[] = "There are many variations of passages of Lorem\n";
  int fd;
  char *filename = "stdout.txt";
  FILE *file;
  char line1[100];
  char line2[100];
  int backup_fd;

  backup_fd = dup(STDOUT_FILENO);

  fd = open(filename, O_RDONLY | O_WRONLY | O_CREAT, 0644);
  dup2(fd, STDOUT_FILENO);

  errno = 0;
  int or = write(STDOUT_FILENO, str, strlen(str));
  int or_errno = errno;

  errno = 0;
  int ft = ft_write(STDOUT_FILENO, str, strlen(str));
  int ft_errno = errno;

  close(STDOUT_FILENO);
  dup2(backup_fd, STDOUT_FILENO);

  file = fopen(filename, "r");
  fgets(line1, sizeof(line1), file);
  fgets(line2, sizeof(line1), file);
  fclose(file);

  ASSERT_EQUAL(or, ft);
  ASSERT_EQUAL(or_errno, ft_errno);
  ASSERT_STR(line1, line2);
}

// CTEST(ft_write, test4) {
//   char str[] = "There are many variations of passages of Lorem\n";

//   errno = 0;
//   int or = write(STDOUT_FILENO, str, strlen(str));
//   int or_errno = errno;

//   errno = 0;
//   int ft = ft_write(STDOUT_FILENO, str, strlen(str));
//   int ft_errno = errno;

//   ASSERT_EQUAL(or, ft);
//   ASSERT_EQUAL(or_errno, ft_errno);
// }
