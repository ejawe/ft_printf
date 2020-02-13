/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_field_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:13:45 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:49:48 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_field_width(char *buff, t_conv *conv)
{
	int		i;
	char	*stock_field_with;

	i = 0;
	stock_field_with = NULL;
	while (ft_isdigit(buff[i]) == 1)
		i++;
	stock_field_with = ft_substr(buff, 0, i);
	conv->field_width_nb = ft_my_atoi(stock_field_with);
	free(stock_field_with);
	stock_field_with = NULL;
}

int		ft_stock_field_width(t_conv *conv, char *buff, int i, va_list ap)
{
	int tmp;

	tmp = 0;
	if (buff[i] == '*')
	{
		conv->field_width_nb = va_arg(ap, int);
		conv->field_width = 1;
		i++;
	}
	if (ft_isdigit(buff[i]))
	{
		ft_field_width(&buff[i], conv);
		conv->field_width = 1;
		i++;
	}
	if (conv->field_width_nb < 0)
	{
		conv->flag = '-';
		tmp = conv->field_width_nb;
		tmp *= -1;
		conv->field_width_nb = tmp;
	}
	i = ft_until_no_digit(buff, i);
	return (i);
}
