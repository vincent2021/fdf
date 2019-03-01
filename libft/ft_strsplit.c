/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:56:54 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/23 00:22:44 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countchar(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_countstr(char const *s, char c)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if (s)
	{
		while (s[i])
		{
			if ((i == 0 && s[i] != c) || (i > 0 && s[i - 1] == c && s[i] != c))
				n++;
			i++;
		}
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nbstr;
	size_t	nbchr;
	char	**tab;

	i = 0;
	j = 0;
	nbstr = ft_countstr(s, c);
	if (!(tab = (char **)malloc((nbstr + 1) * sizeof(char *))) || !s)
		return (NULL);
	while (j < nbstr)
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i - 1] == c && s[i] != c))
		{
			nbchr = ft_countchar(s + i, c);
			if (!(tab[j] = ft_strsub(s, i, nbchr)))
				return (NULL);
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
