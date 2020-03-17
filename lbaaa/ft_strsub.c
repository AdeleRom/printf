/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:58:27 by lniki             #+#    #+#             */
/*   Updated: 2019/04/21 13:24:48 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	i = 0;
	if (!(p = ft_strnew(len)) || !s)
		return (NULL);
	while (len-- && s[start])
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
