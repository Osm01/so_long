/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:14:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/07 15:05:08 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook_manager(int keycode, t_game *t_g)
{
	if (keycode == 53)
		return (free_all(t_g), exit(EXIT_SUCCESS), 0);
	move_manager(keycode, t_g);
	return (1);
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

int	close_window(t_game *t_g)
{
	free_all(t_g);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_values(t_game *t_g, char const *argv[])
{
	t_g->argv = argv;
	t_g->count_move = 0;
	t_g->timer = 0;
	t_g->coin_trigger = 0;
	ft_split_map(t_g);
	if (!count_enemys(t_g))
	{
		return (free_2d_array(t_g->split_map), free(t_g), \
		ft_printf("Error there is no enemy on the map , (*_*)\n"), \
		exit(EXIT_FAILURE));
	}
	t_g->t_ep = get_enemys_positions(t_g);
	t_g->coin_count = count_coins(t_g);
	t_g->count_enemy = count_enemys(t_g);
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
	free (t_g->move_up_enemy);
	free (t_g->t_ep);
	free (t_g);
}
