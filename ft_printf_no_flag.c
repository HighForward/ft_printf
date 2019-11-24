/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:00:41 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/24 03:03:34 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_no_flag_next(t_flag *info)
{
	int i;
	int size;
	//printf("%c", info->flag);
	//printf("%c", info->flag_2);
	//printf("%d", info->flag_value);
	//printf("%c", info->flag_value_2);
	i = 0;
	if (info->flag_value_2 >= (int)ft_strlen(info->str))
	{
		size = info->flag_value_2 - ft_strlen(info->str);
		while (i++ < info->flag_value - info->flag_value_2)
			ft_putchar(' ');
		i = 0;
		while (i++ < size)
			ft_putchar('0');
	}
	else
	{
		size = info->flag_value - ft_strlen(info->str);
		while (size-- > 0)
			ft_putchar(' ');
	}
	ft_putstr(info->str);
	return (1);
}

int		manage_no_flag(t_flag *info)
{
	int i;
	int size;

	if (info->flag_2 == '.' && info->letter != 's')
		return (manage_no_flag_next(info));
	//if (info->flag_2 == '.' && info->letter == 's')
	size = info->flag_value - ft_strlen(info->str);
	i = 0;
	while (i < size && size > 0)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(info->str);
	return (1);
}