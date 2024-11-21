/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycrapper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:02 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/21 17:56:24 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYCRAPPER_H
# define SKYCRAPPER_H

#include "ft_printf/ft_printf.h"

int		ft_print_plate(int *base, int *tvar, char *line, char *view);
int		ft_loop(int *base, int *tvar, char *line, char *view);
int		ft_prepare(char *view);
void	comb(int *tab);
void	cpy_line(int *i, int var, char *line);
char	*create_line(int a, int b, int c, int d);
void	create_column(char *line, char *column);
int		verif_echo(char *plate);
int		verif_left(char *plate, char view);
int		verif_right(char *plate, char view);
int		verif(char *line, char *view);
int		ft_error(void);

#endif