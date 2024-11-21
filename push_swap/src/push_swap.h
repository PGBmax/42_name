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

typedef struct values
{
	int	min_move;
	int	best_index;
	int index;
	int	indexb_help;
}	t_values;

void	ft_lstadd_back(t_list **list, t_list *new);
void	 ft_lstadd_front(t_list **list, t_list *new);
void	 ft_lstclear(t_list **list);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *list);

int		ft_get_max(t_list *list);
int		ft_get_min(t_list *list);
int		fake_rotate(t_list **list, int *place);
int		fake_rrotate(t_list **list, int *place);
int		ft_find_index_max(t_list *list);
int		ft_find_index_min(t_list *list);

void	ft_do_move(t_list **a, t_list **b, int indexa, int indexb);
int		t_find_num(t_list *stk, int num);
void	ft_sort_three(t_list **a);
int		ft_get_place(t_list *stk, int num);
void	ft_empty_b(t_list **a, t_list **b);

t_list	*create_list(int ac, char **av);
void	ft_replace_list(t_list **list, int index);
int		ft_move_list(t_list **a, t_list **b, int index, int *indexb_help);

void	ft_sorting(t_list **a, t_list **b);
int		ft_sorted(t_list	*list);
int		ft_double(int ac, char **av);
void	ft_do_rrr(t_list **a, t_list **b, int *indexa, int *indexb);

int		ft_get_index_a(t_list **a, t_list **b, int *indexb);
int		ft_get_index_b(t_list **a, t_list **b);
void	ft_set_values(t_values *vals, int temp, int *indb, int bst_index);

int		ft_swap(t_list	**list, char c, int check);
int		ft_push(t_list **a, t_list **b, char c, int check);
int		ft_rotate(t_list **list, int *index, char c, int check);
int		ft_reverse_rotate(t_list **list, int *index, char c, int check);

#endif