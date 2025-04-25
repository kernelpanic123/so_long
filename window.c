/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:31:08 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/25 06:55:38 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_window(t_game *data)
{
    int     i;
    i = 0;
    data->win_mlx_ptr = mlx_new_window(data->mlx_ptr, (ft_strlen(data->map[i]) * 64), (count_lines() * 64), "so_long");
}

int wich_input(int keysim, t_game *data)
{
    if (keysim == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_mlx_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    else if (keysim == XK_w)
        case_w_key(data);
    else if (keysim == XK_a)
        case_a_key(data);
    else if (keysim == XK_d)
        case_d_key(data);
    else if (keysim == XK_s)
        case_s_key(data);
    if (data->map[data->y_exit][data->x_exit] != 'E')
    {
        mlx_destroy_window(data->mlx_ptr, data->win_mlx_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    return (0);
}

void load_map_img(t_game *data)
{
    int size;

    size = IMG_SIZE;
    data->img_collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./img/piece.xpm", &size, &size);
    data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit.xpm", &size, &size);
    data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "./img/sol.xpm", &size, &size);
    data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/player.xpm", &size, &size);
    data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm", &size, &size);
}
void draw_each_square(t_game *data, char indicator, int x, int y)
{
    void *img = NULL;
    
    if (indicator == '1')
        img = data->img_wall;
    else if (indicator == '0')
        img = data->img_floor;
    else if (indicator == 'P')
        img = data->img_player;
    else if (indicator == 'E')
        img = data->img_exit;
    else if (indicator == 'C')
        img = data->img_collectible;

    if (img != NULL)
        mlx_put_image_to_window(data->mlx_ptr, data->win_mlx_ptr, img,
             x * IMG_SIZE, y * IMG_SIZE);
}


void draw_map(t_game *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x] != '\0')
        {
            draw_each_square(data, data->map[y][x], x, y);
            x++;
        }
        y++;
    }
}

void print_map(t_game *data)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (data->map[j] != NULL)
    {
        while (data->map[j][i] != '\0')
        {
            printf("%c", data->map[j][i]);
            i++;
        }
        j++;
        i = 0;
    }
}
void init_var_struct(t_game *data)
{
    data->map = parse_map();
    data->x_player = find_x_player(data->map);
    data->y_player = find_y_player(data->map);
    data->nbr_item = parse_item(data->map);
    data->x_exit = find_x_exit(data->map);
    data->y_exit = find_y_exit(data->map);
    
}