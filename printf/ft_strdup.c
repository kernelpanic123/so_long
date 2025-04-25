/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:03:16 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 00:47:19 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdupe(const	char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
