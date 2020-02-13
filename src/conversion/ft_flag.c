/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:10:28 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 16:14:31 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_flag(t_conv *conv, char *buff, int i)
{
	if (buff[i] == '0')
	{
		conv->flag = '0';
		i++;
	}
	while (buff[i] == '0')
		i++;
	if (buff[i] == '-')
	{
		conv->flag = '-';
		i++;
	}
	while (buff[i] == '-' || buff[i] == '0')
		i++;
	return (i);
}
