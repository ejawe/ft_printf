/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:13:59 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 20:15:19 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_ret_s(t_conv *conv, char *s)
{
	int ret;
	int len;

	len = (int)ft_strlen(s);
	ret = len;
	if (conv->dot == 1 && conv->precision == 0 && conv->field_width_nb == 0)
		ret = 0;
	else if (conv->precision == 1 && conv->precision_nb <= len &&
			conv->field_width_nb <= conv->precision_nb)
		ret = conv->precision_nb;
	else if (conv->precision == 1 && conv->precision_nb <= len &&
			conv->field_width_nb > conv->precision_nb)
		ret = conv->field_width_nb;
	else if (conv->precision == 1 && conv->precision_nb > len &&
			conv->field_width_nb >= len)
		ret = conv->field_width_nb;
	else if (conv->precision == 1 && conv->precision_nb == 0 &&
			conv->field_width_nb > 0)
		ret = conv->field_width_nb;
	else if (conv->precision == 0 && conv->field_width_nb > len)
		ret = conv->field_width_nb;
	else if (conv->dot == 1 && conv->precision_nb == 0 &&
			conv->field_width_nb > 0)
		ret = conv->field_width_nb;
	return (ret);
}
