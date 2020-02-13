/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:43:46 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/11 10:40:53 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct				s_spe_conv
{
	int			flag;
	int			field_width;
	int			field_width_nb;
	int			dot;
	int			precision;
	int			precision_nb;
	int			string_to_free;
	int			neg;
	int			ret;
	int			null_ptr;
	int			width;
	long long	conv_nb;
	int			conversion;
}							t_conv;

int							ft_printf(const char *format, ...);
int							ft_string_d(va_list ap, t_conv *conv, char *buff);
int							ft_string_s(va_list ap, t_conv *conv, char *buff);
void						ft_field_with_s(char *buff, t_conv *conv, int i);
void						ft_get_field_width_s(t_conv *conv, va_list ap);
char						*ft_get_precision_s(char *s, t_conv *conv,
							va_list ap, char *buff);
char						*ft_print_zero_n_space_s(t_conv *conv,
							va_list ap,
							char *s);
void						ft_print_left_char_space_s(t_conv *conv, char *s);
int							ft_ret_s(t_conv *conv, char *s);
int							ft_flag(t_conv *conv, char *buff, int i);
int							ft_stock_field_width(t_conv *conv, char *buff,
							int i, va_list ap);
int							ft_until_no_digit(char *buff, int i);
int							ft_get_precision(t_conv *conv, char *buff,
							long long d, va_list ap);
int							ft_nb_string_width(t_conv *conv, long long d);
void						ft_print_char_zero_precision(t_conv *conv, int d);
long long					ft_convert_arg(t_conv *conv, long long d,
							va_list ap);
void						ft_print_left_char_space(t_conv *conv, long long d);
void						ft_print_zero_n_space(t_conv *conv, long long d);
int							ft_ret(t_conv *conv, long long d);
size_t						ft_strlen(const char *s);
int							ft_isdigit(int c);
char						*ft_strdup(const char *s);
char						*ft_strcpy(char *dest, const char *src);
char						*ft_strncpy(char *dest, const char *src, size_t n);
size_t						ft_strlcpy(char *dest, const char *src,
							size_t dstsize);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *haystack,
							const char *needle);
char						*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int							ft_my_atoi(const char *nptr);
char						*ft_strnew(size_t size);
char						*ft_substr(char const *s, unsigned int start,
							size_t len);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
void						ft_putendl(char const *s);
void						ft_putnbr(int n);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_my_putnbr_fd(long long n, int fd);
void						ft_my_putnbr_base(long long nbr, char *base);
int							ft_my_count_base(long long nbr, char *base);
#endif
