/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:56:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/09/01 17:02:34 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>

static	void	new_malloc(char *buf, char **new, int pos, int i)
{
	char	*temp;
	char	*temp2;

	//printf("NEW_MALLOC:\n pos = %d\n", pos);//remove
	if (*new == NULL)
	{
		*new = ft_strsub(buf, pos, i);
		//printf("\nif new = |%s|\n\n", *new);//remove
	}
	else
	{
		temp2 = ft_strsub(buf, pos, i);
		temp = ft_strdup(*new);
		free(*new);
		*new = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
		//printf("\nelse new = |%s|\n\n", *new);//remove
	}
}

static int		buf_parse(char *buf, char **new, int *pos)
{
	/*
	int		i;
	
	//printf("BUF_PARSE:\n");
	//printf(" buf = %s\n", buf);
	i = 0;
	i += *pos;
	while (buf[i] != '\n' && i < BUFF_SIZE && buf[i] != '\0')
	{
		//printf(" buf[%d] = %c\n", i, buf[i]);
		i++;
		printf(" buf[%d] = %c\n", i, buf[i]);
	}
	new_malloc(buf, new, *pos, i);
	//printf(" pos = %d\n i = %d\n", *pos, i);
	if (buf[i] == '\n')// && i < BUFF_SIZE - 1)
		*pos = i + 1;
	//printf(" pos = %d\n i = %d\n", *pos, i);
	//printf(" char at pos = %c\n", buf[*pos]);//remove
	if (i == BUFF_SIZE)// || buf[i] == '\0')
	{
		//printf(" triggered if\n");
		ft_bzero(buf, BUFF_SIZE);
		*pos = -1;
		//return 0
	}
	else if (buf[i] == '\0' || buf[*pos] == '\0') //|| buf[i] == '\n')
	{
		//printf(" triggered else\n");
		*pos = -1;
		return (1);
	}
	else if (buf[i] == '\n')
	{
		puts("qwerty");
		return (1);
	}
	return (0);
	//return (*pos == -1 ? 0 : 1);//bypasses the return condition if need buffer reload.
*/
//------------------------------------------------------------------------------
/*	int		i;
*
	i = 0;
	i += *pos;
	while (buf[i] != '\n' && i < BUFF_SIZE && buf[i] != '\0')
		i++;
	new_malloc(buf, new, *pos, i);
	if (buf[i] == '\n')// && i < BUFF_SIZE - 1)
		*pos = i + 1;
	if (i == BUFF_SIZE)// || buf[i] == '\0')
	{
		ft_bzero(buf, BUFF_SIZE);
		*pos = -1;
	}
	else if (buf[i] == '\0' || buf[*pos] == '\0') //|| buf[i] == '\n')
	{
		*pos = -1;
		return (1);
	}
	else if (buf[i] == '\n')
	{
		puts("qwerty");
		return (1);
	}
	return (0);*/
//--------------------------------------------------------------------------------
	int		i;

	i = 0;
	i += *pos;
	printf("%s :::: buf\n\n", buf);	
	while (i < BUFF_SIZE)
	{
		//if (buf[i] != '\n' && buf[i] != '\0')
		//	i++;
		if (buf[i] == '\n')
		{
			new_malloc(buf, new, *pos, i);
			*pos =  i + 1;;
			return (1);
		}
		else if (buf[i] == '\0')
		{
			new_malloc(buf, new, *pos, i);
			*pos = -1;
			return (1);
		}
		i++;
	}
	ft_bzero(buf, BUFF_SIZE);
	*pos = -1;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static int		r;
	static char		buf[BUFF_SIZE];
	static int		pos = -1;
	char			*new;

	new = NULL;
	while (1)
	{
		//printf("   ||r = %d||\n", r);
		if (pos == -1)
		{
			ft_bzero(buf, BUFF_SIZE);
			r = read(fd, buf, BUFF_SIZE);
			pos = 0;
		}
		else if (r == 0 || r == -1)
			return (r);
		else
		{
		//	printf("poes ::: %i \n\n", pos);
			if (buf_parse(buf, &new, &pos))//buf_parse(buf, &new, &pos, &r))
			{
				*line = new;
				return (1);
			}
		}
	}
	//return (r == 0 ? 0 : 1);
}

int		main()
{
	int		fd;
	char	*line;
	int		gnl;
	int		debug = 10;//DEBUG

	printf("-----------------GET NEXT LINE-----------------\n");
	line = NULL;
	fd = open("test6.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) == 1 && debug)
	{
		//printf("\n--------------start-------------\n");
		printf("line -> %s\n", line);
		free(line);
		printf("gnl = %d\n", gnl);//remove
		//printf("---------------end--------------\n\n");
		debug--;//DEBUG
	}
	printf("gnl = %d\n", gnl);//remove
	return (0);
}

//the buffer is being cleared each time gnl is being called from main.
//read should only be performed if the buffer is empty ie pos = 0;
