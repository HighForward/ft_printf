/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_fct_tiret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:10:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/02 21:53:53 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		manage_i_d_tiret_next(t_flag *info, int i, int count, int display)
{
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
		return (prvt_tiret_1(info, i, display));
	else if (info->flag_2 == '.' && info->flag_value_2 < info->flag_value
		&& info->flag_value_2 >= 0)
		return (prvt_tiret_2(info, i, count, display));
	else if (info->flag_value_2 < 0)
		return (prvt_tiret_3(info, i, count, display));
	else
		return (prvt_tiret_4(info, i, count, display));
}

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
	int temp;

	temp = 0;
	i = info->flag_value_2 - ((ft_strlen(info->str) >= info->flag_value_2) ?
			info->flag_value_2 : ft_strlen(info->str));
	put_zero(i, &display);
	if (info->flag_value_2 == 0 && info->str[0] == '0')
		put_space(1, &display);
	else
		info->str[0] != '0' ?
			putstr_count(info->str, &display) : put_zero(1, &display);
	if (info->flag_value_2 < ft_strlen(info->str))
		temp = ft_strlen(info->str);
	else
		temp = info->flag_value_2;
	i = info->flag_value <= ft_strlen(info->str) ?
			0 : info->flag_value - temp - count;
	put_space(i, &display);
	return (display);
}

int		prvt_tiret_3(t_flag *info, int i, int count, int display)
{
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	i = info->flag_value - (ft_strlen(info->str) >= info->flag_value ?
			info->flag_value : ft_strlen(info->str)) - count;
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
