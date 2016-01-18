/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:52:53 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/18 20:21:08 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include <stdlib.h>
# include "libft.h"
# define BUF_SIZE 21

typedef struct		s_gnl
{
	int				fd;
	char			*tmp;
	struct s_gnl	*next;
}					t_gnl;

t_gnl		*get_next_line(int fd);

#endif
