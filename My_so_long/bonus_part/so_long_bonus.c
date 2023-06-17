/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:45:59 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/16 18:30:54 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_textures_paths(t_game *t_p)
{
	t_p->paths[0] = "textures/player.xpm";
	t_p->paths[1] = "textures/wall.xpm";
	t_p->paths[2] = "textures/coin.xpm";
	t_p->paths[3] = "textures/exit.xpm";
	t_p->animation_path[0] = "textures/enemy_images/enemy01.xpm";
	t_p->animation_path[1] = "textures/enemy_images/enemy02.xpm";
	t_p->animation_path[2] = "textures/enemy_images/enemy03.xpm";
	t_p->animation_path[3] = "textures/enemy_images/enemy04.xpm";
}

void	display_image_with_coor(t_game *t_g, char	*path, \
int x_coor, int y_coor)
{
	t_g->img = mlx_xpm_file_to_image(t_g->mlx_ptr, path, \
	&t_g->img_width, &t_g->img_height);
	if (t_g->img == NULL)
	{
		perror("Error load image");
		exit (1);
	}
	mlx_put_image_to_window(t_g->mlx_ptr, t_g->win_ptr, \
	t_g->img, x_coor, y_coor);
}

void	set_coor(t_game *t_g, int i, int y)
{
	if (t_g->split_map[i][y] == '1')
		display_image_with_coor(t_g, t_g->paths[1], \
		t_g->x_coor, t_g->y_coor);
	if (t_g->split_map[i][y] == 'C')
		display_image_with_coor(t_g, t_g->paths[2], \
		t_g->x_coor, t_g->y_coor);
	if (t_g->split_map[i][y] == 'E')
		display_image_with_coor(t_g, t_g->paths[3], \
		t_g->x_coor, t_g->y_coor);
	if (t_g->split_map[i][y] == 'P')
		display_image_with_coor(t_g, t_g->paths[0], \
		t_g->x_coor, t_g->y_coor);
}

void	set_textures_by_position(t_game *t_g)
{
	int		i;
	int		y;

	i = 0;
	while (t_g->split_map[i])
	{
		y = 0;
		t_g->x_coor = 0;
		while (t_g->split_map[i][y])
		{
			set_coor(t_g, i, y);
			t_g->x_coor += 50;
			y ++;
		}
		t_g->y_coor += 50;
		i ++;
	}
}

int	main(int argc, char const *argv[])
{
	t_game	*t_g;

	if (argc == 2)
	{
		if (!check_file_extension(argv))
			return (ft_printf("Error file extension\n"), exit(1), 0);
		t_g = (t_game *) malloc(sizeof(t_game));
		if (!t_g)
			return (exit(EXIT_FAILURE), 0);
		init_values(t_g, argv);
		if (!check_rectangle(t_g) || !check_one_exit_coll_start(t_g) \
		|| !check_surrounded_by_wall(t_g) || !check_flood_fill(t_g))
			return (ft_printf("Error map\n"), exit(1), EXIT_FAILURE);
		t_g->mlx_ptr = mlx_init();
		calculate_width_height_window(t_g);
		t_g->win_ptr = mlx_new_window(t_g->mlx_ptr, t_g->win_width * 50, \
		t_g->win_height * 50, "The Game");
		set_textures_paths(t_g);
		set_textures_by_position(t_g);
		mlx_hook(t_g->win_ptr, 17, 1L << 2, &close_window, t_g);
		mlx_hook(t_g->win_ptr, 2, 0, &key_hook_manager, t_g);
		mlx_loop_hook(t_g->mlx_ptr, &animation, t_g);
		mlx_loop(t_g->mlx_ptr);
	}
	return (EXIT_SUCCESS);
}
