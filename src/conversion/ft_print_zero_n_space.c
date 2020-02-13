/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_n_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:48:11 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:48:40 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_print_char_space(t_conv *conv, long long d)
{
	int i;

	i = 0;
	conv->width = ft_nb_string_width(conv, d);
	if (conv->precision_nb == 0 && conv->dot == 1 && d == 0)
		i--;
	while (conv->field_width_nb - conv->width > i)
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_print_char_zero(t_conv *conv, long long d)
{
	int i;

	i = 0;
	if (d < 0 && (conv->conversion == 'd' || conv->conversion == 'i'))
	{
		write(1, "-", 1);
		conv->neg = 2;
	}
	conv->width = ft_nb_string_width(conv, d);
	while (conv->field_width_nb - conv->width > i)
	{
		write(1, "0", 1);
		i++;
	}
}

void	ft_print_zero_n_space(t_conv *conv, long long d)
{
	if (conv->flag == '0')
		ft_print_char_zero(conv, d);
	if (conv->flag == 0)
		ft_print_char_space(conv, d);
}
