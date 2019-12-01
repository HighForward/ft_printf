/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 21:48:49 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/01 04:15:50 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void initialize_start(t_start *start, char *s)
{
	start->count = 0;
	start->i = 0;
	start->ret = 0;
	start->str = s;
}

void initialize_struct(t_flag *init, int *i)
{
	(*i)++;
	init->flag = 0;
	init->flag_value = 0;
	init->flag_2 = 0;
	init->flag_value_2 = 0;
	init->letter = 0;

	init->str = NULL;
}