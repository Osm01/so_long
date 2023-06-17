/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:06:34 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/16 18:29:18 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	read_map(t_game *t_g)
{
	t_g->fd = open(t_g->argv[1], O_RDONLY);
	if (t_g->fd < 0)
	{
		perror("Error read the file map");
		exit(EXIT_SUCCESS);
	}
}

int	count_much_allocation(t_game *t_g)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(t_g->fd);
	while (line)
	{
		count ++;
		free (line);
		line = get_next_line(t_g->fd);
	}
	close(t_g->fd);
	return (count);
}

void	ft_split_map(t_game *t_g)
{
	int		count;
	char	*line;
	int		i;

	i = 0;
	read_map(t_g);
	count = count_much_allocation(t_g);
	t_g->split_map = (char **)malloc((sizeof(char *) * (count + 1)));
	if (!t_g->split_map)
		return ;
	t_g->split_map[count] = (char *) NULL;
	read_map(t_g);
	while (i < count)
	{
		line = get_next_line(t_g->fd);
		if (line)
		{
			t_g->split_map[i ++] = ft_strdup(line);
			free (line);
		}
	}
	close(t_g->fd);
}
