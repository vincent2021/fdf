/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 23:09:43 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/30 23:08:33 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && n > 0)
	{
		i++;
		n--;
	}
	return (i);
}

size_t			ft_strlcat(char *restrict dst, const char *restrict src,
		size_t size)
{
	size_t	d;
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = 0;
	d = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strnlen(dst, size);
	if (size == 0)
		return (len_dst + len_src);
	while (dst[d])
		d++;
	while (src[i] && size - 1 > i + len_dst)
		dst[d++] = src[i++];
	dst[d] = '\0';
	return (len_dst + len_src);
}
