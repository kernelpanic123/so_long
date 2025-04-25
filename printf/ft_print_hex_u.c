/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:49:26 by abtouait          #+#    #+#             */
/*   Updated: 2024/12/15 13:44:43 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_length_hex(unsigned int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 16;
		i++;
	}
	return (i);
}

void	ft_convert_hex_u(unsigned int b)
{
	if (b >= 16)
	{
		ft_convert_hex_u(b / 16);
		ft_convert_hex_u(b % 16);
	}
	else
	{
		if (b <= 9)
			ft_print_unsigned(b);
		else
		{
			ft_print_putchar((b - 10 + 'A'));
		}
	}
}

int	ft_print_hex_u(unsigned int b)
{
	ft_convert_hex_u(b);
	return (ft_length_hex(b));
}
