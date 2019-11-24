/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/24 07:21:55 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list va;
	t_flag info;
	int size;
	int i;

	va_start(va, s);
	i = 0;
	initialize_struct(&info);
	while (s[i])
	{
		if ((size = check_arg((char *)&s[i], &info, va)) > 0)
		{
			get_arg_type(va, &info);
			manage_str(&info);
			i += size;
			i++;
			initialize_struct(&info);
		}
		else if (s[i] != '\0' && s[i] != '%')
			ft_putchar(s[i++]);
	}
	va_end(va);
	return (0);
}

int main(void)
{
	//ft_printf("%8s\n%15s\n", "1998", "yo l'ekipe");
	/*printf("%*.*d\n", 8, 5, 1998);
	ft_printf("%*.*d\n", 8, 5, 1998);
	printf("%-*.5d\n", 12, 1998);
	ft_printf("%-*.5d\n", 12, 1998);*/
	/*ft_printf("%-12.5s\n", "1998");*/
	//printf("\n%-20.d<REAL1", 987987987);
	//ft_printf("\n%-20.d<FAKE1", 987987987);
	//printf("\n%-15.18d<REAL2", 987987987);
	//ft_printf("\n%-15.18d<FAKE2", 987987987);
	//printf("\n%-*.d", 30, 987987987);
	//ft_printf("\n%-*.d<FAKE", 5, 987987987);
	/*printf("\n%-*.d<REAL", 5, 987987987);
	ft_printf("\n%-*.d<FAKE", 5, 987987987);*/
	//printf("bite%*.dcbite%s%d%c%c%%\n", 80, 1000, "bite de ", 10, 'c', 'm');
	//ft_printf("bite%*.dcbite%s%d%c%c%%\n", 80, 1000, "bite de ", 10, 'c', 'm');
	//ft_printf("%08.*d\n", "bitw");
	//printf("%08.*d", "bitw");
	//ft_printf("%.8x\n", 45);
	//printf("%p", slt);
	/*ft_printf("%%%s%c%s%%\n", "bite", 'c', "whala");
	printf("%%%s%c%s%%", "bite", 'c', "whala");*/
	/*ft_printf("%.9d", 9781);
	printf("\n%.9d", 9781);*/
}