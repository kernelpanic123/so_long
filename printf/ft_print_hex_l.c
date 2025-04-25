/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:20:42 by abtouait          #+#    #+#             */
/*   Updated: 2024/12/15 13:49:19 by abtouait         ###   ########.fr       */
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

void	ft_convert_hex_l(unsigned int a)
{
	if (a >= 16)
	{
		ft_convert_hex_l(a / 16);
		ft_convert_hex_l(a % 16);
	}
	else
	{
		if (a <= 9)
			ft_print_unsigned(a);
		else
		{
			ft_print_putchar((a - 10 + 'a'));
		}
	}
}

int	ft_print_hex_l(unsigned int a)
{
	ft_convert_hex_l(a);
	return (ft_length_hex(a));
}
