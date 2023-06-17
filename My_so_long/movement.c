/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:57:04 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/04 18:31:10 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_move(t_game *t_g, t_position_player t_pp)
{
	if (t_g->split_map[t_pp.y_coor - 1][t_pp.x_coor] == '0' || \
		t_g->split_map[t_pp.y_coor - 1][t_pp.x_coor] == 'C')
	{
		if (t_g->split_map[t_pp.y_coor - 1][t_pp.x_coor] == 'C')
			t_g->coin_trigger ++;
		t_g->count_move = t_g->count_move + 1;
		set_destination_position_and_set_textures(t_g, t_pp, \
		t_pp.x_coor, t_pp.y_coor - 1);
	}
}

void	down_move(t_game *t_g, t_position_player t_pp)
{
	if (t_g->split_map[t_pp.y_coor + 1][t_pp.x_coor] == '0' || \
		t_g->split_map[t_pp.y_coor + 1][t_pp.x_coor] == 'C')
	{
		if (t_g->split_map[t_pp.y_coor + 1][t_pp.x_coor] == 'C')
			t_g->coin_trigger ++;
		t_g->count_move = t_g->count_move + 1;
		set_destination_position_and_set_textures(t_g, t_pp, \
		t_pp.x_coor, t_pp.y_coor + 1);
	}
}

void	right_move(t_game *t_g, t_position_player t_pp)
{
	if (t_g->split_map[t_pp.y_coor][t_pp.x_coor + 1] == '0' || \
		t_g->split_map[t_pp.y_coor][t_pp.x_coor + 1] == 'C')
	{
		if (t_g->split_map[t_pp.y_coor][t_pp.x_coor + 1] == 'C')
			t_g->coin_trigger ++;
		t_g->count_move = t_g->count_move + 1;
		set_destination_position_and_set_textures(t_g, t_pp, \
		t_pp.x_coor + 1, t_pp.y_coor);
	}
}

void	left_move(t_game *t_g, t_position_player t_pp)
{
	if (t_g->split_map[t_pp.y_coor][t_pp.x_coor - 1] == '0' || \
		t_g->split_map[t_pp.y_coor][t_pp.x_coor - 1] == 'C')
	{
		if (t_g->split_map[t_pp.y_coor][t_pp.x_coor - 1] == 'C')
			t_g->coin_trigger ++;
		t_g->count_move = t_g->count_move + 1;
		set_destination_position_and_set_textures(t_g, t_pp, \
		t_pp.x_coor - 1, t_pp.y_coor);
	}
}

void	game_over(t_game *t_g, t_position_player t_pp)
{
	if (t_g->split_map[t_pp.y_coor + 1][t_pp.x_coor] == 'E' || \
	t_g->split_map[t_pp.y_coor - 1][t_pp.x_coor] == 'E' || \
	t_g->split_map[t_pp.y_coor][t_pp.x_coor + 1] == 'E' || \
	t_g->split_map[t_pp.y_coor][t_pp.x_coor - 1] == 'E')
	{
		t_g->count_move = t_g->count_move + 1;
		ft_printf("Game over you won\n");
		free_all(t_g);
		exit(0);
	}
}
