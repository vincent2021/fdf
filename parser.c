/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:00:47 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/02 22:18:35 by vimucchi         ###   ########.fr       */
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
		if (!(lst->next = malloc(sizeof(t_line))))
			return (0);
		lst = lst->next;
		lst->str = NULL;
		free(line);
	}
	lst->next = NULL;
	return (begin);
}

int			ft_check_map(t_line *line)
{
	t_line	*tmp;
	int		nb_line;

	tmp = line;
	nb_line = 0;
	while (tmp->next)
	{
		if (line->x_str != tmp->x_str)
		{
			write(2, "Error: The map is invalid\n", 26);
			exit(1);
		}
		tmp = tmp->next;
		nb_line++;
	}
	return (nb_line);
}

int			ft_free_lst(t_line *line)
{
	int		i;

	if (line->next != NULL)
		ft_free_lst(line->next);
	i = 0;
	while (line->str && line->str[i])
	{
		free(line->str[i]);
		i++;
	}
	if (line->str)
		free(line->str);
	if (line)
		free(line);
	return (0);
}

t_parse		ft_get_tab(t_line *line)
{
	t_parse	map;
	t_line	*begin;
	int		i;
	int		j;

	begin = line;
	map.y_tab = ft_check_map(line);
	map.x_tab = line->x_str;
	map.tab = malloc(sizeof(int **) * map.y_tab);
	j = 0;
	while (line->next)
	{
		map.tab[j] = malloc(sizeof(int *) * line->x_str);
		i = 0;
		while (i < line->x_str)
		{
			map.tab[j][i] = ft_atoi(line->str[i]);
			i++;
		}
		j++;
		line = line->next;
	}
	ft_free_lst(begin);
	return (map);
}
