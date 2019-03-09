/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:56:02 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/09 16:58:48 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line_x(t_mlx *mlx, int color)
{
	int		x;
	int		pxl;

	if (mlx->p.x2 < mlx->p.x1)
		ft_swap_xy(&(mlx->p.x1), &(mlx->p.y1), &(mlx->p.x2), &(mlx->p.y2));
	x = (mlx->p.x1 < 0) ? 0 : mlx->p.x1;
	while (x <= mlx->p.x2 && x < WIN_WIDTH)
	{
		pxl = -1;
		if (ft_inscreen(mlx, 'x', x))
			pxl = WIN_WIDTH * (mlx->p.y1 + ((mlx->p.y2 - mlx->p.y1)
						* (x - mlx->p.x1)) / (mlx->p.x2 - mlx->p.x1)) + x;
		if (pxl >= 0 && pxl < (WIN_WIDTH * WIN_HEIGHT))
			mlx->img.data[pxl] = color;
		x++;
	}
}

void		ft_line_y(t_mlx *mlx, int color)
{
	int		y;
	int		pxl;

	if (mlx->p.y2 < mlx->p.y1)
		ft_swap_xy(&(mlx->p.x1), &(mlx->p.y1), &(mlx->p.x2), &(mlx->p.y2));
	y = (mlx->p.y1 < 0) ? 0 : mlx->p.y1;
	while (y <= mlx->p.y2 && y < WIN_HEIGHT)
	{
		pxl = -1;
		if (ft_inscreen(mlx, 'y', y))
			pxl = WIN_WIDTH * y + (mlx->p.x1 + ((mlx->p.x2 - mlx->p.x1)
			* (y - mlx->p.y1)) / (mlx->p.y2 - mlx->p.y1));
		if (pxl >= 0 && pxl < (WIN_WIDTH * WIN_HEIGHT))
			mlx->img.data[pxl] = color;
		y++;
	}
}

void		ft_proj(t_mlx *mlx, int *xyz)
{
	int		c;

	c = 5;
	if (mlx->proj == 'p')
	{
		mlx->p.x1 = mlx->p.offset_x + xyz[0] + (c * xyz[2]) / 10;
		mlx->p.x2 = mlx->p.offset_x + xyz[3] + (c * xyz[5]) / 10;
		mlx->p.y1 = mlx->p.offset_y + xyz[1] + (c * xyz[2]) / 20;
		mlx->p.y2 = mlx->p.offset_y + xyz[4] + (c * xyz[5]) / 20;
	}
	if (mlx->proj == 'i')
	{
		mlx->p.x1 = mlx->p.offset_x + (c * xyz[0] - c * xyz[1]) / 10;
		mlx->p.x2 = mlx->p.offset_x + (c * xyz[3] - c * xyz[4]) / 10;
		mlx->p.y1 = mlx->p.offset_y - xyz[2] + ((c / 2) * xyz[0]
			+ (c / 2) * xyz[1]) / 10;
		mlx->p.y2 = mlx->p.offset_y - xyz[5] + ((c / 2) * xyz[3]
			+ (c / 2) * xyz[4]) / 10;
	}
	if (abs(mlx->p.x2 - mlx->p.x1) >= abs(mlx->p.y2 - mlx->p.y1))
		ft_line_x(mlx, ft_color(mlx, xyz[2], xyz[5]));
	else
		ft_line_y(mlx, ft_color(mlx, xyz[2], xyz[5]));
}

void		ft_xyz(t_mlx *mlx, int x, int y)
{
	int xyz[6];

	xyz[0] = x * mlx->p.gap_x;
	xyz[1] = y * mlx->p.gap_y;
	xyz[2] = mlx->map.tab[y][x] * mlx->p.gap_z;
	if (x < (mlx->map.x_tab - 1))
	{
		xyz[3] = (x + 1) * mlx->p.gap_x;
		xyz[4] = y * mlx->p.gap_y;
		xyz[5] = mlx->map.tab[y][x + 1] * mlx->p.gap_z;
		ft_proj(mlx, xyz);
	}
	if (y < (mlx->map.y_tab - 1))
	{
		xyz[3] = x * mlx->p.gap_x;
		xyz[4] = (y + 1) * mlx->p.gap_y;
		xyz[5] = mlx->map.tab[y + 1][x] * mlx->p.gap_z;
		ft_proj(mlx, xyz);
	}
}

void		ft_init_map(t_mlx *mlx)
{
	int		x;
	int		y;

	if (mlx->init == 0)
	{
		ft_define_gap(mlx);
		mlx->init = 1;
		mlx->color = 0;
	}
	if (mlx->p.gap_x == 0)
		mlx->p.gap_x = 1;
	if (mlx->p.gap_y == 0)
		mlx->p.gap_y = 1;
	ft_menu(mlx);
	y = 0;
	while (y < mlx->map.y_tab)
	{
		x = 0;
		while (x < mlx->map.x_tab)
		{
			ft_xyz(mlx, x, y);
			x++;
		}
		y++;
	}
}
