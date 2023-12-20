#ifndef HEADER
#define HEADER

#include <stdlib.h>
#include <sys/types.h>

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

int ft_call(void);
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

t_list *ft_list_create_elem(void *data);
void ft_list_push_front(t_list **begin_list, void *data);

#endif
