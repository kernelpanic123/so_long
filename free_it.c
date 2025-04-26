/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:18:58 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 05:43:00 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *data)
{
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		free(data->map[j]);
		j++;
	}
	free(data->map);
	j = 0;
	while (data->map_flooded[j] != NULL)
	{
		free(data->map_flooded[j]);
		j++;
	}
	free(data->map_flooded);
}

void	free_mlx(t_game *data)
{
	if (data->img_collectible != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_collectible);
	if (data->img_exit != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
	if (data->img_floor != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_floor);
	if (data->img_player != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (data->img_wall != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
	if (data->mlx_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_mlx_ptr);
}

void	init_var_struct(t_game *data)
{
	data->map = parse_map();
	data->map_flooded = parse_map();
	data->x_player = find_x_player(data);
	data->y_player = find_y_player(data->map);
	data->nbr_item = parse_item(data);
	data->x_exit = find_x_exit(data->map);
	data->y_exit = find_y_exit(data->map);
	data->nbr_mouv = 1;
}

void	smol_free(t_game *data)
{
	free_map(data);
	exit(1);
}

int	exit_game(t_game *data)
{
	free_mlx(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data);
	exit(1);
	return (0);
}
