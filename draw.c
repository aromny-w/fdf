/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:30:46 by aromny-w          #+#    #+#             */
/*   Updated: 2019/11/01 16:11:58 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	printmenu(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 1000, 700, WHITE, "        MENU         ");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 730, WHITE, "Arrows       Move cam");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 745, WHITE, "+/-          Zoom cam");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 760, WHITE, "Numpad       Rotate  ");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 775, WHITE, "Page Up/Down Altitude");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 790, WHITE, "M            Menu    ");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 805, WHITE, "Esc          Exit    ");
}

static void	drawmenu(t_fdf *info)
{
	size_t	x;
	size_t	y;

	y = 699;
	while (++y < 825)
	{
		x = 999;
		while (++x < 1215)
		{
			if ((x == 1000 || y == 700) || (x == 1214 || y == 824))
				info->data_addr[x + y * WIDTH] = WHITE;
			else
				info->data_addr[x + y * WIDTH] = BLACK;
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	printmenu(info->mlx_ptr, info->win_ptr);
}

static void	drawline(t_fdf *info, t_point p1, t_point p2)
{
	int		delta[2];
	int		step[2];
	int		error[2];

	delta[0] = ft_abs(p1.x - p2.x);
	delta[1] = ft_abs(p1.y - p2.y);
	step[0] = p1.x < p2.x ? 1 : -1;
	step[1] = p1.y < p2.y ? 1 : -1;
	error[0] = (delta[0] > delta[1] ? delta[0] : -delta[1]) / 2;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		if ((p1.x >= 0 && p1.x < WIDTH) && (p1.y >= 0 && p1.y < HEIGHT))
			info->data_addr[p1.x + p1.y * WIDTH] = p1.color;
		error[1] = error[0];
		if (error[1] > -delta[0])
		{
			error[0] -= delta[1];
			p1.x += step[0];
		}
		if (error[1] < delta[1])
		{
			error[0] += delta[0];
			p1.y += step[1];
		}
	}
}

void		draw(t_fdf *info)
{
	int	i;
	int	j;

	ft_bzero(info->data_addr, info->size_line * HEIGHT);
	j = -1;
	while (++j < info->map.height)
	{
		i = -1;
		while (++i < info->map.width)
		{
			if (i + 1 < info->map.width)
				drawline(info,
				pointproject(info, info->map.matrix[j][i]),
				pointproject(info, info->map.matrix[j][i + 1]));
			if (j + 1 < info->map.height)
				drawline(info,
				pointproject(info, info->map.matrix[j][i]),
				pointproject(info, info->map.matrix[j + 1][i]));
		}
	}
	if (info->menu)
		return (drawmenu(info));
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
}
