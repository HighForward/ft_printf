/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:32:12 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/21 16:13:01 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg_type(va_list va, t_flag *info)
{
	if (info->letter == 'c')
		return (get_char_arg(va, info));
	if (info->letter == 'd')
		return (get_int_arg(va, info));
	if (info->letter == 's')
		return (get_string_arg(va, info));
	return (0);
}

int	get_string_arg(va_list va, t_flag *info)
{
	info->str = va_arg(va, char*);
	return (1);
}

int	get_int_arg(va_list va, t_flag *info)
{
	info->nb = va_arg(va, int);
	return (1);
}

int	get_char_arg(va_list va, t_flag *info)
{
	info->c = (char)va_arg(va, int);
	return (1);
}

