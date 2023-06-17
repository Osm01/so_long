/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:24:27 by ouidriss          #+#    #+#             */
/*   Updated: 2023/05/26 12:48:32 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_coins(t_game *t_g)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	count = 0;
	while (t_g->split_map[i])
	{
		y = 0;
		while (t_g->split_map[i][y])
		{
			if (t_g->split_map[i][y] == 'C')
				count ++;
			y ++;
		}
		i ++;
	}
	return (count);
}

t_position_player	get_position_player(t_game *t_g)
{
	t_position_player	t_pp;
	int					i;
	int					y;

	i = 0;
	while (t_g->split_map[i])
	{
		y = 0;
		while (t_g->split_map[i][y])
		{
			if (t_g->split_map[i][y] == 'P')
			{
				t_pp.x_coor = y;
				t_pp.y_coor = i;
				break ;
			}
			y ++;
		}
		i ++;
	}
	return (t_pp);
}

void	set_destination_position_and_set_textures(t_game *t_g, \
t_position_player t_pp, int d_xpz, int d_ypz)
{
	t_g->split_map[d_ypz][d_xpz] = 'P';
	t_g->split_map[t_pp.y_coor][t_pp.x_coor] = '0';
	mlx_clear_window(t_g->mlx_ptr, t_g->win_ptr);
	t_g->x_coor = 0;
	t_g->y_coor = 0;
	set_textures_by_position(t_g);
}

void	move_manager(int keycode, t_game *t_g)
{
	t_position_player	t_pp;

	t_pp = get_position_player(t_g);
	if (keycode == MOVE_KEY_UP)
		up_move(t_g, t_pp);
	if (keycode == MOVE_KEY_DOWN)
		down_move(t_g, t_pp);
	if (keycode == MOVE_KEY_RIGHT)
		right_move(t_g, t_pp);
	if (keycode == MOVE_KEY_LEFT)
		left_move(t_g, t_pp);
	if (t_g->coin_trigger == t_g->coin_count)
	{
		if (keycode == MOVE_KEY_UP || keycode == MOVE_KEY_DOWN || \
		keycode == MOVE_KEY_RIGHT || keycode == MOVE_KEY_LEFT)
			game_over(t_g, t_pp);
	}
}
