/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:32:12 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/24 07:17:43 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg_type(va_list va, t_flag *info)
{
	if (info->letter == 'c')
		return (get_char_arg(va, info));
	if (info->letter == 'd' || info->letter == 'i' || info->letter == 'x' || info->letter == 'X')
		return (get_int_arg(va, info));
	if (info->letter == 's')
		return (get_string_arg(va, info));
	if (info->letter == '%')
		return (get_percent_arg(va, info));
	return (0);
}

int		get_string_arg(va_list va, t_flag *info)
{
	info->str = va_arg(va, char*);
	return (1);
}

int		get_int_arg(va_list va, t_flag *info)
{
	char *nbr;
	int number;

	number = va_arg(va, int);
	if (info->letter == 'd' || info->letter == 'i')
		nbr = ft_itoa(number);
	else if (info->letter == 'X')
		nbr = ft_itoa_base(number, 16);
	else if (info->letter == 'x')
	{
		nbr = ft_itoa_base(number, 16);
		nbr = HexaToLower(nbr);
	}
	info->str = nbr;
	free(nbr);
	return (1);
}

int		get_char_arg(va_list va, t_flag *info)
{
	char *s;

	s = ft_strnew(1);
	s[0] = (char)va_arg(va, int);

	info->str = s;
	free(s);
	return (1);
}

int		get_percent_arg(va_list va, t_flag *info)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '%';

	info->str = s;
	free(s);
	return (1);
}