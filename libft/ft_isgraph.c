/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 23:07:26 by aromny-w          #+#    #+#             */
/*   Updated: 2018/12/17 23:07:28 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isgraph(int c)
{
	if (ft_isprint(c) && c != 32)
		return (1);
	return (0);
}
