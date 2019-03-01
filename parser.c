/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:00:47 by vimucchi          #+#    #+#             */
/*   Updated: 2019/02/25 20:17:05 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*ft_get_map(int fd)
{
	int		i;
	char	*line;
	t_line	*lst;
	t_line	*begin;

	if (!(lst = malloc(sizeof(t_line))))
		return (0);
	begin = lst;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(lst->str = ft_strsplit(line, ' ')))
			return (0);
		i = 0;
		while (lst->str[i])
			i++;
		lst->x_str = i;
		lst->next = malloc(sizeof(t_line));
		lst = lst->next;
		lst->y_str++;
		free(line);
	}
	lst->next = NULL;
	return (begin);
}

int			ft_check_map(t_line *line)
{
	t_line	*tmp;
	int		x;
	int		nb_line;

	tmp = line;
	nb_line = 0;
	x = line->x_str;
	while (tmp->next)
	{
		if (x != line->x_str)
		{
			write(2, "Error:\nThe file is invalid", 26);
			exit(1);
		}
		tmp = tmp->next;
		nb_line++;
	}
	return (nb_line);
}

t_parse		*ft_get_tab(t_line *line)
{
	t_parse	*map;
	int		i;
	int		j;

	map = malloc(sizeof(t_parse));
	map->y_tab = ft_check_map(line);
	map->x_tab = line->x_str;
	if (!(map->tab = malloc(sizeof(int **) * map->y_tab)))
		return (0);
	j = 0;
	while (line->next)
	{
		map->tab[j] = malloc(sizeof(int *) * line->x_str);
		i = 0;
		while (i < line->x_str)
		{
			map->tab[j][i] = ft_atoi(line->str[i]);
			i++;
		}
		j++;
		line = line->next;
	}
	map->tab[j] = 0;
	return (map);
}
