/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:14:43 by lniki             #+#    #+#             */
/*   Updated: 2019/04/18 17:38:40 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p;
	size_t	dl;

	dl = ft_strlen(dest);
	p = (dest + dl);
	while (*src != '\0' && n--)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
