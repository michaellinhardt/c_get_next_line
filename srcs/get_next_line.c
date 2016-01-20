/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/20 17:17:10 by mlinhard         ###   ########.fr       */
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
		root->end = -1;
		root->start = 0;
		root->next = NULL;
		if (!(root->s = ft_strnew(0)))
			return ((t_gnl *)NULL);
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
		next->end = -1;
		next->start = 0;
		next->next = NULL;
		if (!(next->s = ft_strnew(0)))
			return ((t_gnl *)NULL);
		gnl->next = next;
		gnl = next;
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
		if (destroy->s)
			free(destroy->s);
		free(destroy);
	}
	if (gnl->s)
		free(gnl->s);
	free(gnl);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	t_gnl	*g;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		r;

	if (fd == -10)
		return (gnl_free());
	if (fd < 1 || !(line) || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(g = gnl_init(fd)))
		return (-1);
	if (*line)
		free(*line);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = ft_strdup(g->s);
		free(g->s);
		g->s = ft_strjoin(tmp, buff);
		free(tmp);
	}
	g->start = (g->end + 1);
	while (g->s[++g->end] && g->s[g->end] != '\n' && g->s[g->end] != '\0')
		;
	if (g->s[(g->end)] == '\0' && (g->end - g->start) < 1)
		return (0);
	*line = ft_strsub(g->s, g->start, (g->end - g->start));
	return (1);
}