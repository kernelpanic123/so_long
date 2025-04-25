/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:11:44 by abtouait          #+#    #+#             */
/*   Updated: 2024/12/16 17:55:56 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a == -2147483648)
	{
		return (11);
	}
	if (a < 0)
	{
		a = -a;
		i++;
	}
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int	ft_print_dec(int nb)
{
	char	*str;
	int		i;

	str = ft_itoa(nb);
	i = 0;
	while (str[i] != '\0')
	{
		ft_print_putchar(str[i]);
		i++;
	}
	free(str);
	return (ft_length(nb));
}
