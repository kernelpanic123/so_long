/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:11:16 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/18 23:41:18 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(void)
{
	int		fd = open("map.ber", O_RDONLY);
	int		count = 0;
	char	*line;

	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		free(line);
		count++;
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
int parse_player(char **map)
{
	int i;
	int	j;
	int	nbr_of_player;

	i = 0;
	j = 0;
	nbr_of_player = 0;
	map = parse_map();
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
		if (map[i][j] == 'P')
			nbr_of_player = nbr_of_player + 1;
		j++;
		}
		i++;
		j = 0;
	}
	return (nbr_of_player);
}
int parse_square_map(char **map)
{
	int i;
	int	size_next_line;

	i = 0;
	map = parse_map();
	while (map[i] != NULL)
	{
		size_next_line = ft_strlen(map[0]);
		if (size_next_line != ft_strlen(map[i]))
			return (1);
		i++;
	}
	if (i == ft_strlen(map[0]) - 1)
		return (1);
	return (0);
}
int closed_map(char **map)
{
	int	i;
	int j;
	int height;
	
	height = count_lines() - 1;
	j = 0;
	while (j <= ft_strlen(map[0]) - 2)
	{

		if (map[0][j] != '1' || map[height][j] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}
