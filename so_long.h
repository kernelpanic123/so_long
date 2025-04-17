/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:32:54 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/18 01:25:48 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <stdlib.h>

char **parse_map(void);
char *ft_strcpy(char *dest, char *src);
int	count_lines(void);
int parse_player(char **map);
int parse_square_map(char **map);

#endif