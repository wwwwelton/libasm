#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "../src/header.h"
#include "ctest.h"

CTEST(ft_read, test1) {
  char buffer1[100];
  char buffer2[100];

  errno = 0;
  int or = read(-1, buffer1, 100);
  int or_errno = errno;

  errno = 0;
  int ft = ft_read(-1, buffer2, 100);
  int ft_errno = errno;

  ASSERT_EQUAL(or, ft);
  ASSERT_EQUAL(or_errno, ft_errno);
}

CTEST(ft_read, test2) {
  char str[] = "Contrary to popular belief, Lorem Ipsum is not simply random text.";
  char *filename1 = "input1.txt";
  char *filename2 = "input2.txt";
  char buffer1[100];
  char buffer2[100];

  int fd1 = open(filename1, O_RDWR | O_CREAT, 0644);
  int fd2 = open(filename2, O_RDWR | O_CREAT, 0644);

  write(fd1, str, strlen(str));
  write(fd2, str, strlen(str));

  close(fd1);
  close(fd2);

  fd1 = open(filename1, O_RDWR | O_CREAT, 0644);
  fd2 = open(filename2, O_RDWR | O_CREAT, 0644);

  errno = 0;
  int or = read(fd1, buffer1, strlen(str));
  buffer1[or] = '\0';
  int or_errno = errno;

  errno = 0;
  int ft = ft_read(fd2, buffer2, strlen(str));
  buffer2[ft] = '\0';
  int ft_errno = errno;

  close(fd1);
  close(fd2);

  ASSERT_EQUAL(or, ft);
  ASSERT_EQUAL(or_errno, ft_errno);
  ASSERT_STR(buffer1, buffer2);
}

CTEST(ft_read, test3) {
  char buffer1[100];
  char buffer2[100];

  errno = 0;
  int or = read(STDIN_FILENO, buffer1, 100);
  buffer1[or] = '\0';
  int or_errno = errno;

  errno = 0;
  int ft = ft_read(STDIN_FILENO, buffer2, 100);
  buffer2[ft] = '\0';
  int ft_errno = errno;

  ASSERT_EQUAL(or, ft);
  ASSERT_EQUAL(or_errno, ft_errno);
  ASSERT_STR(buffer1, buffer2);
}
