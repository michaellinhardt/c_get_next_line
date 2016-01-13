/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:41:10 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/17 21:47:27 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	d;
	int		start;
	int		end;
	char	**tab;

	tab = NULL;
	i = 0;
	d = 0;
	if (!s || !(tab =
				(char **)malloc(sizeof(*tab) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
			tab[d++] = ft_strsub(s, start, (end - start));
	}
	tab[d] = NULL;
	return (tab);
}
