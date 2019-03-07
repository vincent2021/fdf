/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:56:49 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/07 19:04:14 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_new_img(t_mlx *mlx)
{
	ft_bzero(mlx->img.data, WIN_WIDTH * WIN_HEIGHT * sizeof(int));
	mlx_clear_window(mlx->ptr, mlx->wdw);
	ft_init_map(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->img.img_ptr, 0, 0);
	ft_menu(mlx);
}

void	ft_move_map(int key, t_mlx *mlx)
{
	if (key == 125)
		mlx->p.offset_y += 5;
	if (key == 126)
		mlx->p.offset_y -= 5;
	if (key == 124)
		mlx->p.offset_x += 5;
	if (key == 123)
		mlx->p.offset_x -= 5;
}

int		keyboard(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	if (key == 69 || key == 24)
	{
		mlx->p.gap_x += 2;
		mlx->p.gap_y += 2;
	}
	if ((key == 78 || key == 27) && mlx->p.gap_x > 2 && mlx->p.gap_y > 2)
	{
		mlx->p.gap_x -= 2;
		mlx->p.gap_y -= 2;
	}
	if (key == 4)
		mlx->p.gap_z++;
	if (key == 37)
		mlx->p.gap_z--;
	if (key >= 123 && key <= 126)
		ft_move_map(key, mlx);
	if (key == 8)
	{
		mlx->color = rand();
		mlx->count++;
	}
	ft_new_img(mlx);
	return (0);
}

void	ft_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 10, 0xFFFFFF, "Commands:");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 40, 0xFFFFFF, "Zoom: +/-");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 60, 0xFFFFFF, "Move with arrows");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 80, 0xFFFFFF, "+/- altitude: H/L");
}
