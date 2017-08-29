/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:15:03 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/01 20:42:37 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list *head;

	head = (t_list*)malloc(sizeof(t_list));
	if (!head)
	{
		return (NULL);
	}
	head->next = NULL;
	if (content)
	{
		head->content = content;
		head->content_size = content_size;
	}
	else
	{
		head->content = NULL;
		head->content_size = 0;
	}
	return (head);
}
