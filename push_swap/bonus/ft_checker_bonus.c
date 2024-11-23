/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:30:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 13:42:55 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

t_list	*create_a(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	av = ft_clean_args(&ac, av);
	if (!av || ft_has_double(av, ac)
		|| ft_create_list(ac, av, &a) == 0)
	{
		ft_clean_all(a, NULL, av);
		ft_printf("Error\n");
		return (NULL);
	}
	ft_clean_all(NULL, NULL, av);
	return (a);
}

char	**ft_get_movelist(int argc)
{
	char	*tp;
	char	*tp_moves;
	char	**moves;
	int		i;
	int		j;

	tp = get_next_line(0);
	tp_moves = NULL;
	i = -1;
	while (tp != NULL)
	{
		tp_moves = ft_strlcat(tp_moves, tp, 1);
		free(tp);
		tp = get_next_line(0);
	}
	free(tp);
	moves = ft_split(tp_moves, (char)*"\n", &argc);
	free(tp_moves);
	while (moves && moves[++i] != 0)
	{
		j = -1;
		while (moves[i][++j] != 0)
			moves[i][j] = moves[i][j + 1];
	}
	return (moves);
}

int	ft_do_moves(t_list **a, t_list **b, char *move)
{
	if (ft_strncmp("rr", move, ft_strlen(move)) == 0)
		return (ft_rr(a, b));
	if (ft_strncmp("rrr", move, ft_strlen(move)) == 0)
		return (ft_rrr(a, b));
	if (ft_strncmp("ss", move, ft_strlen(move)) == 0)
		return (ft_ss(a, b));
	if (ft_strncmp("ra", move, ft_strlen(move)) == 0)
		return (ft_rotate(a, NULL,'a', 0));
	if (ft_strncmp("rb", move, ft_strlen(move)) == 0)
		return (ft_rotate(b, NULL,'b', 0));
	if (ft_strncmp("rra", move, ft_strlen(move)) == 0)
		return (ft_reverse_rotate(a, NULL,'a', 0));
	if (ft_strncmp("rrb", move, ft_strlen(move)) == 0)
		return (ft_reverse_rotate(b, NULL,'b', 0));
	if (ft_strncmp("pa", move, ft_strlen(move)) == 0)
		return (ft_push(a, b, 'a', 0));
	if (ft_strncmp("pb", move, ft_strlen(move)) == 0)
		return (ft_push(b, a, 'b', 0));
	if (ft_strncmp("sa", move, ft_strlen(move)) == 0)
		return (ft_swap(a, 'a', 0));
	if (ft_strncmp("sb", move, ft_strlen(move)) == 0)
		return (ft_swap(b, 'b', 0));
	return (0);
}

int	ft_error(t_list *a, t_list *b, char **moves)
{
	ft_clean_all(a, b, moves);
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	char	**moves;
	int		i;
	t_list	*a;
	t_list	*b;

	i = -1;
	b = NULL;
	if (argc == 1)
		return (0);
	a = create_a(argc, argv);
	if (a == NULL)
		return (ft_error(a, NULL, NULL));
	moves = ft_get_movelist(argc);
	if (moves == NULL && (!ft_is_sorted(a) || ft_lstsize(b) != 0))
		return (ft_error(a, NULL, moves));
	while (moves && moves[++i] != 0)
		if (ft_do_moves(&a, &b, moves[i]) == 0)
			return (ft_error(a, b, moves));
	if (!ft_is_sorted(a) || ft_lstsize(b) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_clean_all(a, b, moves);
	return (0);
}