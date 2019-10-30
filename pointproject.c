/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointproject.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:12:17 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/30 20:27:55 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_point *prime, t_point point)
{
	prime->x = (point.x - point.y) * cos(30 * M_PI / 180);
	prime->y = (point.x + point.y) * sin(30 * M_PI / 180) - point.z;
	prime->z = point.z;
}

static void	rotate_z(t_point *s, int x, int y, double gamma)
{
	s->x = x * cos(gamma) - y * sin(gamma);
	s->y = x * sin(gamma) + y * cos(gamma);
}

static void	rotate_y(t_point *s, int x, double beta)
{
	s->x = x * cos(beta) + s->z * sin(beta);
	s->z = -x * sin(beta) + s->z * cos(beta);
}

static void	rotate_x(t_point *s, int y, double alpha)
{
	s->y = y * cos(alpha) + s->z * sin(alpha);
	s->z = -y * sin(alpha) + s->z * cos(alpha);
}
/*
void		rotationmatrix(t_point *prime, t_point point)
{
	;
}
*/
t_point		pointproject(t_fdf *info, t_point s)
{
	int zoom;

	zoom = 50;
	s.x *= zoom;
	s.y *= zoom;
	s.z *= zoom / 5;
	s.x -= info->map.width * zoom / 2;
	s.y -= info->map.height * zoom / 2;
	rotate_x(&s, s.y, 0);
	rotate_y(&s, s.x, 0);
	rotate_z(&s, s.x, s.y, 0);
	isometric(&s, s);
	s.x += WIDTH / 2;
	s.y += HEIGHT / 2;
	return (s);
}
