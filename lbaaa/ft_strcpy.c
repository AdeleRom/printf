/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:08:22 by lniki             #+#    #+#             */
/*   Updated: 2019/04/07 19:34:51 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*p;

	if (dest != NULL || src != NULL)
	{
		p = dest;
		while (*src != '\0')
		{
			*dest++ = *src++;
		}
		*dest = '\0';
		return (p);
	}
	else
	{
		return (NULL);
	}
}
