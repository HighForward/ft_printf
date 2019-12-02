/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/02 12:40:01 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list	va;
	t_flag	info;
	t_start start;

	va_start(va, s);
	initialize_start(&start, (char*)s);
	while (start.str[start.i])
	{
		if (start.str[start.i] == '%')
		{
			initialize_struct(&info, &start.i);
			start.count = check_arg(&start.str[start.i], &info, va);
			start.i += start.count;
			get_arg_type(va, &info);
			start.count = manage_str(&info);
			start.ret += start.count;
			//info.letter != 's' ? free(info.str) : 0;
		}
		else
		{
			ft_putchar(start.str[start.i++]);
			start.ret++;
		}
	}
	va_end(va);
	return (start.ret);
}
