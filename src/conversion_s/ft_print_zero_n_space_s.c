/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_n_space_s.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:16:15 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 20:18:08 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_width_space_to_print(t_conv *conv, int len)
{
	int i;

	i = 0;
	i = conv->field_width_nb - len;
	if (conv->precision == 0)
		i = conv->field_width_nb - len;
	else if (conv->field_width_nb > len && conv->precision_nb > len)
		i = conv->field_width_nb - len;
	else if (conv->precision_nb < len)
		i = conv->field_width_nb - conv->precision_nb;
	return (i);
}

void	ft_print_left_char_space_s(t_conv *conv, char *s)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = ft_width_space_to_print(conv, len);
	if (conv->dot == 1 && conv->precision_nb == 0 && conv->precision == 0)
	{
		i = conv->field_width_nb;
		while (i > 0)
		{
			write(1, " ", 1);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			write(1, " ", 1);
			i--;
		}
	}
}

void	ft_print_char_space_s(t_conv *conv, char *s)
{
	int i;
	int j;

	i = ft_strlen(s);
	j = conv->field_width_nb;
	if (conv->dot == 1 && conv->precision_nb == 0)
	{
		while (j > 0)
		{
			write(1, " ", 1);
			j--;
		}
	}
	else
	{
		while (j - i > 0)
		{
			write(1, " ", 1);
			j--;
		}
	}
}

char	*ft_print_zero_n_space_s(t_conv *conv, va_list ap, char *s)
{
	if (conv->precision == 0 || (conv->dot == 1 && conv->precision == 0))
	{
		if (!(s = va_arg(ap, char *)))
		{
			s = ft_strdup("(null)");
			conv->string_to_free = 1;
		}
		if (conv->flag != '-')
			ft_print_char_space_s(conv, s);
	}
	return (s);
}
