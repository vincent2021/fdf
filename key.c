/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:41:00 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/02 18:55:28 by vimucchi         ###   ########.fr       */
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
	printf("Key:%d\n", key);
	if (key == 53)
		ft_exit(mlx);
	if (key == 38 || key == 69 || key == 24)
	{
		mlx->p.gap_x *= 1.1;
		mlx->p.gap_y *= 1.1;
	}
	if (key == 40 || key == 27 || key == 78)
	{
		mlx->p.gap_x *= 0.9;
		mlx->p.gap_y *= 0.9;
	}
	if (key == 4)
		mlx->p.alt -= 2;
	if (key == 37)
		mlx->p.alt += 2;
	ft_new_img(mlx);
	return (0);
}
