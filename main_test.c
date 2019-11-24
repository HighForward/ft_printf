#include "ft_printf.h"

int main(void)
{
	//printf("---------->  BASICS TESTS  <----------");
	ft_printf("%s\n", "YO L'EKIPE");
	printf("%s\n", "YO L'EKIPE");
	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');
	ft_printf("%d\n", 1998);
	printf("%d\n", 1998);
	/*printf("---------->   TESTS 2 '-'  <----------\n");*/
	printf("%-8s\n", "1998");
	ft_printf("%-8s\n", "1998");
	printf("%-8d\n", 1998);
	ft_printf("%-8d\n", 1998);
	printf("%-8c\n", 'X');
	ft_printf("%-8c\n", 'X');
	/*printf("----------> TESTS 2 'vide' <----------\n");*/
	printf("%8s\n", "1998");
	ft_printf("%8s\n", "1998");
	printf("%8d\n", 1998);
	ft_printf("%8d\n", 1998);
	printf("%8c\n", 'X');
	ft_printf("%8c\n", 'X');
	/*printf("---------->   TESTS 3 '0'  <----------\n");*/
	printf("%08d\n", 1998);
	ft_printf("%08d\n", 1998);
	//ft_printf("AJOUTER CONVERTION X x u i %");
	//printf("---------->   TESTS 4 '.'  <----------\n");
	printf("%.8s\n", "YO L'EKIPE");
	ft_printf("%.8s\n", "YO L'EKIPE");
	printf("%.8d\n", 1998);
	ft_printf("%.8d\n", 1998);
	printf("%.2d\n", 1998);
	ft_printf("%.2d\n", 1998);
	//printf("---------->   TESTS 5 '-.'  <----------\n");
	printf("%-18.10s\n", "YO L'EKIPE");
	ft_printf("%-18.10s\n", "YO L'EKIPE");
	printf("%-.10d\n", 1998);
	ft_printf("%-.10d\n", 1998);
	printf("%-18.10d\n", 1998);
	ft_printf("%-18.10d\n", 1998);
	//printf("---------->   TESTS 5 '-.'  <----------\n");
	printf("%018.10d\n", 1998);
	ft_printf("%018.10d\n", 1998);
	printf("%06.4d\n", 1998);
	ft_printf("%06.4d\n", 1998);
	ft_printf("########################################\n");

}