/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:34:32 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/28 23:06:12 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	scalarcount(char *str)
{
	int		count;

	count = 0;
	while (*str == ' ')
		str++;
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
