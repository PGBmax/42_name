/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:04:36 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/10 12:58:41 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	x_while(int x_pos, int y_pos, int x, int y)
{
	while (x_pos <= x)
	{
		if ((x_pos == 1 && y_pos == y && y > 1)
			|| (x_pos == x && y_pos == 1 && x > 1))
			ft_putchar('\\');
		else if ((x_pos == 1 && y_pos == 1) || (x_pos == x && y_pos == y))
			ft_putchar('/');
		else if (x_pos == 1 || x_pos == x || y_pos == 1 || y_pos == y)
			ft_putchar('*');
		else
			ft_putchar(' ');
		x_pos++;
	}
	return (x_pos);
}

void	rush(int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = 1;
	y_pos = 1;
	while (y_pos <= y)
	{
		x_pos = 1;
		x_pos = x_while(x_pos, y_pos, x, y);
		y_pos++;
		ft_putchar('\n');
	}
}
