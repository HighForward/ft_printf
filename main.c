#include "includes/ft_printf.h"
#include <libc.h>
#include <limits.h>

int main(void)
{
	int i;
	int size;
	int a, b;

	a = ft_printf("%-22.18u?", 78789);
	printf("\n");
	b = printf("%-22.18u?", 78789);
	if (a != b)
		printf("\ntu \033[1;31m[KO]\033[0;0m mon gars\nfake = %d\nreal = %d\n", a, b);
	else
		printf("\nbravo... \033[1;32m[OK]\033[0;0m\n");
}

//ft_printf("%.*s\\", -10, "YO");