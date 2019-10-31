/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:11:25 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/31 23:47:01 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	terminate(t_fdf *info)
{
	destroystruct(info, 0, info->map.height);
	exit(EXIT_SUCCESS);
}

static void	move(int key, t_cam *cam)
{
	if (key == 69 && cam->dist <= 100)
		cam->dist++;
	if (key == 78 && cam->dist > 1)
		cam->dist--;
	if (key == 123 && cam->x_offset <= WIDTH)
		cam->x_offset += 10;
	if (key == 124 && cam->x_offset >= -WIDTH)
		cam->x_offset -= 10;
	if (key == 125 && cam->y_offset >= -HEIGHT)
		cam->y_offset -= 10;
	if (key == 126 && cam->y_offset <= HEIGHT)
		cam->y_offset += 10;
}

static void	rotate(int key, t_cam *cam)
{
	if (key == 84)
		cam->alpha += 0.05;
	if (key == 91)
		cam->alpha -= 0.05;
	if (key == 86)
		cam->beta -= 0.05;
	if (key == 88)
		cam->beta += 0.05;
	if (key == 83 || key == 85)
		cam->gamma += 0.05;
	if (key == 89 || key == 92)
		cam->gamma -= 0.05;
}

int			hotkeys(int key, t_fdf *info)
{
	if (key == 37)
		info->map.legend += !info->map.legend ? 1 : -1;
	if (key == 53)
		terminate(info);
	if (key >= 83 && key <= 92)
		rotate(key, &info->cam);
	if ((key == 69 || key == 78) || (key >= 123 && key <= 126))
		move(key, &info->cam);
	draw(info);
	return (0);
}
