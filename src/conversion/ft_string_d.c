/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:06:48 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:47:15 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_print_neg_int(t_conv *conv, long long d)
{
	if (conv->neg != 2 && d < 0)
	{
		write(1, "-", 1);
		conv->neg = 2;
	}
	if (conv->neg == 2 && d < 0)
		d *= -1;
	return (d);
}

void	ft_print_arg(t_conv *conv, long long d)
{
	if (conv->conversion == 'p')
		write(1, "0x", 2);
	if (d == 0 && conv->precision_nb == 0 && conv->dot == 1 &&
			conv->conversion != '%')
		return ;
	if (conv->conversion == 'd' || conv->conversion == 'i')
	{
		d = ft_print_neg_int(conv, d);
		ft_my_putnbr_fd(d, 1);
	}
	else if (conv->conversion == 'u')
		ft_my_putnbr_base((unsigned int)d, "0123456789");
	else if (conv->conversion == 'x')
		ft_my_putnbr_base((unsigned int)d, "0123456789abcdef");
	else if (conv->conversion == 'X')
		ft_my_putnbr_base((unsigned int)d, "0123456789ABCDEF");
	else if (conv->conversion == 'c')
		ft_putchar(d);
	else if (conv->conversion == 'p')
		ft_my_putnbr_base(d, "0123456789abcdef");
	else if (conv->conversion == '%')
		write(1, "%", 1);
}

int		ft_string_d(va_list ap, t_conv *conv, char *buff)
{
	int			i;
	long long	d;
	int			ret;
	char		*s;

	i = 1;
	d = 0;
	ret = 0;
	s = NULL;
	i = ft_flag(conv, buff, i);
	i = ft_stock_field_width(conv, buff, i, ap);
	if (buff[i] == '.')
		d = ft_get_precision(conv, &buff[i], d, ap);
	if (conv->precision == 0)
	{
		d = ft_convert_arg(conv, d, ap);
		ft_print_zero_n_space(conv, d);
	}
	ft_print_arg(conv, d);
	if ((conv->flag == '-' && conv->precision_nb < conv->field_width_nb)
			|| conv->field_width_nb < 0)
		ft_print_left_char_space(conv, d);
	ret = ft_ret(conv, d);
	return (ret);
}
