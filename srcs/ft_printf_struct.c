/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:01:02 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/03 00:57:04 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_str_obsolute(t_flag *info, int *count, int *display)
{
	int		i;
	int		size;
	char	*dest;

	dest = NULL;
	size = 0;
	i = 0;
	if (info->str[i] == '-')
	{
		(*count)++;
		(*display)++;
		i++;
		while (info->str[size + i])
			size++;
		dest = ft_strnew(size);
		while (size)
		{
			dest[size - 1] = info->str[size];
			size--;
		}
	}
	free(info->str);
	info->str = dest;
}

void	putstr_count_size(char *s, int *display, int size)
{
	int i;

	i = 0;
	while (s[i] && i < size)
	{
		ft_putchar(s[i]);
		i++;
		(*display)++;
	}
}

void	put_space(int i, int *display)
{
	while (i-- > 0)
	{
		ft_putchar(' ');
		(*display)++;
	}
}

void	put_zero(int i, int *display)
{
	while (i-- > 0)
	{
		ft_putchar('0');
		(*display)++;
	}
}

void	putstr_count(char *s, int *display)
{
	int len;

	len = 0;
	ft_putstr(s);
	len = ft_strlen(s);
	(*display) += len;
}
