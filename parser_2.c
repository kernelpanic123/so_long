/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:45:09 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/19 00:49:23 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int name_valid(char *str)
{
    int		i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r')
		return (1);
	i--;
	if (str[i] != 'e')
		return (1);
	i--;
	if (str[i] != 'b')
		return(1);
	i--;
	if (str[i] != '.')
		return(1);
	return (0);
}

int parse_exit(char **map)
{
	int i;
	int	j;
	int	nbr_exit;

	i = 0;
	j = 0;
	nbr_exit = 0;
	map = parse_map();
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
		if (map[i][j] == 'E')
			nbr_exit = nbr_exit + 1;
		j++;
		}
		i++;
		j = 0;
	}
	return (nbr_exit);
}
int parse_item(char **map)
{
	int i;
	int	j;
	int	nbr_item;

	i = 0;
	nbr_item = 0;
	map = parse_map();
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
		if (map[i][j] == 'C')
			nbr_item = nbr_item + 1;
		j++;
		}
		i++;
	}
	return (nbr_item);
}