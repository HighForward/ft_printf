/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 06:47:55 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/21 21:06:37 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_value_flag_p(char *str, int flag)
{
	int		i;
	int		size;
	char	*template;
	char	*dest;

	i = 0;
	size = 0;
	template = "0x";
	if (!(dest = malloc(sizeof(char) * 8 + ft_strlen(template) + 1)))
		return (NULL);
	dest = ft_strncat(dest, template, ft_strlen(template));
	i = ft_strlen(template);
	while ((ft_strlen(str) + size) < 16 && flag == 1)
	{
		dest[i] = 'f';
		i++;
		size++;
	}
	size = 0;
	dest = ft_strncat(dest, str, ft_strlen(str));
	free(str);
	return (dest);
}

char	*get_hexa_negative(char *str, t_flag *info)
{
	int		size;
	int		x;
	char	*dest;

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

int		ft_abs(long int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*pointer_vide(void)
{
	char	*template;
	char	*str;
	int		i;

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

char	*ft_itoa_base(long int value, long int base, t_flag *info)
{
	char		*str;
	char		*tab;
	t_hexa		hexa;

	if (value == 0 && info->letter == 'p')
		return (pointer_vide());
	hexa.size = 1;
	tab = info->letter == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	hexa.flag = value < 0 ? 1 : 0;
	hexa.a = (value < 0) ? -(value + 1) : value;
	hexa.tmp = hexa.a;
	while (hexa.tmp /= base)
		hexa.size++;
	str = (char *)malloc(sizeof(char) * hexa.size + 1);
	str[hexa.size] = '\0';
	while (hexa.size > 0)
	{
		str[hexa.size - 1] = tab[(hexa.flag == 1) ?
				((15 - hexa.a) % 16) : (hexa.a % 16)];
		hexa.size--;
		hexa.a /= base;
	}
	if (info->letter == 'p')
		return (get_value_flag_p(str, hexa.flag));
	return (hexa.flag == 1 ? get_hexa_negative(str, info) : str);
}
