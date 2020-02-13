/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:12:53 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 16:14:59 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_print_char_zero_precision(t_conv *conv, int d)
{
	int i;

	i = 0;
	if (d < 0 && (conv->conversion == 'd' || conv->conversion == 'i'))
	{
		write(1, "-", 1);
		conv->neg = 2;
		i--;
	}
	while (conv->precision_nb - conv->width > i)
	{
		write(1, "0", 1);
		i++;
	}
}
