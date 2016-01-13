/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:21:58 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 19:03:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		sign;

	sign = 1;
	ret = 0;
	while (ft_isspace(*str))
		++str;
	if (!ft_isdigit(*str))
	{
		if (*str == '-')
			sign = -1;
		else if (*str != '+')
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0') * sign;
	return (ret);
}
