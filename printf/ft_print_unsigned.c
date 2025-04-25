/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:58:00 by abtouait          #+#    #+#             */
/*   Updated: 2024/12/14 19:07:39 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_length_positive(unsigned int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int c)
{
	if (c > 9)
		ft_print_unsigned(c / 10);
	ft_print_putchar(c % 10 + '0');
	return (ft_length_positive(c));
}
