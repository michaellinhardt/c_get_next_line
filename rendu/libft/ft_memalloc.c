/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:02:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/22 05:54:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)))
		ft_bzero(ret, size);
	else
		ret = NULL;
	return (ret);
}
