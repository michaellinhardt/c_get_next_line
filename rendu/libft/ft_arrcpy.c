/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:33:22 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/17 21:56:21 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_arrcpy(char **arr)
{
	char	**new_arr;
	size_t	pos;

	if (!(new_arr = (char**)malloc(sizeof(char *) * (ft_arrlen(arr) + 1))))
		return (NULL);
	pos = 0;
	while (arr && arr[pos])
	{
		new_arr[pos] = ft_strdup(arr[pos]);
		pos++;
	}
	new_arr[pos] = NULL;
	return (new_arr);
}
