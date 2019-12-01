/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_fct_tiret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:10:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 20:22:26 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"



int		prvt_tiret_1(t_flag *info, int i, int display)
{
	i = info->flag_value_2 - ft_strlen(info->str);
	put_zero(i, &display);
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	i = info->flag_value - info->flag_value_2;
	put_space(i, &display);
	return (display);
}

int		prvt_tiret_2(t_flag *info, int i, int count, int display)
{
	i = info->flag_value_2 - ((ft_strlen(info->str) >= info->flag_value_2) ? info->flag_value_2 : ft_strlen(info->str));
	put_zero(i, &display);
	if (info->flag_value_2 == 0 && info->str[0] == '0')
		put_space(1, &display);
	else
		info->str[0] != '0' ? putstr_count(info->str, &display) : put_zero(1, &display);
	i = info->flag_value <= ft_strlen(info->str) ? 0 : info->flag_value - (info->flag_value_2 < ft_strlen(info->str) ? ft_strlen(info->str) : info->flag_value_2) - count;
	put_space(i, &display);
	return (display);
}

int		prvt_tiret_3(t_flag *info, int i, int count, int display)
{
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	i = info->flag_value - (ft_strlen(info->str) >= info->flag_value ? info->flag_value : ft_strlen(info->str)) - count;
	put_space(i, &display);
	return (display);
}

int		prvt_tiret_4(t_flag *info, int i, int count, int display)
{
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	i = info->flag_value - ft_strlen(info->str) - count;
	put_space(i, &display);
	return (display);
}