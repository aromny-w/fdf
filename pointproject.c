/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointproject.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:12:17 by aromny-w          #+#    #+#             */
/*   Updated: 2019/11/01 16:14:17 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_point *prime, t_point point)
{
	prime->x = (point.x - point.y) * cos(30 * M_PI / 180);
	prime->y = (point.x + point.y) * sin(30 * M_PI / 180) - point.z;
	prime->z = point.z;
}

t_point		pointproject(t_fdf *info, t_point point)
{
	point.x *= info->cam.dist;
	point.y *= info->cam.dist;
	point.z *= info->cam.dist / info->altitude;
	point.x -= info->map.width * info->cam.dist / 2;
	point.y -= info->map.height * info->cam.dist / 2;
	pointrotate(&point, info->cam);
	isometric(&point, point);
	point.x += WIDTH / 2 + info->cam.x_offset;
	point.y += (HEIGHT + info->map.height * info->cam.dist) / 2 + info->cam.y_offset;
	return (point);
}
