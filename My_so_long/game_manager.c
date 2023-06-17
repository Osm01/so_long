/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:14:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/01 17:12:04 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook_manager(int keycode, t_game *t_g)
{
	if (keycode == 53)
	{
		free_all(t_g);
		exit(1);
	}
	move_manager(keycode, t_g);
	return (0);
}

int	close_window(t_game *t_g)
{
	free_all(t_g);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_values(t_game *t_g, char const *argv[])
{
	t_g->argv = argv;
	t_g->coin_trigger = 0;
	t_g->count_move = 0;
	ft_split_map(t_g);
	t_g->coin_count = count_coins(t_g);
}

void	free_all(t_game *t_g)
{
	int	i;

	i = 0;
	while (t_g->split_map[i])
	{
		free (t_g->split_map[i]);
		i ++;
	}
	free (t_g->split_map);
	free (t_g);
}

void	calculate_width_height_window(t_game *t_g)
{
	int	i;
	int	y;

	i = 0;
	while (t_g->split_map[i])
	{
		y = 0;
		while (t_g->split_map[i][y] != '\n' && t_g->split_map[i][y] != '\0')
			y ++;
		i ++;
	}
	t_g->win_width = y;
	t_g->win_height = i;
}
