/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:04:29 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/03 22:21:31 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		manage_percent_zero(t_flag *info)
{
	int i;
	int display;

	i = 0;
	display = 0;
	if (info->flag_value >= 0)
	{
		i = info->flag_value;
		put_zero(i - 1, &display);
		putstr_count(info->str, &display);
	}
	else
	{
		i = info->flag_value;
		putstr_count(info->str, &display);
		put_zero(i - 1, &display);
	}
	return (display);
}

int		manage_percent_tiret(t_flag *info)
{
	int i;
	int display;

	i = 0;
	display = 0;
	i = info->flag_value < 0 ? -info->flag_value : info->flag_value;
	putstr_count(info->str, &display);
	put_space(i - 1, &display);
	return (display);
}

int		manage_percent_blank(t_flag *info)
{
	int i;
	int display;

	i = 0;
	display = 0;
	i = info->flag_value;
	put_space(i - 1, &display);
	putstr_count(info->str, &display);
	return (display);
}

int		manage_percent(t_flag *info)
{
	int display;

	display = 0;
	if (info->flag == '.')
	{
		putstr_count(info->str, &display);
		return (display);
	}
	else if (info->flag == '-' || info->flag_value < 0)
		return (manage_percent_tiret(info));
	else if (info->flag == '0')
		return (manage_percent_zero(info));
	else if (info->flag == 0)
		return (manage_percent_blank(info));
	return (0);
}
