/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/20 17:04:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*line = NULL;
	int		fd;

	fd = open("./files/5lignes", O_RDONLY);

	int		i = 0; while (get_next_line(fd, &line) > 0)
	{
		i++;
		printf("call %d: %s\n", i, line);
	}

	get_next_line(-10, (char**)NULL);

	return (0);
}
