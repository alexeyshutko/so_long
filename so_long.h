/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:57:30 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/06/08 17:52:09 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>

# define CEL_SIZE 16

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
}	t_imgs;

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
}	t_mlx;

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_game
{
	int		fd;
	int		ln;
	char	*str;
	char	*pars_str;
	int		width;
	char	**map;
	int		count;
	int		coin;
	t_mlx	mlx;
	t_coord	coord;
	t_imgs	imgs;
	int		moves;
	int		i;
	int		j;
}	t_game;

int		ft_strln(char *str);
int		pars_map(t_game *game, char *str);
int		check_error_ber(char *str);
int		check_error_1(t_game *game, int i, int j, char a);
int		take_map(t_game *game, char *str);
void	write_error(void);
int		ex_exit(void *param);
void	check_map_valid(t_game *game);
int		check_error_character(t_game *game, int i, int j);
int		key_hook(int keycode, t_game *game);
void	move(t_game *game, int x, int y);
void	print_move(t_game *game);
int		get_imgs(t_game *game);
void	img_to_maps_1(t_game *game, char a);
void	img_to_maps(t_game *game);
void	initial_map(t_game *game);
void	initial_x_y(t_game *game);

#endif