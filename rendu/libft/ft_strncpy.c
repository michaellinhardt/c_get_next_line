/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:19:47 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:45:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*tmp;
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	tmp = dst;
	i = 0;
	while (n-- > 0)
	{
		if (src[i] && i <= src_len)
			tmp[i] = src[i];
		else
			tmp[i] = '\0';
		i++;
	}
	return (dst);
}
