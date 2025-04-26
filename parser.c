/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:11:16 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 05:32:19 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(void)
{
	int		fd;
	int		count;
	char	*line;

	fd = open("map.ber", O_RDONLY);
	count = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**parse_map(void)
{
	int		fd;
	char	*line;
	char	**arrays;
	int		i;
	int		total_lines;

	i = 0;
	total_lines = count_lines();
	arrays = malloc(sizeof(char *) * (total_lines + 1));
	if (!arrays)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		arrays[i] = line;
		i++;
		line = get_next_line(fd);
	}
	arrays[i] = NULL;
	close(fd);
	return (arrays);
}

int	parse_player(t_game *data)
{
	int		i;
	int		j;
	int		nbr_of_player;

	i = 0;
	j = 0;
	nbr_of_player = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				nbr_of_player = nbr_of_player + 1;
			j++;
		}
		i++;
		j = 0;
	}
	return (nbr_of_player);
}

int	parse_square_map(t_game *data)
{
	int	i;
	int	size_next_line;

	i = 0;
	while (data->map[i] != NULL)
	{
		size_next_line = ft_strlen(data->map[0]);
		if (size_next_line != ft_strlen(data->map[i]))
			return (1);
		i++;
	}
	if (i == ft_strlen(data->map[0]) - 1)
		return (1);
	return (0);
}

int	closed_map(t_game *data)
{
	int	i;
	int	j;
	int	height;

	height = count_lines() - 1;
	j = 0;
	while (j <= ft_strlen(data->map[0]) - 2)
	{
		if (data->map[0][j] != '1' || data->map[height][j] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i][0] != '1' ||
				data->map[i][ft_strlen(data->map[i]) - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}
