/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:37:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/01 01:12:19 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		manage_str(t_flag *info)
{
	if (info->letter == 'd' || info->letter == 'i' || info->letter == 'u' || info->letter == 'X' || info->letter == 'x')
		return (manage_i_d(info));
	else if (info->letter == 'c')
		return (manage_c(info));
	else if (info->letter == 's')
		return (manage_s(info));
	else if (info->letter == '%')
		return (manage_percent(info));
	else if (info->letter == 'p')
		return (manage_p(info));
	else
		ft_putstr(info->str);
	return (1);
}