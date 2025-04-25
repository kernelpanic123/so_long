/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:56:55 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 00:47:13 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
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

static char	*conversion(char *str, int r, int o)
{
	int	i;

	i = o - 1;
	while (r > 0)
	{
		str[i] = r % 10 + '0';
		r = r / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		o;

	o = ft_length(n);
	if (n == 0)
		return (ft_strdupe("0"));
	if (n == -2147483648)
		return (ft_strdupe("-2147483648"));
	new_str = malloc((o + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	if (n < 0)
	{
		new_str[0] = '-';
		n = -n;
	}
	conversion(new_str, n, o);
	new_str[o] = '\0';
	return (new_str);
}
