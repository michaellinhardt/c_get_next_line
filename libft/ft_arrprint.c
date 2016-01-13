/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:35:09 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/17 21:57:27 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_arrprint(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == NULL)
			break ;
		else if (i > 0)
			ft_putchar('\n');
		ft_putstr(arr[i]);
		i++;
	}
}
