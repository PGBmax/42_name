/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:08:10 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/09 23:08:10 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

void	ft_sorting(t_list **a, t_list **b);

int		ft_swap(t_list	**list, char c, int check);
int		ft_push(t_list **a, t_list **b, char c, int check);
int		ft_rotate(t_list **list, int index, char c, int check);
int		ft_reverse_rotate(t_list **list, int index, char c, int check);

void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstadd_front(t_list **list, t_list *new);
void	ft_lstclear(t_list **list);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *list);

#endif