/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:16:29 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/01 01:11:45 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int get_zero_zero(t_flag *info)
{
	int display;

	display = 0;
	putstr_count(info->str, &display);
	return (display);
}

int manage_i_d_tiret(t_flag *info)
{
	int i;
	int display;
	int count;

	i = 0;
	count = 0;
	display = 0;
	if (info->str[0] == '-')
	{
		get_str_obsolute(info, &count, &display);
		write(1, "-", 1);
	}
	if (info->flag_value == 0 && info->flag_value_2 == 0 && info->str[0] == '0')
	{
		/*if (info->flag_2 == 0)
		{
			ft_putstr(info->str);
			display += ft_strlen(info->str);
			return (display);
		}*/
		if (info->flag_2 == '.')
			return (0);
	}
	else if (info->flag_value == 0 && info->flag_value_2 == 0 && info->str[0] != '0')
	{
		ft_putstr(info->str);
		return (display += ft_strlen(info->str));
	}
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
		return (prvt_tiret_1(info, i, display));
	else if (info->flag_2 == '.' && info->flag_value_2 < info->flag_value && info->flag_value_2 >= 0)
		return (prvt_tiret_2(info, i, count, display));
	else if (info ->flag_value_2 < 0)
		return (prvt_tiret_3(info, i, count, display));
	else
		return (prvt_tiret_4(info, i, count, display));
}

int manage_i_d_blank(t_flag *info)
{
	int i;
	int count;
	int display;

	display = 0;
	i = 0;
	count = 0;
	if (info->str[0] == '-')
		get_str_obsolute(info, &count, &display);
	if (info->flag_value == 0 && info->flag_value_2 == 0 && info->flag_2 == '.' && info->str[0] == '0')
		return (display);
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
		return (prvt_blank_1(info, i, count, display));
	else if (info->flag_2 == '.' && info->flag_value_2 < info->flag_value && info->flag_value_2 >= 0)
		return (prvt_blank_2(info, i, count, display));
	else
		return (prvt_blank_3(info, i, count, display));
}

int manage_i_d_zero(t_flag *info)
{
	int i;
	int count;
	int display;


	count = 0;
	display = 0;
	i = 0;
	if (info->flag_value == 0 && info->flag == '0' && info->flag_2 == 0 && info->str[0] == '0')
		return (get_zero_zero(info));
	if (info->str[0] == '-')
		get_str_obsolute(info, &count, &display);
	if (info->flag_value == 0 && info->flag_value_2 == 0 && info->str[0] == '0')
		return (0);
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
		return (prvt_zero_point_1(info, i, count, display));
	else if (info->flag_2 == '.' && info->flag_value_2 <= info->flag_value && info->flag_value_2 >= 0)
		return (prvt_zero_point_2(info, i, count, display));
	else
		return (prvt_zero_point_3(info, i, count, display));
}

int manage_i_d(t_flag *info)
{
	if (info->flag == '-')
		return (manage_i_d_tiret(info));
	else if (info->flag == 0)
		return (manage_i_d_blank(info));
	else if ((info->flag == '0' || info->flag == '.'))
		return (manage_i_d_zero(info));
	else
		ft_putstr(info->str);
	return (0);
}