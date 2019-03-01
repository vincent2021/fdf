/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:59:49 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/15 23:10:47 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbsize(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	int				sign;
	unsigned int	n2;
	char			*str;

	i = ft_nbsize(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	n2 = n * sign;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (i >= 0 && n2 != 0)
	{
		str[i--] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
	if (sign == -1)
		str[i] = '-';
	return (str);
}
