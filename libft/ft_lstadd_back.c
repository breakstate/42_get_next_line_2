/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 19:41:57 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/01 20:43:13 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, void *content)
{
	if (*alst)
	{
		while ((*alst)->next)
		{
			*alst  = (*alst)->next;
		}
		(*alst)->next = ft_lstnew(content, 1);
	}
	else
		*alst = ft_lstnew(content, 1);
}
