/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:42:22 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/05 12:40:51 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_addr(t_mlx *mlx, int i)
{
	int addr;
	int x;
	int y;

	addr = 0;
	if ((mlx->p.x2 - mlx->p.x1) >= (mlx->p.y2 - mlx->p.y1))
	{
		x = i;
		if ((mlx->p.x2 - mlx->p.x1) != 0)
			addr = WIN_WIDTH * (mlx->p.y1 + ((mlx->p.y2 - mlx->p.y1)
						* (x - mlx->p.x1)) / (mlx->p.x2 - mlx->p.x1)) + x;
	}
	else if ((mlx->p.y2 - mlx->p.y1) > (mlx->p.x2 - mlx->p.x1))
	{
		y = i;
		if ((mlx->p.y2 - mlx->p.y1) != 0)
			addr = WIN_WIDTH * y + (mlx->p.x1 + ((mlx->p.x2 - mlx->p.x1)
						* (y - mlx->p.y1)) / (mlx->p.y2 - mlx->p.y1));
	}
	if (addr <= 0 || addr > (WIN_WIDTH * WIN_HEIGHT))
		return (0);
	return (addr);
}

void		ft_line(t_mlx *mlx, int color)
{
	int		x;
	int		y;

	if (mlx->p.x1 > mlx->p.x2)
		ft_swap_xy(&(mlx->p.x1), &(mlx->p.x2), &(mlx->p.y1), &(mlx->p.y2));
	if ((mlx->p.x2 - mlx->p.x1) >= (mlx->p.y2 - mlx->p.y1))
	{
		x = mlx->p.x1;
		while (x <= mlx->p.x2)
		{
			mlx->img.data[ft_get_addr(mlx, x)] = color;
			x++;
		}
	}
	else if ((mlx->p.y2 - mlx->p.y1) > (mlx->p.x2 - mlx->p.x1))
	{
		y = mlx->p.y1;
		while (y <= mlx->p.y2)
		{
			mlx->img.data[ft_get_addr(mlx, y)] = color;
			y++;
		}
	}
}

void		ft_proj(t_mlx *mlx, int *xyz)
{
	int		c;

	c = 5;
	if (mlx->proj == 'p')
	{
		mlx->p.x1 = mlx->p.gap_x + xyz[0] + (c * xyz[2]) / 10;
		mlx->p.x2 = mlx->p.gap_x + xyz[3] + (c * xyz[5]) / 10;
		mlx->p.y1 = mlx->p.gap_y + xyz[1] + (c * xyz[2]) / 20;
		mlx->p.y2 = mlx->p.gap_y + xyz[4] + (c * xyz[5]) / 20;
	}
	if (mlx->proj == 'i')
	{
		mlx->p.x1 = (WIN_WIDTH * 2) / 5 + (c * xyz[0] - c * xyz[1])
			/ 10;
		mlx->p.x2 = (WIN_WIDTH * 2) / 5 + (c * xyz[3] - c * xyz[4])
			/ 10;
		mlx->p.y1 = WIN_HEIGHT / 3 - xyz[2] + ((c / 2) * xyz[0]
				+ (c / 2) * xyz[1]) / 10;
		mlx->p.y2 = WIN_HEIGHT / 3 - xyz[5] + ((c / 2) * xyz[3]
				+ (c / 2) * xyz[4]) / 10;
	}
	if (xyz[2] != 0 || xyz[5] != 0)
		ft_line(mlx, 16761035);
	else
		ft_line(mlx, 65535);
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
		ft_define_gap(mlx, 0);
		mlx->init = 1;
	}
	if (mlx->p.gap_x == 0)
		mlx->p.gap_x = 1;
	if (mlx->p.gap_y == 0)
		mlx->p.gap_y = 1;
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
