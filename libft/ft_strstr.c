/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 08:37:02 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/16 11:10:23 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) < 1)
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i] != little[0] && big[i] != '\0')
			i++;
		while (big[i + j] == little[j] && big[i + j] != '\0')
			j++;
		if (j == ft_strlen(little))
			return ((char *)&big[i]);
		else if (i == ft_strlen(big))
			return (NULL);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
