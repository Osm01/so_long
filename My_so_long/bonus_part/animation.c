/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:55:06 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/07 15:03:25 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_to_screen(t_game *t_g)
{
	char	*string;
	char	*count_move;

	count_move = ft_itoa(t_g->count_move);
	string = ft_strjoin_normal("Move count :", count_move);
	mlx_string_put(t_g->mlx_ptr, t_g->win_ptr, 0, 0, 255, string);
	free (string);
	free (count_move);
}

void	move_enemy_up_down(t_game *t_g, int index)
{
	int	x;
	int	y;

	if (t_g->move_up_enemy[index])
	{
		y = (t_g->t_ep[index].y_coor / 50) - 1;
		x = t_g->t_ep[index].x_coor / 50;
		if (t_g->split_map[y][x] == 'P' || t_g->split_map[y + 1][x] == 'P')
			return (ft_printf("Game over\n"), free_all(t_g), exit(EXIT_SUCCESS));
		if (t_g->split_map[y][x] == '1' || t_g->split_map[y][x] == 'C' \
		|| t_g->split_map[y][x] == 'E')
			t_g->move_up_enemy[index] = 0;
	}
	else
	{
		y = (t_g->t_ep[index].y_coor / 50) + 1;
		x = t_g->t_ep[index].x_coor / 50;
		if (t_g->split_map[y][x] == 'P' || t_g->split_map[y - 1][x] == 'P')
			return (ft_printf("Game over\n"), free_all(t_g), exit(EXIT_SUCCESS));
		if (t_g->split_map[y][x] == '1' || t_g->split_map[y][x] == 'C' \
		|| t_g->split_map[y][x] == 'E')
			t_g->move_up_enemy[index] = 1;
	}	
}

void	move_enemy(t_game *t_g, int index)
{
	move_enemy_up_down(t_g, index);
	if (t_g->move_up_enemy[index])
	{
		t_g->split_map[(t_g->t_ep[index].y_coor / 50) - 1] \
		[t_g->t_ep[index].x_coor / 50] = 'X';
		t_g->t_ep[index].y_coor -= 50;
		t_g->split_map[(t_g->t_ep[index].y_coor / 50)] \
		[t_g->t_ep[index].x_coor / 50] = '0';
	}
	else
	{
		t_g->split_map[(t_g->t_ep[index].y_coor / 50) + 1] \
		[t_g->t_ep[index].x_coor / 50] = 'X';
		t_g->t_ep[index].y_coor += 50;
		t_g->split_map[(t_g->t_ep[index].y_coor / 50)] \
		[t_g->t_ep[index].x_coor / 50] = '0';
	}
}

void	enemy_animation_move_manager(t_game *t_g, int *index, int count)
{
	int				i;

	i = 0;
	while (i < count)
		move_enemy(t_g, i ++);
	mlx_clear_window(t_g->mlx_ptr, t_g->win_ptr);
	t_g->x_coor = 0;
	t_g->y_coor = 0;
	set_textures_by_position(t_g);
	i = 0;
	while (i < count)
	{
		display_image_with_coor(t_g, t_g->animation_path[*index], \
		t_g->t_ep[i].x_coor, t_g->t_ep[i].y_coor);
		i ++;
	}
	*index = *index + 1;
}

int	animation(t_game *t_g)
{
	static int			i = 0;

	print_to_screen(t_g);
	if (t_g->timer == 0)
		enemy_animation_move_manager(t_g, &i, t_g->count_enemy);
	if (t_g->timer == 20)
		enemy_animation_move_manager(t_g, &i, t_g->count_enemy);
	if (t_g->timer == 40)
		enemy_animation_move_manager(t_g, &i, t_g->count_enemy);
	if (t_g->timer == 60)
		enemy_animation_move_manager(t_g, &i, t_g->count_enemy);
	if (t_g->timer > 60)
	{
		t_g->timer = 0;
		i = 0;
	}
	t_g->timer ++;
	return (0);
}
