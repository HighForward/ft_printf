/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fct_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:00:04 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/02 19:20:51 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		manage_s_prvt_1(t_flag *info, int i, int display)
{
	if (info->flag_value_2 > ft_strlen(info->str))
	{
		i = info->flag_value > ft_strlen(info->str) ?
			info->flag_value - ft_strlen(info->str) : 0;
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

int		manage_s_prvt_2(t_flag *info, int i, int display)
{
	if (info->flag_2 == 0 && info->flag_value > ft_strlen(info->str))
	{
		i = info->flag_value - ft_strlen(info->str);
		put_space(i, &display);
	}
	putstr_count(info->str, &display);
	return (display);
}

int		manage_s_prvt_3(t_flag *info, int i, int display)
{
	i = info->flag_value_2 > ft_strlen(info->str) ? info->flag_value
			- ft_strlen(info->str) : info->flag_value
				- info->flag_value_2;
	put_space(i, &display);
	i = info->flag_value_2 > ft_strlen(info->str) ?
		ft_strlen(info->str) : info->flag_value_2;
	putstr_count_size(info->str, &display, i);
	return (display);
}

int		manage_s_prvt_4(t_flag *info, int display)
{
	if (info->flag_value_2 == 0)
		put_space(info->flag_value, &display);
	else
		putstr_count(info->str, &display);
	return (display);
}
