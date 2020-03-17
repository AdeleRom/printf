/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:42:26 by lniki             #+#    #+#             */
/*   Updated: 2019/04/24 14:35:38 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*a_getstring(char **pdest, const char *src, char delimiter)
{
	int		len;
	char	*p;
	char	*dest;

	*pdest = NULL;
	len = 0;
	p = (char*)src;
	if (src == NULL)
		return (NULL);
	while (*p != '\0' && *p != delimiter && len++ + 1)
		p++;
	if (len == 0)
		return (p);
	len++;
	if (!(*pdest = (char*)malloc(len * sizeof(char))))
		return (NULL);
	dest = *pdest;
	len--;
	while (len-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (src);
}

char				**ft_strsplit(char const *s, char c)
{
	int			cnt;
	char		**res;
	char		**p;
	char const	*e;

	if (s == NULL)
		return (NULL);
	cnt = a_getcap(s, c);
	if (!(res = (char**)malloc((cnt + 1) * sizeof(char*))))
		return (NULL);
	p = res;
	e = s + ft_strlen(s);
	while (s < e)
	{
		if (!(s = a_getstring(p, s, c)))
		{
			a_free_result(res);
			return (NULL);
		}
		if (*p != NULL)
			p++;
		s++;
	}
	*p = NULL;
	return (res);
}
