/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:56:06 by abtouait          #+#    #+#             */
/*   Updated: 2024/12/16 17:56:36 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_length_ptr(unsigned long int c)
{
	unsigned int	i;

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

void	ft_convert_hex_ptr(unsigned long int a)
{
	if (a >= 16)
	{
		ft_convert_hex_ptr(a / 16);
		ft_convert_hex_ptr(a % 16);
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

int	ft_print_ptr(unsigned long int n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_convert_hex_ptr(n);
	return (ft_length_ptr(n) + 2);
}
