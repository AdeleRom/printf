/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:39:06 by lniki             #+#    #+#             */
/*   Updated: 2019/04/21 17:13:48 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	char	*pd;

	if (dest == NULL && src == NULL)
		return (NULL);
	pd = dest;
	ft_bzero(dest, size);
	while (*src != '\0' && size > 0)
	{
		*dest++ = *src++;
		size--;
	}
	return (pd);
}
