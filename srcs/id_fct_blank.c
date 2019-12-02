/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_fct_zero_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:53:22 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/02 16:53:16 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		prvt_blank_1(t_flag *info, int i, int count, int display)
{
	if (count == 1)
		write(1, "-", 1);
	i = info->flag_value_2 > ft_strlen(info->str) ?
			(info->flag_value_2 - ft_strlen(info->str)) : 0;
	put_zero(i, &display);
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	return (display);
}

int		prvt_blank_2(t_flag *info, int i, int count, int display)
{
	i = info->flag_value - ((ft_strlen(info->str) <= info->flag_value_2)
			? info->flag_value_2 : ft_strlen(info->str)) - count;
	put_space(i, &display);
	i = info->flag_value_2 - ft_strlen(info->str);
	if (count == 1)
		write(1, "-", 1);
	put_zero(i, &display);
	if (info->str[0] == '0' && info->flag_value_2 != 0)
	{
		put_zero(1, &display);
		return (display);
	}
	info->str[0] != '0' ?
		putstr_count(info->str, &display) : put_space(1, &display);
	return (display);
}

int		prvt_blank_3(t_flag *info, int i, int count, int display)
{
	i = info->flag_value > ft_strlen(info->str) ?
			info->flag_value - ft_strlen(info->str) : 0;
	put_space(i - count, &display);
	if (count == 1)
	{
		write(1, "-", 1);
	}
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	return (display);
}
