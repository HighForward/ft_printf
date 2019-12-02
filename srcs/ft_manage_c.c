/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:10:48 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/02 15:31:03 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		manage_c(t_flag *info)
{
	int display;
	int i;

	i = 0;
	display = 0;
	if (info->flag_value && info->flag != '-')
		put_space(info->flag_value - 1, &display);
	write(1, &info->str[0], 1);
	display++;
	if (info->flag_value && info->flag == '-')
		put_space(info->flag_value - 1, &display);
	return (display);
}
