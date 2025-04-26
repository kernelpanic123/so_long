/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:55:47 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 06:08:46 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc == 2)
	{
		if (name_valid(argv[1]) == 1)
		{
			ft_printf("Error\nName map error!\n");
			exit(0);
		}
		init_var_struct(&data);
		if (big_parse(&data) == 1)
		{	
			ft_printf("Error\nformat map invalid!\n");
			smol_free(&data);
		}
		data.mlx_ptr = mlx_init();
		initialize_window(&data);
		load_map_img(&data);
		draw_map(&data);
		mlx_key_hook(data.win_mlx_ptr, wich_input, &data);
		mlx_hook(data.win_mlx_ptr, 17, 0, exit_game, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
