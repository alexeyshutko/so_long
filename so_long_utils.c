/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:36 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 20:18:54 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strln(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	pars_map(t_game *game, char *name_map)
{
	game->width = 0;
	game->fd = open(name_map, O_RDONLY);
	game->str = get_next_line(game->fd);
	game->ln = ft_strln(game->str);
	while (game->str)
	{
		if (ft_strln(game->str) == game->ln)
		{
			game->pars_str = game->str;
			game->str = get_next_line(game->fd);
			free(game->pars_str);
		}
		else
			return (1);
		game->width++;
	}
	close(game->fd);
	return (0);
}

int	check_error_ber(char *str)
{
	int	count;
	int	lnstr;

	count = 0;
	lnstr = 0;
	lnstr = ft_strln(str) - 4;
	if (str[lnstr] == '.')
	{
		if (str[lnstr + 1] == 'b')
		{
			if (str[lnstr + 2] == 'e')
			{
				if (str[lnstr + 3] == 'r')
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

int	take_map(t_game *game, char *name_map)
{
	game->count = 0;
	game->fd = open(name_map, O_RDONLY);
	game->str = get_next_line(game->fd);
	game->map = (char **) malloc(sizeof(char *) * (game->width + 1));
	game->map[game->width] = NULL;
	while (game->str)
	{
		game->map[game->count] = game->str;
		game->str = get_next_line(game->fd);
		game->count++;
	}
	close(game->fd);
	return (0);
}
