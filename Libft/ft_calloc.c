/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:58:49 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/08 15:49:53 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
	unsigned char	*test;
	void			*alloc;
	size_t 			i;

	alloc = malloc((size + 1) * nmemb);
	test = (unsigned char *) alloc;
	i = 0;
	while (i <= size)
	{
		test[i] = 0;
		i++;
	}
	return (alloc);
}

int main(void)
{
	char *i;
	int a;

	a = 0;
	i = calloc(5, sizeof(int));
	while (a < 5)
	{
		printf("%d", i[a]);
		a++;
	}
}