/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:13:30 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/16 18:28:01 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_valid_map(char **check)
{
	int	i;
	int	y;

	i = 0;
	while (check[i])
	{
		y = 0;
		while (check[i][y])
		{
			if (check[i][y] == '\n')
				break ;
			if (check[i][y] != '1' && check[i][y] != 'E')
				return (0);
			y ++;
		}
		i ++;
	}
	return (1);
}

void	flood_fill(char **map, t_position_player t_pp, \
int new_xpz, int new_ypz)
{
	if (map[new_ypz][new_xpz] == '1' || map[new_ypz][new_xpz] == 'E')
		return ;
	map[new_ypz][new_xpz] = '1';
	t_pp.x_coor = new_xpz;
	t_pp.y_coor = new_ypz;
	flood_fill(map, t_pp, new_xpz + 1, new_ypz);
	flood_fill(map, t_pp, new_xpz - 1, new_ypz);
	flood_fill(map, t_pp, new_xpz, new_ypz + 1);
	flood_fill(map, t_pp, new_xpz, new_ypz - 1);
}

char	**copy_data(char **src)
{
	char	**cpy;
	int		i;
	int		z;

	i = 0;
	z = 0;
	while (src[i])
		i ++;
	cpy = (char **)malloc(sizeof(char *) * (i + 1));
	while (src[z])
	{
		cpy[z] = ft_strdup(src[z]);
		z ++;
	}
	cpy[z] = (char *) NULL;
	return (cpy);
}

int	check_flood_fill(t_game *t_g)
{
	t_position_player	t_pp;
	char				**check;
	int					re;
	int					i;

	re = 0;
	t_pp = get_position_player(t_g);
	check = copy_data(t_g->split_map);
	flood_fill(check, t_pp, t_pp.x_coor, t_pp.y_coor);
	re = check_valid_map(check);
	i = 0;
	while (check[i])
		free (check[i++]);
	free (check);
	return (re);
}
