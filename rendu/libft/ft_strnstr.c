/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:57:14 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:47:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*tmp_s1;
	const char	*tmp_s2;
	size_t		tmp_n;

	if (s2[0] == '\0')
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	while (*s1 != '\0' && n)
	{
		tmp_s1 = s1;
		tmp_s2 = s2;
		tmp_n = n;
		while (*tmp_s2 != '\0' && *tmp_s1 == *tmp_s2 && tmp_n)
		{
			tmp_s1++;
			tmp_s2++;
			tmp_n--;
		}
		if (*tmp_s2 == '\0')
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
