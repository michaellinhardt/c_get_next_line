/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:36:16 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 19:04:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s1, unsigned int start, size_t len)
{
	char	*sub;

	if (!s1)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	ft_memcpy(sub, s1 + start, len);
	sub[len] = '\0';
	return (sub);
}
