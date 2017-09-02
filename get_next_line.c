/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:56:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/09/02 16:53:25 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#define debugf //printf

static	void	new_malloc(char *buf, char **new, int pos, int i)
{
	char	*temp;
	char	*temp2;

	printf(" ---NEW_MALLOC:\n ---buf = [[%s]]\n ---new = [[%s]]\n ---pos = %d\n ---i = %d\n", buf, *new, pos, i);//remove
	if (*new == NULL)
	{
		*new = ft_strsub(buf, pos, i);
		printf("\n --->>if new = |%s|\n\n", *new);//remove
	}
	else
	{
		temp2 = ft_strsub(buf, pos, i);
		temp = ft_strdup(*new);
		printf( " ---else:\n ---temp = %s\n ---temp2 = %s\n", temp, temp2);
		free(*new);
		*new = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
		printf("\n --->>else new = |%s|\n\n", *new);//remove
	}
}

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

/*
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
*/
//-----------------------------------------------------------------------------

//i
//while buf
//	if \n
//		append and parse again.
//		pos = i (point after '\n'
//	else 
//		reload and parse. 
//		pos = -1
//reload

static int		buf_parse(char *buf, char **new, int *pos)
{
	int		i;

	printf(" -BUF_PARSE:\n");
	i = 0;
	i += *pos;
	while (buf[i])
	{
		printf(" -buf[%d] = %c\n", i, buf[i]);//remove
		if (buf[i] == '\n')
		{
			new_malloc(buf, new, *pos, i - *pos);
			*pos = i + 1;
			printf("\n >i = %d\n >pos = %d\n", i, *pos);//remove
			return (1);//I DONT TRUST THIS PART
		}
		i++;
	}
	printf("AFTER WHILE\n");
	new_malloc(buf, new, *pos, i);
	printf("\n -i = %d\n -pos = %d\n", i, *pos);//remove
	*pos = -1;
	printf("\n -i = %d\n -pos = %d\n", i, *pos);//remove
	//return (0);
	return (i == BUFF_SIZE ? 0 : 1);
}

int		get_next_line(const int fd, char **line)
{
	static int		r;
	static char		buf[BUFF_SIZE + 1];
	static int		pos = -1;
	char			*new;

	printf("GNL:\n");
	new = NULL;
	while (1)
	{
		if (pos == -1)
		{
			printf(" RELOAD BUFFER\n");
			ft_bzero(buf, BUFF_SIZE + 1);
			r = read(fd, buf, BUFF_SIZE);
			printf(" r = %d\n", r);
			pos = 0;
		}
		if (r == 0 || r == -1)
			return (r);
		else
		{
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
	fd = open("test5.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) == 1 && debug)
	{
		printf("\n--------------start-------------\n");
		printf("line -> |%s|\n", line);
		free(line);
		printf("gnl = %d\n", gnl);//remove
		printf("---------------end--------------\n\n");
		debug--;//DEBUG
	}
	printf("gnl = %d\n", gnl);//remove
	return (0);
}

//weird errors right now, skips letters sometimes and prints \n for last line.
//changed buffer to BUFF_SIZE + 1 for null terminator.
//testing now with revised buf_parse.
