/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:48 by lniki             #+#    #+#             */
/*   Updated: 2019/04/24 11:55:27 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *s)
{
	char				*cur;
	int					m;
	unsigned long		r;

	cur = (char *)s;
	r = 0;
	m = 0;
	while (*cur == ' ' || (*cur >= '\t' && *cur <= '\r'))
		cur++;
	if (*cur == '-' || *cur == '+')
		m = (*cur++ == '-') ? 1 : 0;
	while (*cur >= '0' && *cur <= '9')
	{
		r = (r * 10) + (*cur++ - '0');
		if (r > (unsigned long)9223372036854775807 + m)
			return (m ? 0 : -1);
	}
	return ((int)(m ? (-1 * r) : r));
}
