/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:23:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/11 08:52:13 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (dst == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			dst[i + j] = s2[j];
			j++;
		}
		dst[i + j] = '\0';
		return (dst);
	}
	return (NULL);
}
