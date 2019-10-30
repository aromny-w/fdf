/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:11:25 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/31 00:11:07 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	terminate(t_fdf *info)
{
	destroystruct(info, 0, info->map.height);
	exit(EXIT_SUCCESS);
}

int			hotkeys(int key, t_fdf *info)
{
	if (key == 53)
		terminate(info);
	if (key == 69 && info->cam.dist <= INT_MAX)
		info->cam.dist++;
	if (key == 78 && info->cam.dist > 1)
		info->cam.dist--;
	if (key == 123 && info->cam.x_offset >= INT_MIN)
		info->cam.x_offset -= 10;
	if (key == 124 && info->cam.x_offset <= INT_MAX)
		info->cam.x_offset += 10;
	if (key == 125 && info->cam.x_offset >= INT_MIN)
		info->cam.y_offset -= 10;
	if (key == 126 && info->cam.x_offset <= INT_MAX)
		info->cam.y_offset += 10;
	draw(info);
	return (0);
}
