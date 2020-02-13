/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:28:12 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:28:35 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

long long	ft_convert_arg(t_conv *conv, long long d, va_list ap)
{
	if (conv->conversion == 'd' || conv->conversion == 'i' ||
			conv->conversion == 'x' || conv->conversion == 'X' ||
			conv->conversion == 'c')
		d = va_arg(ap, int);
	else if (conv->conversion == 'p')
	{
		if (!(d = (unsigned long long)va_arg(ap, void*)))
			conv->null_ptr = 1;
	}
	else if (conv->conversion == 'u')
		d = va_arg(ap, unsigned int);
	return (d);
}
