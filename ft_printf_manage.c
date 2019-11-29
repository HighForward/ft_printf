/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:37:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/29 20:53:06 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		manage_str(t_flag *info)
{
	if (info->letter == 'd' || info->letter == 'i')
		return (manage_i_d(info));
	else if (info->letter == 'c')
		return (manage_c(info));
	else if (info->letter == 's')
		return (manage_s(info));
	/*else if (info->flag == 0 && info->flag_value != 0)
		return (manage_no_flag(info));*/
	else
		ft_putstr(info->str);
	return (1);
}