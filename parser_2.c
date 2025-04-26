/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:45:09 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 05:34:31 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_valid(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r')
		return (1);
	i--;
	if (str[i] != 'e')
		return (1);
	i--;
	if (str[i] != 'b')
		return (1);
	i--;
	if (str[i] != '.')
		return (1);
	return (0);
}

int	parse_exit(t_game *data)
{
	int	i;
	int	j;
	int	nbr_exit;

	i = 0;
	j = 0;
	nbr_exit = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'E')
				nbr_exit = nbr_exit + 1;
			j++;
		}
		i++;
		j = 0;
	}
	return (nbr_exit);
}

int	parse_item(t_game *data)
{
	int	i;
	int	j;
	int	nbr_item;

	i = 0;
	nbr_item = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'C')
				nbr_item = nbr_item + 1;
			j++;
		}
		i++;
	}
	return (nbr_item);
}
