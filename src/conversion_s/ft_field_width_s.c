/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:58:18 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 19:59:35 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_get_field_width_s(t_conv *conv, va_list ap)
{
	int tmp;

	tmp = 0;
	conv->field_width_nb = va_arg(ap, int);
	if (conv->field_width_nb < 0)
	{
		conv->flag = '-';
		tmp = conv->field_width_nb;
		tmp *= -1;
		conv->field_width_nb = tmp;
	}
}

void	ft_field_with_s(char *buff, t_conv *conv, int i)
{
	int		j;
	char	*stock_field_with;
	int		tmp;

	tmp = 0;
	j = i;
	stock_field_with = NULL;
	while (ft_isdigit(buff[i]) == 1)
		i++;
	stock_field_with = ft_substr(buff, j, i);
	conv->field_width_nb = ft_my_atoi(stock_field_with);
	free(stock_field_with);
	if (conv->field_width_nb < 0)
	{
		conv->flag = '-';
		tmp = conv->field_width_nb;
		tmp *= -1;
		conv->field_width_nb = tmp;
	}
}
