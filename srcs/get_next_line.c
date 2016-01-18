/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/18 22:18:25 by mlinhard         ###   ########.fr       */
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
	if (fd == -10)
		return (root);
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

static int		gnl_free(void)
{
	t_gnl	*gnl;
	t_gnl	*destroy;

	gnl = gnl_init(-10);
	while (gnl->next)
	{
		destroy = gnl;
		gnl = gnl->next;
		if (destroy->tmp)
			free(destroy->tmp);
		free(destroy);
	}
	if (gnl->tmp)
		free(gnl->tmp);
	free(gnl);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	t_gnl	*gnl;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp = NULL;

	if (fd == -10)
		return (gnl_free());
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (!(gnl = gnl_init(fd)))
		return (-1);
	if (*line)
		free(*line);
	if (!gnl->tmp)
		gnl->tmp = ft_strnew(0);
	while (!(ft_strchr(gnl->tmp, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		printf("buff: %s", buff);
		tmp = ft_strdup(gnl->tmp);
		free(gnl->tmp);
		gnl->tmp = ft_strjoin(tmp, buff);
		free(tmp);
	}
	
	free(buff);
	return (0);
}