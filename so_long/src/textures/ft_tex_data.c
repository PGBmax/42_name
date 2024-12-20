/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:11:25 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:48:36 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_textures_data(t_textures *tex, t_game *game)
{
	tex->collec = ft_load_png("./text/collec.png", game);
	tex->ground = ft_load_png("./text/ground.png", game);
	tex->fground = ft_load_png("./texb/fake_ground.png", game);
	tex->exit = ft_load_png("./text/exit.png", game);
}
