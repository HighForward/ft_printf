/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:48:24 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/21 16:10:49 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

typedef struct	s_flag
{
	char	flag;
	int		flag_value;
	char	flag_2;
	int		flag_value_2;
	char	letter;

	char 	*str;
	int		nb;
	char	c;
}				t_flag;

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int check_letter(char c);
int get_flag_value(char *s, int *i);
int get_flag(char c);
int	check_arg(char *s, t_flag *info);

void initialize_struct(t_flag *init);

int 	get_arg_type(va_list va, t_flag *info);
int		get_string_arg(va_list va, t_flag *info);
int		get_char_arg(va_list va, t_flag *info);
int		get_int_arg(va_list va, t_flag *info);

#endif
