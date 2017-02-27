/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:32:01 by aemilien          #+#    #+#             */
/*   Updated: 2017/02/27 10:03:13 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_file
{
	int			fd;
	char		*buf;
}				t_file;

int				get_next_line(const int fd, char **line);
int				get_next_char(const int fd, char **line, char c);

#endif
