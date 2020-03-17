/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:06:34 by lniki             #+#    #+#             */
/*   Updated: 2019/04/23 10:24:47 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dl;
	size_t	i;

	dl = ft_strlen(dest);
	if (dl >= n)
		return (n + ft_strlen(src));
	n = n - dl - 1;
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[dl + i] = src[i];
		i++;
	}
	dest[i + dl] = '\0';
	return (dl + ft_strlen(src));
}
