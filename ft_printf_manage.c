/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:37:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 16:31:04 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_str(t_flag *info)
{
	if (info->flag == '-')
		manage_hypen(info);
	else if (info->flag == '0')
		manage_zero(info);
	else if (info->flag == '.')
		manage_point(info);
	else if (info->flag == 0)
		ft_putstr(info->str);
	return (1);
}