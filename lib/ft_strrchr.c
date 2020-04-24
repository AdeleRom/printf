/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:48:28 by lniki             #+#    #+#             */
/*   Updated: 2019/04/21 13:07:29 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rez;

	rez = (char *)s + ft_strlen(s);
	while (*rez != c)
	{
		if (rez == s)
			return (NULL);
		rez--;
	}
	return (rez);
}
