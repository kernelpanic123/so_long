/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:32:54 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/19 00:34:48 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <stdlib.h>

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

#endif