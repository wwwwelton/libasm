#ifndef HEADER
#define HEADER

#include <sys/types.h>

int ft_call(void);
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

#endif
