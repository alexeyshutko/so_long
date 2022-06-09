/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:09 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 20:39:43 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_imgs(t_game *game)
{
	int	a;

	a = 50;
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx.mlx, "./images/wall.xpm",
			&a, &a);
	game->imgs.floor = mlx_xpm_file_to_image(game->mlx.mlx,
			"./images/floor.xpm", &a, &a);
	game->imgs.player = mlx_xpm_file_to_image((void *)game->mlx.mlx,
			"./images/player.xpm", &a, &a);
	game->imgs.coin = mlx_xpm_file_to_image(game->mlx.mlx,
			"./images/coin.xpm", &a, &a);
	game->imgs.exit = mlx_xpm_file_to_image(game->mlx.mlx, "./images/exit.xpm",
			&a, &a);
	return (1);
}

void	img_to_maps_1(t_game *game, char a)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->imgs.floor, (50 * game->j), (50 * game->i));
	if (a == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->imgs.player, (50 * game->j), (50 * game->i));
	}
	if (a == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->imgs.coin, (50 * game->j),
			(50 * game->i));
	}
	if (a == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->imgs.exit, (50 * game->j), (50 * game->i));
	}
}

void	img_to_maps(t_game *game)
{
	game->i = 0;
	game->j = 0;
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j] != '\0')
		{
			if (game->map[game->i][game->j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
					game->imgs.wall, (50 * game->j), (50 * game->i));
			if (game->map[game->i][game->j] == '0')
				img_to_maps_1(game, '0');
			if (game->map[game->i][game->j] == 'P')
				img_to_maps_1(game, 'P');
			if (game->map[game->i][game->j] == 'C')
				img_to_maps_1(game, 'C');
			if (game->map[game->i][game->j] == 'E')
				img_to_maps_1(game, 'E');
			game->j++;
		}
		game->i++;
	}
}
