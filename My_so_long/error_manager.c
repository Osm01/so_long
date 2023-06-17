/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:04:23 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/04 13:11:21 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_coll_start_counter(char checker, \
int *_exit, int *_coll, int *_start)
{
	if (checker == 'E')
		*_exit = *_exit + 1;
	if (checker == 'C')
		*_coll = *_coll + 1;
	if (checker == 'P')
		*_start = *_start + 1;
}

int	check_one_exit_coll_start(t_game *t_g)
{
	int	i;
	int	y;
	int	_exit;
	int	_coll;
	int	_start;

	_exit = 0;
	_coll = 0;
	_start = 0;
	i = 0;
	while (t_g->split_map[i])
	{
		y = 0;
		while (t_g->split_map[i][y])
		{
			exit_coll_start_counter(t_g->split_map[i][y], \
			&_exit, &_coll, &_start);
			y ++;
		}
		i ++;
	}
	if ((_start != 1 || _exit != 1) || _coll < 1)
		return (0);
	return (1);
}

int	check_surrounded_by_wall(t_game *t_g)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (t_g->split_map[i][y] && t_g->split_map[i][y] != '\n')
	{
		if (t_g->split_map[i][y ++] != '1')
			return (0);
	}
	y --;
	while (t_g->split_map[i])
	{
		if (t_g->split_map[i][0] != '1' || t_g->split_map[i][y] != '1')
			return (0);
		i ++;
	}
	i --;
	y = 0;
	while (t_g->split_map[i][y] && t_g->split_map[i][y] != '\n')
	{
		if (t_g->split_map[i][y ++] != '1')
			return (0);
	}
	return (1);
}

int	check_rectangle(t_game *t_g)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	y = 0;
	z = 0;
	while (t_g->split_map[i])
	{
		if (y != z)
			return (0);
		y = 0;
		while (t_g->split_map[i][y])
		{
			if (t_g->split_map[i][y] == '\n')
				break ;
			y ++;
		}
		if (i == 0)
			z = y;
		i ++;
	}
	return (1);
}

int	check_file_extension(char const **argv)
{
	char	**file;
	int		i;

	file = ft_split(argv[1], '.');
	i = 0;
	while (file[i])
		i ++;
	i --;
	if (!ft_strcmp(file[i], "ber"))
		return (free_2d_array(file), 1);
	return (0);
}
