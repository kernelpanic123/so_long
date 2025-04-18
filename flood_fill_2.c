/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:00:53 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/19 01:37:48 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exit_reachable(char **map)
{
    int x_player;
    int y_player;
    int x_exit;
	int y_exit;
	
    x_player = find_x_player(map);
    y_player = find_y_player(map);
    x_exit = find_x_exit(map);
    y_exit = find_y_exit(map);
    flood_fill(map, y_player, x_player);
    if (map[y_exit][x_exit] != 'V' || item_reachable(map) == 1)
        return (1);
	
    return (0);
    
}
int item_reachable(char **map)
{
    int	i;
	int	j;
	
	i = 0;
    while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int open_map(char *str)
{
	int fd;
	
	if (!str)
		return (1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}
int	check_elem(char **map)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\n')
		{
			if ((map[i][j] == 'E') || (map[i][j] == 'P') || (map[i][j] == 'C')
			|| (map[i][j] == '0') || (map[i][j] == '1'))
				j++;
			else
				return(1);
		}
		j = 0;
		i++;	
	}
	return (0);
}
int big_parse(char **map)
{
	if (parse_player(map) != 1)
		return (1);
	if (check_elem(map) != 0)
		return (1);
	if (parse_square_map(map) != 0)
		return (1);
	if (closed_map(map) != 0)
		return (1);
	if (parse_exit(map) != 1)
		return (1);
	if (exit_reachable(map) != 0)
		return (1);
	if (parse_item(map) < 1)
		return (1);
	return (0);
}
