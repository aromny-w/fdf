/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:44:54 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/27 15:34:02 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	todecimal(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (c - 'A' + 10);
}

static int	checkcolor(char **str)
{
	int nbr;

	if (!ft_isxdigit(**str))
		return (0);
	while (ft_isxdigit(**str) && (nbr >= 0x000000 && nbr <= 0xffffff))
		nbr = 10 * nbr + todecimal(*(*str)++);
	if (**str || !(nbr >= 0x000000 && nbr <= 0xffffff))
		return (0);
	return (1);
}

static int	checknumber(char **str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (**str == '+' || **str == '-')
		if (*(*str)++ == '-')
			sign = -1;
	if (!ft_isdigit(**str))
		return (0);
	while (ft_isdigit(**str) &&
	(nbr * sign >= INT_MIN && nbr * sign <= INT_MAX))
		nbr = 10 * nbr + (*(*str)++ - '0');
	if (!(nbr * sign >= INT_MIN && nbr * sign <= INT_MAX))
		return (0);
	return (1);
}

int			isvalid(char *str)
{
	if (!checknumber(&str))
		return (0);
	if (!*str)
		return (1);
	if (*str++ == ',')
	{
		if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
			str += 2;
		else
			return (0);
		if (!checkcolor(&str) || *str)
			return (0);
	}
	else
		return (0);
	return (1);
}
