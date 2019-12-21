/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 21:48:49 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/21 22:44:08 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialize_start(t_start *start, char *s)
{
	start->count = 0;
	start->i = 0;
	start->ret = 0;
	start->str = s;
}

void	initialize_struct(t_flag *init, int *i)
{
	(*i)++;
	init->flag = 0;
	init->flag_value = 0;
	init->flag_2 = 0;
	init->flag_value_2 = 0;
	init->letter = 0;
	init->str = NULL;
}

int		id_tiret_help(t_flag *info, int display)
{
	ft_putstr(info->str);
	display += ft_strlen(info->str);
	return (display);
}

int		id_tiret_help_2(t_flag *info, int display)
{
	ft_putstr(info->str);
	return (display += ft_strlen(info->str));
}

int		manage_tiret_point_help(t_flag *info, int display, int i)
{
	if (info->flag_value_2 < 0)
	{
		if (info->flag_value > ft_strlen(info->str))
		{
			i = info->flag_value - ft_strlen(info->str);
			putstr_count(info->str, &display);
			put_space(i, &display);
			return (display);
		}
		putstr_count(info->str, &display);
		return (display);
	}
	i = info->flag_value_2 < ft_strlen(info->str) ?
		info->flag_value_2 : ft_strlen(info->str);
	putstr_count_size(info->str, &display, i);
	i = info->flag_value - i;
	put_space(i, &display);
	return (display);
}
