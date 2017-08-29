/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:09:58 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/16 12:02:15 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] == s2[i]) && (i < n - 1) && s1[i] && s2[i])
		{
			i++;
		}
		if (s1[i] == s2[i])
			return (1);
		else
			return (0);
	}
	return (0);
}
