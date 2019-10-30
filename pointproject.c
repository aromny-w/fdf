/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointproject.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:12:17 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/31 00:16:45 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_point *prime, t_point point)
{
	prime->x = (point.x - point.y) * cos(30 * M_PI / 180);
	prime->y = (point.x + point.y) * sin(30 * M_PI / 180) - point.z;
	prime->z = point.z;
}

static void	rotategamma(t_point *prime, t_point point, float gamma)
{
	prime->x = point.x * cos(gamma) - point.y * sin(gamma);
	prime->y = point.x * sin(gamma) + point.y * cos(gamma);
	prime->z = point.z;
}

static void	rotatebeta(t_point *prime, t_point point, float beta)
{
	prime->x = point.x * cos(beta) + point.z * sin(beta);
	prime->y = point.y;
	prime->z = -point.x * sin(beta) + point.z * cos(beta);
}

static void	rotatealpha(t_point *prime, t_point point, float alpha)
{
	prime->x = point.x;
	prime->y = point.y * cos(alpha) + point.z * sin(alpha);
	prime->z = -point.y * sin(alpha) + point.z * cos(alpha);
}

void		pointrotate(t_point *point, t_cam cam)
{
	rotatealpha(point, *point, cam.x_axis);
	rotatebeta(point, *point, cam.y_axis);
	rotategamma(point, *point, cam.z_axis);
}

t_point		pointproject(t_fdf *info, t_point point)
{
	point.x *= info->cam.dist;
	point.y *= info->cam.dist;
	point.z *= info->cam.dist / 1;
	point.x -= info->map.width * info->cam.dist / 2;
	point.y -= info->map.height * info->cam.dist / 2;
	pointrotate(&point, info->cam);
	isometric(&point, point);
	point.x += WIDTH / 2 + info->cam.x_offset;
	point.y += HEIGHT / 2 + info->cam.y_offset;
	return (point);
}
