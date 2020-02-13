/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:17:58 by dmontgen          #+#    #+#             */
/*   Updated: 2020/02/10 20:22:46 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_print_arg_s(char *s, t_conv *conv)
{
	int i;

	i = 0;
	if (conv->precision_nb == 0 && conv->dot == 1)
		return ;
	else if (conv->precision == 0)
		ft_putstr(s);
	else if (conv->precision == 1)
	{
		while (s[i] && i < conv->precision_nb)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int		ft_get_flag(t_conv *conv, char *buff)
{
	int i;

	i = 1;
	if (buff[i] == '0')
	{
		while (buff[i] && buff[i] == '0')
			i++;
	}
	if (buff[i] == '-')
	{
		conv->flag = '-';
		i++;
	}
	while (buff[i] == '-' || buff[i] == '0')
		i++;
	return (i);
}

int		ft_string_s(va_list ap, t_conv *conv, char *buff)
{
	int		i;
	char	*s;
	int		ret;

	ret = 0;
	s = NULL;
	i = ft_get_flag(conv, buff);
	if (buff[i] == '*')
	{
		ft_get_field_width_s(conv, ap);
		i++;
	}
	else if (buff[i] != '*' && ft_isdigit(buff[i]) == 1)
		ft_field_with_s(buff, conv, i);
	i = ft_until_no_digit(buff, i);
	if (buff[i] == '.')
		s = ft_get_precision_s(s, conv, ap, &buff[i]);
	s = ft_print_zero_n_space_s(conv, ap, s);
	ft_print_arg_s(s, conv);
	if (conv->flag == '-')
		ft_print_left_char_space_s(conv, s);
	ret = ft_ret_s(conv, s);
	if (conv->string_to_free == 1)
		free(s);
	return (ret);
}
