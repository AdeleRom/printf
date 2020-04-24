/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:49:45 by lniki             #+#    #+#             */
/*   Updated: 2019/04/24 15:47:54 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pd;
	char	*ps;

	if (n == 0 || dest == src)
		return (dest);
	pd = (char *)dest;
	ps = (char *)src;
	while (n-- > 0)
		*pd++ = *ps++;
	return (dest);
}
