/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:30:23 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 14:54:02 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H

# include "../src/push_swap.h"
#
# include "GNL/get_next_line_bonus.h"

t_list	*create_a(int ac, char **av);
char	**ft_get_movelist(int argc);
int		ft_do_moves(t_list **a, t_list **b, char *move);
int		ft_error(t_list *a, t_list *b, char **moves);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_rr(t_list **a, t_list **b);
int		ft_rrr(t_list **a, t_list **b);
int		ft_ss(t_list **a, t_list **b);

#endif