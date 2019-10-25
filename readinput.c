/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:30:24 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/26 00:23:52 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	readinput(t_fdf *info, int fd, char *line)
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
	(void)info;
	//
}
