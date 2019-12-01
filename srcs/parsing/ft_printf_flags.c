/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:31 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/30 19:57:50 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/ft_printf.h"

int check_letter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int get_flag_value(char *s, int *i)
{
	int nb;

	nb = 0;
	while (s[*i] && s[*i] == '-')
		(*i)++;
	if ((s[*i] >= '0' && s[*i] <= '9'))
	{
		while ((s[*i] && (s[*i] >= '0' && s[*i] <= '9')))
		{
			nb = nb * 10 + (s[*i] - 48);
			(*i)++;
		}
		return (nb);
	}
	return (0);
}

int get_flag(char c)
{
	if (c == '.' || c == '-' || c == '0')
		return (1);
	return (0);
}

int	check_arg(char *s, t_flag *info, va_list va)
{
	int i;
	int star;
	star = 0;
	i = 0;
	if ((get_flag(s[i])) == 1)
	{
		info->flag = s[i++];
		while (s[i] == '-')
			i++;
	}
	if (s[i] == '*')
	{
		info->flag_value = va_arg(va, int);
		i++;
		star = 1;
	}
	else
		info->flag_value = get_flag_value(s, &i);
	if ((get_flag(s[i])) != 0)
		info->flag_2 = s[i++];
	if (s[i] == '*')
	{
		info->flag_value_2 = va_arg(va, int);
		i++;
	}
	else
		info->flag_value_2 = get_flag_value(s, &i);
	if ((check_letter(s[i])) != 0)
		info->letter = s[i++];
	if (star == 1 && info->flag != '.' && info->letter != '%' && info->flag_value < 0)
	{
		info->flag_value = -info->flag_value;
		info->flag = '-';
	}
	return (i);
}