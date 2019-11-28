/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:16:29 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 17:59:10 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"


int manage_i_d_tiret(t_flag *info)
{
	int i;
	int display;
	int count;

	i = 0;
	count = 0;
	if (info->str[0] == '-')
	{
		get_str_obsolute(info);
		write(1, "-", 1);
		count++;
	}
	if (info->flag_value == 0 && info->flag_value_2 == 0 && info->str[0] == '0')
	{
		if (info->flag_2 == 0)
		{
			ft_putstr(info->str);
			return (ft_strlen(info->str) + count);
		}
		if (info->flag_2 == '.')
			return (0);
	}
	else if (info->flag_value == 0 && info->flag_value_2 == 0 && info->str[0] != '0')
	{
		ft_putstr(info->str);
		return (display = ft_strlen(info->str) + count);
	}
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
	{
		i = info->flag_value_2 - ft_strlen(info->str);
		put_zero(i);
		ft_putstr(info->str);
		i = info->flag_value - info->flag_value_2;
		display = info->flag_value_2 > ft_strlen(info->str) ? info->flag_value_2 + count : ft_strlen(info->str) + count;
	}
	else if (info->flag_2 == '.' && info->flag_value_2 < info->flag_value && info->flag_value_2 >= 0)
	{
		i = info->flag_value_2 - ((ft_strlen(info->str) >= info->flag_value_2) ? info->flag_value_2 : ft_strlen(info->str));
		put_zero(i);
		if (info->flag_value_2 == 0 && info->str[0] == '0')
			ft_putchar(' ');
		else
			info->str[0] != '0' ? ft_putstr(info->str) : ft_putchar('0');
		i = info->flag_value <= ft_strlen(info->str) ? 0 : info->flag_value - (info->flag_value_2 < ft_strlen(info->str) ? ft_strlen(info->str) : info->flag_value_2) - count;
		display = info->flag_value > ft_strlen(info->str) ? info->flag_value + count: ft_strlen(info->str);
	}
	else if (info ->flag_value_2 < 0)
	{
		ft_putstr(info->str);
		i = info->flag_value - (ft_strlen(info->str) >= info->flag_value ? info->flag_value : ft_strlen(info->str)) - count;
		display = i + ft_strlen(info->str) + count;
	}
	else
	{
		ft_putstr(info->str);
		i = info->flag_value - ft_strlen(info->str) - count;
		if (info->flag_value <= ft_strlen(info->str))
			display = ft_strlen(info->str) + count;
		else
			display = i + ft_strlen(info->str) + count;
	}
	while (i-- > 0)
		ft_putchar(' ');
	return (display);
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
	{
		get_str_obsolute(info);
		count++;
	}
	if (info->flag_value == 0 && info->flag_value_2 == 0 && info->flag_2 == '.' && info->str[0] == '0')
		return (display);
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
	{
		if (count == 1)
			write(1,"-", 1);
		i = info->flag_value_2 > ft_strlen(info->str) ? (info->flag_value_2 - ft_strlen(info->str)) : 0;
		while (i-- > 0)
			ft_putchar('0');
		ft_putstr(info->str);
		return (display = (info->flag_value_2 > ft_strlen(info->str) ? info->flag_value_2 : ft_strlen(info->str)) + count);
	}
	else if (info->flag_2 == '.' && info->flag_value_2 < info->flag_value && info->flag_value_2 > 0)
	{
		i = info->flag_value - ((ft_strlen(info->str) <= info->flag_value_2) ? info->flag_value_2 : ft_strlen(info->str)) - count;
		put_space(i);
		i = info->flag_value_2 - ft_strlen(info->str);
		if (count == 1)
			write(1, "-", 1);
		put_zero(i);
		info->str[0] != '0' ? ft_putstr(info->str) : ft_putchar(' ');
		display = info->flag_value > ft_strlen(info->str) ? info->flag_value : ft_strlen(info->str);
		return (display);
	}
	else
	{
		i = info->flag_value > ft_strlen(info->str) ? info->flag_value - ft_strlen(info->str) : 0;
		put_space(i - count);
		if (count == 1)
			write(1, "-", 1);
		ft_putstr(info->str);
		if (info->flag_value <= ft_strlen(info->str))
			return (ft_strlen(info->str) + count);
		else
			display = info->flag_value > ft_strlen(info->str) ? info->flag_value : ft_strlen(info->str);
		return (display);
	}
}

int manage_i_d_zero(t_flag *info)
{
	int i;
	int count;
	int display;

	count = 0;
	i = 0;
	if (info->str[0] == '-')
	{
		get_str_obsolute(info);
		count++;
	}
	if (info->flag_value == 0 && info->flag_value_2 == 0 && info->str[0] == '0')
		return (0);
	if (info->flag_2 == '.' && info->flag_value_2 >= info->flag_value)
	{
		if (count == 1)
			ft_putchar('-');
		i = info->flag_value_2 - ft_strlen(info->str);
		while (i-- > 0)
			ft_putchar('0');
		ft_putstr(info->str);
		return (count + (display = info->flag_value_2 > ft_strlen(info->str) ? info->flag_value_2 : ft_strlen(info->str)));
	}
	else if (info->flag_2 == '.' && info->flag_value_2 <= info->flag_value && info->flag_value_2 >= 0)
	{
		i = info->flag_value - ((ft_strlen(info->str) >= info->flag_value_2) ? ft_strlen(info->str) : info->flag_value_2);
		put_space(i - count);
		if (count == 1)
			ft_putchar('-');
		i = info->flag_value_2 - ft_strlen(info->str);
		put_zero(i);
		info->str[0] == '0' && info->flag_value_2 == 0 ? ft_putchar(' ') : ft_putstr(info->str);
		return (count + (display = info->flag_value > ft_strlen(info->str) ? info->flag_value - count : ft_strlen(info->str)));
	}
	else
	{
		if (count == 1)
			ft_putchar('-');
		i = info->flag_value - ft_strlen(info->str) - count;
		put_zero(i + (info->flag == '.' && count == 1 ? 1 : 0));
		ft_putstr(info->str);
		display = info->flag_value > ft_strlen(info->str) ? info->flag_value : (ft_strlen(info->str) + count);
		if (info->flag == '.' && info->flag_value > ft_strlen(info->str) && count == 1)
			display++;
	}
	return (display);
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