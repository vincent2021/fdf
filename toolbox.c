/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:58:45 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/04 20:52:20 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_swap_xy(int *x1, int *x2, int *y1, int *y2)
{
	int		tmp;

	tmp = *x2;
	*x2 = *x1;
	*x1 = tmp;
	tmp = *y2;
	*y2 = *y1;
	*y1 = tmp;
}

void		ft_error_map(int index)
{
	if (index == 0)
		write(2, "Error: The map is invalid\n", 26);
	if (index == 1)
		write(2, "Error: Wrong memory allocation\n", 31);
	exit(1);
}
