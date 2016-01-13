/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:42:50 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:45:21 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	len = (ft_strlen(s1) >= ft_strlen(s2)) ? ft_strlen(s1) : ft_strlen(s2);
	return (ft_strncmp(s1, s2, len));
}
