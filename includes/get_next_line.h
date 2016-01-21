/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:52:53 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/21 04:54:50 by mlinhard         ###   ########.fr       */
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
# define MAP 1
# define F ft_bootstrap

typedef struct		s_gnl
{
	int				fd;
	char			*s;
	int				start;
	int				end;
	char			b[BUFF_SIZE + 1];
	char			*t;
	int				r;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
void				ft_bootstrap(char **line);

#endif
