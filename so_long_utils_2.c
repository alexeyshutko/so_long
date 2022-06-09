/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:29 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 17:37:59 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_valid(t_game *game)
{
	int	i;

	i = 0;
	i = check_error_1(game, 0, 0, '1');
	if (i == 1)
		write_error();
	i = check_error_character(game, -1, -1);
	if (i == 1)
		write_error();
}

int	check_error_1(t_game *game, int i, int j, char a)
{
	while (game->map[(game->width - 1)][j] != '\0' && game->map[0][i] != '\n')
	{
		if (a == game->map[0][i])
			i++;
		if (a == game->map[(game->width - 1)][j])
			j++;
		else
			return (1);
	}
	i = 0;
	j = 0;
	while (i != game->width && j != game->width)
	{
		if (a == game->map[i][0])
			i++;
		if (a == game->map[j][game->ln - 1])
			j++;
		else
			return (1);
	}
	return (0);
}

int	check_error_character(t_game *game, int i, int j)
{
	int	count_p;
	int	count_e;

	game->coin = 0;
	count_p = 0;
	count_e = 0;
	while (++i < game->width)
	{
		while (++j < game->ln)
		{
			if (game->map[i][j] == 'P')
				count_p++;
			if (game->map[i][j] == 'E')
				count_e++;
			if (game->map[i][j] == 'C')
				game->coin++;
			if (count_e > 1 || count_p > 1)
				write_error();
		}
		j = -1;
	}
	if (game->coin == 0 || count_p == 0 || count_e == 0)
		write_error();
	return (0);
}

void	write_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ex_exit(void *param)
{
	(void) param;
	exit(0);
	return (0);
}
