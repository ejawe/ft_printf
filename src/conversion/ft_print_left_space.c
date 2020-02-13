/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:36:05 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:56:19 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_print_left_char_space(t_conv *conv, long long d)
{
	int i;

	i = 0;
	conv->width = ft_nb_string_width(conv, d);
	if (conv->field_width_nb >= conv->precision_nb && conv->precision == 1 &&
			conv->precision_nb >= conv->width)
	{
		i = conv->field_width_nb - conv->precision_nb - conv->neg;
		if (conv->neg == 2)
			i++;
	}
	else
		i = conv->field_width_nb - conv->width;
	if (conv->precision_nb == 0 && conv->dot == 1 && d == 0)
		i++;
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
	}
}
