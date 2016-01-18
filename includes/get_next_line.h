/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:52:53 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/18 22:09:39 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct		s_gnl
{
	int				fd;
	char			*tmp;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);

#endif
