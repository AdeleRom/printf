/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_getcap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:34:35 by lniki             #+#    #+#             */
/*   Updated: 2019/04/24 15:50:02 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			a_getcap(const char *src, char delimiter)
{
	int cnt;
	int len;

	cnt = 0;
	len = 0;
	while (*src != '\0')
	{
		if (*src == delimiter)
		{
			if (len > 0)
			{
				len = 0;
				cnt++;
			}
		}
		else
			len++;
		src++;
	}
	if (len > 0)
		cnt++;
	return (cnt);
}
