/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:52:53 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/28 03:43:34 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 9999
# define MAP 0
# define F ft_bootstrap

typedef struct		s_gnl
{
	char			b[BUFF_SIZE + 1];
	int				fd;
	char			*t;
	int				r;
	int				i;
	char			*s;
	char			**l;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
void				ft_bootstrap(char **line);

#endif
