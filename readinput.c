/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:30:24 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/27 00:39:57 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	del(void *elem, size_t size)
{
	size = 0;
	free(elem);
}

static void	clearline(char **line, size_t i)
{
	while (i--)
		free(line[i]);
	free(line);
}

static int	countsegments(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		count++;
		if (*str == '-')
			str++;
		while (ft_isdigit(*str))
			str++;
		if (*str == ',')
			if (*++str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
			{
				str += 2;
				while (ft_isxdigit(*str))
					str++;
			}
		while (*str == ' ')
			str++;
	}
	return (count);
}

static int	validate(t_fdf *info, t_list *buf)
{
	char	**line;
	int		i;

	while (buf)
	{
		i = -1;
		if (info->map.width != countsegments(buf->content) ||
		!(line = ft_strsplit(buf->content, ' ')))
			return (0);
		while (++i < info->map.width)
			if (!isvalid(line[i]))
				break ;
		clearline(line, info->map.width);
		if (i != info->map.width)
			return (0);
		buf = buf->next;
	}
	return (1);
}

void		readinput(t_fdf *info, int fd, char *line)
{
	t_list	*buf;

	buf = NULL;
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd(&buf, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	ft_lstrev(&buf);
	info->map.width = countsegments(buf->content);
	info->map.height = ft_lstsize(buf);
	if (!validate(info, buf))
		exit(-1);
	ft_printf("test");
	ft_lstdel(&buf, del);
	close(fd);
}
