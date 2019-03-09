/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:55:09 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/09 16:47:02 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->ptr, mlx->wdw);
	exit(1);
}

void		ft_close(int fd)
{
	if (close(fd) == -1)
	{
		write(2, "Error: file can't be closed\n", 28);
		exit(1);
	}
}

int			ft_open(char *file)
{
	int		i;
	int		fd;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
	{
		write(2, "Error: Usage: ./fdf <file.fdf> -p/-i\n", 37);
		exit(1);
	}
	if ((fd = open(file, O_RDONLY | O_SYMLINK)) == -1)
	{
		write(2, "Error: file doesn't exist\n", 26);
		exit(1);
	}
	return (fd);
}

void		ft_init_mlx(t_mlx *mlx)
{
	t_img	img;

	if (!(mlx->ptr = mlx_init()))
		ft_error_map(2);
	if (!(mlx->wdw = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		ft_error_map(2);
	if (!(img.img_ptr = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT)))
		ft_error_map(2);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.s_l),
			&(img.endian));
	mlx->img = img;
	mlx->init = 0;
}

int			main(int ac, char **av)
{
	int		fd;
	t_mlx	mlx;

	if (ac == 2 || (ac == 3 && (!ft_strcmp(av[2], "-i")
					|| !ft_strcmp(av[2], "-p"))))
	{
		fd = ft_open(av[1]);
		mlx.map = ft_get_tab(ft_get_map(fd));
		ft_close(fd);
		ft_init_mlx(&mlx);
		if (ac == 3)
			mlx.proj = av[2][1];
		else
			mlx.proj = 'i';
		ft_init_map(&mlx);
		mlx_put_image_to_window(mlx.ptr, mlx.wdw, mlx.img.img_ptr, 0, 0);
		ft_menu(&mlx);
		mlx_hook(mlx.wdw, 2, 5, keyboard, &mlx);
		mlx_hook(mlx.wdw, DESTROYNOTIFY, NOEVENTMASK, ft_exit, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		write(2, "Usage: ./fdf <file.fdf> -p/-i\n", 30);
	return (0);
}
