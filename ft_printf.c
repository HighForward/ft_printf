/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/21 16:36:53 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list va;
	t_flag info;
	int size;
	int i;

	va_start(va, s);
	i = 0;
	if (!(check_arg((char*)s, &info)))
		return (0);
	/*printf("%c", info.flag);
	printf("%d", info.flag_value);
	printf("%c", info.flag_2);
	printf("%d", info.flag_value_2);
	printf("%c", info.letter);
	printf("\n");*/
	get_arg_type(va, &info);
	//printf_result_of((char*)s, info);



	va_end(va);
	return (0);
}

int main(void)
{
	ft_printf("%s", "YO L'EKIPE");
	printf("\n%05.2%");
}