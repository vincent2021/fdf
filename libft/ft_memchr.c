/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:59:14 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/21 23:15:38 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *src;

	src = (const char *)s;
	while (n--)
	{
		if (*src == (char)c)
			return ((void *)src);
		else
			src++;
	}
	return (NULL);
}
