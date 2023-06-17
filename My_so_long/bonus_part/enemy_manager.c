/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:13:11 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/07 15:03:59 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_enemys(t_game *t_g)
{
	int	count;
	int	i;
	int	y;

	count = 0;
	i = 0;
	while (t_g->split_map[i])
	{
		y = 0;
		while (t_g->split_map[i][y])
		{
			if (t_g->split_map[i][y] == 'X')
				count ++;
			y ++;
		}
		i ++;
	}
	return (count);
}

void	set_rest_enemy_coor(t_game *t_g, t_enemy_position *t_ep)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (t_g->split_map[y])
	{
		x = 0;
		while (t_g->split_map[y][x])
		{
			if (t_g->split_map[y][x] == 'X')
			{
				t_ep[i].x_coor = x * 50;
				t_ep[i].y_coor = y * 50;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	reset_move_up_enemys(int *move_up, int count)
{
	int	i;

	i = 0;
	while (i < count)
		move_up[i ++] = 0;
}

t_enemy_position	*get_enemys_positions(t_game *t_g)
{
	int					count;
	t_enemy_position	*t_ep;

	count = count_enemys(t_g);
	t_ep = (t_enemy_position *) malloc(sizeof(t_enemy_position) * count);
	t_g->move_up_enemy = (int *) malloc (sizeof(int) * (count));
	if (!t_ep || !t_g->move_up_enemy)
		return (NULL);
	reset_move_up_enemys(t_g->move_up_enemy, count);
	set_rest_enemy_coor(t_g, t_ep);
	return (t_ep);
}
