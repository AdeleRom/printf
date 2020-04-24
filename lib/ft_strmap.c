/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:42:57 by lniki             #+#    #+#             */
/*   Updated: 2019/04/21 13:16:37 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*rez;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(rez = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		rez[i] = (*f)(s[i]);
		i++;
	}
	rez[i] = '\0';
	return (rez);
}
