/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:45:32 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/11 10:29:16 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_len_base(char *base)
{
	int lb;

	lb = 0;
	while (base[lb] != '\0')
		lb++;
	return (lb);
}

void	ft_my_putnbr_base(long long nbr, char *base)
{
	int lb;
	int resultat[100];
	int i;

	lb = 0;
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr == 0)
	{
		ft_putchar('0');
		return ;
	}
	lb = ft_len_base(base);
	while (nbr)
	{
		resultat[i] = nbr % lb;
		nbr = (nbr / lb);
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[resultat[i]]);
}
