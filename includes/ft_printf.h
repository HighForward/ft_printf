/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:48:24 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/28 14:12:00 by mbrignol         ###   ########.fr       */
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

void get_str_obsolute(t_flag *info);
void initialize_struct(t_flag *init);
void	put_space(int i);
void	put_zero(int i);

int 	get_arg_type(va_list va, t_flag *info);
int		get_string_arg(va_list va, t_flag *info);
int		get_char_arg(va_list va, t_flag *info);
int		get_int_arg(va_list va, t_flag *info);
int		get_percent_arg(t_flag *info);

int		manage_str(t_flag *info);

int		manage_s(t_flag *info);

int		manage_c(t_flag *info);
int		manage_c_tiret(t_flag *info);
int		manage_c_blank(t_flag *info);

int 	manage_i_d(t_flag *info);
int		manage_i_d_tiret(t_flag *info);
int		manage_i_d_blank(t_flag *info);
int		manage_i_d_zero(t_flag *info);

int		ft_abs(int nb);
char	*ft_itoa_base(int value, int base);
char	*HexaToLower(char *s);

#endif
