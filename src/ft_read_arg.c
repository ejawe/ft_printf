/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:23:15 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 20:23:54 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_read_arg(char *buff, va_list ap, t_conv *conv)
{
	int ret;

	ret = 0;
	if (conv->conversion == 'd' || conv->conversion == 'i' ||
			conv->conversion == 'x' || conv->conversion == 'X' ||
			conv->conversion == 'c' || conv->conversion == 'u' ||
			conv->conversion == 'p' || conv->conversion == '%')
		ret = ft_string_d(ap, conv, buff);
	else if (conv->conversion == 's')
		ret = ft_string_s(ap, conv, buff);
	return (ret);
}
