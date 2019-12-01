/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 06:47:55 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/01 03:03:51 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*get_value_flag_p(char *str, int flag)
{
	int i;
	int size;
	char *template;
	char *dest;

	i = 0;
	size = 0;
	if (flag == 1)
		template = "0x7ffe";
	else
		template = "0x10";
	if (!(dest = malloc(sizeof(char) * 8 + ft_strlen(template) + 1)))
		return (NULL);
	while (template[i])
	{
		dest[i] = template[i];
		i++;
	}
	while ((ft_strlen(str) + size) < 7)
	{
		dest[i] = '0';
		i++;
		size++;
	}
	size = 0;
	while (str[size])
	{
		dest[i] = str[size];
		i++;
		size++;
	}
	dest[i] = '\0';
	free(str);
	return (dest);
}

char	*get_hexa_negative(char *str, t_flag *info)
{
	int size;
	int x;
	char *dest;

	x = 0;
	size = 0;
	if (ft_strlen(str) == 8)
		return (str);
	if (!(dest = malloc(sizeof(char) * 9)))
		return (NULL);
	while (size < (8 - ft_strlen(str)))
	{
		dest[size] = info->letter == 'x' ? 'f' : 'F';
		size++;
	}
	while (str[x])
	{
		dest[size] = str[x];
		size++;
		x++;
	}
	free(str);
	dest[size] = '\0';

	return (dest);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*pointer_vide(t_flag *info)
{
	char *template;
	char *str;
	int i;

	template = "0x0";
	i = 0;
	if (!(str = malloc(sizeof(char) * ft_strlen(template) + 1)))
		return (NULL);
	while (template[i])
	{
		str[i] = template[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(int value, int base, t_flag *info)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;
	int 	a;

	if (value == 0 && info->letter == 'p')
	{
		return (pointer_vide(info));
	}
	size = 1;
	tab = info->letter == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	flag = value < 0 ? 1 : 0;
	a = (value < 0) ? -(value + 1) : value;
	tmp = a;
	while (tmp /= base)
		size++;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size)
	{
		str[size - 1] = tab[(flag == 1) ? (15 - a % 16) : (a % 16)];
		size--;
		a /= base;
	}
	if (info->letter == 'p')
		return (get_value_flag_p(str, flag));
	return (flag == 1 ? get_hexa_negative(str, info) : str);
}