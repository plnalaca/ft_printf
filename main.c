#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int x = ft_printf(" %u \n", 0);
	int y = printf(" %u \n", 0);

	printf("%d ---- %d\n", x, y);
}