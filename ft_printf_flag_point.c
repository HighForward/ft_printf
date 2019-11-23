/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:29:40 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 16:54:48 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int		manage_point(t_flag *info)
{
	int i;
	int size;
	int j;

	size = ft_strlen(info->str);
	i = info->flag_value - size;
	j = 0;
	if (info->letter == 'd')
	{
		while (i > 0)
		{
			ft_putchar('0');
			i--;
		}
		ft_putstr(info->str);
	}
	if (info->letter == 's')
	{
		while (j < info->flag_value && j < size)
			ft_putchar(info->str[j++]);
	}
	return (1);
}