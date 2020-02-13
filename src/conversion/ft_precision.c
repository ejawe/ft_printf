/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:55:16 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:34:49 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_printf_space_precision(t_conv *conv, long long d, va_list ap)
{
	int	j;

	j = 0;
	d = va_arg(ap, int);
	if (d < 0 && (conv->conversion == 'd' || conv->conversion == 'i'))
		conv->neg = 1;
	conv->width = ft_nb_string_width(conv, d);
	j = 0;
	if (conv->field_width_nb >= conv->precision_nb)
	{
		if (conv->precision_nb >= conv->width)
			j = conv->field_width_nb - conv->precision_nb - conv->neg;
		if (conv->precision_nb < conv->width)
			j = conv->field_width_nb - conv->width;
	}
	if (conv->precision_nb == 0 && conv->field_width_nb >= 1 && d == 0)
		j++;
	while (j > 0 && conv->flag != '-')
	{
		write(1, " ", 1);
		j--;
	}
	return (d);
}

int		ft_precision(char *buff, t_conv *conv, va_list ap, long long d)
{
	int		i;
	int		j;
	char	*stock_precision;

	i = 1;
	j = 0;
	if (buff[i] == '*')
		conv->precision_nb = va_arg(ap, int);
	if (ft_isdigit(buff[i]) == 1)
	{
		j = ft_until_no_digit(&buff[i], i);
		stock_precision = ft_substr(&buff[i], 0, j);
		conv->precision_nb = ft_my_atoi(stock_precision);
		free(stock_precision);
		stock_precision = NULL;
	}
	if (conv->precision_nb < 0)
	{
		conv->precision = 0;
		return (0);
	}
	d = ft_printf_space_precision(conv, d, ap);
	ft_print_char_zero_precision(conv, d);
	return (d);
}

int		ft_get_precision(t_conv *conv, char *buff, long long d,
		va_list ap)
{
	int i;

	i = 0;
	conv->dot = 1;
	if (conv->conversion != '%' && (buff[i + 1] == '*' ||
				ft_isdigit(buff[i + 1])))
	{
		conv->precision = 1;
		d = ft_precision(&buff[i], conv, ap, d);
	}
	return (d);
}
