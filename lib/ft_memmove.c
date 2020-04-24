/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:11:57 by lniki             #+#    #+#             */
/*   Updated: 2019/04/18 15:57:16 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t c)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*pd;
	const unsigned char	*ps;

	d = dest;
	s = src;
	pd = d + (c - 1);
	ps = s + (c - 1);
	if (d < s)
	{
		while (c-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (c-- > 0)
			*pd-- = *ps--;
	}
	return (dest);
}
