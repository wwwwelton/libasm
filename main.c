#include <stdio.h>
#include <string.h>
#include "header.h"
#include <unistd.h>
#include <errno.h>

int main(void) {
	ssize_t ret = 0;
	char buf[10];
	buf[10] = '\0';
	setbuf(stdout, NULL);
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
	// ret = ft_write(1, "hello ", 0);
	// printf("%ld", ret);
	// printf("\n%s", strerror(errno));

	// printf("\n=========\n");

	// ret = ft_write(90, "hello ", 7);
	// printf("%ld", ret);
	// printf("\n%s", strerror(errno));

	// printf("\n=========\n");

	// ret = ft_write(1, "hello ", 7);
	// printf("%ld", ret);
	// printf("\n%s", strerror(errno));

	ret = ft_read(1, buf, 9);
	printf("%ld", ret);
	printf("%s", buf);
	printf("\n%s", strerror(errno));

	printf("\n=========\n");

	ret = ft_read(-1, buf, 9);
	printf("%ld", ret);
	printf("%s", buf);
	printf("\n%s", strerror(errno));

	printf("\n=========\n");

	return (0);
}
