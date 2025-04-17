/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:55:47 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/18 01:31:38 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	char ** map;
	int i;
	
	i = 0;
	map = parse_map();
	printf("%d", parse_square_map(map));
	printf("%d", ft_strlen(map[i]));
	printf("%d", count_lines());
	
	return (0);
}