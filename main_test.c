#include "printf.h"

int main (int ac, char **av)
{
	int number;

	number = 1234;
	/*printf(" %-3c .\n", 'c');
	printf(" %-3s .\n", "string");
	printf(" %-3p .\n", &number);
	printf(" %-3d .\n", number);
	printf(" %-3i .\n", number);
	printf(" %-3u .\n", (unsigned int) number);
	printf(" %-3x .\n", number);
	printf(" %-3X .\n", number);
	printf(" %-3% .\n");
*/

	//ft_printf("d %s", "salut");
	//printf("\nd %s\n", "bonjour");

	int first, second, ko, ok;
	float rate;
	char *color;
	int index;
	char **kos;

	ko = 0;
	ok = 0;
	index = 0;
	kos = (char **)malloc(sizeof(char *) * 100);
	if (ac > 1 && av[1][0] == 'a')
	{
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %d ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %d", 1337);
		printf("\nfirst: %d, second: %d, equals: %s\033[00m\n", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO]<--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %s ", "yo lekip");
		first =     printf("\n---- REAL PRINTF ----\nint : %s", "yo lekip");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %u ", (unsigned int)1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %u", (unsigned int)1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %p ", &rate);
		first =     printf("\n---- REAL PRINTF ----\nint : %p", &rate);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %x ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %x", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %X ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %X", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %c ", 'c');
		first =     printf("\n---- REAL PRINTF ----\nint : %c", 'c');
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5c ", 'c');
		first =     printf("\n---- REAL PRINTF ----\nint : %-5c", 'c');
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5s ", "yo lekip");
		first =     printf("\n---- REAL PRINTF ----\nint : %-5s", "yo lekip");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5p ", &number);
		first =     printf("\n---- REAL PRINTF ----\nint : %-5p", &number);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5d ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-5d", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5i ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-5i", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5u ", (unsigned int)4294967295);
		first =     printf("\n---- REAL PRINTF ----\nint : %-5u", (unsigned int)4294967295);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-8x ", 1685);
		first =     printf("\n---- REAL PRINTF ----\nint : %-8x", 1685);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-8X ", 1685);
		first =     printf("\n---- REAL PRINTF ----\nint : %-8X", 1685);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-5% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %-5%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010d ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %010d", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010i ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %010i", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010u ", (unsigned int)1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %010u", (unsigned int)1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010x ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %010x", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010X ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %010X", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;		if (second != first)
			sprintf(kos[ko], "test #%d failed.", ko+ok);
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %010%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %5.3s ", "forty-two");
		first =     printf("\n---- REAL PRINTF ----\nint : %5.3s", "forty-two");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.10d ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.10d", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.10i ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.10i", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.10u ", (unsigned int)1337);
		first =     printf("\n---- REAL PRINTF ----\nint : %.10u", (unsigned int)1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.10x ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.10x", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.10X ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.10X", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.10% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %.10%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*c ", 10, 'f');
		first =     printf("\n---- REAL PRINTF ----\nint : %*c", 10, 'f');
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*s ", 10, "yo lekip");
		first =     printf("\n---- REAL PRINTF ----\nint : %*s", 10, "yo lekip");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*p ", 20, &number);
		first =     printf("\n---- REAL PRINTF ----\nint : %*p", 20, &number);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*d ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*d", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*i ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*i", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*u ", 56, (unsigned int)4294967295);
		first =     printf("\n---- REAL PRINTF ----\nint : %*u", 56, (unsigned int)4294967295);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*x ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*x", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*X ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*X", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*% ", 10);
		first =     printf("\n---- REAL PRINTF ----\nint : %*%", 10);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-2.10s ", "forty-two-leet");
		first =     printf("\n---- REAL PRINTF ----\nint : %-2.10s", "forty-two-leet");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-.10d ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-.10d", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-.10i ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-.10i", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-.10u ", (unsigned int)421337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-.10u", (unsigned int)421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-.10x ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-.10x", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-.10X ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nint : %-.10X", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %-8.10% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %-8.10%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010.8d ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %010.8d", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010.8i ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %010.8i", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010.8u ", (unsigned int)42133721);
		first =     printf("\n---- REAL PRINTF ----\nint : %010.8u", (unsigned int)42133721);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010.8x ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %010.8x", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010.8X ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %010.8X", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %010.8% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %010.8%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010s ", "hello");
		first =     printf("\n---- REAL PRINTF ----\nint : %.010s", "hello");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010d ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.010d", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010i ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.010i", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010u ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.010u", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010x ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.010x", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010X ", 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %.010X", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %.010% ");
		first =     printf("\n---- REAL PRINTF ----\nint : %.010%");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10s ", 5, "not the same as others");
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10s", 5, "not the same as others");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10d ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10d", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10i ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10i", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10u ", 16, (unsigned int)42133721);
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10u", 16, (unsigned int)42133721);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10x ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10x", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10X ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10X", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %*.10% ", 16);
		first =     printf("\n---- REAL PRINTF ----\nint : %*.10%", 16);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}

		kos[ko + 1] = 0;
		index++;
		if (kos[1])
			printf("\n\033[1;31mTEST ERRORS:\033[00m\n");
		while (kos[index])
		{
			printf("- \033[1;31m%s\033[00m\n", kos[index]);
			free(kos[index]);
			index++;
		}
		free(kos);
	}
	else
	{
		second = ft_printf(  "---- FAKE PRINTF ----\nint : %5.3s ", "for");
		first =     printf("\n---- REAL PRINTF ----\nint : %5.2s", "for");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
	}

	rate = (float)(100 * ko)/(ko + ok);
	if (rate > 0 && rate < 15)
		color = ft_strdup("\033[01;33m");
	else if (rate == 0)
		color = ft_strdup("\033[1;32m");
	else
		color = ft_strdup("\033[1;31m");
	printf("\n\033[01;33mFINAL RESULT :\033[00m\n\033[1;32m[OK] \033[00m: %d, \033[1;31m[KO] \033[00m: %d, KO rate : %s%.2f%% %s\033[00m\n", ok, ko, color, rate, rate == 0 ? "😃" : "😞");
	free(color);
	//free(kos);
	// "." : f to do : s
	// attention aux conversions x et X négative
	// "*" : rajoute x ' ' devant pour avoir n char total, avec n passé en parametre
	// "0" : rajoute x '0' devant pour avoir n char total, avec n en width;
	// demander pour le "-"
	// demander pour le const char * str du prototype de ft_printf()
	// rajouter un buffer, le résultat et d'abord écrit dedans afin de rajouter les zéros ou espaces
	return (0);
}