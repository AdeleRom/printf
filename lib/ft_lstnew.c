/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:19:52 by lniki             #+#    #+#             */
/*   Updated: 2019/04/21 13:28:43 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p_list;

	if (!(p_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		p_list->content = NULL;
		p_list->content_size = 0;
	}
	else
	{
		if (!(p_list->content = malloc(content_size)))
		{
			free(p_list);
			return (NULL);
		}
		ft_memcpy(p_list->content, content, content_size);
		p_list->content_size = content_size;
	}
	p_list->next = NULL;
	return (p_list);
}
