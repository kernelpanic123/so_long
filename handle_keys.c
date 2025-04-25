/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:39:41 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 00:54:10 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void case_w_key(t_game *data)
{
    if (data->map[data->y_player - 1][data->x_player] == 'C')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->y_player = data->y_player - 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        data->nbr_item = data->nbr_item - 1;
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
    }
    else if (data->map[data->y_player - 1][data->x_player] == 'E' && data->nbr_item != 0)
        return ;
    else if (data->map[data->y_player - 1][data->x_player] != '1')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->y_player = data->y_player - 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;        
    }   
}
void case_s_key(t_game *data)
{   
    if (data->map[data->y_player + 1][data->x_player] == 'C')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->y_player = data->y_player + 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        data->nbr_item = data->nbr_item - 1;
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
    }
    else if (data->map[data->y_player + 1][data->x_player] == 'E' && data->nbr_item != 0)
        return ; 
    else if (data->map[data->y_player + 1][data->x_player] != '1')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->y_player = data->y_player + 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
                
    }   
}
void case_d_key(t_game *data)
{
    if (data->map[data->y_player][data->x_player + 1] == 'C')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->x_player = data->x_player + 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        data->nbr_item = data->nbr_item - 1;
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
    } 
    else if (data->map[data->y_player][data->x_player + 1] == 'E' && data->nbr_item != 0)
        return ;
    else if (data->map[data->y_player][data->x_player + 1] != '1')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->x_player = data->x_player + 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
                
    }   
}
void case_a_key(t_game *data)
{
    if (data->map[data->y_player][data->x_player - 1] == 'C')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->x_player = data->x_player - 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        data->nbr_item = data->nbr_item - 1;
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
    }
    else if (data->map[data->y_player][data->x_player - 1] == 'E' && data->nbr_item != 0)
        return ;
    else if (data->map[data->y_player][data->x_player - 1] != '1')
    {
        data->map[data->y_player][data->x_player] = '0';
        draw_each_square(data, '0', data->x_player, data->y_player);
        data->x_player = data->x_player - 1;
        data->map[data->y_player][data->x_player] = 'P';
        draw_each_square(data, 'P', data->x_player, data->y_player);
        ft_printf("total mouvement : %d\n", data->nbr_mouv);
        data->nbr_mouv = data->nbr_mouv + 1;
                
    }   
}

