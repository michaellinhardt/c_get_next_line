/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/20 20:58:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*line = NULL;
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;

	fd = 0; fd1 = 0; fd2 = 0; fd3= 0; fd4 = 0; fd5 = 0;

	// TEST MULTI FD
	fd1 = open("./files/1lignes", O_RDONLY);
	fd = get_next_line(fd1, &line);
	printf("1lignes, 1/1, %d: %s\n", fd, line);

	fd2 = open("./files/3lignes", O_RDONLY);
	fd = get_next_line(fd2, &line);
	printf("3lignes, 1/3, %d: %s\n", fd, line);

	fd3 = open("./files/5lignes", O_RDONLY);
	fd = get_next_line(fd3, &line);
	printf("5lignes, 1/5, %d: %s\n", fd, line);
	fd = get_next_line(fd3, &line);
	printf("5lignes, 2/5, %d: %s\n", fd, line);

	fd = get_next_line(fd2, &line);
	printf("3lignes, 2/3, %d: %s\n", fd, line);

	fd = get_next_line(fd3, &line);
	printf("5lignes, 3/5, %d: %s\n", fd, line);

	// CETTE LIGNE VA FREE LES DONNEE DE CE FD CAR IL EST TERMINé
	fd = get_next_line(fd1, &line);
	printf("1lignes, 2/1, %d: %s\n", fd, line);

	fd = get_next_line(fd3, &line);
	printf("5lignes, 4/5, %d: %s\n", fd, line);

	fd = get_next_line(fd2, &line);
	printf("3lignes, 3/3, %d: %s\n", fd, line);

	fd = get_next_line(fd2, &line);
	printf("3lignes, 4/3, %d: %s\n", fd, line);

	fd = get_next_line(fd3, &line);
	printf("5lignes, 5/5, %d: %s\n", fd, line);

	// CETTE LIGNE VA FORCER UN FREE AUTO ET TOTAL CAR 
	// C'EST LE DERNIER FD QUI ETAIT OUVERT
	fd = get_next_line(fd3, &line);
	printf("5lignes, 6/5, %d: %s\n", fd, line);

	// LE PROGRAMME A FREE TOUS DE MANIERE AUTO CAR 
	// AUCUN FD N'ETAIS OUVERT
	// PUIS ON ROUVRE UN NOUVEAU FD
	fd5 = open("./files/6lignes", O_RDONLY);
	while ((fd = get_next_line(fd5, &line)) == 1)
		printf("6lignes, 1/6, %d: %s\n", fd, line);

	// ON DEMANDE UN FREE TOTAL PLUSIEURS FOIS, PAS D'ERREUR
	get_next_line(-10, &line);
	get_next_line(-10, &line);


/* 
	// TEST BASIQUE, DANS UN WHILE, FONCTIONNEMENT NORMALE
	fd = open("./files/1lignes", O_RDONLY);
	int		i = 0; while (get_next_line(fd, &line) == 1)
	{
		i++;
		printf("call %d: %s\n", i, line);
	}
	printf("call %d non executé !\n", (i+1));
*/

	return (0);
}
