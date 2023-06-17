/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:12:32 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/01 19:41:07 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*paths[5];
	char const	**argv;
	char		**split_map;
	int			fd;
	int			img_width;
	int			img_height;
	int			win_width;
	int			win_height;
	int			x_coor;
	int			y_coor;
	int			count_move;
	int			coin_trigger;
	int			coin_count;
}	t_game;

typedef struct s_position_player
{
	int		x_coor;
	int		y_coor;
}	t_position_player;

enum {
	MOVE_KEY_UP = 13,
	MOVE_KEY_DOWN = 1,
	MOVE_KEY_RIGHT = 2,
	MOVE_KEY_LEFT = 0
};

t_position_player	get_position_player(t_game *t_g);
void				set_destination_position_and_set_textures(t_game *t_g, \
t_position_player t_pp, int d_xpz, int d_ypz);
void				ft_split_map(t_game *t_g);
void				read_map(t_game *t_g);
int					key_hook_manager(int keycode, t_game *t_g);
void				calculate_width_height_window(t_game *t_g);
void				set_textures_by_position(t_game *t_g);
void				move_manager(int keycode, t_game *t_g);
int					count_coins(t_game *t_g);
void				up_move(t_game *t_g, t_position_player t_pp);
void				down_move(t_game *t_g, t_position_player t_pp);
void				right_move(t_game *t_g, t_position_player t_pp);
void				left_move(t_game *t_g, t_position_player t_pp);
void				game_over(t_game *t_g, t_position_player t_pp);
int					check_one_exit_coll_start(t_game *t_g);
int					check_surrounded_by_wall(t_game *t_g);
int					check_rectangle(t_game *t_g);
int					check_flood_fill(t_game *t_g);
int					check_file_extension(char const *argv[]);
int					close_window(t_game *t_g);
void				init_values(t_game *t_g, char const *argv[]);
void				free_all(t_game *t_g);
void				free_2d_array(char **array);
char				**ft_split(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_substrr(char const *s, unsigned int start, size_t len);
size_t				ft_strlenn(char const *str);

#endif