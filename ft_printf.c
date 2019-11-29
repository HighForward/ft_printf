/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/29 20:01:43 by mbrignol         ###   ########.fr       */
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
			/*if (info.letter == 'i' || info.letter == 'd' || info.letter == 'c' || info.letter == '%')
				free(info.str);*/
		}
		else
		{
			ft_putchar(s[i++]);
			uep++;
		}
	}
	va_end(va);
	return (uep);
}
/*printf("\n---< FLAGS >---\n");
printf("FLAG 1  > %c\n", info.flag);
printf("VALUE 1 > %d\n", info.flag_value);
printf("FLAG 2  > %c\n", info.flag_2);
printf("VALUE 2 > %d\n", info.flag_value_2);
printf("CONVERT > %c\n", info.letter);
printf("<--------------\n");*/