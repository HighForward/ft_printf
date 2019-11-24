/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:00:38 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 22:49:23 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_zero(t_flag *info)
{
	int size;
	int i;
	if (info->flag_2 == '.')
		return (manage_no_flag_next(info));
	i = 0;
	size = ft_strlen(info->str);
	i = info->flag_value - size;
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
	ft_putstr(info->str);
	return (1);
}