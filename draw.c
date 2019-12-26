/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:30:46 by aromny-w          #+#    #+#             */
/*   Updated: 2019/11/26 20:19:57 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	printmenu(void *mlx_ptr, void *win_ptr)
{
	char	*menu[9];

	menu[0] = "            CONTROL MENU            ";
	menu[1] = " Arrows         Move camera         ";
	menu[2] = " +/-            Zoom camera         ";
	menu[3] = " Numpad 1-4/6-9 Rotate figure       ";
	menu[4] = " Numpad 0       Parallel projection ";
	menu[5] = " Numpad 5       Isometric projection";
	menu[6] = " Page Up/Down   Altitude change     ";
	menu[7] = " M              Menu                ";
	menu[8] = " Esc            Exit                ";
	mlx_string_put(mlx_ptr, win_ptr, 815, 700, WHITE, menu[0]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 730, WHITE, menu[1]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 745, WHITE, menu[2]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 760, WHITE, menu[3]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 775, WHITE, menu[4]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 790, WHITE, menu[5]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 805, WHITE, menu[6]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 820, WHITE, menu[7]);
	mlx_string_put(mlx_ptr, win_ptr, 815, 835, WHITE, menu[8]);
}

static void	drawmenu(t_fdf *info)
{
	size_t	x;
	size_t	y;

	y = 699;
	while (++y < 860)
	{
		x = 814;
		while (++x < 1185)
		{
			if ((x == 815 || y == 700) || (x == 1184 || y == 859))
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
	int	delta[2];
	int	step[2];
	int	error[2];

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
