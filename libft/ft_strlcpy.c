/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:49:37 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/30 23:16:41 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(src);
	i = 0;
	while (src[i] && size > 1)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	if (size != 0)
		dst[i] = '\0';
	return (len_s);
}
