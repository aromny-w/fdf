/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:46:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/27 19:34:35 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initmlx(t_fdf *info)
{
	if (!(info->mlx_ptr = mlx_init()) ||
		!(info->win_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, NAME)) ||
		!(info->img_ptr = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT)))
		destroystruct(info, 1, 0);
	info->data_addr = mlx_get_data_addr(info->img_ptr, &info->bits_per_pixel,
	&info->size_line, &info->endian);
	//
}
