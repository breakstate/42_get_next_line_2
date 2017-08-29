/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:26:47 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/22 11:47:22 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;

	i = 0;
	if (s != NULL)
	{
		dst = (char *)malloc(sizeof(char) * len + 1);
		if (dst == NULL)
			return (NULL);
		while (i < len)
		{
			dst[i] = s[start];
			i++;
			start++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
