/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 23:30:02 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/31 23:49:21 by aromny-w         ###   ########.fr       */
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

typedef struct	s_cam
{
	int		dist;
	int		x_offset;
	int		y_offset;
	double	alpha;
	double	beta;
	double	gamma;
}				t_cam;

typedef struct	s_map
{
	t_point	**matrix;
	int		width;
	int		height;
	int		legend;
	int		*color;
}				t_map;

typedef struct	s_fdf
{
	t_map	map;
	t_cam	cam;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_fdf;

void	fdf(int	fd);
void	initstruct(t_fdf *info);
void	destroystruct(t_fdf *info, int status, int i);
void	readinput(t_fdf *info, int fd, char *line);
int		pointcount(char *str);
int		pointparse(t_fdf *info, char *str, int x, int y);
void	draw(t_fdf *info);
t_point	pointproject(t_fdf *info, t_point s);
int		hotkeys(int key, t_fdf *info);
void	printmatrix(t_map map); //debug

#endif
