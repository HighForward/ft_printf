/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:32:12 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/21 21:44:39 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_arg_type(va_list va, t_flag *info)
{
	if (info->letter == 'c')
		return (get_char_arg(va, info));
	if (info->letter == 'd' || info->letter == 'i' || info->letter == 'x'
		|| info->letter == 'X' || info->letter == 'u' || info->letter == 'p')
		return (get_int_arg(va, info));
	if (info->letter == 's')
		return (get_string_arg(va, info));
	if (info->letter == '%')
		return (get_percent_arg(info));
	return (0);
}

int		get_string_arg(va_list va, t_flag *info)
{
	info->str = va_arg(va, char*);
	if (info->str == NULL)
		info->str = "(null)";
	return (1);
}

int		get_int_arg(va_list va, t_flag *info)
{
	char *nbr;

	nbr = NULL;
	if (info->letter == 'd' || info->letter == 'i')
		nbr = ft_itoa(va_arg(va, int));
	else if (info->letter == 'u')
		nbr = ft_itoa_unsigned(va_arg(va, unsigned int));
	else if (info->letter == 'X' || info->letter == 'x')
	{
		nbr = ft_itoa_base((va_arg(va, unsigned int)), 16, info);
	}
	else if (info->letter == 'p')
	{
		nbr = ft_itoa_base(va_arg(va, long int), 16, info);
	}
	info->str = nbr;
	return (1);
}

int		get_char_arg(va_list va, t_flag *info)
{
	char *s;

	s = ft_strnew(1);
	s[0] = (char)va_arg(va, int);
	info->str = s;
	return (1);
}

int		get_percent_arg(t_flag *info)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '%';
	info->str = s;
	return (1);
}
