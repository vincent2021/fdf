/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:20:36 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/28 20:15:26 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_check_base(char *s1, char c)
{
	int				i;

	i = 0;
	while (s1[i])
		if (s1[i++] == c)
			return (1);
	return (0);
}

static int			ft_lbase(char *base)
{
	int				i;

	i = 0;
	while (base[i])
	{
		if (ft_check_base(base + 1 + i, base[i]) == 1)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void				ft_putnbr_base(int nb, char *base)
{
	int				i;
	int				nb_conv[32];
	int				lbase;
	unsigned int	nb2;

	lbase = ft_lbase(base);
	i = 0;
	if (nb < 0 && lbase != 0)
	{
		nb2 = nb * -1;
		ft_putchar('-');
	}
	else
		nb2 = nb;
	if (nb2 == 0 && lbase != 0)
		ft_putchar(base[0]);
	while (nb2 > 0 && lbase != 0)
	{
		nb_conv[i++] = nb2 % lbase;
		nb2 = nb2 / lbase;
	}
	while (i > 0 && lbase != 0)
		ft_putchar(base[nb_conv[i-- - 1]]);
}
