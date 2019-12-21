/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:37:01 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/21 18:50:01 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		manage_str(t_flag *info, t_start *start)
{
	int count;

	count = 0;
	if (info->letter == 'd' || info->letter == 'i')
		count = manage_i_d(info);
	else if (info->letter == 'x' || info->letter == 'X')
		count = manage_i_d(info);
	else if (info->letter == 'u')
		count = manage_i_d(info);
	else if (info->letter == 'c')
		count = manage_c(info);
	else if (info->letter == 's')
		count = manage_s(info);
	else if (info->letter == '%')
		count = manage_percent(info);
	else if (info->letter == 'p')
		count = manage_p(info);
	start->ret += count;
	return (0);
}
