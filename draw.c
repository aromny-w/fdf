/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:30:46 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/28 23:32:37 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawline(t_fdf *info, t_point s1, t_point s2)
{
	;
}

void		draw(t_fdf *info)
{
	int	i;
	int	j;

	j = -1;
	while (++j < info->map.height)
	{
		i = -1;
		while (++i < info->map.width)
		{
			if (i + 1 < info->map.width)
				drawline(info, info->map.matrix[j][i], info->map.matrix[j][i + 1]);
			if (j + 1 < info->map.height)
				drawline(info, info->map.matrix[j][i], info->map.matrix[j + 1][i]);
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
}
