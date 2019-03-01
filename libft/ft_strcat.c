/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:23:14 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/30 22:05:36 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t i;
	size_t len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	while (s1 && s2[i])
	{
		s1[i + len_s1] = s2[i];
		i++;
	}
	s1[i + len_s1] = '\0';
	return (s1);
}
