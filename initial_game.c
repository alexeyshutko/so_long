/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:50:47 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 17:45:06 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		move(*(&game), 0, -1);
	if (keycode == 1 || keycode == 125)
		move(*(&game), 0, 1);
	if (keycode == 0 || keycode == 123)
		move(*(&game), -1, 0);
	if (keycode == 2 || keycode == 124)
		move(*(&game), 1, 0);
	return (0);
}

void	move(t_game *game, int x, int y)
{
	char	a;

	a = game->map[game->coord.y + y][game->coord.x + x];
	if (a == '0' || a == 'C')
	{
		if (a == 'C')
			game->coin--;
		game->map[game->coord.y + y][game->coord.x + x] = 'P';
		game->map[game->coord.y][game->coord.x] = '0';
		game->moves++;
		game->coord.x += x;
		game->coord.y += y;
		print_move(game);
		img_to_maps(game);
	}
	if (a == 'E')
	{
		if (game->coin == 0)
		{
			write(1, "YOU WIN\n", 8);
			exit(0);
		}
	}
}

void	print_move(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free (str);
}
