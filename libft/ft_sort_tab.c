/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 20:11:34 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/30 22:57:08 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*swap;

	k = 0;
	i = 0;
	j = 0;
	while (tab[k])
		k++;
	while (tab[i])
	{
		j = 0;
		while (j < k - 1)
		{
			if (0 < ft_strcmp(tab[j], tab[j + 1]))
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}
