/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:01:02 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 13:52:28 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void initialize_struct(t_flag *init)
{
	init->flag = 0;
	init->flag_value = 0;
	init->flag_2 = 0;
	init->flag_value_2 = 0;
	init->letter = 0;

	init->str = NULL;
}