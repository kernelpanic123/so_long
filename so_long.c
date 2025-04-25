/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:55:47 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/25 02:25:15 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_game data;

	data.mlx_ptr = mlx_init();
	init_var_struct(&data);
	initialize_window(&data);
	load_map_img(&data);
	draw_map(&data);
	mlx_key_hook(data.win_mlx_ptr, wich_input, &data);
    mlx_loop(data.mlx_ptr);
	return (0);
}