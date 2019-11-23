/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:31 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 19:54:02 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int check_letter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int get_flag_value(char *s, int *i)
{
	int size;
	int nb;

	size = 0;
	nb = 0;
	if ((s[size] >= '0' && s[size] <= '9'))
	{
		while ((s[size] && (s[size] >= '0' && s[size] <= '9')))
		{
			nb = nb * 10 + (s[size] - 48);
			size++;
			(*i)++;
		}
		return (nb);
	}
	return (0);
}

int get_flag(char c)
{
	if (c == '.' || c == '-' || c == '*' || c == '0')
		return (1);
	return (0);
}

int	check_arg(char *s, t_flag *info)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if ((get_flag(s[i])) != 0)
			{
				info->flag = s[i];
				i++;
			}
			info->flag_value = get_flag_value(&s[i], &i);
			if ((get_flag(s[i])) != 0)
			{
				info->flag_2 = s[i];
				i++;
				info->flag_value_2 = get_flag_value(&s[i], &i);
			}
			if ((check_letter(s[i])) != 0)
				info->letter = s[i];
			else
				return (0);
		}
		i++;
	}
	return (1);
}