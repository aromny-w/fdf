/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:34:32 by aromny-w          #+#    #+#             */
/*   Updated: 2019/11/02 17:28:32 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pointcount(char *str)
{
	int		count;

	count = 0;
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str) || *str == ' ' || *str == '-')
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
