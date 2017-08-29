/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:24:12 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/10 16:24:16 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int dst_len;
	int j;
	int len;

	j = 0;
	if (!((int)ft_strlen(dst) >= (int)size))
		i = ft_strlen(dst);
	else
		return ((int)size + (int)ft_strlen(src));
	i = ft_strlen(dst);
	dst_len = i;
	len = size - i - 1;
	while (len-- > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (len == 1)
		dst_len = (int)size - 1;
	dst[i] = '\0';
	return (dst_len + (int)ft_strlen(src));
}
