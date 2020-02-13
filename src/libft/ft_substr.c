/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:24:58 by dmontgen          #+#    #+#             */
/*   Updated: 2020/01/03 18:15:33 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
	{
		newstr[0] = '\0';
		return (newstr);
	}
	while (len--)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
