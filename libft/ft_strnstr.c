/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:22:59 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/23 00:20:26 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l_cmp;

	i = 0;
	if (!(l_cmp = ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i] && (i + l_cmp - 1) < len)
	{
		if (ft_strncmp(&haystack[i], needle, l_cmp) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
