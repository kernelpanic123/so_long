/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:00:53 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 05:48:53 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_reachable(t_game *data)
{
	int	x_player;
	int	y_player;
	int	x_exit;
	int	y_exit;

	x_player = find_x_player(data);
	y_player = find_y_player(data->map);
	x_exit = find_x_exit(data->map);
	y_exit = find_y_exit(data->map);
	flood_fill(data->map_flooded, y_player, x_player);
	if (data->map_flooded[y_exit][x_exit] != 'V' || item_reachable(data) == 1)
		return (1);
	return (0);
}

int	item_reachable(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_flooded[i] != NULL)
	{
		j = 0;
		while (data->map_flooded[i][j] != '\0')
		{
			if (data->map_flooded[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	open_map(char *str)
{
	int	fd;

	if (!str)
		return (1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

int	check_elem(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\n')
		{
			if ((data->map[i][j] == 'E') || (data->map[i][j] == 'P')
				|| (data->map[i][j] == 'C')
					|| (data->map[i][j] == '0') || (data->map[i][j] == '1'))
				j++;
			else
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	big_parse(t_game *data)
{
	if (parse_player(data) != 1)
		return (1);
	if (check_elem(data) != 0)
		return (1);
	if (parse_square_map(data) != 0)
		return (1);
	if (closed_map(data) != 0)
		return (1);
	if (parse_exit(data) != 1)
		return (1);
	if (exit_reachable(data) != 0)
		return (1);
	if (parse_item(data) < 1)
		return (1);
	return (0);
}
