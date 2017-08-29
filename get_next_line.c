/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:56:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/08/29 15:47:41 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>

static	void	new_malloc(char *buf, char **new, int *pos, int *i)
{
	char	*temp;
	char	*temp2;

	if (*new == NULL)
	{
		*new = ft_strsub(buf, *pos, *i);
		printf("\nif new = |%s|\n\n", *new);
	}
	else
	{
		temp2 = ft_strsub(buf, *pos, *i);
		temp = ft_strdup(*new);
		free(*new);
		*new = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
		printf("\nelse new = |%s|\n\n", *new);
	}
}

static int		buf_parse(char *buf, char **new, int *pos, int *r)
{
	int		i;

	i += *pos;
	while (buf[i] != '\n' && i < BUFF_SIZE && buf[i] != '\0')
		i++;
	new_malloc(buf, new, pos, &i);
	*pos = i - 1;
	printf("pos = %c\n", buf[*pos]);//remove
	//if (i == BUFF_SIZE)// == buffsize then bzero and pos = 0 probs
	return (i == BUFF_SIZE ? 0 : 1);//bypasses the return condition if need buffer reload.
}

int		get_next_line(const int fd, char **line)
{
	static int		r;
	static char		buf[BUFF_SIZE];
	static int		pos;
	char	*new;

	new = NULL;
	while ((read(fd, buf, BUFF_SIZE)))
	{
		printf("buf = |%s|\n", buf);//remove
		pos = 0;
		if (buf_parse(buf, &new, &pos, &r) == 1)
		{
			*line = new;
			printf("new = |%s|\n", new);//remove
			return (1);
		}
	}
	return (r == 0 ? 0 : 1);
}

int		main()
{
	int		fd;
	char	*line;
	int		gnl;

	line = NULL;
	fd = open("test2.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		printf("\n--------------start-------------\n");
		printf("line -> %s\n", line);
		free(line);
		printf("gnl = %d\n", gnl);//remove
		printf("---------------end--------------\n\n");
	}
	printf("gnl = %d\n", gnl);//remove
	return (0);
}
