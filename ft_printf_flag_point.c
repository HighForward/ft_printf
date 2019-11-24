/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:29:40 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/24 06:34:32 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_point(t_flag *info)
{
	int i;
	int size;
	int j;
	size = ft_strlen(info->str);
	i = info->flag_value - size;
	j = 0;
	if (info->letter == 'd' || info->letter == 'x' || info->letter == 'X')
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