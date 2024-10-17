/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:43:58 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/16 22:49:18 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n, int check);
int	ft_putstr(char *s);
int	ft_strlen(const char *s);
int ft_puthexa(unsigned long n, int uporlow);

#endif