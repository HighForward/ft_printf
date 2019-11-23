/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 19:34:24 by mbrignol         ###   ########.fr       */
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
	if (!(check_arg((char*)s, &info)))
		return (0);
	get_arg_type(va, &info);

	manage_str(&info);
	va_end(va);
	return (0);
}

int main(void)
{
	ft_printf("%89.5d", 789);
	printf("\n%-*.5d", 8,789);
}