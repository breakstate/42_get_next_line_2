/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:02:01 by bmoodley          #+#    #+#             */
/*   Updated: 2017/06/10 16:34:42 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
