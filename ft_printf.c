/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 18:03:48 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list va;
	t_flag info;
	char *str;
	int i;
	int count;
	int ret;
	int uep;

	uep = 0;
	ret = 0;
	str = (char*)s;
	va_start(va, s);
	i = 0;

	while (str[i])
	{
		if (str[i] == '%')
		{
			initialize_struct(&info);
			i+=1;
			count = check_arg(&str[i], &info, va);
			get_arg_type(va, &info);
			ret = manage_str(&info);
			uep = uep + ret;
			i += count;

		}
		else
		{
			ft_putchar(s[i++]);
			uep++;
		}
	}
	/*printf("\n---< FLAGS >---\n");
	printf("FLAG 1  > %c\n", info.flag);
	printf("VALUE 1 > %d\n", info.flag_value);
	printf("FLAG 2  > %c\n", info.flag_2);
	printf("VALUE 2 > %d\n", info.flag_value_2);
	printf("CONVERT > %c\n", info.letter);
	printf("<--------------\n");*/
	va_end(va);
	return (uep);
}

int main(void)
{
	int i;
	int size;

	int a, b;

	/*a = ft_printf("%04.*d", 8, 13374221);
	printf("\n");
	b = printf("%04.*d", 8, 13374221);*/
	a = ft_printf("%---3.*d\\", -4, -4888);
	printf("\n");
	b = printf("%---3.*d\\", -4, -4888);
	if (a != b)
		printf("\ntu \033[1;31m[KO]\033[0;0m mon gars\nfake = %d\nreal = %d\n", a, b);
	else
		printf("\nbravo... \033[1;32m[OK]\033[0;0m\n");

}

//printf("\n%d\n", ft_printf("%---2.*d", 0, -456789));
//printf("\n%d\n", ft_printf("%09.*d", 5, -456789));
//<< A DEBUG >>//
//printf("\n%d\n", ft_printf("%---*d", 1, 1337));
//printf("\n%d\n", ft_printf("%03.*d", 1, -13374221));


	/*printf("\n%d\n", ft_printf("%*.*d", 5, 0, -42));
	printf("\n%d\n", printf("%*.*d", 5, 0, -42));*/
	//printf("\n%d\n", ft_printf("%d", 42));
	//printf("\n%d\n", printf("%d", 42));
//ERRORS
/*
 * 	printf("\n%d\n", ft_printf("%01.16d", -42));
 * 	printf("\n%d\n", ft_printf("%00.0d", 0));
 *  printf("\n%d\n", ft_printf("%0.0d", 0));
 *  printf("\n%d\n", ft_printf("%-*.0d", -0, 0));
 *  printf("\n%d\n", ft_printf("%-*.0d", -2, 0));
 *  printf("\n%d\n", ft_printf("%-*.0d", 2, 0));
 *  printf("\n%d\n", ft_printf("%-*.0d", -0, 16)); //RETURN
 *  printf("\n%d\n", ft_printf("%-*.*d", 0, -5, 16)); //RETURN
 *  printf("\n%d\n", ft_printf("%-*.*d", 0, 5, 16)); //RETURN ET LES 0
 *  printf("\n%d\n", ft_printf("%-*.*d", 0, 0, -16)); //RETURN
 *
 *  printf("\n%d\n", ft_printf("%0*.*d", 16, -16, -16));
 *  printf("\n%d\n", ft_printf("%0*.*d", 16, 16, -16));
 *  printf("\n%d\n", ft_printf("%*.*d", 16, 16, -16));
 *  printf("\n%d\n", ft_printf("%-*.*d", 16, 16, -16));
 *
 *  printf("\n%d\n", ft_printf("%0*.*d", 0, 0, 0));
 *  printf("\n%d\n", ft_printf("%0*.*d", 9, 5, -16));
 *  printf("\n%d\n", ft_printf("%-*d", 0, -16));
 *
 */


	/*printf("\n%d\n", ft_printf("%0*.*d", 30, 15, 0));
	printf("\n%d\n", printf("%0*.*d", 30, 15, 0));*/

	/*printf("\n%d\n", ft_printf("%-*.*d", 10, -80, 789));
	printf("\n%d\n", printf("%-*.*d", 10, -80, 789));*/


	/*printf("\n%d\n", ft_printf("%0*.*d", -25, -5, 0));
	printf("\n%d\n", printf("%0*.*d", -25, -5, 0));*/

	//printf("%d\n", ft_printf("%-.d", 42));
	//printf("%d\n", printf("%-.d", 423));



	//printf("%012d", 19);
	/*ft_printf("%*.*d\n", 8, 5, 1998);
	printf("%-*.5d\n", 12, 1998);
	ft_printf("%-*.5d\n", 12, 1998);
	ft_printf("%-12.5s\n", "1998");
	//printf("\n%-20.d<REAL1", 987987987);
	//ft_printf("\n%-20.d<FAKE1", 987987987);
	//printf("\n%-15.18d<REAL2", 987987987);
	//ft_printf("\n%-15.18d<FAKE2", 987987987);
	//printf("\n%-*.d", 30, 987987987);
	//ft_printf("\n%-*.d<FAKE", 5, 987987987);
	printf("\n%-*.d<REAL", 5, 987987987);
	ft_printf("\n%-*.d<FAKE", 5, 987987987);
	//printf("bite%*.dcbite%s%d%c%c%%\n", 80, 1000, "bite de ", 10, 'c', 'm');
	//ft_printf("bite%*.dcbite%s%d%c%c%%\n", 80, 1000, "bite de ", 10, 'c', 'm');
	//ft_printf("%08.*d\n", "bitw");
	//printf("%08.*d", "bitw");
	//ft_printf("%.8x\n", 45);
	//printf("%p", slt);
	ft_printf("%%%s%c%s%%\n", "bite", 'c', "whala");
	printf("%%%s%c%s%%", "bite", 'c', "whala");
	ft_printf("%.9d", 9781);
	printf("\n%.9d", 9781);*/
	/*size = printf("%8.9s\n", "YO L'EKIP");
	i = ft_printf("%8.9s\n", "YO L'EKIP");
	printf("\n\n%d - FAKE -\n", i);
	printf("\n%d - REAL -", size);*/
//}