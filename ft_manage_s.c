/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:27:19 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/29 21:25:04 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		manage_s_blank(t_flag *info)
{
	int i;
	int display;

	i = 0;
	display = 0;

	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
	{
		if (info->flag_value_2 > ft_strlen(info->str))
		{
			i = info->flag_value > ft_strlen(info->str) ? info->flag_value - ft_strlen(info->str) : 0;
			put_space(i, &display);
			putstr_count(info->str, &display);
		}
		else
		{
			i = info->flag_value_2;
			putstr_count_size(info->str, &display, i);
		}
		return (display);
	}
	else if (info->flag_2 == '.' && info->flag_value_2 < info->flag_value)
	{
		if (info->flag_value > ft_strlen(info->str))
		{
			i = info->flag_value_2 > ft_strlen(info->str) ? info->flag_value - ft_strlen(info->str) : info->flag_value - info->flag_value_2;
			put_space(i, &display);
			i = info->flag_value_2 > ft_strlen(info->str) ? ft_strlen(info->str) : info->flag_value_2;
			putstr_count_size(info->str, &display, i);
			return (display);
		}
		else if (info->flag_value < ft_strlen(info->str) && info->flag_value_2 <= 0)
		{
			if (info->flag_value_2 == 0)
				put_space(info->flag_value, &display);
			else
				putstr_count(info->str, &display);
			return (display);
		}
		else
		{
			i = info->flag_value - info->flag_value_2;
			put_space(i, &display);
			putstr_count_size(info->str, &display, info->flag_value_2);
			return (display);
		}
	}
	else
	{
		if (info->flag_2 == 0 && info->flag_value > ft_strlen(info->str))
		{
			i = info->flag_value - ft_strlen(info->str);
			put_space(i, &display);
		}
		putstr_count(info->str, &display);
		return (display);
	}
}

int		manage_s_tiret(t_flag *info)
{
	int i;
	int display;

	display = 0;

	if (info->flag_2 == '.')
	{
		i = info->flag_value_2 < ft_strlen(info->str) ? info->flag_value_2 : ft_strlen(info->str);
		putstr_count_size(info->str, &display, i);
		i = info->flag_value - i;
		put_space(i, &display);
		return (display);
	}
	else
	{
		i = info->flag_value > ft_strlen(info->str) ? info->flag_value - ft_strlen(info->str) : 0;
		putstr_count(info->str, &display);
		put_space(i, &display);
		return (display);
	}
}

int		manage_s_point(t_flag *info)
{
	int display;

	display = 0;
	if (info->flag_value < 0)
		putstr_count(info->str, &display);
	else
		putstr_count_size(info->str, &display, info->flag_value);
	return (display);
}

int		manage_s(t_flag *info)
{
	if (info->flag == 0)
		return (manage_s_blank(info));
	else if (info->flag == '-')
		return (manage_s_tiret(info));
	else if (info->flag == '.')
		return (manage_s_point(info));;
	return (0);
}