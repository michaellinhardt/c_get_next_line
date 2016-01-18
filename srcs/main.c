/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/18 22:10:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void gnl_print(t_gnl *gnl)
{
	if (!gnl)
		return ;
	while (gnl->next)
	{
		printf("%d: %s\n", gnl->fd, gnl->tmp);
		gnl = gnl->next;
	}
	printf("%d: %s\n", gnl->fd, gnl->tmp);
}

int		main(void)
{
	t_gnl	*gnl = NULL;
	char	*line = NULL;
	int		fd;

	fd = open("./files/5lignes", O_RDONLY);

	get_next_line(fd, &line);
	printf("call1: %s\n", line);

	get_next_line(fd, &line);
	printf("call2: %s\n", line);
	
	free(line);
	get_next_line(-10, (char**)NULL);

	return (0);
	gnl_print(gnl);
}
