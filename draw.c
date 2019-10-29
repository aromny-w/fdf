/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:30:46 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/29 21:42:14 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setpixel(t_fdf *info, int x, int y, int color)
{
	int	*image;

	image = (int *)info->data_addr;
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
		image[x + y * WIDTH] = color;
}

static void	drawline(t_fdf *info, t_point s1, t_point s2)
{
	int	delta[2];
	int	sign[2];
	int	error[2];

	delta[0] = abs(s1.x - s2.x);
	delta[1] = abs(s1.y - s2.y);
	sign[0] = s1.x < s2.x ? 1 : -1;
	sign[1] = s1.y < s2.y ? 1 : -1;
	error[0] = (delta[0] > delta[1] ? delta[0] : delta[1]) / 2;
	while (!(s1.x == s2.x && s1.y == s2.y))
	{
		setpixel(info, s1.x, s1.y, s1.color);
		error[1] = error[0];
		if (error[1] > -delta[0])
		{
			error[0] -= delta[1];
			s1.x += sign[0];
		}
		if (error[1] < delta[1])
		{
			error[0] += delta[0];
			s1.y += sign[1];
		}
	}
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
