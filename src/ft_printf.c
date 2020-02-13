/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:19:44 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/11 10:45:15 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_len_instruc(const char *format)
{
	int i;

	i = 0;
	i++;
	while (format[i] != 'd' && format[i] != 'i' && format[i] != 'u' &&
			format[i] != 'x' && format[i] != 'X' && format[i] != 'c' &&
			format[i] != 's' && format[i] != 'p' && format[i] != '%')
		i++;
	i++;
	return (i);
}

int				ft_check_str(va_list ap, t_conv *conv, const char *format)
{
	int		ret;
	int		i;
	char	*buff;

	i = 0;
	ret = 0;
	buff = NULL;
	buff = ft_substr(format, 0, ft_len_instruc(format));
	while (buff[i])
		i++;
	conv->conversion = buff[i - 1];
	if (conv->conversion == 'd' || conv->conversion == 'i' ||
			conv->conversion == 'x' || conv->conversion == 'X' ||
			conv->conversion == 'c' || conv->conversion == 'u' ||
			conv->conversion == 'p' || conv->conversion == '%')
		ret = ft_string_d(ap, conv, buff);
	else if (conv->conversion == 's')
		ret = ft_string_s(ap, conv, buff);
	free(buff);
	return (ret);
}

static void		init_struct(t_conv *conv)
{
	conv->flag = 0;
	conv->field_width = 0;
	conv->field_width_nb = 0;
	conv->dot = 0;
	conv->precision = 0;
	conv->precision_nb = 0;
	conv->string_to_free = 0;
	conv->neg = 0;
	conv->ret = 0;
	conv->null_ptr = 0;
	conv->width = 0;
	conv->conv_nb = 0;
	conv->conversion = 0;
}

int				ft_string_printf(const char *format, va_list ap, t_conv *conv)
{
	int i;
	int ret;
	int len;

	i = 0;
	ret = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_struct(conv);
			len = ft_len_instruc(&format[i]);
			ret += (ft_check_str(ap, conv, &format[i]) - len);
			i = i + len;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	ret = ret + i;
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_conv	conv;
	int		ret;

	va_start(ap, format);
	ret = ft_string_printf(format, ap, &conv);
	va_end(ap);
	return (ret);
}
