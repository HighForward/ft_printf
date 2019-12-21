/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:48:24 by mbrignol          #+#    #+#             */
/*   Updated: 2019/12/21 22:41:56 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_start
{
	int			i;
	int			ret;
	int			count;
	char		*str;
}				t_start;

typedef struct	s_arg
{
	int			i;
	int			star;
}				t_arg;

typedef struct	s_flag
{
	char		flag;
	int			flag_value;
	char		flag_2;
	int			flag_value_2;
	char		letter;

	char		*str;
}				t_flag;

typedef struct	s_hexa
{
	long int	tmp;
	long int	a;
	int			size;
	int			flag;
}				t_hexa;

int				ft_printf(const char *s, ...);

int				check_letter(char c);
int				get_flag_value(char *s, int *i);
int				get_flag(char c);
int				check_arg(char *s, t_flag *info, va_list va);
int				check_arg_next(char *s, t_flag *info, va_list va, t_arg *arg);

void			get_str_obsolute(t_flag *info, int *count, int *display);
void			initialize_struct(t_flag *init, int *i);
void			initialize_start(t_start *start, char *s);
void			put_space(int i, int *display);
void			put_zero(int i, int *display);
void			putstr_count(char *s, int *display);

void			putstr_count_size(char *s, int *display, int size);

int				get_arg_type(va_list va, t_flag *info);
int				get_string_arg(va_list va, t_flag *info);
int				get_char_arg(va_list va, t_flag *info);
int				get_int_arg(va_list va, t_flag *info);
int				get_percent_arg(t_flag *info);

int				manage_str(t_flag *info, t_start *start);

int				manage_s(t_flag *info);
int				manage_s_blank(t_flag *info);
int				manage_s_blank_help(t_flag *info, int display, int i);
int				manage_s_prvt_1(t_flag *info, int i, int display);
int				manage_s_prvt_2(t_flag *info, int i, int display);
int				manage_s_prvt_3(t_flag *info, int i, int display);
int				manage_s_prvt_4(t_flag *info, int display);
int				manage_s_tiret(t_flag *info);
int				manage_tiret_point_help(t_flag *info, int display, int i);
int				manage_s_point(t_flag *info);

int				manage_c(t_flag *info);

int				manage_i_d(t_flag *info);

int				manage_i_d_tiret(t_flag *info);
int				manage_i_d_tiret_next(t_flag *info, int i, int count,
		int display);
int				prvt_tiret_1(t_flag *info, int i, int display);
int				prvt_tiret_2(t_flag *info, int i, int count, int display);
int				prvt_tiret_3(t_flag *info, int i, int count, int display);
int				prvt_tiret_4(t_flag *info, int i, int count, int display);
int				id_tiret_help(t_flag *info, int display);
int				id_tiret_help_2(t_flag *info, int display);

int				manage_i_d_blank(t_flag *info);
int				prvt_blank_1(t_flag *info, int i, int count, int display);
int				prvt_blank_2(t_flag *info, int i, int count, int display);
int				prvt_blank_3(t_flag *info, int i, int count, int display);

int				manage_i_d_zero(t_flag *info);
int				get_zero_zero(t_flag *info);
int				prvt_zero_point_1(t_flag *info, int i, int count, int display);
int				prvt_zero_point_2(t_flag *info, int i, int count, int display);
int				prvt_zero_point_3(t_flag *info, int i, int count, int display);

int				manage_percent(t_flag *info);
int				manage_percent_tiret(t_flag *info);
int				manage_percent_zero(t_flag *info);

int				manage_p(t_flag *info);
int				manage_p_tiret(t_flag *info);

int				ft_abs(long int nb);
char			*ft_itoa_base(long int value, long int base, t_flag *info);
char			*ft_itoa_unsigned(unsigned int n);
char			*get_hexa_negative(char *str, t_flag *info);
char			*get_value_flag_p(char *str, int flag);
char			*pointer_vide(void);

int				ft_strlen(const char *str);
void			ft_putchar(char c);
char			*ft_strnew(int size);
void			ft_putstr(char *str);
char			*ft_itoa(int n);
char			*ft_strncat(char *dest, char *src, unsigned int nb);

#endif
