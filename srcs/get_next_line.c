/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/21 05:29:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_init_one(t_gnl *gnl, int fd)
{
	if (fd > -100)
	{
		if (!(gnl->s = ft_strnew(0)))
			return (1);
	}
	else
		gnl->s = NULL;
	gnl->fd = fd;
	gnl->next = NULL;
	gnl->end = -1;
	gnl->start = 0;
	return (0);
}

static t_gnl	*gnl_init(int fd)
{
	static t_gnl	*root;
	t_gnl			*gnl;
	t_gnl			*n;

	if (fd == -200 && !(root = NULL))
		return ((t_gnl *)NULL);
	if (!root)
	{
		if (!(root = (t_gnl *)malloc(sizeof(t_gnl))))
			return ((t_gnl *)NULL);
		gnl_init_one(root, -100);
	}
	if (fd == -10)
		return (root);
	gnl = root;
	while (gnl->fd != fd && gnl->next)
		gnl = gnl->next;
	if (gnl->fd != fd)
	{
		if (!(n = (t_gnl *)malloc(sizeof(t_gnl))) || (gnl_init_one(n, fd)))
			return ((t_gnl *)NULL);
		gnl->next = n;
		gnl = n;
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
	if (gnl->fd > -100 && gnl->s)
		free(gnl->s);
	free(gnl);
	gnl_init(-200);
	return (0);
}

static int		gnl_free_one(int fd)
{
	t_gnl	*gnl;
	t_gnl	*prev;
	t_gnl	*next;

	gnl = gnl_init(-10);
	prev = NULL;
	next = (gnl->next) ? gnl->next : NULL;
	while (gnl->fd != fd)
	{
		prev = gnl;
		gnl = gnl->next;
		next = gnl->next;
	}
	if (gnl->s)
		free(gnl->s);
	free(gnl);
	if (prev)
		prev->next = next;
	gnl = gnl_init(-10);
	if (!gnl->next)
		gnl_free();
	return (0);
}

int				get_next_line(int fd, char **line)
{
	t_gnl	*g;
	void	(*f)(char **line);

	if (*line)
		free(*line);
	if (!(*line = NULL) && fd == -10)
		return (gnl_free());
	if (fd < 1 || !(line) || BUFF_SIZE < 1 || !(g = gnl_init(fd)) ||
		read(fd, g->b, 0) < 0)
		return (-1);
	while ((g->r = read(fd, g->b, BUFF_SIZE)) > 0)
	{
		g->b[g->r] = '\0', g->t = ft_strdup(g->s), free(g->s);
		g->s = ft_strjoin(g->t, g->b), free(g->t);
	}
	g->start = (g->end + 1);
	while (g->s[++g->end] && g->s[g->end] != '\n' && g->s[g->end] != '\0')
		;
	if (g->r == 0 && g->s[(g->end)] == '\0' && (g->end - g->start) < 1)
		return (gnl_free_one(fd));
	*line = ft_strsub(g->s, g->start, (g->end - g->start));
	if (MAP && (f = F))
		(f)(line);
	return (1);
}