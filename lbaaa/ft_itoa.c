/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:42:26 by lniki             #+#    #+#             */
/*   Updated: 2019/04/23 11:36:26 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*a_nbr(char *p, int nb)
{
	if (nb == -2147483648LL)
	{
		*p++ = '-';
		*p++ = '2';
		p = a_nbr(p, 147483648);
	}
	else if (nb < 0)
	{
		*p++ = '-';
		p = a_nbr(p, -nb);
	}
	else if (nb > 9)
	{
		p = a_nbr(p, nb / 10);
		p = a_nbr(p, nb % 10);
	}
	else
	{
		*p++ = (nb + '0');
		*p = '\0';
	}
	return (p);
}

char			*ft_itoa(int n)
{
	char	*res;

	if (!(res = (char*)malloc(12 * sizeof(char))))
		return (NULL);
	a_nbr(res, n);
	return (res);
}
