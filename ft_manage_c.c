/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:10:48 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 14:10:38 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		manage_c_tiret(t_flag *info)
{
	int i;

	ft_putchar(info->str[0]);
	i = info->flag_value > 1 ? info->flag_value - 1 : 0;
	put_space(i);

	return (info->flag_value > 1 ? info->flag_value : 1);
}

int		manage_c_blank(t_flag *info)
{
	int i;

	i = info->flag_value > 1 ? info->flag_value - 1 : 0;
	put_space(i);
	ft_putchar(info->str[0]);

	return (info->flag_value > 1 ? info->flag_value : 1);
}

int		manage_c(t_flag *info)
{
	if (info->flag == '-')
		return (manage_c_tiret(info));
	else if (info->flag == 0)
		return (manage_c_blank(info));
	else
		ft_putchar(info->str[0]);
	return (1);
}