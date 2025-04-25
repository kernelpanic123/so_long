/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:20:14 by abtouait          #+#    #+#             */
/*   Updated: 2025/04/26 00:47:00 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_print_putchar(int a);
int		ft_print_putstr(char *str);
int		ft_print_dec(int nb);
int		ft_print_unsigned(unsigned int c);
int		ft_print_hex_l(unsigned int a);
int		ft_print_hex_u(unsigned int b);
int		ft_print_ptr(unsigned long n);
int		ft_printf(const char *str, ...);
int		ft_print_pourcent(void);
char	*ft_itoa(int n);
char	*ft_strdupe(const	char *s1);

#endif
