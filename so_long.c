/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:53 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 18:36:21 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	else
	{
		if (check_error_ber(argv[1]) != 1)
			write_error();
		i = pars_map(&game, argv[1]);
		if (i == 1)
			write_error();
		take_map(&game, argv[1]);
		check_map_valid(&game);
		initial_x_y(&game);
		game.mlx.mlx = mlx_init();
		initial_map(&game);
		mlx_hook(game.mlx.mlx_win, 2, 0L, key_hook, &game);
		mlx_hook(game.mlx.mlx_win, 17, 1L << 0, ex_exit, &game);
		mlx_loop(game.mlx.mlx);
	}
	return (0);
}
