/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 23:30:02 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/28 22:59:28 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080
# define NAME "fdf"

# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int 	color;
}				t_point;

typedef struct	s_map
{
	int		width;
	int		height;
	t_point	**matrix;
	//
}				t_map;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_map	map;
	//
}				t_fdf;

void	fdf(int	fd);
void	readinput(t_fdf *info, int fd, char *line);
int		scalarcount(char *str);
int		scalarparse(t_fdf *info, char *str, int x, int y);
void	initmlx(t_fdf *info);
void	destroystruct(t_fdf *info, int status, int i);
void	printmatrix(t_map map); //debug

#endif
