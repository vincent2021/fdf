/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:31:01 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/28 19:04:50 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	while (s2[i] && s1 != NULL && i < n)
	{
		s1[i + len_s1] = s2[i];
		i++;
	}
	s1[i + len_s1] = '\0';
	return (s1);
}
