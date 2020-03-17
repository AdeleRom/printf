/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:06 by lniki             #+#    #+#             */
/*   Updated: 2019/04/24 15:43:15 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char a;
	unsigned char *pd;
	unsigned char *ps;

	a = (unsigned char)c;
	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (src || dest)
		while (n--)
		{
			*pd++ = *ps++;
			if (*(pd - 1) == a)
				return (pd);
		}
	return (NULL);
}
