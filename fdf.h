/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:17:01 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/09 17:16:38 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <fcntl.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define NOEVENTMASK 0L
# define DESTROYNOTIFY 17

typedef struct		s_line
{
	char			**str;
	int				x_str;
	struct s_line	*next;
}					t_line;

typedef struct		s_parse
{
	int				**tab;
	int				x_tab;
	int				y_tab;
}					t_parse;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				gap_x;
	int				gap_y;
	int				gap_z;
	int				offset_x;
	int				offset_y;
}					t_coord;

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	int				init;
	int				color;
	char			proj;
	t_img			img;
	t_parse			map;
	t_coord			p;
}					t_mlx;

t_line				*ft_get_map(int fd);
t_parse				ft_get_tab(t_line *str);
void				ft_init_map(t_mlx *mlx);
int					keyboard(int key, t_mlx *mlx);
void				ft_menu(t_mlx *mlx);
int					ft_exit(t_mlx *mlx);
void				ft_swap_xy(int *x1, int *y1, int *x2, int *y2);
void				ft_error_map(int index);
void				ft_define_gap(t_mlx *mlx);
int					ft_color(t_mlx *mlx, int z1, int z2);
int					ft_inscreen(t_mlx *mlx, char c, int i);

#endif
