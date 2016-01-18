/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/18 20:21:51 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*gnl_init(int fd)
{
	static t_gnl	*root;
	t_gnl			*gnl;
	t_gnl			*next;

	if (!root)
	{
		if (!(root = (t_gnl *)malloc(sizeof(t_gnl))))
			return ((t_gnl *)NULL);
		root->fd = fd;
	}
	gnl = root;
	while (gnl->fd != fd && gnl->next)
		gnl = gnl->next;
	if (gnl->fd != fd)
	{
		if (!(next = (t_gnl *)malloc(sizeof(t_gnl))))
			return ((t_gnl *)NULL);
		next->fd = fd;
		gnl->next = next;
		return (next);
	}
	return (gnl);
}

t_gnl			*get_next_line(int fd)
{
	t_gnl	*gnl;

	if (!(gnl = gnl_init(fd)))
		return ((t_gnl *)NULL);
	fd++;
	return (gnl);
}