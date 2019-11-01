/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:13:35 by aromny-w          #+#    #+#             */
/*   Updated: 2019/11/01 16:14:28 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotatezaxis(t_point *prime, t_point point, float gamma)
{
	prime->x = point.x * cos(gamma) - point.y * sin(gamma);
	prime->y = point.x * sin(gamma) + point.y * cos(gamma);
	prime->z = point.z;
}

static void	rotateyaxis(t_point *prime, t_point point, float beta)
{
	prime->x = point.x * cos(beta) + point.z * sin(beta);
	prime->y = point.y;
	prime->z = -point.x * sin(beta) + point.z * cos(beta);
}

static void	rotatexaxis(t_point *prime, t_point point, float alpha)
{
	prime->x = point.x;
	prime->y = point.y * cos(alpha) + point.z * sin(alpha);
	prime->z = -point.y * sin(alpha) + point.z * cos(alpha);
}

void		pointrotate(t_point *point, t_cam cam)
{
	rotatexaxis(point, *point, cam.alpha);
	rotateyaxis(point, *point, cam.beta);
	rotatezaxis(point, *point, cam.gamma);
}

