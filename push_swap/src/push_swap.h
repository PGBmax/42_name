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
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	struct t_list	*a;
	struct t_list	*b;
}	t_stack;

void	*ft_bzero(void *s, size_t n)
void	*ft_calloc(size_t nmemb, size_t size)
void	ft_error(int argc, char **argv)
void	check_integers(int argc, char **argv)
void	check_int_size(int argc, char **argv)
void	check_for_doubles(t_list *a)
t_list	*create_list(int argc, char **argv)
t_list	*ft_newnode(int content)
void	ft_clearnodes(t_list **lst)
int		ft_listsize(t_list *head)
t_list	*ft_lstlast(t_list *head)

void	ft_push(t_stack *stacks, char c)
void	ft_p(t_stack *stacks, char c)
void	ft_one_b(t_stack *stacks)
void	ft_empty_b(t_stack *stacks)

void	ft_rotate(t_stack *stacks, char c)
void	ft_r(t_stack *stacks, t_list *list, char c, int check)

void	ft_rrotate(t_stack *stacks, char c)
void	ft_rr(t_stack *stacks, t_list *list, int check)

void	ft_swap(t_stack *stacks, char c)
void	ft_s(t_list *list, char c, int check)

#endif