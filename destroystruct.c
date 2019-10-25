/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroystruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:58:10 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/26 00:36:34 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroystruct(t_fdf *info)
{
	if (info->win_ptr)
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	if (info->img_ptr)
		mlx_destroy_image(info->mlx_ptr, info->img_ptr);
}
