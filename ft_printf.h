/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:48:24 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/24 01:57:46 by mbrignol         ###   ########.fr       */
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
}				t_flag;

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int ft_printf(const char *s, ...);

int check_letter(char c);
int get_flag_value(char *s, int *i);
int get_flag(char c);
int	check_arg(char *s, t_flag *info, va_list va);

void initialize_struct(t_flag *init);

int 	get_arg_type(va_list va, t_flag *info);
int		get_string_arg(va_list va, t_flag *info);
int		get_char_arg(va_list va, t_flag *info);
int		get_int_arg(va_list va, t_flag *info);

int 	get_len_of_args(t_flag *info);
int		manage_str(t_flag *info);

int		manage_no_flag(t_flag *info);
int		manage_no_flag_next(t_flag *info);
int		manage_hypen(t_flag *info);
int		manage_hypen_next(t_flag *info);
int		manage_hypen_next_string(t_flag *info);
int		manage_zero(t_flag *info);
int		manage_point(t_flag *info);

#endif
