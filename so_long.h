/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:32:54 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 00:42:16 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include "ft_printf.h"

# define IMG_SIZE 64

typedef struct s_game
{   
    void 	*win_mlx_ptr;
    void 	*mlx_ptr;
    int 	x_player;
    int		y_player;
    void	*img;
    char	**map;
    void	*img_wall;
    void	*img_floor;
    void	*img_player;
    void	*img_exit;
    void	*img_collectible;
    int		img_square;
    int     nbr_item;
    int     x_exit;
    int     y_exit;
    int     nbr_mouv;

}t_game;

char **parse_map(void);
int	count_lines(void);
int parse_player(char **map);
int parse_square_map(char **map);
int closed_map(char **map);

//parser_2
int name_valid(char *str);
int parse_exit(char **map);
int parse_item(char **map);

//flood_fill
int find_x_player(char **map);
int find_y_player(char **map);
int find_x_exit(char **map);
int find_y_exit(char **map);
void flood_fill(char **map, int x, int y);

//flood_fill_2
int exit_reachable(char **map);
int item_reachable(char **map);
int big_parse(char **map);
int	check_elem(char **map);

//window
void initialize_window(t_game *data);
int wich_input(int keysim, t_game *data);
void load_map_img(t_game *data);
void draw_each_square(t_game *data, char indicator, int x, int y);
void draw_map(t_game *game);
void case_w_key(t_game *data);
void print_map(t_game *data);
void init_var_struct(t_game *data);

//handle_keys
void case_w_key(t_game *data);
void case_s_key(t_game *data);
void case_d_key(t_game *data);
void case_a_key(t_game *data);

#endif