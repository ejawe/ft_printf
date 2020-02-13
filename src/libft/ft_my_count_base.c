/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_count_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:28:00 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 20:44:41 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_my_count_base(long long nbr, char *base)
{
	int	lb;
	int	i;
	int	neg;

	lb = 0;
	i = 0;
	neg = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		neg = 0;
	}
	if (nbr == 0)
	{
		i = 1;
		return (i);
	}
	while (base[lb] != '\0')
		lb++;
	while (nbr)
	{
		nbr = (nbr / lb);
		i++;
	}
	return (i + neg);
}
