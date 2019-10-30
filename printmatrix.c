/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:36:25 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/30 19:10:25 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printmatrix(t_map map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map.height)
	{
		i = -1;
		while (++i < map.width)
			ft_printf("[x:%2d y:%2d z:%2d color:%#8X]",
			map.matrix[j][i].x,
			map.matrix[j][i].y,
			map.matrix[j][i].z,
			map.matrix[j][i].color);
		ft_printf("\n");
	}
}
