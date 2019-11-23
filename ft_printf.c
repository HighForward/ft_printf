/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:15 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/23 21:50:14 by mbrignol         ###   ########.fr       */
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
	initialize_struct(&info);
	if (!(check_arg((char*)s, &info)))
		return (0);
	get_arg_type(va, &info);

	manage_str(&info);
	va_end(va);
	return (0);
}

int main(void)
{
	/*ft_printf("%1.18d", 789);
	printf("\n%1.18d<- REAL\n", 789);*/
	/*ft_printf("%18.1d", 789);
	printf("\n%18.1d", 789);*/
	ft_printf("%10.15dyey", 789);
	printf("<- FAKE\n%10.15d<- REAL", 789);


	//ft_printf("%0.8d", 789);
}