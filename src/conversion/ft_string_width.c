/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:15:31 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:50:47 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_nb_string_width_other(t_conv *conv, long long d)
{
	int i;

	i = 0;
	if (conv->conversion == 'p')
	{
		i = ft_my_count_base(d, "0123456789abcdef");
		i += 2;
		return (i);
	}
	else if (conv->conversion == 'u')
	{
		i = ft_my_count_base((unsigned int)d, "0123456789");
		return (i);
	}
	else if (conv->conversion == 'c' || conv->conversion == '%')
	{
		i = 1;
		return (i);
	}
	return (i);
}

int		ft_nb_string_width_hexa(t_conv *conv, long long d)
{
	int i;

	i = 0;
	if (conv->conversion == 'x')
	{
		i = ft_my_count_base(d, "0123456789abcdef");
		if (d < 0)
			i = ft_my_count_base((unsigned int)d, "0123456789abcdef");
		return (i);
	}
	else if (conv->conversion == 'X')
	{
		i = ft_my_count_base(d, "0123456789ABCDEF");
		if (d < 0)
			i = ft_my_count_base((unsigned int)d, "0123456789ABCDEF");
		return (i);
	}
	return (i);
}

int		ft_nb_string_width(t_conv *conv, long long d)
{
	int i;

	i = 0;
	if (conv->conversion == 'x' || conv->conversion == 'X')
		i = ft_nb_string_width_hexa(conv, d);
	else if (conv->conversion == 'p' || conv->conversion == 'u' ||
			conv->conversion == 'c' || conv->conversion == '%')
		i = ft_nb_string_width_other(conv, d);
	else if (conv->conversion == 'd' || conv->conversion == 'i')
	{
		if (d == 0)
			return (1);
		if (d < 0)
		{
			i++;
			d *= -1;
		}
		while (d > 0)
		{
			d = d / 10;
			i++;
		}
		return (i);
	}
	return (i);
}
