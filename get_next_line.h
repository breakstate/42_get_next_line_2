/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:47:58 by bmoodley          #+#    #+#             */
/*   Updated: 2017/09/04 14:11:08 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# define BUFF_SIZE 1000

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_gnl
{
	char		buffer[BUFF_SIZE];
	int			fd;
	int			r;
	int			pos;
}				t_gnl;

int		get_next_line(const int fd, char **line);

#endif
