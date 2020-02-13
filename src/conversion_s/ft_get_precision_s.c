/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:00:07 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 20:13:30 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_nul_str(char *s, t_conv *conv)
{
	s = ft_strdup("(null)");
	conv->string_to_free = 1;
	return (s);
}

char	*ft_print_precision_s(va_list ap, t_conv *conv, char *s)
{
	int i;

	i = conv->field_width_nb;
	if (!(s = va_arg(ap, char *)))
		s = ft_nul_str(s, conv);
	conv->width = ft_strlen(s);
	if (conv->precision_nb > conv->width && conv->flag != '-')
	{
		while (i - conv->width > 0)
		{
			write(1, " ", 1);
			i--;
		}
	}
	else if (conv->precision_nb <= conv->width && conv->flag != '-')
	{
		while (i - conv->precision_nb > 0)
		{
			write(1, " ", 1);
			i--;
		}
	}
	return (s);
}

void	ft_precision_nb(char *buff, va_list ap, t_conv *conv)
{
	int		i;
	char	*stock_precision;

	i = 0;
	stock_precision = NULL;
	if (buff[i] == '*')
	{
		conv->precision_nb = va_arg(ap, int);
		if (conv->precision_nb < 0)
			conv->precision = 0;
	}
	else if (ft_isdigit(buff[i]) == 1)
	{
		i = ft_until_no_digit(buff, i);
		stock_precision = ft_substr(buff, 0, i);
		conv->precision_nb = ft_my_atoi(stock_precision);
		free(stock_precision);
	}
	if (conv->precision_nb < 0)
	{
		conv->precision = 0;
		conv->dot = 0;
	}
}

char	*ft_precision_s(char *buff, t_conv *conv, va_list ap, char *s)
{
	int i;

	i = 0;
	conv->precision = 1;
	ft_precision_nb(&buff[i], ap, conv);
	if (conv->precision == 1)
		s = ft_print_precision_s(ap, conv, s);
	return (s);
}

char	*ft_get_precision_s(char *s, t_conv *conv, va_list ap, char *buff)
{
	int i;

	i = 1;
	conv->dot = 1;
	if (buff[i] == '*' || ft_isdigit(buff[i]))
		s = ft_precision_s(&buff[i], conv, ap, s);
	return (s);
}
