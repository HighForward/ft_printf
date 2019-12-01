/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:34:51 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 19:44:29 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		prvt_zero_point_1(t_flag *info, int i, int count, int display)
{
	if (count == 1)
		ft_putchar('-');
	i = info->flag_value_2 - ft_strlen(info->str);
	put_zero(i, &display);
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	return (display);
}

int		prvt_zero_point_2(t_flag *info, int i, int count, int display)
{
	i = info->flag_value - ((ft_strlen(info->str) >= info->flag_value_2) ? ft_strlen(info->str) : info->flag_value_2);
	put_space(i - count, &display);
	if (count == 1)
		ft_putchar('-');
	i = info->flag_value_2 - ft_strlen(info->str);
	put_zero(i, &display);
	info->str[0] == '0' && info->flag_value_2 == 0 ? put_space(1, &display) : putstr_count(info->str, &display);
	return (display);
}

int		prvt_zero_point_3(t_flag *info, int i, int count, int display)
{
	if (count == 1)
		ft_putchar('-');
	i = info->flag_value - ft_strlen(info->str) - count;
	put_zero((i + (info->flag == '.' && count == 1 ? 1 : 0)), &display);
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	return (display);
}