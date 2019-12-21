/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:31 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/21 20:59:10 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_letter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		get_flag_value(char *s, int *i)
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

int		get_flag(char c)
{
	if (c == '.' || c == '-' || c == '0')
		return (1);
	return (0);
}

int		check_arg_next(char *s, t_flag *info, va_list va, t_arg *arg)
{
	if ((get_flag(s[arg->i])) != 0)
		info->flag_2 = s[arg->i++];
	if (s[arg->i] == '*')
	{
		info->flag_value_2 = va_arg(va, int);
		arg->i++;
	}
	else
		info->flag_value_2 = get_flag_value(s, &arg->i);
	if ((check_letter(s[arg->i])) != 0)
		info->letter = s[arg->i++];
	if (arg->star == 1 && info->flag != '.' &&
		info->letter != '%' && info->flag_value < 0)
	{
		info->flag_value = -info->flag_value;
		info->flag = '-';
	}
	return (arg->i);
}

int		check_arg(char *s, t_flag *info, va_list va)
{
	t_arg arg;

	arg.star = 0;
	arg.i = 0;
	if ((get_flag(s[arg.i])) == 1)
	{
		info->flag = s[arg.i++];
		while (s[arg.i] == '-')
			arg.i++;
	}
	if (s[arg.i] == '*')
	{
		info->flag_value = va_arg(va, int);
		arg.i++;
		arg.star = 1;
	}
	else
		info->flag_value = get_flag_value(s, &arg.i);
	return (check_arg_next(s, info, va, &arg));
}
