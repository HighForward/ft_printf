/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_hypen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:04:07 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 19:09:01 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_hypen_next(t_flag *info)
{
	int size;
	int i;

	i = 0;
	size = info->flag_value_2 - ft_strlen(info->str);
	while (i < size)
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(info->str);
	i = info->flag_value_2;
	while (i < info->flag_value)
	{
		ft_putchar(' ');
		i++;
	}
	return (1);
}

int		manage_hypen_next_string(t_flag *info)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (i < info->flag_value_2 && i < ft_strlen(info->str))
	{
		ft_putchar(info->str[i]);
		i++;
	}
	i = info->flag_value - i;
	while (size < i)
	{
		ft_putchar(' ');
		size++;
	}
	return (1);
}

int		manage_hypen(t_flag *info)
{
	int size;
	int len;

	if (info->flag_2 == '.' && info->letter != 's')
		return (manage_hypen_next(info));
	if (info->flag_2 == '.' && info->letter == 's')
		return (manage_hypen_next_string(info));
	size = ft_strlen(info->str);
	ft_putstr(info->str);
	len = info->flag_value - size;
	while (len > 0)
	{
		ft_putchar(' ');
		len--;
	}
	return (1);
}