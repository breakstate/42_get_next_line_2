/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:57:04 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/16 11:51:24 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	len = ft_strlen(s);
	if (s != NULL)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			if (i == (len))
				return ("");
			i++;
		}
		j = (len - 1);
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		j = j - i + 1;
		return (ft_strsub(s, i, j));
	}
	return (NULL);
}
