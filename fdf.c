/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 23:29:53 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/27 19:35:23 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_win(t_fdf *info)
{
	destroystruct(info, 0, info->map.height);
	exit(EXIT_SUCCESS);
}

void		fdf(int fd)
{
	t_fdf	info;

	ft_memset(&info, 0, sizeof(t_fdf));
	readinput(&info, fd, NULL);
	initmlx(&info);
	//
	mlx_hook(info.win_ptr, 17, 1L << 17, close_win, &info);
	mlx_loop(info.mlx_ptr);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		fdf(open(argv[1], O_RDONLY));
	else
		ft_printf("Usage : ./fdf <filename>");
	exit(EXIT_SUCCESS);
}
