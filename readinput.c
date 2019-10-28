/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:30:24 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/28 23:04:03 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	del(void *elem, size_t size)
{
	size = 0;
	free(elem);
}

static void	clearvec(char **vec, size_t i)
{
	while (i--)
		free(vec[i]);
	free(vec);
}

static int	vecparse(t_fdf *info, t_list *buf)
{
	char	**vec;
	int		j;
	int		i;

	j = 0;
	while (buf)
	{
		i = -1;
		if (info->map.width != scalarcount(buf->content) ||
		!(vec = ft_strsplit(buf->content, ' ')))
			return (0);
		while (++i < info->map.width)
			if (!scalarparse(info, vec[i], i, j))
				break ;
		clearvec(vec, info->map.width);
		if (i != info->map.width)
			return (0);
		j++;
		buf = buf->next;
	}
	return (1);
}

static void	initmatrix(t_fdf *info, int width, int height)
{
	int	i;

	if (!(info->map.matrix = (t_point **)malloc(sizeof(t_point *) * height)))
		return (destroystruct(info, 1, 0));
	i = -1;
	while (++i < height)
	{
		if (!(info->map.matrix[i] = (t_point *)malloc(sizeof(t_point) * width)))
			return (destroystruct(info, 1, i));
		ft_memset(info->map.matrix[i], 0, width);
	}
}

void		readinput(t_fdf *info, int fd, char *line)
{
	t_list	*buf;

	buf = NULL;
	if (fd == -1)
		destroystruct(info, 1, 0);
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd(&buf, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	ft_lstrev(&buf);
	info->map.width = scalarcount(buf->content);
	info->map.height = ft_lstsize(buf);
	initmatrix(info, info->map.width, info->map.height);
	if (!vecparse(info, buf))
		destroystruct(info, 1, info->map.height);
	ft_lstdel(&buf, del);
	close(fd);
}
