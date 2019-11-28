/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:27:19 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 16:28:36 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		manage_s_blank(t_flag *info)
{
	int i;

	//i = info->flag_value > ft_strlen(info->str) ? info->flag_value - ft_strlen(info->str)
	return (0);
}

int		manage_s(t_flag *info)
{
	if (info->flag == 0)
		return (manage_s_blank(info));
	printf("bite");
	return (0);
}