/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:58:45 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/09 17:03:23 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_inscreen(t_mlx *mlx, char c, int i)
{
	if (c == 'x')
	{
		if (mlx->p.x2 - mlx->p.x1 == 0)
			return (0);
		return (1);
	}
	if (c == 'y')
	{
		if (mlx->p.y2 - mlx->p.y1 == 0)
			return (0);
		if (mlx->p.x1 + ((mlx->p.x2 - mlx->p.x1) * (i - mlx->p.y1))
				/ (mlx->p.y2 - mlx->p.y1) > WIN_WIDTH)
			return (0);
		if (mlx->p.x1 + ((mlx->p.x2 - mlx->p.x1) * (i - mlx->p.y1))
				/ (mlx->p.y2 - mlx->p.y1) < 0)
			return (0);
		return (1);
	}
	return (0);
}

int			ft_color(t_mlx *mlx, int z1, int z2)
{
	if (z1 != 0 || z2 != 0)
	{
		if (mlx->color == -1)
			return (rand());
		if (mlx->color > 0)
			return (mlx->color);
		else
			return (16761035);
	}
	return (65535);
}

void		ft_swap_xy(int *x1, int *y1, int *x2, int *y2)
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
	if (index == 2)
		write(2, "Error with mlx\n", 15);
	if (index == 3)
		write(2, "Error memory allocation\n", 24);
	exit(1);
}

void		ft_define_gap(t_mlx *mlx)
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
	mlx->p.gap_x = gap_x;
	mlx->p.gap_y = gap_y;
	mlx->p.gap_z = gap_z;
	if (mlx->proj == 'p')
	{
		mlx->p.offset_x = mlx->p.gap_x;
		mlx->p.offset_y = mlx->p.gap_y;
	}
	else
	{
		mlx->p.offset_x = WIN_WIDTH * 2 / 5;
		mlx->p.offset_y = WIN_HEIGHT / 3;
	}
}
