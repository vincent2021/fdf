#include "fdf.h"

void	ft_proj_iso(t_mlx *mlx, int *xyz)
{
	int a;
	int b;
	int color;
	int offset_x;
	int	offset_y;

	a = 500;
	b = 500;
	offset_x = (WIN_WIDTH * 2) / 5;
	offset_y = WIN_HEIGHT / 5;
	mlx->p.x1 = offset_x + (a * xyz[0] - b * xyz[1]) / 1000;
	mlx->p.x2 = offset_x + (a * xyz[3] - b * xyz[4]) / 1000;
	mlx->p.y1 = offset_y -xyz[2] + ((a / 2) * xyz[0] + (b / 2) * xyz[1]) / 1000;
	mlx->p.y2 = offset_y -xyz[5] + ((a / 2) * xyz[3] + (b / 2) * xyz[4]) / 1000;
	color = 65535;
	if (xyz[2] > 0 || xyz[5] > 0)
		color = 16761035;
	ft_line(mlx, color);

}

void  ft_proj_p(t_mlx *mlx, int *xyz)
{
	int a;
	int color;

	a = 500;
	mlx->p.x1 = mlx->p.gap_x + xyz[0] + (a * xyz[2]) / 1000;
	mlx->p.x2 = mlx->p.gap_x + xyz[3] + (a * xyz[5]) / 1000;
	mlx->p.y1 = mlx->p.gap_y + xyz[1] + (a * xyz[2]) / 2000;
	mlx->p.y2 = mlx->p.gap_y + xyz[4] + (a * xyz[5]) / 2000;
	color = 65535;
	if (xyz[2] > 0 || xyz[5] > 0)
		color = 16761035;
	ft_line(mlx, color);
}

void		ft_draw_map(t_mlx *mlx)
{
	int 		x;
	int 		y;
	int			**tab;
	int			gap_x;
	int			gap_y;
	int			gap_z;
	int			xyz[6];

	tab = mlx->map.tab;
	if (mlx->check == 0)
	{
		mlx->p.gap_x = WIN_WIDTH / (mlx->map.x_tab + 1);
		mlx->p.gap_y = WIN_HEIGHT / (mlx->map.y_tab + 1);
		mlx->p.gap_z = (mlx->p.gap_x + mlx->p.gap_y) / 10;
	}
	gap_x = mlx->p.gap_x;
	gap_y = mlx->p.gap_y;
	gap_z = mlx->p.gap_z;
	y = 0;
	while (y < mlx->map.y_tab)
	{
		x = 0;
		while (x < mlx->map.x_tab)
		{
			xyz[0] = x * gap_x;
			xyz[1] = y * gap_y;
			xyz[2] = tab[y][x] * gap_z;
			if (mlx->proj == 'i')
			{
				if (x < (mlx->map.x_tab - 1))
				{
					xyz[3] = (x + 1) * gap_x;
					xyz[4] = y * gap_y;
					xyz[5] = tab[y][x + 1] * gap_z;
					ft_proj_iso(mlx, xyz);
				}
				if (y < (mlx->map.y_tab - 1))
				{
					xyz[3] = x * gap_x;
					xyz[4] = (y + 1) * gap_y;
					xyz[5] = tab[y + 1][x] * gap_z;
					ft_proj_iso(mlx, xyz);
				}
			}
			if (mlx->proj == 'p')
			{
				if (x < (mlx->map.x_tab - 1))
				{
					xyz[3] = (x + 1) * gap_x;
					xyz[4] = y * gap_y;
					xyz[5] = tab[y][x + 1] * gap_z;
					ft_proj_p(mlx, xyz);
				}
				if (y < (mlx->map.y_tab - 1))
				{
					xyz[3] = x * gap_x;
					xyz[4] = (y + 1) * gap_y;
					xyz[5] = tab[y + 1][x] * gap_z;
					ft_proj_p(mlx, xyz);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_swap_xy(int *x1, int *x2, int *y1, int *y2)
{
	int	tmp;

	tmp = *x2;
	*x2 = *x1;
	*x1 = tmp;
	tmp = *y2;
	*y2 = *y1;
	*y1 = tmp;
}

void	ft_line(t_mlx *mlx, int color)
{
	int x;
	int y;
	t_coord p;

	p = mlx->p;
	if (p.x1 > p.x2)
		ft_swap_xy(&(p.x1), &(p.x2), &(p.y1), &(p.y2));
	if ((p.x2 - p.x1) > (p.y2 - p.y1))
	{
		x = p.x1;
		while (x <= p.x2)
		{
			mlx->img.data[WIN_WIDTH * (p.y1 + ((p.y2 - p.y1) * (x - p.x1 )) / (p.x2 - p.x1)) + x] = color;
			x++;
		}
	}
	else if ((p.y2 - p.y1) > (p.x2- p.x1))
	{
		y = p.y1;
		while (y <= p.y2)
		{
			mlx->img.data[WIN_WIDTH * y + (p.x1 + ((p.x2 - p.x1) * (y - p.y1)) / (p.y2 - p.y1))] = color;
			y++;
		}
	}
}
