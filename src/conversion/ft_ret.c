/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:40:05 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:42:22 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_ret(t_conv *conv, long long d)
{
	int ret;

	ret = 0;
	conv->width = ft_nb_string_width(conv, d);
	if (conv->conversion == 'p' && conv->null_ptr == 1 && d == 0 &&
			conv->precision_nb == 0 && conv->dot == 1)
		conv->width = 2;
	ret = conv->width;
	if (conv->precision_nb >= conv->field_width_nb &&
			conv->precision_nb >= conv->width)
	{
		ret = conv->precision_nb;
		if (d < 0)
			ret++;
	}
	else if (conv->field_width_nb > 0 && conv->field_width_nb > conv->width)
		ret = conv->field_width_nb;
	else if ((d == 0 && conv->conversion != 'p' && conv->conversion != '%' &&
				conv->precision_nb >= 0 && (conv->dot == 1 &&
					conv->precision_nb == 0) && conv->field_width_nb != 1))
		ret = 0;
	return (ret);
}
