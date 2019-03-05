/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:58:45 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/05 12:23:21 by vimucchi         ###   ########.fr       */
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

void		ft_define_gap(t_mlx *mlx, int zoom)
{
	int		gap_x;
	int		gap_y;
	int		gap_z;

	gap_x = WIN_WIDTH / (mlx->map.x_tab + 1);
	gap_y = WIN_HEIGHT / (mlx->map.y_tab + 1);
	gap_z = 1;
	if (gap_x < gap_y)
		gap_y = gap_x;
	else
		gap_x = gap_y;
	if (zoom == 0)
	{
		mlx->p.gap_x = gap_x;
		mlx->p.gap_y = gap_y;
		mlx->p.gap_z = gap_z;
	}
}
