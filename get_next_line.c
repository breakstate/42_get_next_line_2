/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:56:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/09/04 14:08:56 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>

static	void	new_malloc(char *buf, char **new, int pos, int i)
{
	char		*temp;
	char		*temp2;

	if (*new == NULL)
	{
		if (buf[pos] != '\0')
			*new = ft_strsub(buf, pos, i);
	}
	else
	{
		temp2 = ft_strsub(buf, pos, i);
		temp = ft_strdup(*new);
		free(*new);
		*new = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
	}
}

static int		buf_parse(char *buf, char **new, int *pos, char **line)
{
	int			i;

	i = *pos;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			new_malloc(buf, new, *pos, i - *pos);
			*pos = i + 1;
			*line = *new;
			return (1);
		}
		i++;
	}
	new_malloc(buf, new, *pos, i - *pos);
	*pos = -1;
	return (0);
}


/*int				get_next_line(const int fd, char **line)
{
	static int	r = -2;
	static char	buf[BUFF_SIZE + 1];
	static int	pos = -1;
	char		*new;

	new = NULL;
	while (42)
	{
		if (pos == -1)
		{
			ft_bzero(buf, BUFF_SIZE + 1);
			r = read(fd, buf, BUFF_SIZE);
			pos = 0;
		}
		if (r == 0 || r == -1)
		{
			if (new == NULL)
				return (r);
			*line = new;
			return (1);
		}
		else if (buf_parse(buf, &new, &pos, line))
			return (1);
	}
}
*/

static void	build(char **line, char **new, char *pos)
{
	*line = ft_strsub(*new, 0, ft_strlen(*new) - ft_strlen(*new));
	*new = ft_strdup(pos + 1);
}

static int	ft_append(int fd, char **new)
{
	char	*buf;
	int		ret;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))
	if (buf == NULL)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		*new = ft_strjoin_f(*new, buff);
	}
	free(buff);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char *new;
	char		*pos;
	int			ret;

	if (new != NULL)
		new = ft_strnew(0);
	pos = ft_strchr(new, '\n');
	while (!pos)
	{
		ret = ft_append(fd, &new);
		if (ret == 0)
		{
			if (ft_strlen(bin) == 0)
				return (0);
			new = ft_strjoin(new, "\n");//ft_strjoin_f
		}
		if (ret < 0)
			return (-1);
		else
			pos = ft_strchr(new, '\n');
	}
	build(line, &new, pos);
	return (1);
}


/*
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
*/
//weird errors right now, skips letters sometimes and prints \n for last line.
//changed buffer to BUFF_SIZE + 1 for null terminator.
//testing now with revised buf_parse.
