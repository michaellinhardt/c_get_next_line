/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:35:27 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:46:27 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	i = size;
	while (i-- != 0 && *tmp_dst != '\0')
		tmp_dst++;
	dst_len = tmp_dst - dst;
	i = size - dst_len;
	if (i == 0)
		return (dst_len + ft_strlen(tmp_src));
	while (*tmp_src != '\0')
	{
		if (i != 1)
		{
			*tmp_dst++ = *tmp_src;
			i--;
		}
		tmp_src++;
	}
	*tmp_dst = '\0';
	return (dst_len + (tmp_src - src));
}
