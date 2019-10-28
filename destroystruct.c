/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroystruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:58:10 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/28 23:02:50 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroystruct(t_fdf *info, int status, int i)
{
	if (info->win_ptr)
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	if (info->img_ptr)
		mlx_destroy_image(info->mlx_ptr, info->img_ptr);
	if (status == 1)
		ft_putstr_fd("Error\n", 2);
	if (info->map.matrix)
	{
		while (i--)
			free(info->map.matrix[i]);
		free(info->map.matrix);
	}
	if (status == 0 || status == 1)
		exit(status);
}
