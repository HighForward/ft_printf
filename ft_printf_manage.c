/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:37:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/24 05:42:19 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_str(t_flag *info)
{
	if (info->flag == '-')
		return (manage_hypen(info));
	else if (info->flag == '0')
		return (manage_zero(info));
	else if (info->flag == '.')
		return (manage_point(info));
	else if (info->flag == 0 && info->flag_value != 0)
		return (manage_no_flag(info));
	else
		ft_putstr(info->str);
	return (1);
}