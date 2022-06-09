/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:21 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 18:39:30 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_map(t_game *game)
{
	get_imgs(game);
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			50 * game->ln, 50 * game->width, "so_long");
	img_to_maps(game);
}

void	initial_x_y(t_game *game)
{
	int	j;
	int	i;
	int	count;

	count = 0;
	j = 0;
	i = 0;
	while (++i < game->width)
	{
		while (++j < game->ln)
		{
			if (game->map[i][j] == 'P')
			{
				count++;
				game->coord.y = i;
				game->coord.x = j;
			}
		}
		j = -1;
	}
}
