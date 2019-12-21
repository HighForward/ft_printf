/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 01:32:05 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/03 22:21:31 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		manage_p_tiret(t_flag *info)
{
	int display;
	int i;

	display = 0;
	i = ft_strlen(info->str) < info->flag_value ?
			info->flag_value - ft_strlen(info->str) : 0;
	putstr_count(info->str, &display);
	put_space(i, &display);
	return (display);
}

int		manage_p(t_flag *info)
{
	int display;
	int i;

	display = 0;
	if (info->flag == '-')
		return (manage_p_tiret(info));
	i = ft_strlen(info->str) < info->flag_value ?
			info->flag_value - ft_strlen(info->str) : 0;
	put_space(i, &display);
	putstr_count(info->str, &display);
	return (display);
}
