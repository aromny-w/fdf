/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:11:25 by aromny-w          #+#    #+#             */
/*   Updated: 2019/11/01 17:22:59 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	terminate(t_fdf *info)
{
	destroystruct(info, 0, info->map.height);
	exit(EXIT_SUCCESS);
}

static void	project(int key, t_cam *cam, t_fdf *info)
{
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	if (key == 82)
		info->projection = parallel;
	if (key == 87)
		info->projection = isometric;
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
	if (key == 83 || key == 89)
		cam->gamma += 0.05;
	if (key == 85 || key == 92)
		cam->gamma -= 0.05;
}

int			hotkeys(int key, t_fdf *info)
{
	if (key == 82 || key == 87)
		project(key, &info->cam, info);
	if (key == 46)
		info->menu += !info->menu ? 1 : -1;
	if (key == 53)
		terminate(info);
	if (key >= 83 && key <= 92)
		rotate(key, &info->cam);
	if ((key == 69 || key == 78) || (key >= 123 && key <= 126))
		move(key, &info->cam);
	if (key == 116 && info->altitude > 0.05f)
		info->altitude -= 0.05f;
	if (key == 121)
		info->altitude += 0.05f;
	draw(info);
	return (0);
}
