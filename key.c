/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:56:49 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/04 19:56:54 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_new_img(t_mlx *mlx)
{
	ft_bzero(mlx->img.data, WIN_WIDTH * WIN_HEIGHT * sizeof(int));
	mlx_clear_window(mlx->ptr, mlx->wdw);
	ft_init_map(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->img.img_ptr, 0, 0);
}

int		keyboard(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	if (key == 69 || key == 24)
	{
		mlx->p.gap_x++;
		mlx->p.gap_y++;
	}
	if ((key == 78 || key == 27) && mlx->p.gap_x != 0 && mlx->p.gap_y != 0)
	{
		mlx->p.gap_x--;
		mlx->p.gap_y--;
	}
	if (key == 4 || key == 126)
		mlx->p.gap_z++;
	if (key == 37 || key == 125)
		mlx->p.gap_z--;
	ft_new_img(mlx);
	return (0);
}
