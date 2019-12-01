/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:07:29 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/30 18:08:38 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_itoamalloc(unsigned int nb)
{
	int xd;

	xd = 0;
	xd = (nb <= 0 ? 1 : 0);
	while (nb != 0)
	{
		nb = nb / 10;
		xd++;
	}
	return (xd);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	int				len;
	int				less;
	unsigned int	nb;

	less = (n < 0 ? 1 : 0);
	len = ft_itoamalloc(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	nb = (n < 0 ? -n : n);
	while (len >= 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	if (less == 1)
		str[0] = '-';
	return (str);
}
