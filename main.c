#include <stdio.h>
#include <string.h>
#include "header.h"
#include <unistd.h>
#include <errno.h>

int main(void) {
	// printf("%d", ft_call());
	// char* str = strdup("Libasmr");

	// printf("%ld\n", strlen(str));
	// printf("%ld\n", ft_strlen(str));

	// printf("%s\n", str);

	// free(str);

	// ssize_t ret = ft_write(1, "zé da manga\n", 14);
	// printf("%ld", ret);

	// printf("%ld", write(90, "hello ", 7));
	// printf("\n%s", strerror(errno));
	printf("%ld", ft_write(90, "hello ", 7));
	printf("\n%s", strerror(errno));

	return (0);
}
