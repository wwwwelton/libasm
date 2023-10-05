#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main(void) {
	// printf("%d", ft_call());
	char* str = strdup("Libasmr");

	printf("%ld\n", strlen(str));
	printf("%ld\n", ft_strlen(str));

	printf("%s\n", str);

	free(str);

	return (0);
}
